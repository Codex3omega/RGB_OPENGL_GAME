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

class Game
{
public:

	std::string name;

	Game(std::string _name);

	Shader red_box_shader;
	//Shader green_box_shader;
	//Shader blue_box_shader;

	Texture red_box;
	unsigned int red_box_texture;
	//Texture green_box;
	//Texture blue_box;

	Shader def_shader;
	
	float vertices[20];
	float indices[6];

	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	void Init();
	void Update();
	void Draw();
	void Run();
	void CleanUp();

};

