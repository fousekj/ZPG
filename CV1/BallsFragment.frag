#version 330

#define MAX_LIGHTS 1

struct PointLight {
	vec3 position;
    vec3 color;

    float constant;
    float linear;
    float quadratic;
};

in vec3 ex_worldPos;
in vec3 ex_worldNorm;

out vec4 fragColor;

uniform PointLight pointLights[MAX_LIGHTS];
uniform vec3 viewPosition;
uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;

void main() {

    float test = pointLights[0].constant;
    test = pointLights[0].linear;
    test = pointLights[0].quadratic;

    vec3 lightDir = normalize(pointLights[0].position - vec3(ex_worldPos));
    vec3 viewDir = normalize(viewPosition - vec3(ex_worldPos));
    vec3 norm = normalize(ex_worldNorm);
    vec3 reflectDir = reflect(-lightDir, norm);

    float diff = max(dot(lightDir, normalize(ex_worldNorm)), 0.0);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);

    vec4 diffuse = diff * vec4(objectColor, 1.0) * vec4(pointLights[0].color, 1.0);
    vec4 specular = spec * vec4(pointLights[0].color, 1.0);
    
    fragColor = ambient + diffuse + specular;

}