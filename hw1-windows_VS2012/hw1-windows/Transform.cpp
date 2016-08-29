// Transform.cpp: implementation of the Transform class.

#include <stdio.h>
#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis)
{
  // YOUR CODE FOR HW1 HERE
	printf("Wolo");
  // You will change this return call
  return mat3();
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	//Get rotation matrix
	float rad = (degrees * (pi / 180.0f));
	mat3 rotMatrixX = mat3(1, 0, 0, 0, cos(rad), -sin(rad), 0, sin(rad), cos(rad));
	rotMatrixX = glm::transpose(rotMatrixX);
	eye = eye * rotMatrixX;
//	up = up * -(rotMatrixX);

	printf("Wolo");
}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
	//Get rotation matrix 
	float rad = (degrees * (pi / 180.0));
	mat3 rotMatrixY = mat3(cos(rad), 0, sin(rad), 0, 1,0, -sin(rad), 0, cos(rad));
	rotMatrixY = glm::transpose(rotMatrixY);


	printf("Wolo");

}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE

  // You will change this return call
  return mat4();
}

Transform::Transform()
{

}

Transform::~Transform()
{

}
