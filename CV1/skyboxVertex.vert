#version 330

in vec3 ex_texCoord;
out vec4 frag_color;

uniform samplerCube skybox;

void main()
{
    frag_color = texture(skybox, ex_texCoord);
} 