#pragma once
#include <GL\freeglut.h>

class Floor
{
public:
	Floor();
	void draw();
	~Floor() = default;
private:
	int  x1, x2, y1, y2;
	GLfloat color[4];
};