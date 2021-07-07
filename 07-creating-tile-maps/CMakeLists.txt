add_executable(07-creating-tile-maps ${TINYXML_SRCS} ${BASE64_SRCS} main.cpp Game.h Game.cpp TextureManager.cpp TextureManager.h GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h LoaderParams.h SDLGameObject.cpp SDLGameObject.h Vector2D.h InputHandler.cpp InputHandler.h GameState.h MenuState.h PlayState.cpp PlayState.h GameStateMachine.cpp GameStateMachine.h MenuButton.cpp MenuButton.h PauseState.cpp PauseState.h GameOverState.cpp GameOverState.h AnimatedGraphic.cpp AnimatedGraphic.h GameObjectFactory.cpp GameObjectFactory.h StateParser.cpp StateParser.h MainMenuState.cpp MainMenuState.h Level.cpp Level.h Layer.h TileLayer.cpp TileLayer.h LevelParser.cpp LevelParser.h ObjectLayer.cpp ObjectLayer.h)

install(TARGETS 07-creating-tile-maps DESTINATION bin/)

target_link_libraries(07-creating-tile-maps ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${ZLIB_LIBRARIES})

file(COPY assets DESTINATION .)