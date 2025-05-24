#include "Game.h"

Game::Game(std::string _name){

	name = _name;

	red_box_shader.init("Shaders/Default.vert", "Shaders/Red_Box.frag");
	

	float _vertices[20] = {
		
		-0.1f, 0.15f, 0.0f, 0.0f, 1.0f,  // top left
		0.1f , 0.15f, 0.0f, 1.0f, 1.0f, // top right
		0.1f, -0.15f, 0.0f, 1.0f, 0.0f, // bottom right
		-0.1f, -0.15f, 0.0f, 0.0f, 0.0f // botttom left 
	
	};
	float _indices[6] = {
		0, 1, 2,
		2, 3, 1

	};

	std::copy(_vertices, _vertices + 20, vertices);
	std::copy(_indices, _indices + 6, indices);

	std::cout << vertices[1] << std::endl;

	def_shader.init("Shaders/Default.vert", "Shaders/Red_Box.frag");


	glGenVertexArrays(1, &vao);

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glGenTextures(1, &red_box_texture);
	glBindTexture(GL_TEXTURE_2D, red_box_texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char* data = stbi_load("Assets/Red_box.png", &width, &height, &nrChannels, 0);

	if (data != NULL) {

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {

		std::cout << "Failed to Load Texture" << std::endl;

	}
	stbi_image_free(data);

	def_shader.use();
	def_shader.setInt("texture_", 0);
	glBindTexture(GL_TEXTURE_2D, 0);


}

void Game::Init() {

	red_box_shader.init("Shaders/Default.vert", "Shaders/Red_Box.frag");
	//green_box_shader.init("Shaders/Default.vert", "Shaders/Green_Box.frag");
	//blue_box_shader.init("Shaders/Default.vert", "Shaders/Green_Box.frag");

	//red_box.create(0.2f, 0.3f, "Assets/Red_box.png", 0, red_box_shader);



}

void Game::Update() {




}

void Game::Draw() {

	//red_box.draw(red_box_shader);
	//green_box.draw(green_box_shader);
	//blue_box.draw(blue_box_shader);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, red_box_texture);

	def_shader.use();
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_FLOAT, &indices);
	glBindVertexArray(0);


}

void Game::Run() {

	Update();
	Draw();

}

void Game::CleanUp() {

	red_box_shader.delete_shader();
	//green_box_shader.delete_shader();
	//blue_box_shader.delete_shader();

	red_box.UnloadTexture();
	//green_box.UnloadTexture();
	//blue_box.UnloadTexture();

}