#pragma once
#pragma once
#include <GL\freeglut.h>
#include <functional>


class Dog
{
public:
	Dog();
	GLfloat local[16];	//local coordinate system transformation matrix
	GLfloat headXAngle;
	GLfloat headYAngle;
	GLfloat tailXAngle;
	GLfloat tailYAngle;
	std::function<void()> nextMove;
	bool isMoving;

	void init();
	void draw();
	~Dog() = default;

};

