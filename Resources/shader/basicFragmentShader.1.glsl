#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    
    FragColor = vec4( gl_FragCoord.y / 600 * 1.0f,  gl_FragCoord.x / 800 * 0.5f, 0.6f, 1.0f );

    FragColor = texture( ourTexture, TexCoord );
}