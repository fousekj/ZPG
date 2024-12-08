#version 330

in vec4 ex_worldPos;
in vec3 ex_worldNorm;

out vec4 fragColor;
struct Light {
	vec3 position;
    vec3 color;

    float constant;
    float linear;
    float quadratic;
    float cutOff;
    vec3 direction;
    int type;
};
#define MAX_LIGHTS 4

uniform Light lights[MAX_LIGHTS];
uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;
uniform int lightCount;

uniform float r_a;
uniform float r_d;
uniform float r_s;

void main() {
    vec3 test = viewPosition;
    float test_mat = r_a * r_d * r_s;
    vec4 ambient = vec4(0.0);
    vec4 diffuse = vec4(0.0);

    for (int i = 0; i < lightCount; ++i) {
        if (lights[i].type == 0) {
            vec3 lightDir = normalize(lights[i].position - vec3(ex_worldPos));
            float diff = max(dot(lightDir, normalize(ex_worldNorm)), 0.0);
    
            ambient += vec4(0.1, 0.1, 0.1, 1.0);
            diffuse += diff * vec4(objectColor, 1.0) * vec4(lights[i].color, 1.0);
        }
    }
    fragColor = ambient + diffuse;
}