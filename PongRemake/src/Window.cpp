#include "Window.h"
#include "Log.h"
#include <iostream>


Window::Window(const char* title, Vector2 size, Uint32 FLAGS)
{
	this->size = size;

	SDL_Init(SDL_INIT_EVERYTHING);
	ASSERT(SDL_Init(SDL_INIT_EVERYTHING) == 0, "Initializing SDL...");

	p_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->size.x, this->size.y, FLAGS);
	ASSERT(p_window, "Creating Window...");

	p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_PRESENTVSYNC);
	ASSERT(p_renderer, "Creating Renderer...");
	
	m_running = true;
	LOG("Mainloop Initialized...");
}

Window::~Window()
{
	LOG("Cleaning SDL...");
	SDL_DestroyWindow(p_window);
	SDL_DestroyRenderer(p_renderer);
	SDL_Quit();
	LOG("Destroyed Window! \nDestroyed Renderer! \nExitting Application...");
}

void Window::PollEvent(SDL_Event* event)
{
	SDL_PollEvent(event);
	if (event->type == SDL_QUIT) {
		LOG("Initializing CLOSE_APPLICATION...");
		m_running = false;
	}
}

void Window::Clear()
{
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 255);
	SDL_RenderClear(p_renderer);
}

void Window::Draw(const SDL_Rect* c_rect)
{
	SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(p_renderer, c_rect);
}

void Window::Present()
{
	SDL_RenderPresent(p_renderer);
}

bool Window::Running()
{
	return m_running;
}

Vector2 Window::GetScreenSize()
{
	return size;
}
