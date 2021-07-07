project(SDLBook_cmake)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)

find_package(ZLIB REQUIRED)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR}, ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_MIXER_INCLUDE_DIR} ${ZLIB_INCLUDE_DIRS})
include_directories(vendor/)
file(GLOB_RECURSE TINYXML_SRCS ${PROJECT_SOURCE_DIR}/vendor/tinyxml/*.cpp)
file(GLOB_RECURSE BASE64_SRCS ${PROJECT_SOURCE_DIR}/vendor/base64/*.cpp)

add_executable(sdlbook_cmake main.c)

# Include chapters.
add_subdirectory ("01-getting-started")
add_subdirectory ("02-drawing-in-sdl")
add_subdirectory ("03-working-with-game-objects")
add_subdirectory ("04-exploring-movement-and-input")
add_subdirectory ("05-finite-state-machines")
add_subdirectory ("06-data-driven-design")
add_subdirectory ("07-creating-tile-maps")

install(TARGETS sdlbook_cmake DESTINATION bin)
target_link_libraries(sdlbook_cmake ${SDL2_LIBRARIES})
