#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Game.h"

const int screenW = 1280;
const int screenH = 720;

#pragma region Other Functions

void frame_buffer_size_callback(GLFWwindow* _window, int width, int height);

#pragma endregion





int main() {

	

#pragma region Window

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(screenW, screenH, "RGB", NULL, NULL);
	if (window == NULL) {

		std::cout << "Window Failed to Open" << std::endl;
		glfwTerminate();
		return -1;

	}
	glfwMakeContextCurrent(window);

	// Load Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// resize window
	glViewport(0, 0, screenW, screenH);
    glfwSetFramebufferSizeCallback(window, frame_buffer_size_callback);



#pragma endregion

	Game game("RGB Made with OpenGL");

#pragma region Loop

	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.4f, 0.6f, 0.1f, 1.0f);

		game.Run();

		glfwSwapBuffers(window);
		glfwPollEvents();

	}

#pragma endregion

#pragma region CleanUp
	game.CleanUp();
	glfwTerminate();
	return 0;
#pragma endregion

}


#pragma region Other Functions

void frame_buffer_size_callback(GLFWwindow* _window, int width, int height) {

	glViewport(0, 0, width, height);
}

#pragma endregion

