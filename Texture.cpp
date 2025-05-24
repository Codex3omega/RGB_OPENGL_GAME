#include "Texture.h"


bool Texture::create(float normal_w, float normal_h, const char* _path, unsigned int _id, Shader& shader) {

	float _vertices [20] = {
		
		-normal_w, normal_h, 0.0f, 0.0f, 1.0f, // Top left vertex
		normal_w, normal_h, 0.0f, 1.0f, 1.0f, // Top Right vertex
		normal_w, -normal_h, 0.0f, 1.0f, 0.0f, // Bottom right vertex
		-normal_w, -normal_h, 0.0f, 0.0f, 0.0f // Bottom left vertex

	
	};

	float _indices[6] = {
	
		0, 1, 2,
		2, 3, 1
	
	};

	id = _id;

	// store 
	std::copy(_vertices, _vertices + 20, vertices);
	std::copy(_indices, _indices + 6, indices);

	stbi_set_flip_vertically_on_load(true);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_DYNAMIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(_path, &width, &height, &nrChannels, 0);

	if (data != NULL) {

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {

		std::cout << "Failed to Load Texture" << std::endl;

	}
	stbi_image_free(data);

	// shader
	shader.use();
	shader.setInt("texture_", id);
	glBindTexture(GL_TEXTURE_2D, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}

void Texture::draw(Shader &shader) {

	switch (id) {

	case 0 :
		glActiveTexture(GL_TEXTURE0);
		break;

	case 1:
		glActiveTexture(GL_TEXTURE1);
		break;

	case 2:
		glActiveTexture(GL_TEXTURE2);
		break;

	case 3:
		glActiveTexture(GL_TEXTURE3);
		break;

	case 4:
		glActiveTexture(GL_TEXTURE4);
		break;

	case 5:
		glActiveTexture(GL_TEXTURE5);
		break;
	}

	glBindTexture(GL_TEXTURE_2D, texture);

	shader.use();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, &indices);
	glBindVertexArray(0);
	
}

void Texture::UnloadTexture() {

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ebo);

}