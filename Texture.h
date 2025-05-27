#pragma once
#include <glad/glad.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <algorithm>
#include <iostream>
#include "Shader.h"

class Texture
{

public:

	const char* path;
	unsigned int id;
	unsigned int texture;

	Shader* shader;

	std::string shader_texture_name;
	
	bool init(float normalized_width, float normalized_height, const char* _path, unsigned int _id);
	void activate_texture();
	void UnloadTexture();



};

