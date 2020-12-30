#pragma once
#include "Point.h"


class InputListener
{
public:
	InputListener()
	{

	}
	~InputListener()
	{

	}

	// KEYS (virtual callback functions)
	virtual void onKeyDown(int key) = 0;
	virtual void onKeyUp(int key) = 0;

	// MOUSE
	virtual void onMouseMove(const Point &delta_mouse_pos) = 0;
};