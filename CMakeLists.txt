cmake_minimum_required(VERSION 2.6)
project(wxBKEditor CXX)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-scripts)
find_package(wxwidgets3)
find_package(shadowdive)

set(CMAKE_C_FLAGS "-Wall -std=c++11 -ggdb -Werror")
set(CMAKE_C_FLAGS_DEBUG "-Wall -std=c++11 -ggdb -Werror")
set(CMAKE_C_FLAGS_RELEASE "-Wall -std=c++11 -O2 -march=native -Werror -s")

add_executable(wxbkeditor 
    src/gui.cpp
    src/app.cpp
    src/editorframe.cpp
    src/animationdialog.cpp
    src/spritedialog.cpp
    src/animationtreedataitem.cpp
)

set(COREINCS
    src/
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
