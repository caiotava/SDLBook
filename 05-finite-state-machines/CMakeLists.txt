add_executable(05-finite-state-machines main.cpp Game.h Game.cpp TextureManager.cpp TextureManager.h GameObject.h Player.cpp Player.h Enemy.cpp Enemy.h LoaderParams.h SDLGameObject.cpp SDLGameObject.h Vector2D.h InputHandler.cpp InputHandler.h GameState.h MenuState.cpp MenuState.h PlayState.cpp PlayState.h GameStateMachine.cpp GameStateMachine.h MenuButton.cpp MenuButton.h PauseState.cpp PauseState.h GameOverState.cpp GameOverState.h AnimatedGraphic.cpp AnimatedGraphic.h)

install(TARGETS 05-finite-state-machines DESTINATION bin/)

target_link_libraries(05-finite-state-machines ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

file(COPY assets DESTINATION .)