#version 330

#define MAX_LIGHTS 1

struct Light {
	vec3 position;
    vec3 color;

    float constant;
    float linear;
    float quadratic;
    float cutOff;
    int type;
};

in vec3 ex_worldPos;
in vec3 ex_worldNorm;

out vec4 fragColor;

uniform Light lights[MAX_LIGHTS];
uniform vec3 viewPosition;
uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform int lightCount;

uniform float r_a;
uniform float r_d;
uniform float r_s;

void main() {
    
    float test = lights[0].constant;
    test = lights[0].linear;
    test = lights[0].quadratic;
    test = lightCount;
    test = lights[0].type;
    test = lights[0].cutOff;
    test = r_a;
    test = r_d;
    test = r_s;


    vec3 lightDir = normalize(lights[0].position - vec3(ex_worldPos));
    vec3 viewDir = normalize(viewPosition - vec3(ex_worldPos));
    vec3 norm = normalize(ex_worldNorm);
    vec3 reflectDir = reflect(-lightDir, norm);

    float diff = max(dot(lightDir, normalize(ex_worldNorm)), 0.0);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);

    vec4 diffuse = diff * vec4(objectColor, 1.0) * vec4(lights[0].color, 1.0);
    vec4 specular = spec * vec4(lights[0].color, 1.0);
    
    fragColor = ambient + diffuse + specular;

}