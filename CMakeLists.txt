cmake_minimum_required(VERSION 2.6)
project(wxBKEditor CXX)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-scripts)
find_package(wxwidgets3)
find_package(shadowdive)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -Werror ${WX_OPTS}")
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -march=native -s")

add_executable(wxbkeditor 
    src/wxbkeditor/gui.cpp
    src/wxbkeditor/app.cpp
    src/wxbkeditor/editorframe.cpp
    src/wxbkeditor/animationtreedataitem.cpp
    src/shared/shared.cpp
    src/shared/animationdialog.cpp
    src/shared/spritedialog.cpp
)

add_executable(wxafeditor 
    src/wxafeditor/gui.cpp
    src/wxafeditor/app.cpp
    src/wxafeditor/editorframe.cpp
    src/wxafeditor/animationtreedataitem.cpp
    src/shared/shared.cpp
    src/shared/animationdialog.cpp
    src/shared/spritedialog.cpp
)

set(COREINCS
    src/shared/
    ${WXWIDGETS_INCLUDE_DIR} 
    ${SHADOWDIVE_INCLUDE_DIR} 
)

set(CORELIBS
    ${WXWIDGETS_LIBRARY}
    ${SHADOWDIVE_LIBRARY}
)

IF(MINGW)
    set(CORELIBS mingw32 ${CORELIBS} comctl32)
ENDIF(MINGW)

include_directories(${COREINCS})
target_link_libraries(wxbkeditor ${CORELIBS})
target_link_libraries(wxafeditor ${CORELIBS})
