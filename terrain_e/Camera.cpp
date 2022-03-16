//#include"Camera.h"
//#include "LoadShaders.h"
//
//
//Camera::Camera(int width, int height, glm::vec3 position)
//{
//	Camera::width = width;
//	Camera::height = height;
//	Position = position;
//}
//
//void Camera::updateMatrix(float nearPlane, float farPlane)
//{
//	// Initializes matrices since otherwise they will be the null matrix
//	//glm::mat4 view = glm::mat4(1.0f);
//	//glm::mat4 projection = glm::mat4(1.0f);
//
//	//double xpos, ypos;
//	double viewx = 400;
//	double viewy = 0;
//	double viewz = 0;
//	//float nearz = 1.0f;
//	//float farz = 20000.0f;
//	//bool closeloop = 0;
//
//	//glm::vec3 center = glm::vec3(0, 0, 400);
//
//	//View = glm::mat4(glm::lookAt(center + glm::vec3(viewx, viewy, viewz), center, glm::vec3(0.0f, 0.0f, 1.0f)));
//
//
//	// Makes camera look in the right direction from the right position
//	view = glm::lookAt(center + glm::vec3(viewx, viewy, viewz), Position, Up);
//
//	// Adds perspective to the scene
//	projection = glm::perspective(glm::radians(100.0f), (float)width / height, nearPlane, farPlane);
//
//	// Sets new camera matrix
//	//cameraMatrix = projection * view;
//	cameraMatrix = model * projection * view;
//}
//
//void Camera::Matrix(const string vs_name, const string fs_name, const char* uniform)
//{
//	// Exports camera matrix
//	ShaderInfo shader_info[] =
//	{
//		{ GL_VERTEX_SHADER, vs_name.c_str() },
//	{ GL_FRAGMENT_SHADER, fs_name.c_str() },
//	{ GL_NONE, NULL }
//	};
//	Prog = LoadShaders(shader_info);
//
//	//glUniformMatrix4fv(glGetUniformLocation(Prog, "model_matrix"), 1, GL_FALSE, glm::value_ptr(model));
//	//glUniformMatrix4fv(glGetUniformLocation(Prog, "view_matrix"), 1, GL_FALSE, glm::value_ptr(view));
//	//glUniformMatrix4fv(glGetUniformLocation(Prog, "projection_matrix"), 1, GL_FALSE, glm::value_ptr(projection));
//	
//	glUniformMatrix4fv(glGetUniformLocation(Prog, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
//}
//
//float Camera::checkSpeed(float speed) 
//{
//	if (speed < 0.0f) {
//		speed = 0.0;
//	}
//	else if (speed > MAX_SPEED) {
//		speed = MAX_SPEED;
//	}
//	return speed;
//}
//
//void Camera::Inputs(GLFWwindow* window)
//{
//	//float currentFrame = glfwGetTime();
//	//deltaTime = currentFrame - lastFrame;
//	//lastFrame = currentFrame;
//
//	//speed = 2.5 * deltaTime;
//
//	// Handles key inputs
//	if (glfwGetKey(window, GLFW_KEY_W))
//	{
//		if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		{
//			cout << "w" << glGetString(GL_VERSION) << endl;
//			speed += acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center - glm::vec3(15.0f, 0.0f, 0.0f));
//		}
//		else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_RELEASE)
//		{
//			cout << "rw" << glGetString(GL_VERSION) << endl;
//			speed -= acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center - glm::vec3(15.0f, 0.0f, 0.0f));
//		}
//
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_A))
//	{
//		if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		{
//			cout << "A" << glGetString(GL_VERSION) << endl;
//			speed += acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center - glm::vec3(0.0f, 15.0f, 0.0f));
//		}
//		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_RELEASE)
//		{
//			cout << "rA" << glGetString(GL_VERSION) << endl;
//			speed -= acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center - glm::vec3(0.0f, 15.0f, 0.0f));
//		}
//	}
//
//
//	if (glfwGetKey(window, GLFW_KEY_S))
//	{
//		if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		{
//			cout << "s" << glGetString(GL_VERSION) << endl;
//			speed += acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center + glm::vec3(15.0f, 0.0f, 0.0f));
//		}
//		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_RELEASE)
//		{
//			cout << "rs" << glGetString(GL_VERSION) << endl;
//			speed -= acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center + glm::vec3(15.0f, 0.0f, 0.0f));
//		}
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_D))
//	{
//		if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		{
//			cout << "d" << glGetString(GL_VERSION) << endl;
//			speed += acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center + glm::vec3(0.0f, 15.0f, 0.0f));
//		}
//		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_RELEASE)
//		{
//			cout << "rd" << glGetString(GL_VERSION) << endl;
//
//			speed -= acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center + glm::vec3(0.0f, 15.0f, 0.0f));
//		}
//
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_UP))
//	{
//		if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//		{
//			cout << "u" << glGetString(GL_VERSION) << endl;
//
//			speed += acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center + glm::vec3(0.0f, 0.0f, 15.0f));
//		}
//		else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_RELEASE)
//		{
//			cout << "ru" << glGetString(GL_VERSION) << endl;
//
//			speed -= acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center + glm::vec3(0.0f, 0.0f, 15.0f));
//		}
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//	{
//		if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//		{
//			speed += acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center - glm::vec3(0.0f, 0.0f, 15.0f));
//		}
//		else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_RELEASE)
//		{
//			speed -= acceleration;
//			speed = checkSpeed(speed);
//			Position += speed * (center - glm::vec3(0.0f, 0.0f, 15.0f));
//		}
//
//	}
//}