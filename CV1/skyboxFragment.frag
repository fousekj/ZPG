#version 330
layout(location=0) in vec3 vPos;

out vec3 ex_texCoord;

uniform mat4 modelMatrix;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;

void main()
{
    gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4 (vPos, 1.0);
    ex_texCoord = vPos;
}