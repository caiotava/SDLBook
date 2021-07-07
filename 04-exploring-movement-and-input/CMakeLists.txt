add_executable(04-exploring-movement-and-input main.cpp Game.h Game.cpp TextureManager.cpp TextureManager.h GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h LoaderParams.h SDLGameObject.cpp SDLGameObject.h Vector2D.h InputHandler.cpp InputHandler.h)

install(TARGETS 04-exploring-movement-and-input DESTINATION bin/)

target_link_libraries(04-exploring-movement-and-input ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

file(COPY assets DESTINATION .)