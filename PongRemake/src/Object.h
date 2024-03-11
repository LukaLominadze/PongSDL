#pragma once
#include <SDL2/SDL.h>
#include "Vector2.h"

class Object : public SDL_Rect
{
public:
	Object(Vector2 position, Vector2 size);
	~Object();

	void Move(Vector2 delta);
	void ClampPosition(int maxX, int maxY);

	Vector2 GetAbsolutePosition();
private:
};

