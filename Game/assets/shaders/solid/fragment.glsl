#version 460 core
			
layout(location = 0) out vec4 Color;

in vec3 v_Position;

void main()
{
	Color = vec4(v_Position * 0.5 + 0.5, 1.0);
}