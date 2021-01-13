#pragma once
#include "Header.h"



Wall::Wall() : x1(-20), x2(20),
color{ 0, 1, 0, 1.0f }
{};

void  Wall::draw()
{


	GLfloat specular[] = { 0.1f, 0.1f, 0.1f },
		shininess = 0.3f;
	GLfloat color[4] = { 0.651f, 0.502f, 0.392f, 1.0f };
	glColor4fv(color);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

	for (int i = 0; i < 4; i++) {
		glPushMatrix();
				switch (i) {
				case 0:
					glTranslatef(0, 0, -20.0f);
					glScalef(40, 7, 1);
					glutSolidCube(1);
					glPopMatrix();
					break;
				case 1:
					glTranslatef(20.0f, 0, 0);
					glScalef(1, 7, 40);
					glutSolidCube(1);
					glPopMatrix();
					break;
				case 2:
					glTranslatef(-20.0f, 0, 0);
					glScalef(1, 7, 40);
					glutSolidCube(1);
					glPopMatrix();
					break;
				case 3:
					glTranslatef(0, 0, 20.0f);
					glScalef(40, 7, 1);
					glutSolidCube(1);
					glPopMatrix();
					break;
				}
				
	}
}