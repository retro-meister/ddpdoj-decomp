include(BundleUtilities)
set(app "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/DaiOuJou.app")
fixup_bundle("${app}" "" "")
execute_process(COMMAND /usr/bin/codesign --force --deep --sign - "${app}"
                COMMAND_ERROR_IS_FATAL ANY)
