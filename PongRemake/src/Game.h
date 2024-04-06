#pragma once
#include <SDL2/SDL.h>
#include "Vector2.h"
#include "Window.h"
#include "Player.h"
#include "Ball.h"
#include <SDL2/SDL.h>
class Game
{
public:
	Game(const char* title, Vector2 screenSize, Uint32 FLAGS);
	~Game();

	void Run();
private:
	Window* p_window;
	SDL_Event event{};
	const Uint8* keystate;
	Vector2 screenSize;
};

