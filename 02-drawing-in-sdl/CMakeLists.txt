add_executable(02-drawing-in-sdl main.cpp Game.h Game.cpp TextureManager.cpp TextureManager.h)

install(TARGETS 02-drawing-in-sdl DESTINATION bin/)

target_link_libraries(02-drawing-in-sdl ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

file(COPY assets DESTINATION .)