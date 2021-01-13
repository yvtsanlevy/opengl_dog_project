#pragma once
#include "floor.h"



Floor::Floor() : x1(-20), y1(-20), x2(20), y2(20),
color{ 0, 1, 0, 1.0f }
 {};

void  Floor::draw()
{


	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3d(0, 1, 0);
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f },
		shininess = 128.0f;
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	for (int x = x1; x < x2; x++) {
		for (int y = y1; y < y2; y++) {
			glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,  color);
			glVertex3d(x, 0, y);
			glVertex3d(x + 1, 0, y);
			glVertex3d(x + 1, 0, y + 1);
			glVertex3d(x, 0, y + 1);
		}
	}

	glEnd();
	glPopMatrix();
}