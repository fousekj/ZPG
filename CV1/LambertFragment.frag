#version 330

in vec4 ex_worldPos;
in vec3 ex_worldNorm;

out vec4 fragColor;

uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;

void main() {
    vec3 test = viewPosition;
    vec3 lightDir = normalize(lightPosition - vec3(ex_worldPos));
    float diff = max(dot(lightDir, normalize(ex_worldNorm)), 0.0);
    
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
    vec4 diffuse = diff * vec4(objectColor, 1.0) * vec4(lightColor, 1.0);
    
    fragColor = ambient + diffuse;
}