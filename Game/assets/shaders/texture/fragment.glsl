#version 460 core
			
layout(location = 0) out vec4 Color;

in vec2 v_TexCoord;

uniform sampler2D u_Texture;

void main()
{
	Color = texture(u_Texture, v_TexCoord);
}