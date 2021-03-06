project(TrabalhoCG CXX C)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
###################
file(GLOB_RECURSE ENGINE_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.h" "src/*.hpp")
file(GLOB_RECURSE ENGINE_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp" "thirdparties/*.c" "thirdparty/*.cpp")
file(GLOB_RECURSE GAME_SHADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "shaders/*.glsl")
file(GLOB_RECURSE MODELS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "models/*.obj" "models/*.JPG" "models/*.jpg")



##################



set(SRC_LIST ${ENGINE_SOURCES} ${GAME_SHADERS} ${ENGINE_HEADERS})
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeInclude)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Type of build: release of debug")


file(COPY ${GAME_SHADERS} ${TEXTURES} ${MODELS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

# the FindOpenGL.cmake file sets the value of
# OPENGL_LIBRARY to /usr/local/lib/libGL.so,
# this place has an old version of the libGL.
if(UNIX)
    set(OPENGL_LIBRARY "/usr/lib/libGL.so")
endif()

add_executable(${CMAKE_PROJECT_NAME} ${SRC_LIST})

# If using g++, we need to set the c++11 standart and
# the -rdynamic flag for backtrace.
if( NOT MSVC)
    if( CMAKE_BUILD_TYPE STREQUAL "Release")
        add_definitions(-DRELEASE)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
    else()
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
    endif()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

    if(UNIX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -rdynamic")
    endif()
endif()

include_directories(src/ thirdparty/ ${SDL2_INCLUDE_DIRECTORY} ${SDL2IMAGE_INCLUDE_DIR} ${GLEW_INCLUDE_DIRECTORY} ${OpenGL_INCLUDE_DIRECTORY}
                         ${GLM_INCLUDE_DIRECTORY}    )
target_link_libraries(${CMAKE_PROJECT_NAME} ${GLM_LIRBARY} ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${GLEW_LIBRARIES} ${OPENGL_LIBRARY})

