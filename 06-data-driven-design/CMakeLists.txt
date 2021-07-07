add_executable(06-data-driven-design main.cpp Game.h Game.cpp TextureManager.cpp TextureManager.h GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h LoaderParams.h SDLGameObject.cpp SDLGameObject.h Vector2D.h InputHandler.cpp InputHandler.h GameState.h MenuState.h PlayState.cpp PlayState.h GameStateMachine.cpp GameStateMachine.h MenuButton.cpp MenuButton.h PauseState.cpp PauseState.h GameOverState.cpp GameOverState.h AnimatedGraphic.cpp AnimatedGraphic.h GameObjectFactory.cpp GameObjectFactory.h StateParser.cpp StateParser.h MainMenuState.cpp MainMenuState.h ${TINYXML_SRCS})

install(TARGETS 06-data-driven-design DESTINATION bin/)

target_link_libraries(06-data-driven-design ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} )

file(COPY assets DESTINATION .)