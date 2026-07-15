# // -------------------------------------
# NOTICE: This CMake configuration will automatically download and build GLFW 
# locally via Git if it is not found on your system. If you do not agree to 
# this automated behavior, please do not use this file.
# -------------------------------------

cmake_minimum_required(VERSION 3.14)
project(KrossEngineC C)

add_executable(kross main.c)

target_compile_features(kross PRIVATE c_std_99)

if(MSVC)
    target_compile_options(kross PRIVATE /W3)
elseif(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_C_COMPILER_ID MATCHES "GNU")
    target_compile_options(kross PRIVATE -Wall -Wextra)
endif()

find_package(OpenGL REQUIRED)
target_link_libraries(kross PRIVATE OpenGL::GL)

find_package(glfw3 CONFIG QUIET)
if(NOT glfw3_FOUND)
    find_package(GLFW QUIET)
endif()

if(glfw3_FOUND)
    target_link_libraries(kross PRIVATE glfw)
elseif(GLFW_FOUND)
    target_link_libraries(kross PRIVATE GLFW::GLFW)
else()
    message(STATUS "GLFW not found locally. Fetching from GitHub for Windows build...")
    include(FetchContent)
    
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_INSTALL OFF CACHE BOOL "" FORCE) 

    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG        3.4
    )
    FetchContent_MakeAvailable(glfw)
    
    target_link_libraries(kross PRIVATE glfw)
endif()
# -------------------------------------
