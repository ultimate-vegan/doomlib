cmake_minimum_required(VERSION 3.14)

project(doomlib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(doomlib SHARED
  doomlib_global.h
  doomlib.cpp
  doomlib.h
  wadfile.cpp
  wadfile.h
  common.cpp
  common.h
  thing.cpp thing.h
)

file(GLOB_RECURSE DL_SOURCES
    test.cpp
    doomlib.cpp
    common.cpp
    wadfile.cpp
    thing.cpp
)

file(GLOB_RECURSE DL_HEADERS
    doomlib_global.h
    doomlib.h
    common.h
    wadfile.h
    thing.h
)

add_executable(doomlibtest ${DL_SOURCES} ${DL_HEADERS}
     wadfile.h wadfile.cpp
     common.cpp common.h
     thing.h thing.cpp
     doommap.h doommap.cpp)

install(TARGETS doomlibtest
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_compile_definitions(doomlib PRIVATE DOOMLIB_LIBRARY)
