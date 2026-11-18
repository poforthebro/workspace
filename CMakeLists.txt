cmake_minimum_required(VERSION 3.16)
project(TNG033_All_Projects LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recursively find all CMakeLists.txt files across all subfolders (including spaces in folder names like "Ovning 2")
file(GLOB_RECURSE ALL_SUB_CMAKELISTS CONFIGURE_DEPENDS RELATIVE "${CMAKE_SOURCE_DIR}" "*/CMakeLists.txt")

foreach(CMAKELIST IN LISTS ALL_SUB_CMAKELISTS)
    # Skip anything inside the build/ directory
    if(NOT CMAKELIST MATCHES "^build/")
        get_filename_component(SUBDIR "${CMAKELIST}" DIRECTORY)
        add_subdirectory("${SUBDIR}")
    endif()
endforeach()