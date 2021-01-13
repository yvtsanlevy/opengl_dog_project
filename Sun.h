#pragma once

#include <GL\freeglut.h>

/*
sun Light is light source with uniform light distribution.
*/
class Sun
{
public:
	GLfloat color[4];
	GLfloat position[4];

	Sun();
	void addLight();
	void draw();
	void disable();
	void enable();
	~Sun() = default;
};

