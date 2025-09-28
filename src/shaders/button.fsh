#version 330 core

out vec4 FragColor;

uniform sampler2D tex;
uniform bool highlight;

in vec2 interpCoord;

void main()
{
   vec4 color = texture(tex, interpCoord); 
   if (color.a < 0.1) {discard;} 
   if (highlight) { 
       FragColor = clamp(color*vec4(2.0,2.0,2.0,1.0), 0, 1.0); 
   } 
   else { 
       FragColor = texture(tex, interpCoord);
   } 
}