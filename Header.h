#pragma once

#include "floor.h"
#include "chair.h"
#include "Camera.h"
#include "House.h"
#include "Sun.h"
#include "Dog.h"
#include "Lamppost.h"
#include "Wall.h"

class Context {
public:
	GLfloat globalAmbient = 0.3f;
	int isDogView = 0;
	Floor floor;
	Chair chair;
	Camera camera;
	House house;
	Sun sun;
	Dog dog;
	Lamppost lamppost;
	Wall wall;

	
}; 
