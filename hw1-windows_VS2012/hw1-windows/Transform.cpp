// Transform.cpp: implementation of the Transform class.

#include <stdio.h>
#include "Transform.h"

//Please implement the following functions:

// Helper rotation function.  
mat3 Transform::rotate(const float degrees, const vec3& axis)
{
  // YOUR CODE FOR HW1 HERE
	float rad = (degrees * (pi / 180.0));
	mat3 identity = mat3(1, 0, 0, 0, 1, 0, 0, 0, 1);  

	//we need to obtain matrix A 
	mat3 A = mat3(0,axis.z, -axis.y , -axis.z , 0 , axis.x , axis.y , -axis.x , 0);
	mat3  a = mat3((axis.x * axis.x), (axis.x * axis.y), (axis.x * axis.z), (axis.x * axis.y), (axis.y * axis.y), (axis.y * axis.z), (axis.x * axis.z), (axis.y * axis.z), (axis.z * axis.z));
	//rodriguez formula is I3x3* cos(theta) + aaT(1 - cos (theta)) + A* sin(theta)
	mat3 result = (identity * cos(rad)) + (a * (1 - cos(rad)))  + (A * (sin(rad)));
  // You will change this return call
  return result;
}

// Transforms the camera left around the "crystal ball" interface
void Transform::left(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE
	printf("Eye's Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	printf("UP's Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));
	eye = eye * rotate(degrees, -up);

	//mat3 rotMatrixY = mat3(cos(rad), 0, sin(rad), 0, 1, 0, -sin(rad), 0, cos(rad));
	//rotMatrixY = glm::transpose(rotMatrixY);
	//eye = eye * rotMatrixY;

}

// Transforms the camera up around the "crystal ball" interface
void Transform::up(float degrees, vec3& eye, vec3& up) {
  // YOUR CODE FOR HW1 HERE 
	printf("Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", eye.x, eye.y, eye.z, sqrt(pow(eye.x, 2) + pow(eye.y, 2) + pow(eye.z, 2)));
	printf("UP's Coordinates: %.2f, %.2f, %.2f; distance: %.2f\n", up.x, up.y, up.z, sqrt(pow(up.x, 2) + pow(up.y, 2) + pow(up.z, 2)));

	vec3 helper = glm::normalize(glm::cross(up, eye));
	eye = eye * rotate(degrees, helper);
	up = up * rotate(degrees, helper);


}

// Your implementation of the glm::lookAt matrix
mat4 Transform::lookAt(vec3 eye, vec3 up) {
  // YOUR CODE FOR HW1 HERE
  //First we need to create a coordintae frame 
	vec3 center = vec3(0, 0, 0);
	vec3 b = up;
	vec3 a = eye - center;
	vec3 w = glm::normalize(a);
	vec3 bXwCross = glm::cross(b, w);
	vec3 u = glm::normalize(bXwCross);
	vec3 v = glm::cross(w, u);


	//Second Define a rotation matrix 
	mat4 R = mat4(u.x, v.x, w.x, 0 , u.y, v.y, w.y,0, u.z, v.z, w.z,0 , -glm::dot(u,eye) , -glm::dot(v, eye), -glm::dot(w, eye),1);

	//apply appropiate translation for camera (eye) location
	
  // You will change this return call
  return R;
}
mat4 Transform::perspective(float fovy, float aspect, float zNear, float zFar)
{
	mat4 ret;
	// YOUR CODE FOR HW2 HERE
	// New, to implement the perspective transform as well.  
	return ret;
}

mat4 Transform::scale(const float &sx, const float &sy, const float &sz)
{
	mat4 ret = mat4(sx ,0,0,0,0,sy,0,0,0,0,sz,0,0,0,0,1);
	// YOUR CODE FOR HW2 HERE
	// Implement scaling 
	return ret;
}

mat4 Transform::translate(const float &tx, const float &ty, const float &tz)
{
	mat4 ret = mat4(tx, 0, 0, 0, 0, ty, 0, 0, 0, 0, tz, 0, 0, 0, 0, 1);
	// YOUR CODE FOR HW2 HERE
	// Implement translation 
	return ret;
}
Transform::Transform()
{

}

Transform::~Transform()
{

}
