#version 330 core

in vec4 ex_worldPos;
in vec3 ex_worldNorm;
in vec2 ex_texCoord;  // Add texture coordinates input

out vec4 fragColor;

uniform vec3 lightPosition;
uniform vec3 lightColor;
uniform vec3 viewPosition;
uniform sampler2D textureID;  // The texture sampler

void main() {
    // Lighting calculations
    vec3 lightDir = normalize(lightPosition - vec3(ex_worldPos));
    vec3 viewDir = normalize(viewPosition - vec3(ex_worldPos));
    vec3 norm = normalize(ex_worldNorm);
    vec3 reflectDir = reflect(-lightDir, norm);

    // Diffuse and specular components
    float diff = max(dot(lightDir, norm), 0.0);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32.0);
    
    // Texture sampling
    vec4 texColor = texture(textureID, ex_texCoord);  // Sample the texture
    
    // Ambient, diffuse, and specular lighting
    vec4 ambient = 0.1 * texColor;  // Use texture color for ambient lighting
    vec4 diffuse = diff * texColor * vec4(lightColor, 1.0);
    vec4 specular = spec * vec4(lightColor, 1.0);
    
    // Final color output
    fragColor = ambient + diffuse + specular;
}
