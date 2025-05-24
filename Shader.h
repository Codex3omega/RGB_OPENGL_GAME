#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader
{
public:
	unsigned int id;
	//Shader(const char* vertex_path, const char* frag_path);

	void init(const char* vertex_path, const char* frag_path);

	void use();

	void setBool(const std::string& name, bool value) const;
	void setFloat(const std::string& name, float value) const;
	void setInt(const std::string& name, int value) const;

	void setFloatVec4(const std::string& name, float x, float y, float z, float w);
	void setFloatVec3(const std::string& name, float x, float y, float z);
	void setMat4(const std::string& name, glm::mat4);

	void delete_shader();
};

