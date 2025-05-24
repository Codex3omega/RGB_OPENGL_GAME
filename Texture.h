#pragma once
#include <glad/glad.h>
#include <stb_image.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "Shader.h"


class Texture
{

public:



	float vertices[20];
	float indices[6];


	const char* path;

	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	unsigned int id;
	unsigned int texture;

	std::string shader_texture_name;
	

	bool create(float normalized_width, float normalized_height, const char* _path, unsigned int _id, Shader& shader);
	void draw(Shader &shader);
	void UnloadTexture();



};

