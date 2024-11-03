#version 330

in vec3 fragColor;

out vec4 fragColorOut;

uniform vec3 objectColor;

void main () {
    vec3 test = objectColor;
    fragColorOut = vec4 (fragColor, 1.0);
}