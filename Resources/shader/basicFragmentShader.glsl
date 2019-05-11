#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4( gl_FragCoord.x / 800 * 0.5f,  0.5f, gl_FragCoord.y / 600 * 1.0f, 1.0f );
}