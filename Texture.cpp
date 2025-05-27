#include "Texture.h"


bool Texture::init(float normal_w, float normal_h, const char* _path, unsigned int _id) {

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(_path, &width, &height, &nrChannels, 0);
	GLenum format = GL_RGB;
	if (nrChannels == 4) format = GL_RGBA;
	if (data != NULL) {

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {

		std::cout << "Failed to Load Texture" << std::endl;
		return false;
	}
	stbi_image_free(data);

	glBindTexture(GL_TEXTURE_2D, 0);


	return true;
}

void Texture::UnloadTexture() {

	glDeleteTextures(1, &texture);

}

void Texture::activate_texture() {
	glActiveTexture(GL_TEXTURE0 + id);
	glBindBuffer(GL_TEXTURE_2D, texture);
}
