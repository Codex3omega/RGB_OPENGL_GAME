#include "Game.h"

Game::Game(std::string _name)
{

	name = _name;

	def_shader.init("Shaders/Default.vert", "Shaders/Red_Box.frag");

	player.init(&red_box, &green_box, &blue_box, 0.0f, -0.9f, 0.5f, 0.05f, 0.9f);
}

void Game::Init() {


}

void Game::Update(float delta, GLFWwindow* g_window) {

	player.update(delta, g_window);

}

void Game::Draw() {

	player.draw(def_shader);

}

void Game::Run(float delta, GLFWwindow* _window) {

	Update(delta,_window);
	Draw();

}

void Game::CleanUp() {

	red_box.UnloadTexture();
	green_box.UnloadTexture();
	blue_box.UnloadTexture();

}
