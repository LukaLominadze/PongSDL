#include "Game.h"

Game::Game(const char* title, Vector2 screenSize, Uint32 FLAGS)
{
	p_window = new Window(title, screenSize, FLAGS);

	keystate = SDL_GetKeyboardState(NULL);
}

Game::~Game()
{
	delete p_window;
}

void Game::Run()
{
	Player player1 = Player(Vector2(50, 240), Vector2(16, 120));
	Player player2 = Player(Vector2(534, 240), Vector2(16, 120));
	Ball ball = Ball(Vector2(285, 285), Vector2(10, 10), Vector2(4, 4), Vector2(600, 600));

	ball.LaunchBall();

	while (p_window->Running()) {
		p_window->PollEvent(&event);

		player1.Movement(keystate, SDL_SCANCODE_W, SDL_SCANCODE_S, 10);
		player2.Movement(keystate, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, 10);
		player1.ClampPosition(600, 600);
		player2.ClampPosition(600, 600);

		ball.MoveBall();
		ball.Collision(&player1, &player2);
		
		p_window->Clear();
		p_window->Draw(&player1);
		p_window->Draw(&player2);
		p_window->Draw(&ball);
		p_window->Present();
	}
}
