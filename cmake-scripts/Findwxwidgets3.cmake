
if(MINGW)
    set(WXWIDGETS_SEARCH_PATHS
        /usr/local/
        /usr
        /opt
    )

    find_path(WXWIDGETS_INCLUDE_DIR wx/wx.h
        HINTS ${WXWIDGETS_ROOT}
        PATH_SUFFIXES include include/wx-3.0
        PATHS ${WXWIDGETS_SEARCH_PATHS}
    )

    find_path(WXWIDGETS_SETUP_PATH wx/setup.h
        HINTS ${WXWIDGETS_ROOT}
        PATH_SUFFIXES 
            lib/wx/include/msw-unicode-static-3.0/ 
            lib/wx/include/msw-unicode-dynamic-3.0/
        PATHS ${WXWIDGETS_SEARCH_PATHS}
    )

    set(SEARCH_LIBS wx_mswu_html-3.0 wx_mswu_adv-3.0 wx_mswu_aui-3.0 wx_mswu_core-3.0 wx_baseu-3.0)

    foreach(SLIB ${SEARCH_LIBS})
    find_library(FOUND_${SLIB}_LIB ${SLIB} HINTS ${WXWIDGETS_ROOT} PATH_SUFFIXES lib64 lib bin PATHS ${WXWIDGETS_SEARCH_PATHS} )
    set(WXWIDGETS_LIBRARY ${WXWIDGETS_LIBRARY} ${FOUND_${SLIB}_LIB})
    endforeach(SLIB)

    set(WXWIDGETS_INCLUDE_DIR ${WXWIDGETS_INCLUDE_DIR} ${WXWIDGETS_SETUP_PATH})

    if(WXWIDGETS_INCLUDE_DIR AND WXWIDGETS_LIBRARY)
        SET(WXWIDGETS_FOUND TRUE)
    ENDIF(WXWIDGETS_INCLUDE_DIR AND WXWIDGETS_LIBRARY)

    SET(WX_OPTS "")
else(MINGW)
    find_program(WX_CONFIG
        NAMES wx-config-3.0 wx-config-2.9 wx-config
        PATHS
            /usr/bin
            /usr/local/bin
    )

    set(WXWIDGETS_INCLUDE_DIR "")
    set(WXWIDGETS_LIBRARY "")

    execute_process(
        COMMAND ${WX_CONFIG} "--cxxflags"
        OUTPUT_VARIABLE WX_INC_OPTS
    )

    execute_process(
        COMMAND ${WX_CONFIG} "--libs" "std,aui"
        OUTPUT_VARIABLE WX_LIB_OPTS
    )

    string(REGEX REPLACE "(\r?\n)+$" "" WX_LIB_OPTS "${WX_LIB_OPTS}")
    string(REGEX REPLACE "(\r?\n)+$" "" WX_INC_OPTS "${WX_INC_OPTS}")

    if(WX_INC_OPTS AND WX_LIB_OPTS)
        set(WXWIDGETS_FOUND TRUE)
    endif(WX_INC_OPTS AND WX_LIB_OPTS)

    set(WX_OPTS "${WX_LIB_OPTS} ${WX_INC_OPTS}")
endif(MINGW)

if(WXWIDGETS_FOUND)
    message(STATUS "Found wxWidgets.")
else(WXWIDGETS_FOUND)
    message(WARNING "Could not find wxWidgets")
endif(WXWIDGETS_FOUND)

