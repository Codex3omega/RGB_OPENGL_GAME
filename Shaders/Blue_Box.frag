#version 460 core

out vec4 FragColor;
in vec2 tex_coords;

uniform sampler2D texture_;

void main(){

	FragColor = texture(texture_, tex_coords);

}