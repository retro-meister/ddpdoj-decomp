cmake_minimum_required(VERSION 3.20)
project(ddpdoj_pc LANGUAGES C)

include(CTest)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(SDL_SHARED ON)
set(SDL_STATIC OFF)
set(SDL_TEST_LIBRARY OFF)
set(sdl_source "${CMAKE_CURRENT_SOURCE_DIR}/../vendor/SDL")
add_subdirectory("${sdl_source}" vendor/SDL EXCLUDE_FROM_ALL)
if(WIN32)
    set_target_properties(SDL3-shared PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
endif()
find_package(Python3 COMPONENTS Interpreter REQUIRED)

add_library(ddpdoj_arcade_address STATIC arcade_address.c)
target_compile_features(ddpdoj_arcade_address PRIVATE c_std_11)
target_include_directories(ddpdoj_arcade_address PUBLIC ../include)
target_link_libraries(ddpdoj_arcade_address PRIVATE ${CMAKE_DL_LIBS})

function(stage_sjis_sources output)
    set(staged_sources)
    get_filename_component(repo_root ".." ABSOLUTE)
    foreach(source IN LISTS ARGN)
        get_filename_component(input "${source}" ABSOLUTE)
        file(RELATIVE_PATH relative "${repo_root}" "${input}")
        set(staged "${CMAKE_CURRENT_BINARY_DIR}/sjis/${relative}")
        set(encoder "${CMAKE_CURRENT_SOURCE_DIR}/../tools/sjis.py")
        add_custom_command(OUTPUT "${staged}"
            COMMAND Python3::Interpreter "${encoder}" "${input}" "${staged}"
            DEPENDS "${input}" "${encoder}"
            VERBATIM)
        list(APPEND staged_sources "${staged}")
    endforeach()
    add_custom_target(stage_${output} DEPENDS ${staged_sources})
    set(${output} "${staged_sources}" PARENT_SCOPE)
endfunction()

add_library(ddpdoj_mode STATIC mode.c)
target_include_directories(ddpdoj_mode PUBLIC ../include)

add_library(ddpdoj_game_loop OBJECT ../src/game/system/main.c)
target_compile_features(ddpdoj_game_loop PRIVATE c_std_11)
target_compile_definitions(ddpdoj_game_loop PRIVATE DDPDOJ_PC)
target_include_directories(ddpdoj_game_loop PRIVATE ../include)
target_link_libraries(ddpdoj_game_loop PRIVATE ddpdoj_arcade_address)

add_library(ddpdoj_death_loop OBJECT ../src/game/system/main.c)
target_compile_features(ddpdoj_death_loop PRIVATE c_std_11)
target_compile_definitions(ddpdoj_death_loop PRIVATE DDPDOJ_PC PUBLIC DEATH_LABEL)
target_include_directories(ddpdoj_death_loop PRIVATE ../include)
target_link_libraries(ddpdoj_death_loop PRIVATE ddpdoj_arcade_address)

function(game_manifest_sources output executable group)
    set(manifest "${CMAKE_CURRENT_SOURCE_DIR}/../config/${executable}/splat.yaml")
    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${manifest}")
    # Splat names source sections in list entries and BSS sections in mappings.
    set(prefix [=[^ +[-] +(\[0x[0-9a-fA-F]+, (c|[.][a-z]+), |\{type: [.][a-z]+, vram: 0x[0-9a-fA-F]+, name: )]=])
    if(group STREQUAL "gameplay")
        set(source_pattern "game/([a-zA-Z0-9_]+/)?[a-zA-Z0-9_]+")
    else()
        set(source_pattern "game/${group}/[a-zA-Z0-9_]+")
    endif()
    set(suffix [=[(\]|\})]=])
    file(STRINGS "${manifest}" entries REGEX "${prefix}${source_pattern}${suffix}")
    set(sources)
    foreach(entry IN LISTS entries)
        string(REGEX MATCH "${source_pattern}" source "${entry}")
        list(APPEND sources "../src/${source}.c")
    endforeach()
    list(REMOVE_DUPLICATES sources)
    if(group STREQUAL "gameplay")
        list(FILTER sources EXCLUDE REGEX "/game/(frontend|system)/")
    endif()
    if(NOT sources)
        message(FATAL_ERROR "No ${group} source subsegments found in ${manifest}")
    endif()
    set(${output} "${sources}" PARENT_SCOPE)
endfunction()

function(add_game_library target executable group)
    game_manifest_sources(sources ${executable} ${group})
    list(REMOVE_ITEM sources ${${group}_sjis_inputs})
    add_library(${target} STATIC ${sources} ${${group}_sjis} ${ARGN})
    if(TARGET stage_${group}_sjis)
        add_dependencies(${target} stage_${group}_sjis)
    endif()
    set_target_properties(${target} PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED YES)
    target_compile_definitions(${target} PUBLIC DDPDOJ_PC)
    target_include_directories(${target} PRIVATE ../include)
    target_link_libraries(${target} PRIVATE ddpdoj_arcade_address)
    # The arcade register bank accesses the same storage through several types.
    target_compile_options(${target} PRIVATE -Wno-int-conversion -fno-common -fno-strict-aliasing)
    if(executable STREQUAL "DEATH.ELF")
        target_compile_definitions(${target} PUBLIC DEATH_LABEL)
    endif()
endfunction()

set(frontend_sjis_inputs ../src/game/frontend/menu.c ../src/game/frontend/name_entry.c)
set(system_sjis_inputs ../src/game/system/memcard.c)
stage_sjis_sources(frontend_sjis ${frontend_sjis_inputs})
stage_sjis_sources(system_sjis ${system_sjis_inputs})
add_game_library(ddpdoj_main_frontend SLPS_252.33 frontend)
add_game_library(ddpdoj_death_frontend DEATH.ELF frontend)
add_game_library(ddpdoj_main_system SLPS_252.33 system ../src/game/system/cd_io.c)
add_game_library(ddpdoj_death_system DEATH.ELF system ../src/game/system/cd_io.c)
add_game_library(ddpdoj_main_gameplay SLPS_252.33 gameplay)
add_game_library(ddpdoj_death_gameplay DEATH.ELF gameplay)
add_library(ddpdoj_replay_storage STATIC replay_storage.c)
target_compile_features(ddpdoj_replay_storage PRIVATE c_std_11)
target_compile_options(ddpdoj_replay_storage PRIVATE -fno-common)
target_include_directories(ddpdoj_replay_storage PUBLIC ../include)
target_link_libraries(ddpdoj_main_system PUBLIC ddpdoj_replay_storage)
target_link_libraries(ddpdoj_death_system PUBLIC ddpdoj_replay_storage)

add_library(ddpdoj_gallery_system OBJECT ../src/gallery/sys.c)
target_compile_features(ddpdoj_gallery_system PRIVATE c_std_11)
target_compile_definitions(ddpdoj_gallery_system PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_gallery_system PRIVATE ../include)

stage_sjis_sources(gallery_sjis ../src/gallery/main.c ../src/gallery/viewer.c)
add_library(ddpdoj_gallery STATIC
    ${gallery_sjis}
    gallery_solid_rect.c
    ../src/gallery/bmp.c
    ../src/gallery/cd.c
    ../src/gallery/font.c
    ../src/gallery/glyph_cache.c
    ../src/gallery/iop.c
    ../src/gallery/lzss.c
    ../src/gallery/mc.c
    ../src/gallery/pad.c
    ../src/gallery/sound.c
    ../src/gallery/sprite.c
    ../src/gallery/tex_upload.c
    $<TARGET_OBJECTS:ddpdoj_gallery_system>
)
set_target_properties(ddpdoj_gallery PROPERTIES C_STANDARD 11 C_STANDARD_REQUIRED YES)
add_dependencies(ddpdoj_gallery stage_gallery_sjis)
target_compile_definitions(ddpdoj_gallery PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_gallery PUBLIC ../include)
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_link_libraries(ddpdoj_gallery PRIVATE m)
endif()

add_library(ddpdoj_gif STATIC gif_packet.c gif_stream.c)
target_compile_features(ddpdoj_gif PRIVATE c_std_11)
target_compile_definitions(ddpdoj_gif PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_gif PUBLIC . ../include)

add_library(ddpdoj_gs STATIC gs.c gs_texture.c presentation.c vblank.c)
target_link_libraries(ddpdoj_gs PUBLIC ddpdoj_gif SDL3::SDL3)

add_library(ddpdoj_disc STATIC disc_image.c)
target_compile_features(ddpdoj_disc PUBLIC c_std_11)
target_include_directories(ddpdoj_disc PUBLIC .)

add_library(ddpdoj_sfx STATIC sfx.c)
target_link_libraries(ddpdoj_sfx PUBLIC SDL3::SDL3 PRIVATE ddpdoj_disc)

add_library(ddpdoj_sound STATIC bgm.c)
target_compile_features(ddpdoj_sound PRIVATE c_std_11)
target_include_directories(ddpdoj_sound PUBLIC ../include)
target_link_libraries(ddpdoj_sound PRIVATE ddpdoj_sfx ddpdoj_disc)
target_link_libraries(ddpdoj_main_system PRIVATE ddpdoj_sound)
target_link_libraries(ddpdoj_death_system PRIVATE ddpdoj_sound)

add_library(ddpdoj_cdvd STATIC cdvd.c)
target_compile_features(ddpdoj_cdvd PRIVATE c_std_11)
target_include_directories(ddpdoj_cdvd PUBLIC . ../include)
target_link_libraries(ddpdoj_cdvd PUBLIC ddpdoj_disc PRIVATE SDL3::SDL3)

add_library(ddpdoj_pad STATIC pad.c)
target_compile_features(ddpdoj_pad PRIVATE c_std_11)
target_compile_definitions(ddpdoj_pad PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_pad PUBLIC . ../include)
target_link_libraries(ddpdoj_pad PUBLIC SDL3::SDL3)
add_library(ddpdoj_memory_card STATIC memory_card.c)
target_compile_features(ddpdoj_memory_card PRIVATE c_std_11)
target_compile_definitions(ddpdoj_memory_card PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_memory_card PUBLIC . ../include)
target_link_libraries(ddpdoj_memory_card PRIVATE SDL3::SDL3)
target_link_libraries(ddpdoj_main_system PRIVATE ddpdoj_memory_card)
target_link_libraries(ddpdoj_death_system PRIVATE ddpdoj_memory_card)
target_link_libraries(ddpdoj_gallery PRIVATE ddpdoj_cdvd ddpdoj_gs ddpdoj_mode ddpdoj_pad ddpdoj_sfx)

foreach(mode IN ITEMS main death)
    # The original core groups call into one another. Let CMake rescan the
    # archive group when the platform linker resolves static inputs in order.
    target_link_libraries(ddpdoj_${mode}_system PRIVATE ddpdoj_${mode}_frontend ddpdoj_mode)
    target_link_libraries(ddpdoj_${mode}_frontend PRIVATE ddpdoj_${mode}_gameplay)
    target_link_libraries(ddpdoj_${mode}_gameplay PRIVATE ddpdoj_${mode}_system)
    add_library(${mode}-mode MODULE mode_runtime.c)
    target_link_libraries(${mode}-mode PRIVATE
        ddpdoj_${mode}_system
        ddpdoj_sound ddpdoj_sfx ddpdoj_mode ddpdoj_cdvd ddpdoj_pad ddpdoj_memory_card ddpdoj_gs)
endforeach()
add_library(gallery-mode MODULE mode_runtime.c)
target_compile_definitions(gallery-mode PRIVATE DDPDOJ_GALLERY_HOST)
target_link_libraries(gallery-mode PRIVATE
    ddpdoj_gallery ddpdoj_gs ddpdoj_cdvd ddpdoj_mode ddpdoj_pad ddpdoj_sfx)

set(mode_modules main-mode death-mode gallery-mode)
set_target_properties(${mode_modules} PROPERTIES PREFIX "")
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    foreach(module IN LISTS mode_modules)
        target_link_options(${module} PRIVATE "LINKER:--exclude-libs,ALL")
    endforeach()
endif()
function(add_launcher target name mode)
    add_executable(${target} desktop.c presentation.c)
    target_include_directories(${target} PRIVATE ../include)
    target_compile_definitions(${target} PRIVATE START_MODE=${mode}
        MODE_SUFFIX="${CMAKE_SHARED_MODULE_SUFFIX}")
    target_link_libraries(${target} PRIVATE ddpdoj_disc SDL3::SDL3)
    set_target_properties(${target} PROPERTIES OUTPUT_NAME ${name})
    add_dependencies(${target} ${mode_modules})
endfunction()
add_launcher(ddpdoj_main ddpdoj GAME_MODE_MAIN)
add_launcher(ddpdoj_death ddpdoj-death GAME_MODE_DEATH_LABEL)
add_launcher(ddpdoj_gallery_host ddpdoj-gallery GAME_MODE_GALLERY)
set(desktop_modes ddpdoj_main ddpdoj_death ddpdoj_gallery_host)
if(APPLE)
    set(app "DaiOuJou.app/Contents")
    set_target_properties(${desktop_modes} ${mode_modules} PROPERTIES INSTALL_RPATH "@executable_path/../Frameworks")
    install(TARGETS ${mode_modules} LIBRARY DESTINATION "${app}/PlugIns")
    install(TARGETS ${desktop_modes} RUNTIME DESTINATION "${app}/MacOS")
    install(FILES "$<TARGET_FILE:SDL3-shared>" DESTINATION "${app}/Frameworks"
            RENAME "$<TARGET_SONAME_FILE_NAME:SDL3-shared>")
    install(FILES macos/Info.plist DESTINATION "${app}")
    install(FILES "${sdl_source}/LICENSE.txt" DESTINATION "${app}/Resources" RENAME SDL3-LICENSE.txt)
    install(SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/macos/bundle.cmake")
else()
    install(TARGETS ${mode_modules} LIBRARY DESTINATION DaiOuJou)
    install(TARGETS ${desktop_modes} RUNTIME DESTINATION DaiOuJou)
    install(FILES "${sdl_source}/LICENSE.txt" DESTINATION DaiOuJou RENAME SDL3-LICENSE.txt)
    if(WIN32)
        install(FILES "$<TARGET_FILE:SDL3-shared>" DESTINATION DaiOuJou)
    else()
        set_target_properties(${desktop_modes} ${mode_modules} PROPERTIES INSTALL_RPATH "$ORIGIN")
        install(FILES "$<TARGET_FILE:SDL3-shared>" DESTINATION DaiOuJou
                RENAME "$<TARGET_SONAME_FILE_NAME:SDL3-shared>")
    endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CPACK_GENERATOR TGZ)
    set(CPACK_PACKAGE_FILE_NAME "DaiOuJou-Linux-${CMAKE_SYSTEM_PROCESSOR}")
    set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
    include(CPack)
endif()

if(BUILD_TESTING)
    add_executable(ddpdoj_memory_card_test tests/memory_card_test.c)
    target_link_libraries(ddpdoj_memory_card_test PRIVATE ddpdoj_memory_card SDL3::SDL3)
    add_test(NAME memory_card COMMAND ddpdoj_memory_card_test)

    add_executable(ddpdoj_arcade_address_test tests/arcade_address_test.c)
    target_compile_definitions(ddpdoj_arcade_address_test PRIVATE DDPDOJ_PC)
    target_link_libraries(ddpdoj_arcade_address_test PRIVATE ddpdoj_arcade_address)
    add_test(NAME arcade_address COMMAND ddpdoj_arcade_address_test)

    foreach(mode IN ITEMS main death)
        add_executable(ddpdoj_${mode}_data_alias_test tests/data_alias_test.c)
        target_link_libraries(ddpdoj_${mode}_data_alias_test PRIVATE
            ddpdoj_${mode}_gameplay ddpdoj_replay_storage)
        add_test(NAME ${mode}_data_aliases COMMAND ddpdoj_${mode}_data_alias_test)

        add_executable(ddpdoj_${mode}_boss_slots_test tests/boss_slots_test.c)
        target_link_libraries(ddpdoj_${mode}_boss_slots_test PRIVATE
            ddpdoj_${mode}_gameplay ddpdoj_${mode}_system)
        add_test(NAME ${mode}_boss_slots COMMAND ddpdoj_${mode}_boss_slots_test)
    endforeach()

    add_executable(ddpdoj_gif_test tests/gif_packet_test.c)
    target_link_libraries(ddpdoj_gif_test PRIVATE ddpdoj_gif)
    add_test(NAME gif_packets COMMAND ddpdoj_gif_test)

    add_executable(ddpdoj_gallery_render_test tests/gallery_render_test.c)
    target_link_libraries(ddpdoj_gallery_render_test PRIVATE ddpdoj_gallery ddpdoj_gs ddpdoj_disc)
    add_test(NAME gallery_render COMMAND ddpdoj_gallery_render_test)

    add_executable(ddpdoj_gallery_boot_test tests/gallery_boot_test.c)
    target_link_libraries(ddpdoj_gallery_boot_test PRIVATE
        ddpdoj_gallery ddpdoj_gs ddpdoj_cdvd ddpdoj_mode ddpdoj_pad ddpdoj_sfx)

    add_executable(ddpdoj_task_test
        tests/task_test.c
        ../src/game/system/task.c
        ../src/game/system/system_state.c
    )
    target_compile_features(ddpdoj_task_test PRIVATE c_std_11)
    target_compile_definitions(ddpdoj_task_test PRIVATE DDPDOJ_PC)
    target_include_directories(ddpdoj_task_test PRIVATE ../include)
    add_test(NAME task_scheduler COMMAND ddpdoj_task_test)

    add_executable(ddpdoj_game_loop_test tests/game_loop_test.c)
    target_link_libraries(ddpdoj_game_loop_test PRIVATE ddpdoj_game_loop ddpdoj_mode ddpdoj_replay_storage)
    add_test(NAME game_loop COMMAND ddpdoj_game_loop_test)

    add_executable(ddpdoj_death_loop_test tests/game_loop_test.c)
    target_link_libraries(ddpdoj_death_loop_test PRIVATE ddpdoj_death_loop ddpdoj_mode ddpdoj_replay_storage)
    add_test(NAME death_label_loop COMMAND ddpdoj_death_loop_test)

    add_executable(ddpdoj_gallery_mode_test tests/gallery_mode_test.c)
    target_link_libraries(ddpdoj_gallery_mode_test PRIVATE ddpdoj_gallery_system ddpdoj_mode)
    add_test(NAME gallery_mode COMMAND ddpdoj_gallery_mode_test)

    add_executable(ddpdoj_disc_test tests/disc_test.c ../src/game/system/cd_io.c)
    add_executable(ddpdoj_gallery_disc_test tests/disc_test.c ../src/gallery/cd.c)
    add_executable(ddpdoj_splash_test tests/splash_test.c)
    target_link_libraries(ddpdoj_splash_test PRIVATE ddpdoj_main_system
        ddpdoj_sound ddpdoj_sfx ddpdoj_mode ddpdoj_cdvd ddpdoj_pad ddpdoj_memory_card ddpdoj_gs)
    add_test(NAME splash_render COMMAND ddpdoj_splash_test)
    add_executable(ddpdoj_pad_test tests/pad_test.c ../src/gallery/pad.c)
    target_link_libraries(ddpdoj_pad_test PRIVATE ddpdoj_pad ddpdoj_gallery_system ddpdoj_mode)
    add_test(NAME pad_mapping COMMAND ddpdoj_pad_test)
    foreach(target IN ITEMS ddpdoj_disc_test ddpdoj_gallery_disc_test)
        target_compile_definitions(${target} PRIVATE DDPDOJ_PC)
        target_link_libraries(${target} PRIVATE ddpdoj_cdvd)
    endforeach()
    add_test(NAME disc_image COMMAND ddpdoj_disc_test main-disc-fixture.iso)
    add_test(NAME gallery_disc_image COMMAND ddpdoj_gallery_disc_test gallery-disc-fixture.iso)

    set(DDPDOJ_TEST_ISO "" CACHE FILEPATH "Optional retail ISO for native disc checks")
    set(DDPDOJ_TEST_BASEROM "${CMAKE_CURRENT_SOURCE_DIR}/../baserom" CACHE PATH
        "Directory containing the extracted retail executables")
    add_executable(ddpdoj_retail_sound_test tests/retail_sound_test.c)
    target_link_libraries(ddpdoj_retail_sound_test PRIVATE ddpdoj_sound ddpdoj_sfx ddpdoj_disc)

    if(DDPDOJ_TEST_ISO)
        add_test(NAME retail_sound COMMAND ddpdoj_retail_sound_test "${DDPDOJ_TEST_ISO}")
        set_tests_properties(retail_sound PROPERTIES ENVIRONMENT "SDL_AUDIODRIVER=dummy")
        add_test(NAME retail_disc_image
                 COMMAND ddpdoj_disc_test "${DDPDOJ_TEST_ISO}" "${DDPDOJ_TEST_BASEROM}")
        add_test(NAME retail_splash_render COMMAND ddpdoj_splash_test "${DDPDOJ_TEST_ISO}")
        add_test(NAME retail_gallery_loading_font
                 COMMAND ddpdoj_gallery_render_test --retail "${DDPDOJ_TEST_ISO}")
        add_test(NAME retail_gallery_boot COMMAND ddpdoj_gallery_boot_test "${DDPDOJ_TEST_ISO}")

        foreach(mode IN ITEMS main death)
            set(target ddpdoj_${mode}_retail_gameplay_test)
            add_executable(${target} tests/retail_gameplay_test.c)
            target_link_libraries(${target} PRIVATE ddpdoj_${mode}_system
                ddpdoj_sound ddpdoj_sfx ddpdoj_mode ddpdoj_cdvd ddpdoj_pad ddpdoj_memory_card ddpdoj_gs)
            add_test(NAME retail_${mode}_gameplay COMMAND ${target} "${DDPDOJ_TEST_ISO}"
                "${CMAKE_CURRENT_BINARY_DIR}/test-cards-${mode}")
            set_tests_properties(retail_${mode}_gameplay PROPERTIES
                ENVIRONMENT "SDL_AUDIODRIVER=dummy" RUN_SERIAL TRUE TIMEOUT 180)
        endforeach()
        add_executable(ddpdoj_retail_card_test tests/retail_card_test.c)
        target_link_libraries(ddpdoj_retail_card_test PRIVATE ddpdoj_main_system
            ddpdoj_sound ddpdoj_sfx ddpdoj_mode ddpdoj_cdvd ddpdoj_pad ddpdoj_memory_card ddpdoj_gs)
        add_test(NAME retail_card_save_load COMMAND ddpdoj_retail_card_test "${DDPDOJ_TEST_ISO}"
            "${CMAKE_CURRENT_BINARY_DIR}/test-cards-save-load")
        set_tests_properties(retail_card_save_load PROPERTIES ENVIRONMENT "SDL_AUDIODRIVER=dummy")

        add_test(NAME retail_two_player COMMAND ddpdoj_main_retail_gameplay_test "${DDPDOJ_TEST_ISO}"
            "${CMAKE_CURRENT_BINARY_DIR}/test-cards-two-player" --two-player)
        set_tests_properties(retail_two_player PROPERTIES
            ENVIRONMENT "SDL_AUDIODRIVER=dummy" RUN_SERIAL TRUE TIMEOUT 180)
        foreach(slot RANGE 0 9)
            set(name retail_super_replay_${slot})
            if(slot EQUAL 2)
                set(name retail_super_replay)
            elseif(slot EQUAL 4)
                set(name retail_super_replay_stage5)
            endif()
            add_test(NAME ${name} COMMAND ddpdoj_main_retail_gameplay_test "${DDPDOJ_TEST_ISO}"
                "${CMAKE_CURRENT_BINARY_DIR}/test-cards-replay-${slot}" --super-replay ${slot})
            set_tests_properties(${name} PROPERTIES LABELS super-replay
                ENVIRONMENT "SDL_AUDIODRIVER=dummy" RUN_SERIAL TRUE TIMEOUT 600)
        endforeach()
    endif()
endif()
