#version 330 core
out vec4 FragColor;
in vec3 glColor;
// texture samplers

uniform float mixValue;

void main()
{
	// linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = vec4(glColor, 1.0);
}