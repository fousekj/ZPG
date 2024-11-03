#version 330

in vec4 ex_worldPos;
in vec3 ex_worldNorm;

out vec4 fragColor;

uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;

void main() {
    vec3 test = lightPosition;
    test = lightColor;
    test = viewPosition;
    fragColor = vec4(objectColor, 1.0);
}