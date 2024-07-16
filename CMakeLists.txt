cmake_minimum_required(VERSION 3.14)

project(doomlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_library(doomlib SHARED
#   doomlib_global.h
#   doomlib.cpp
#   doomlib.h
#   test.cpp
# )

file(GLOB_RECURSE DL_SOURCES
    test.cpp
    doomlib.cpp
)

file(GLOB_RECURSE DL_HEADERS
    doomlib_global.h
    doomlib.h
)

add_executable(doomlibtest ${DL_SOURCES} ${DL_HEADERS}
    wadfile.h wadfile.cpp
    common.cpp
    common.h
    things.h things.cpp)

install(TARGETS doomlibtest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# target_compile_definitions(doomlib PRIVATE DOOMLIB_LIBRARY)
