//#ifndef CAMERA_CLASS_H
//#define CAMERA_CLASS_H
//
//#include <iostream>
//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include<glm/gtx/rotate_vector.hpp>
//#include<glm/gtx/vector_angle.hpp>
//
//using namespace std;
//
//class Camera
//{
//public:
//	GLuint Prog;
//	float MAX_SPEED = 20.0f;
//	// Stores the main vectors of the camera
//	glm::vec3 center = glm::vec3(0, 0, 400);
//	glm::vec3 Position = Position + center;
//
//	//glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
//
//	//glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
//	glm::vec3 Up = glm::vec3(0.0f, 0.0f, 1.0f);
//
//	glm::mat4 model = glm::mat4(1.0);
//	glm::mat4 view = glm::mat4(1.0);
//	glm::mat4 projection = glm::mat4(1.0);
//
//	glm::mat4 cameraMatrix = glm::mat4(1.0f);
//
//	//timming
//	//store difference between the timestamp of this frame and the last frame
//	//how much time has elapsed since the last frame
//	//float deltaTime = 0.0f;
//	//timestamp of the previous frame
//	//float lastFrame = 0.0f;
//
//	// Prevents the camera from jumping around when first clicking left click
//	//bool firstClick = true;
//
//	// Stores the width and height of the window
//	int width;
//	int height;
//
//	// Adjust the speed of the camera and it's sensitivity when looking around
//	float speed = 10.0f;
//	float acceleration = 3.0f;
//	//float sensitivity = 100.0f;
//
//	// Camera constructor to set up initial values
//	Camera(int width, int height, glm::vec3 position);
//
//	// Updates and exports the camera matrix to the Vertex Shader
//	void updateMatrix(float nearPlane, float farPlane);
//	void Matrix(const string vs_name, const string fs_name, const char* uniform);
//	float checkSpeed(float speed);
//	// Handles camera inputs
//	void Inputs(GLFWwindow* window);
//};
//#endif