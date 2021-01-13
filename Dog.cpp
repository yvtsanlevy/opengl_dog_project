#include "Dog.h"
#include <GL\freeglut.h>

Dog::Dog() :
headXAngle(0.0f),
headYAngle(10.0f),
tailXAngle(0.0f),
tailYAngle(-10.0f),
nextMove(nullptr),
isMoving(false) {};

void Dog::init() {
	GLfloat viewModelMatrix[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, viewModelMatrix);
	glLoadIdentity();

	glRotatef(-90.0f, 0.0f, 1.0f, 0.0f);
	glTranslatef(-0.5, 1.05f, -2.8f);

	glGetFloatv(GL_MODELVIEW_MATRIX, local);
	glLoadMatrixf(viewModelMatrix);
}

void Dog::draw() {

	glPushMatrix();
	GLfloat color[4] = { 0.6f, 0.5f, 0.05f, 1.0f };
	glColor4fv(color);

	GLfloat dog_specular[] = { 0.1f, 0.1f, 0.1f },
		dog_shininess = 0.1f;

	glMaterialfv(GL_FRONT, GL_SPECULAR, dog_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, dog_shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

	//torso
	glPushMatrix();
	glScalef(0.7f ,0.7, 0.7f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//legs
	glPushMatrix();
	glRotatef(0, 1, 0, 0);
	glTranslated(-0.3, -0.75, -0.6);
	glScalef(0.15f, 0.6f, 0.15f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(0, 1, 0, 0);
	glTranslated(0.3f, -0.75, -0.6);
	glScalef(0.15f, 0.6f, 0.15f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(0, 1, 0, 0);
	glTranslated(0.3f, -0.75, 0.6);
	glScalef(0.15 ,0.6, 0.15);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(0, 1, 0, 0);
	glTranslated(-0.3f, -0.75, 0.6);
	glScalef(0.15 , 0.6, 0.15 );
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//tail
	glPushMatrix();
	glTranslated(0.0f, 0.0f, -0.99);
	glRotatef(-30, 1, 0, 0);
	glRotatef(tailYAngle, 1, 0, 0);
	glRotatef(tailXAngle, 0, 1, 0);
	glScalef(0.15, 0.15 , 0.54);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//head rotation
	glPushMatrix();
	glRotatef(headYAngle, 1, 0, 0);
	glRotatef(headXAngle, 0, 1, 0);

	//head
	glPushMatrix();
	glTranslated(0.0f, 0.75 , 0.9);
	glScalef(0.24 , 0.465 , 0.48);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();


	//ears
	glPushMatrix();
	glTranslated(-0.24, 1.14, 0.78);
	glScalef(0.24, 0.3f, 0.24);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.24, 1.14, 0.78);
	glScalef(0.24,  0.3f, 0.24);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	//nose


	GLfloat nose_specular[] = { 0.1f, 0.1f, 0.1f },
		nose_shininess = 0.3f;
	GLfloat color_nose[4] = { 0.4,0.4, 0.3, 1.0f };
	glColor4fv(color_nose);

	glMaterialfv(GL_FRONT, GL_SPECULAR, nose_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, nose_shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_nose);


	glPushMatrix();
	glTranslated(0.0f, 0.66, 1.26);
	glScalef(0.2f, 0.2f, 0.2f);
	glutSolidSphere(1, 30, 30);
	glPopMatrix();

	
	//eyes
	GLfloat eyes_specular[] = { 0.4f, 0.4f, 0.4f },
		eyes_shininess = 1.0f;
	GLfloat color_eyes[] = { 0.05,0.14,0.6,1 };
	glColor4fv(color_eyes);
	glMaterialfv(GL_FRONT, GL_SPECULAR, eyes_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, eyes_shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_eyes);

	glPushMatrix();
	glTranslated(0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
	glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5f * 0.3f, 3.0f * 0.3f, 4.4f * 0.3f);
	glScalef(0.25f * 0.3f, 0.25f * 0.3f, 0.25f * 0.3f);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}
