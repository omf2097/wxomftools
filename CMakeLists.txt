cmake_minimum_required(VERSION 2.6)
project(wxBKEditor CXX)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-scripts)
find_package(wxwidgets3)
find_package(shadowdive)
find_package(ZLIB)
find_package(PNG)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 ${WX_OPTS}")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb -fno-omit-frame-pointer -Werror")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g -O2 -fno-omit-frame-pointer -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")


add_executable(wxbkeditor
    src/wxbkeditor/gui.cpp
    src/wxbkeditor/app.cpp
    src/wxbkeditor/editorframe.cpp
    src/wxbkeditor/animationtreedataitem.cpp
    src/wxbkeditor/newanimationdialog.cpp
    src/shared/shared.cpp
    src/shared/animationdialog.cpp
    src/shared/spritedialog.cpp
    src/shared/spriteimportdialog.cpp
    src/shared/helpers.cpp
    src/shared/stringtreedataitem.cpp
)

#add_executable(wxafeditor
#    src/wxafeditor/gui.cpp
#    src/wxafeditor/app.cpp
#    src/wxafeditor/editorframe.cpp
#    src/wxafeditor/animationtreedataitem.cpp
#    src/shared/shared.cpp
#    src/shared/animationdialog.cpp
#    src/shared/spritedialog.cpp
#    src/shared/spriteimportdialog.cpp
#    src/shared/helpers.cpp
#    src/shared/stringtreedataitem.cpp
#)

set(COREINCS
    src/shared/
    ${WXWIDGETS_INCLUDE_DIR}
    ${SHADOWDIVE_INCLUDE_DIR}
)

set(CORELIBS
    ${WXWIDGETS_LIBRARY}
    ${SHADOWDIVE_LIBRARY}
    ${PNG_LIBRARY}
    ${ZLIB_LIBRARY}
)

IF(MINGW)
    set(CORELIBS mingw32 ${CORELIBS} comctl32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

    IF(NOT ${CMAKE_BUILD_TYPE} MATCHES "Debug")
        set_target_properties(wxbkeditor PROPERTIES LINK_FLAGS "-mwindows")
#        set_target_properties(wxafeditor PROPERTIES LINK_FLAGS "-mwindows")
    ENDIF()
ENDIF()


include_directories(${COREINCS})
target_link_libraries(wxbkeditor ${CORELIBS})
#target_link_libraries(wxafeditor ${CORELIBS})
