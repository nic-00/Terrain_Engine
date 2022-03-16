#version 440
in vec2 TexCoord;
in float height;
in float Draw;
in float down;

out vec4 Color;
uniform sampler2D mountTexture;

uniform sampler2D rockTexture;



void main()
{

    vec4 Colorm = texture(mountTexture, TexCoord);
    vec4 Colorr = texture(rockTexture, TexCoord * 8);
    if(Draw>0.0)
    {
        Colorm.z=Colorm.z*1.3; 
        Color.y = Color.y*1.1; 
        Colorm.w = Colorm.w - 0.3;
    }
    Color = Colorm * 1.2 + Colorr * 0.2;

}