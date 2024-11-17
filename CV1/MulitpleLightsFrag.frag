#version 330

#define MAX_LIGHTS 4

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
uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;

void main() {
    vec4 diffuse = vec4(0.0f);
    vec4 specular = vec4(0.0f);

    vec4 ambient = vec4(0.0, 0.0, 0.0, 1.0);

    for (int i = 0; i < 3; ++i)
    {
        vec3 camera_direction = normalize(viewPosition - ex_worldPos);
        vec3 light_direction;
        float attenuation = 1;
        float spotlight_intensity = 1;

        light_direction = normalize(pointLights[i].position - ex_worldPos);

        vec3 reflection_direction = reflect(-light_direction, ex_worldNorm);

        float light_distance = length(pointLights[i].position - ex_worldPos);

        attenuation = 1.0 / (pointLights[i].constant + (pointLights[i].linear * light_distance) + (pointLights[i].quadratic * pow(light_distance, 2)));

        float diffuse_strength = max(dot(normalize(light_direction), normalize(ex_worldNorm)), 0.0);
        diffuse += vec4((diffuse_strength * attenuation) * pointLights[i].color, 1);

        float spec = max(dot(camera_direction, reflection_direction), 0.0);
        spec = pow(spec, 32);
        specular += spec * attenuation * vec4(pointLights[i].color, 1.0);
    }

    fragColor = (ambient + diffuse + specular) * vec4(objectColor, 1);
    
}