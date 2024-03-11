#include "Object.h"
#include "Math.h"
#include "Log.h"

Object::Object(Vector2 position, Vector2 size)
{
	x = position.x;
	y = position.y;
	w = size.x;
	h = size.y;

	LOG("Object Created!");
}

Object::~Object()
{
}

void Object::Move(Vector2 delta)
{
	x += delta.x;
	y += delta.y;
}

void Object::ClampPosition(int maxX, int maxY)
{
	x = Clamp(x, 0, maxX - w);
	y = Clamp(y, 0, maxY - h);
}

Vector2 Object::GetAbsolutePosition()
{
	return Vector2(x + w / 2, y + h / 2);
}
