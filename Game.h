#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <fstream>
#include "Shader.h"
#include "Texture.h"
#include "Dep/include/stb_image.h"
#include "Player.h"

class Game
{
public:

	std::string name;

	Game(std::string _name);

	Shader def_shader;

	Texture red_box;
	Texture green_box;
	Texture blue_box;

	Player player;


	void Init();
	void Update(float delta, GLFWwindow* g_window);
	void Draw();
	void Run(float delta, GLFWwindow* _window);
	void CleanUp();

};

