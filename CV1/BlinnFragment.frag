#version 330

in vec4 ex_worldPos;
in vec3 ex_worldNorm;

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

out vec4 fragColor;

uniform Light lights[MAX_LIGHTS];
uniform vec3 objectColor;
uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;
uniform int lightCount;


void main() {

	if(lights[0].type == 0 && lightCount > 0) {
		vec3 lightDir = normalize(lights[0].position - vec3(ex_worldPos));
        vec3 viewDir = normalize(viewPosition - vec3(ex_worldPos));
        vec3 halfwayDir = normalize(lightDir + viewDir);
    
        float diff = max(dot(lightDir, normalize(ex_worldNorm)), 0.0);
        vec3 norm = normalize(ex_worldNorm);
        float spec = pow(max(dot(norm, halfwayDir), 0.0), 32.0);
    
        vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
        vec4 diffuse = diff * vec4(objectColor, 1.0) * vec4(lights[0].color, 1.0);
        vec4 specular = spec * vec4(lights[0].color, 1.0);
    
        fragColor = ambient + diffuse + specular;
			
	}
		
	
}