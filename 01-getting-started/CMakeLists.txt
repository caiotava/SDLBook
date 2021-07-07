add_executable(01.1-hello-sdl 01-hello-sdl.cpp Game.h)
add_executable(01.2-breaking-up-hello-sdl 02-breaking-up-hello-sdl.cpp)
add_executable(01.3-the-game-class 03-the-game-class.cpp Game.cpp)

install(TARGETS 01.1-hello-sdl 01.2-breaking-up-hello-sdl 01.3-the-game-class DESTINATION bin)

target_link_libraries(01.1-hello-sdl ${SDL2_LIBRARIES})
target_link_libraries(01.2-breaking-up-hello-sdl ${SDL2_LIBRARIES})
target_link_libraries(01.3-the-game-class ${SDL2_LIBRARIES})
