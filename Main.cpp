#pragma once

#include <windows.h>
#include <iostream>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_freeglut.h"
#include "imgui/imgui_impl_opengl2.h"
#include <GL\freeglut.h>
#include "Header.h"

using namespace std;

//single point of access to all rendered objects
Context gContext;



void draw() {
	
	//sun
	glPushMatrix();
	glTranslatef(gContext.sun.position[0], gContext.sun.position[1], gContext.sun.position[2]);
	gContext.sun.addLight();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(gContext.sun.position[0], gContext.sun.position[1], gContext.sun.position[2]);
	gContext.sun.draw();
	glPopMatrix();
	

	//lamppost 

	glPushMatrix();
	glTranslatef(gContext.lamppost.position[0], gContext.lamppost.position[1], gContext.lamppost.position[2]);
	gContext.lamppost.addlight();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(gContext.lamppost.position[0], gContext.lamppost.position[1], gContext.lamppost.position[2]);
	gContext.lamppost.draw();
	glPopMatrix();

	gContext.lamppost.enable();
	

	//floor

	gContext.floor.draw();

	
	//chair
	glPushMatrix();
	glTranslated(0, 1.05, -3);
	glRotatef(225, 0, 1, 0);
	gContext.chair.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(3, 1.05, 3);
	glRotatef(45, 0, 1, 0);
	gContext.chair.draw();
	glPopMatrix();
	
	//house
	glPushMatrix();
	glTranslated(-5, 0, -10);
	glRotatef(90, 0, 1, 0);
	gContext.house.draw();
	glPopMatrix();

	//dog
	glPushMatrix();
	glMultMatrixf(gContext.dog.local);
	gContext.dog.draw();
	glPopMatrix();

	gContext.wall.draw();

}

//gui interaction handling via imgui
void UserInterface()
{
	ImGuiWindowFlags window_flags = 0;
	if (ImGui::Begin("Opengl Dog Scene", (bool*)false, (ImGuiWindowFlags)window_flags))
	{

		if (ImGui::CollapsingHeader("Camera"))
		{
			ImGui::SliderFloat("camera  x position", &gContext.camera.position[0], -20.0f, 20.0f);
			ImGui::SliderFloat("camera  y position", &gContext.camera.position[1], -20.0f, 20.0f);
			ImGui::SliderFloat("camera  z position", &gContext.camera.position[2], -20.0f, 20.0f);
			ImGui::SliderFloat("camera target x", &gContext.camera.target[0], -20.0f, 20.0f);
			ImGui::SliderFloat("camera target y", &gContext.camera.target[1], -20.0f, 20.0f);
			ImGui::SliderFloat("camera target z", &gContext.camera.target[2], -20.0f, 20.0f);
		}

		if (ImGui::CollapsingHeader("Dog"))
		{
			ImGui::RadioButton("camera view", &gContext.isDogView, 0); ImGui::SameLine();
			ImGui::RadioButton("dog view", &gContext.isDogView, 1);
			ImGui::SliderFloat("head horizontal", &gContext.dog.headXAngle, -30.0f, 30.0f);
			ImGui::SliderFloat("head vertical", &gContext.dog.headYAngle, -5.0f, 50.0f);
			ImGui::SliderFloat("tail horizontal", &gContext.dog.tailXAngle, -25.0f, 25.0f);
			ImGui::SliderFloat("tail vertical", &gContext.dog.tailYAngle, -14.0f, 50.0f);
		}


		if (ImGui::CollapsingHeader("sun"))
		{
			ImGui::ColorEdit3("sun light color", reinterpret_cast<float*>(&gContext.sun.color));
			ImGui::SliderFloat("sun  x position", &gContext.sun.position[0], -20.0f, 20.0f);
			ImGui::SliderFloat("sun  y position", &gContext.sun.position[1], -20.0f, 20.0f);
			ImGui::SliderFloat("sun  z position", &gContext.sun.position[2], -20.0f, 20.0f);
			ImGui::SliderFloat("ambient light adjust", &gContext.globalAmbient, 0.0f, 1.0f);

		}
		if (ImGui::CollapsingHeader("lamppost"))
		{
			ImGui::ColorEdit3("lamppost color", reinterpret_cast<float*>(&gContext.lamppost.color));
			ImGui::SliderFloat("lamppost  x position", &gContext.lamppost.position[0], -20.0f, 20.0f);
			ImGui::SliderFloat("lamppost  y position", &gContext.lamppost.position[1], -20.0f, 20.0f);
			ImGui::SliderFloat("lamppost  z position", &gContext.lamppost.position[2], -20.0f, 20.0f);
			ImGui::SliderFloat("lamppost target x", &gContext.lamppost.target[0], -20.0f, 20.0f);
			ImGui::SliderFloat("lamppost target y", &gContext.lamppost.target[1], -20.0f, 20.0f);
			ImGui::SliderFloat("lamppost target z", &gContext.lamppost.target[2], -20.0f, 20.0f);
			ImGui::SliderFloat("lamppost cutoff", &gContext.lamppost.cutoff, 0.0f, 90.0f);
			ImGui::SliderFloat("lamppost exponent", &gContext.lamppost.exponent, 0.0f, 90.0f);

		}

		if (ImGui::CollapsingHeader("Help"))
		{
			ImGui::Text("Camera section:");
			ImGui::TextWrapped((string("The controls in the Camera section are controling the camera position  and the camera target")).c_str());
			ImGui::Text("dog position:");
			ImGui::TextWrapped((string("The keyboard arrows control the dog position .").c_str()));
			ImGui::Text("Dog head and tail orientaion:");
			ImGui::TextWrapped((string("The controls in the Dog section are controlling the head vertical and horizontal orientaion and the") +
				string(" tail vertical and horizontal orientation")).c_str());
			ImGui::Text("Lights section:");
			ImGui::TextWrapped((string("The controls in the Light section are controling the Light in the scene, 'ambient light adjust' controls the global ambient light value, ")).c_str());
		}
		if (ImGui::Button("Quit"))
		{
			exit(0);
		}
	}
	ImGui::End();
}


//keyboard events handling
void keyboard(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT:  gContext.dog.nextMove = []() { glRotatef(10, 0, 1, 0); };   break;
	case GLUT_KEY_RIGHT: gContext.dog.nextMove = []() { glRotatef(-10, 0, 1, 0); };  break;
	case GLUT_KEY_UP:	 gContext.dog.nextMove = []() { glTranslated(0, 0, 0.2); }; break;
	case GLUT_KEY_DOWN:  gContext.dog.nextMove = []() { glTranslated(0, 0, -0.2); }; break;

	}
	glutPostRedisplay();
}

//display handling, rendering all objects
void display() {
	//imgui new frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplFreeGLUT_NewFrame();

	//update interaction
	UserInterface();

	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO();

	glViewport(0, 0, (GLsizei)io.DisplaySize.x, (GLsizei)io.DisplaySize.y);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40.0, io.DisplaySize.x / io.DisplaySize.y, 1.0, 150.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//update the dog's transformation matrix
	if (gContext.dog.nextMove) {
		gContext.dog.isMoving = true;
		GLfloat viewModelMatrix[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, viewModelMatrix);
		glLoadMatrixf(gContext.dog.local);
		gContext.dog.nextMove();
		gContext.dog.nextMove = nullptr;
		glGetFloatv(GL_MODELVIEW_MATRIX, gContext.dog.local);
		glLoadMatrixf(viewModelMatrix);
	}
	//change viewing mode if in Dog view 
	if (gContext.isDogView) {
		GLfloat viewModelMatrix[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, viewModelMatrix);
		glLoadMatrixf(gContext.dog.local);

		glRotatef(gContext.dog.headYAngle, 1, 0, 0);
		glRotatef(gContext.dog.headXAngle, 0, 1, 0);
		glTranslated(0, 0.75, 0.9);

		GLfloat cameraPoseInDogView[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, cameraPoseInDogView);
		glLoadMatrixf(viewModelMatrix);

		//Hack...
		GLfloat zAngle = atan2(-cameraPoseInDogView[2], cameraPoseInDogView[0]);
		GLfloat yAngle = atan2(-cameraPoseInDogView[9], cameraPoseInDogView[5]);

		gluLookAt(cameraPoseInDogView[12], cameraPoseInDogView[13], cameraPoseInDogView[14],
			sin(zAngle) + cameraPoseInDogView[12],
			-yAngle + cameraPoseInDogView[13],
			cos(zAngle) + cameraPoseInDogView[14],
			0, 1, 0);
	}
	else
	{
		//view mode of camera view setup
		gluLookAt(gContext.camera.position[0], gContext.camera.position[1], gContext.camera.position[2],
			gContext.camera.target[0], gContext.camera.target[1], gContext.camera.target[2], 0, 1, 0);
	}
	GLfloat globalAmbientVec[4] = { gContext.globalAmbient, gContext.globalAmbient, gContext.globalAmbient, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientVec);


	

	draw();

	glDisable(GL_LIGHTING);
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	glEnable(GL_LIGHTING);

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE | GLUT_STENCIL);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("opengl dog scene");
	glutDisplayFunc(display);

	// Setup ImGui binding
	ImGui::CreateContext();

	ImGui_ImplFreeGLUT_Init();
	ImGui_ImplFreeGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();

	glutSpecialFunc(keyboard);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	gContext.sun.enable();
	gContext.dog.init();
	



	// Setup style
	ImGui::StyleColorsClassic();

	glutMainLoop();

	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplFreeGLUT_Shutdown();
	ImGui::DestroyContext();

	return 0;
}