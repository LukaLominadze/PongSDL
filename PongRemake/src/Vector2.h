#pragma once

class Vector2 {
public:
	inline Vector2() {
		x = 0;
		y = 0;
	}

	inline Vector2(int x, int y) {
		this->x = x;
		this->y = y;
	}
	int x, y;
};
