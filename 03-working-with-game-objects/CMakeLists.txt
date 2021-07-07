add_executable(03-working-with-game-objects main.cpp Game.h Game.cpp TextureManager.cpp TextureManager.h GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h LoaderParams.h SDLGameObject.cpp SDLGameObject.h)

install(TARGETS 03-working-with-game-objects DESTINATION bin/)

target_link_libraries(03-working-with-game-objects ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

file(COPY assets DESTINATION .)