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
    
    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0) * r_a;
    vec4 diffuse = vec4(0.0);
    vec4 specular = vec4(0.0);
    vec3 tst = objectColor;
    for (int i = 0; i < lightCount; ++i)
	{
        if (lights[i].type == 0) {
            vec3 camera_direction = normalize(viewPosition - vec3(ex_worldPos));
            vec3 light_direction = normalize(lights[i].position - vec3(ex_worldPos));
            float attenuation = 1;
            vec3 reflection_direction = reflect(-light_direction, ex_worldNorm);

            float light_distance = length(lights[i].position - vec3(ex_worldPos));

            attenuation = 1.0 / (lights[i].constant + (lights[i].linear * light_distance) + (lights[i].quadratic * pow(light_distance, 2)));

            float diffuse_strength = max(dot(normalize(light_direction), normalize(ex_worldNorm)), 0.0);
            diffuse += vec4((diffuse_strength * r_d * attenuation ) * lights[i].color, 1);

            float spec = max(dot(camera_direction, reflection_direction), 0.0);
            spec = pow(spec, 32);
            specular += spec * r_s * attenuation * vec4(lights[i].color, 1.0);
        }
        
    }
    fragColor = ambient + diffuse + specular;
}