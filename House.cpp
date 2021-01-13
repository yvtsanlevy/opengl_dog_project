#include "House.h"
#include <GL\freeglut.h>


void House::piramid() {
	glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
	  // Front
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Right
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(1.0f, -1.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Back
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(1.0f, -1.0f, -1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// Left
	glColor3f(1.0f, 0.0f, 0.0f);       // Red
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glEnd();   // Done drawing the pyramid
}
void House::draw()
{
	glPushMatrix();
	

	GLfloat specular[] = { 0.1f, 0.1f, 0.1f },
		shininess = 0.3f;
	GLfloat color[4] = { 0.651f, 0.502f, 0.392f, 1.0f };
	glColor4fv(color);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);

	//scale to model with higher values
	glScalef(0.3f, 0.3f, 0.3f);

	//Walls
	glPushMatrix();
	glScalef(20, 20, 20);
	glutSolidCube(1);
	glPopMatrix();

	//roof

	GLfloat roof_specular[] = { 0.1f, 0.1f, 0.1f },
		roof_shininess = 0.3f;
	GLfloat color_roof[4] = { 1,0, 0, 1.0f };
	glColor4fv(color_roof);

	glMaterialfv(GL_FRONT, GL_SPECULAR, roof_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, roof_shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_roof);

	glPushMatrix();
	glTranslated(0, 15, 0);
	glScalef(10, 5, 10);
	piramid();
	glPopMatrix();

	//door

	GLfloat door_specular[] = { 0.1f, 0.1f, 0.1f },
		door_shininess = 0.3f;
	GLfloat color_door[4] = { 0,0, 1, 1.0f };
	glColor4fv(color_door);

	glMaterialfv(GL_FRONT, GL_SPECULAR, door_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, door_shininess);
	glMaterialf(GL_FRONT, GL_EMISSION, 0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color_door);

	glPushMatrix();
	//glRotatef(180, 0, 0, 1);
	glTranslated(-10, 0, 0);
	glScalef(0.5, 12, 6);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}