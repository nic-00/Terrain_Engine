#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <cmath>

#include "mountain.h"
#include "skybox.h"
#include "water.h"

using namespace std;

const unsigned int Width = 1000;
const unsigned int Height = 1000;

double xpos, ypos;
double viewx = 400;
double viewy = 0;
double viewz = 0;
float nearz = 1.0f;
float farz = 20000.0f;
float speed = 0.0f;
float MAX_SPEED = 3.0f;
float acceleration = 0.05f;
float deceleration = 0.05f;
bool closeloop = 0;
bool release = 0;

glm::mat4 Model = glm::mat4(1.0);
glm::mat4 View = glm::mat4(1.0);
glm::mat4 Projection = glm::mat4(1.0);
glm::vec3 center = glm::vec3(0, 0, 400);
glm::vec3 Position;

float checkSpeed(float speed) 
{
	if (speed <= 0.0f) {
		speed = 0.0f;
	}
	else if (speed > MAX_SPEED) {
		speed = MAX_SPEED;
	}
	return speed;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(key == GLFW_KEY_W)
	{

		switch (action) 
		{
			case GLFW_REPEAT:
				speed += acceleration;
				speed = checkSpeed(speed);
				center.x -= 10.f * speed;
				break;
			
			case GLFW_RELEASE:

				speed -= deceleration;
				speed = checkSpeed(speed);
				center.x -= 3.f * speed;
				speed = 0.0f;
				break;
		}

	}

	if (key == GLFW_KEY_A)
	{
		switch (action) {

			case GLFW_REPEAT:
				speed += acceleration;
				speed = checkSpeed(speed);
				center.y -= speed * 10.f;
				break;

			case GLFW_RELEASE:
				speed -= deceleration;
				speed = checkSpeed(speed);
				center.y -= speed * 3.0f;
				speed = 0.0f;
				break;
			
		}
			
	}

	if(key == GLFW_KEY_S)
	{
		switch (action) {
		case GLFW_REPEAT:
			speed += acceleration;
			speed = checkSpeed(speed);
			center.x += speed * 10.f;
			break;

		case GLFW_RELEASE:
			speed -= deceleration;
			speed = checkSpeed(speed);
			center.x += speed * 3.f;
			speed = 0.0f;
			break;
		}
	}

	if(key == GLFW_KEY_D)
	{
		switch (action) {
		case GLFW_REPEAT:
			speed += acceleration;
			speed = checkSpeed(speed);
			center.y += speed * 10.f;
			break;
		case GLFW_RELEASE:
			speed -= deceleration;
			speed = checkSpeed(speed);
			center.y += speed * 3.f;
			speed = 0.0f;
			break;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_UP))
	{
		switch (action) {
		case GLFW_REPEAT:
			speed += acceleration;
			speed = checkSpeed(speed);
			center.z += speed * 10.f;
			break;

		case GLFW_RELEASE:
			speed -= deceleration;
			speed = checkSpeed(speed);
			center.z += speed * 3.f;
			speed = 0.0f;
			break;
		}
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		switch (action) {
		case GLFW_REPEAT:
			speed += acceleration;
			speed = checkSpeed(speed);
			center.z -= speed * 10.f;
			break;
		case GLFW_RELEASE:
			speed -= deceleration;
			speed = checkSpeed(speed);
			center.z -= speed * 3.f;
			speed = 0.0f;
			break;
		}

	}
}

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	GLFWwindow* window = glfwCreateWindow(Width, Height, "Terrain_Engine", NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	gladLoadGL();
	glfwSetKeyCallback(window, key_callback);
	glViewport(0, 0, Width, Height);


	mountain mount;
	mount.Init("mountain.vert", "mountain.frag", "heightmap.bmp", "terrain-texture3.bmp", "detail.png");
	Skybox box1;
	box1.Init("skybox.vert", "skybox.frag", 1, "SkyBox3.bmp");
	Skybox box2;
	box2.Init("skybox.vert", "skybox.frag", 2, "SkyBox0.bmp");
	Skybox box3;
	box3.Init("skybox.vert", "skybox.frag", 3, "SkyBox1.bmp");
	Skybox box4;
	box4.Init("skybox.vert", "skybox.frag", 4, "SkyBox2.bmp");
	Skybox box5;
	box5.Init("skybox.vert", "skybox.frag", 5, "SkyBox4.bmp");
	Water sea;
	sea.Init("water.vert", "water.frag", "SkyBox5.bmp");
	sea.Wave_Init("wave.vert", "wave.frag", "SkyBox5.bmp");


	while (!glfwWindowShouldClose(window))
	{
		
		static const float black[] = { 0.0f, 0.0f, 0.0f, 0.0f };

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_MULTISAMPLE);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearBufferfv(GL_COLOR, 0, black);


		float aspect = (float)Height / (float)Width;
		View = glm::mat4(glm::lookAt(center + glm::vec3(viewx, viewy, viewz), center, glm::vec3(0.0f, 0.0f, 1.0f)));
		Projection = glm::mat4(glm::perspective(glm::radians(100.0f), 1.0f / aspect, nearz, farz));

		mount.Display(window, Model, View, Projection);
		box1.Display(window, Model, View, Projection);
		box2.Display(window, Model, View, Projection);
		box3.Display(window, Model, View, Projection);
		box4.Display(window, Model, View, Projection);
		box5.Display(window, Model, View, Projection);
		sea.Display(window, Model, View, Projection);
		sea.WaveDisplay(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}