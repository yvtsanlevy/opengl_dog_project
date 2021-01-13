#pragma once
#include <math.h>
#include <GL/freeglut.h>


class Lamppost {
public:
	GLfloat position[4] = { -2.0f, 2.5f, 0.0f , 1.0f };
	GLfloat target[3] = { -5, 0.0f, 0.0f };
	GLfloat color[3] = { 1.0f, 1.0f, 1.0f };
	GLfloat cutoff = 30.0f;
	GLfloat exponent = 0.0f;

	Lamppost();
	void addlight();
	void draw();
	void disable();
	void enable();
	~Lamppost() = default;
private:
	void normalize(const GLfloat* vec, GLfloat* output);
	void cross(const GLfloat* vec1, const GLfloat* vec2, GLfloat* output);
	void lookAt(GLfloat* eye, GLfloat* center, GLfloat* up);
};