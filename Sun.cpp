#include "Sun.h"

Sun::Sun() : color{ 0.255f, 0.255f, 0 , 1.0f },
position{ 0, 7, 0.0f , 1.0f } {}

void Sun::addLight() {
	if (!glIsEnabled(GL_LIGHT0))
		return;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
	glLightfv(GL_LIGHT0, GL_SPECULAR, color);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0f);
}

void Sun::draw()
{
	if (!glIsEnabled(GL_LIGHT0))
		return;
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glColor4fv(color);
	glutSolidSphere(0.5, 100, 100);
	glEnable(GL_LIGHTING);
	glPopMatrix();
}

void Sun::disable()
{
	glDisable(GL_LIGHT0);
}

void Sun::enable()
{
	glEnable(GL_LIGHT0);
}