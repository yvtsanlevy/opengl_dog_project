#include "chair.h"
#include <GL\freeglut.h>

void Chair::draw()
{
	glPushMatrix();
	GLfloat ambient[] = { 0.19225f,	0.19225f,	0.19225f, 1.0f },
		diffuse[] = { 0.50754f,	0.50754f,	0.50754f, 1.0f },
		specular[] = { 0.508273f,	0.508273f,	0.508273f },
		shininess = 0.4f * 128.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	//scale to model with higher values
	glScalef(0.3f, 0.3f, 0.3f);

	//top
	glPushMatrix();
	glScalef(5, 0.5, 5);
	glutSolidCube(1);
	glPopMatrix();

	//Backrest
	glPushMatrix();
	glTranslated(0, 1.75, 2);
	glScalef(5, 5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	//legs
	glPushMatrix();
	glTranslated(-2.5, -1.75, -2);
	glScalef(0.5, 3.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5, -1.75, -2);
	glScalef(0.5, 3.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.5, -1.75, 2);
	glScalef(0.5, 3.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.5, -1.75, 2);
	glScalef(0.5, 3.5, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}