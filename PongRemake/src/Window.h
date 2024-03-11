#pragma once
#include <SDL2/SDL.h>
#include "Vector2.h"

class Window
{
public:
	Window(const char* title, Vector2 size, Uint32 FLAGS);
	~Window();

	void PollEvent(SDL_Event* event);
	void Clear();
	void Draw(const SDL_Rect* c_rect);
	void Present();

	bool Running();

	Vector2 GetScreenSize();
private:
	SDL_Window* p_window;
	SDL_Renderer* p_renderer;

	Vector2 size;

	bool m_running;
};

