#pragma once

inline int Clamp(int value, int min, int max) {
	if (value > max) {
		return max;
	}
	else if (value < min) {
		return min;
	}
	else {
		return value;
	}
}
