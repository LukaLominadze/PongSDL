#include "Game.h"
#include "Log.h"

Game* game = nullptr;

int main(int argc, char* argv[]) {
	game = new Game("Pong", Vector2(600, 600), SDL_WINDOW_SHOWN);
	ASSERT(game, "Initializing Game...");

	game->Run();

	delete game;
	return 0;
}