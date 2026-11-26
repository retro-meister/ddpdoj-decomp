cmake_minimum_required(VERSION 3.20)
project(ddpdoj_pc LANGUAGES C)

include(CTest)
find_package(SDL3 3.2 CONFIG REQUIRED)
find_package(Python3 COMPONENTS Interpreter REQUIRED)

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

add_library(ddpdoj_death_loop OBJECT ../src/game/system/main.c)
target_compile_features(ddpdoj_death_loop PRIVATE c_std_11)
target_compile_definitions(ddpdoj_death_loop PRIVATE DDPDOJ_PC PUBLIC DEATH_LABEL)
target_include_directories(ddpdoj_death_loop PRIVATE ../include)

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
    # Legacy arcade calls still pass packed integers across the register ABI.
    target_compile_options(${target} PRIVATE -Wno-int-conversion -fno-common)
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

add_library(ddpdoj_gif STATIC gif_packet.c gif_stream.c)
target_compile_features(ddpdoj_gif PRIVATE c_std_11)
target_compile_definitions(ddpdoj_gif PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_gif PUBLIC . ../include)

add_library(ddpdoj_gs STATIC gs.c gs_texture.c)
target_link_libraries(ddpdoj_gs PUBLIC ddpdoj_gif SDL3::SDL3)

add_library(ddpdoj_disc STATIC disc_image.c)
target_compile_features(ddpdoj_disc PUBLIC c_std_11)
target_include_directories(ddpdoj_disc PUBLIC .)

add_library(ddpdoj_sfx STATIC sfx.c)
target_link_libraries(ddpdoj_sfx PUBLIC SDL3::SDL3 PRIVATE ddpdoj_disc)

add_library(ddpdoj_cdvd STATIC cdvd.c)
target_compile_features(ddpdoj_cdvd PRIVATE c_std_11)
target_include_directories(ddpdoj_cdvd PUBLIC . ../include)
target_link_libraries(ddpdoj_cdvd PUBLIC ddpdoj_disc PRIVATE SDL3::SDL3)

add_library(ddpdoj_video STATIC video.c)
target_compile_features(ddpdoj_video PRIVATE c_std_11)
target_compile_definitions(ddpdoj_video PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_video PUBLIC . ../include)
target_link_libraries(ddpdoj_video PUBLIC SDL3::SDL3)

add_library(ddpdoj_pad STATIC pad.c)
target_compile_features(ddpdoj_pad PRIVATE c_std_11)
target_compile_definitions(ddpdoj_pad PUBLIC DDPDOJ_PC)
target_include_directories(ddpdoj_pad PUBLIC . ../include)
target_link_libraries(ddpdoj_pad PUBLIC SDL3::SDL3)
target_link_libraries(ddpdoj_gallery PRIVATE ddpdoj_cdvd ddpdoj_gs ddpdoj_mode ddpdoj_pad ddpdoj_sfx)

if(BUILD_TESTING)
    foreach(mode IN ITEMS main death)
        add_executable(ddpdoj_${mode}_data_alias_test tests/data_alias_test.c)
        target_link_libraries(ddpdoj_${mode}_data_alias_test PRIVATE
            ddpdoj_${mode}_gameplay ddpdoj_replay_storage)
        add_test(NAME ${mode}_data_aliases COMMAND ddpdoj_${mode}_data_alias_test)
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
    add_executable(ddpdoj_splash_test tests/splash_test.c
        ../src/game/frontend/splash.c ../src/game/system/system_state.c)
    target_link_libraries(ddpdoj_splash_test PRIVATE ddpdoj_video ddpdoj_disc)
    add_test(NAME splash_render COMMAND ddpdoj_splash_test)
    add_executable(ddpdoj_pad_test tests/pad_test.c ../src/gallery/pad.c)
    target_link_libraries(ddpdoj_pad_test PRIVATE ddpdoj_pad ddpdoj_gallery_system ddpdoj_mode)
    add_test(NAME pad_mapping COMMAND ddpdoj_pad_test)
    foreach(target IN ITEMS ddpdoj_disc_test ddpdoj_gallery_disc_test)
        target_compile_definitions(${target} PRIVATE DDPDOJ_PC)
        target_link_libraries(${target} PRIVATE ddpdoj_cdvd)
    endforeach()
    if(WIN32 AND TARGET SDL3::SDL3-shared)
        foreach(target IN ITEMS ddpdoj_disc_test ddpdoj_gallery_disc_test ddpdoj_splash_test
                                ddpdoj_pad_test ddpdoj_gallery_render_test ddpdoj_gallery_boot_test)
            add_custom_command(TARGET ${target} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:${target}>
                VERBATIM)
        endforeach()
    endif()
    add_test(NAME disc_image COMMAND ddpdoj_disc_test main-disc-fixture.iso)
    add_test(NAME gallery_disc_image COMMAND ddpdoj_gallery_disc_test gallery-disc-fixture.iso)

    set(DDPDOJ_TEST_ISO "" CACHE FILEPATH "Optional retail ISO for native disc checks")
    set(DDPDOJ_TEST_BASEROM "${CMAKE_CURRENT_SOURCE_DIR}/../baserom" CACHE PATH
        "Directory containing the extracted retail executables")
    if(DDPDOJ_TEST_ISO)
        add_test(NAME retail_disc_image
                 COMMAND ddpdoj_disc_test "${DDPDOJ_TEST_ISO}" "${DDPDOJ_TEST_BASEROM}")
        add_test(NAME retail_splash_render COMMAND ddpdoj_splash_test "${DDPDOJ_TEST_ISO}")
        add_test(NAME retail_gallery_loading_font
                 COMMAND ddpdoj_gallery_render_test --retail "${DDPDOJ_TEST_ISO}")
        add_test(NAME retail_gallery_boot COMMAND ddpdoj_gallery_boot_test "${DDPDOJ_TEST_ISO}")
    endif()
endif()
