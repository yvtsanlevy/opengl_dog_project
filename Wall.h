#pragma once
#include <GL\freeglut.h>

class Wall
{
public:
	Wall();
	void draw();
	~Wall() = default;
private:
	int  x1, x2;
	GLfloat color[4];
};