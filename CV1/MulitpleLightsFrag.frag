#version 330

#define MAX_LIGHTS 4

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

in vec3 ex_worldPos;
in vec3 ex_worldNorm;

out vec4 fragColor;

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
    vec4 diffuse = vec4(0.0f);
    vec4 specular = vec4(0.0f);

    vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0) * r_a;

    for (int i = 0; i < lightCount; ++i)
    {
        // point light
        if (lights[i].type == 0) {
			vec3 camera_direction = normalize(viewPosition - ex_worldPos);
            vec3 light_direction = normalize(lights[i].position - ex_worldPos);
            float attenuation = 1;
            vec3 reflection_direction = reflect(-light_direction, ex_worldNorm);

            float light_distance = length(lights[i].position - ex_worldPos);

            attenuation = 1.0 / (lights[i].constant + (lights[i].linear * light_distance) + (lights[i].quadratic * pow(light_distance, 2)));

            float diffuse_strength = max(dot(normalize(light_direction), normalize(ex_worldNorm)), 0.0);
            diffuse += vec4((diffuse_strength * r_d * attenuation ) * lights[i].color, 1);

            float spec = max(dot(camera_direction, reflection_direction), 0.0);
            spec = pow(spec, 32);  
            specular += spec * r_s * attenuation * vec4(lights[i].color, 1.0);
		} 
        // spot light
        else if ( lights[i].type == 1 ) {

            vec3 camera_direction = normalize(viewPosition - ex_worldPos);
			vec3 light_direction = normalize(lights[i].position - ex_worldPos);
			float attenuation = 1.0;
			float spotlight_intensity = 1.0;

            float theta = dot(light_direction, normalize(-lights[i].direction));
            spotlight_intensity = (theta - lights[i].cutOff) / (1 - lights[i].cutOff);
            if (theta <= lights[i].cutOff) {
				continue;
			}

			vec3 reflection_direction = reflect(-light_direction, ex_worldNorm);

			float light_distance = length(lights[i].position - ex_worldPos);

			attenuation = 1.0 / (lights[i].constant + (lights[i].linear * light_distance) + (lights[i].quadratic * pow(light_distance, 2)));

			float diffuse_strength = max(dot(normalize(light_direction), normalize(ex_worldNorm)), 0.0);
			diffuse += vec4((diffuse_strength * r_d * attenuation * spotlight_intensity ) * lights[i].color, 1);

			float spec = max(dot(camera_direction, reflection_direction), 0.0);
			spec = pow(spec, 32);
			specular += spec * r_s * attenuation * vec4(lights[i].color, 1.0);

        }
        // directional light
        else if (lights[i].type == 2) {

			vec3 camera_direction = normalize(viewPosition - ex_worldPos);
			vec3 light_direction = normalize(-lights[i].direction);
			float attenuation = 1;

			vec3 reflection_direction = reflect(-light_direction, ex_worldNorm);

			float diffuse_strength = max(dot(normalize(light_direction), normalize(ex_worldNorm)), 0.0);
			diffuse += vec4((diffuse_strength * r_d * attenuation ) * lights[i].color, 1);

			float spec = max(dot(camera_direction, reflection_direction), 0.0);
			spec = pow(spec, 32);
			specular += spec * r_s * attenuation * vec4(lights[i].color, 1.0);
		}
        
    }

    fragColor = (ambient + diffuse + specular) * vec4(objectColor, 1);
    
}