#version 460 core

layout (local_size_x = 32, local_size_y = 32) in;
layout(r32f, binding = 0) uniform image2D imgOutput;

uniform ivec2 screenSize;
uniform dvec2 offset;
uniform double scale;
//uniform float discardThresholdSqrd;
uniform int maxIterations;

int currentInter;

dvec2 xy;

dvec2 graphSpace(dvec2 coord)
{
    double aspectRatio = screenSize.x/screenSize.y;
    return (((coord - screenSize.xy/2)/screenSize * scale) - (offset/screenSize))*dvec2(aspectRatio,1.0);
}

void main() {
    currentInter = 0;
    ivec2 texelCoord = ivec2(gl_GlobalInvocationID.xy);
    dvec2 xy = graphSpace(vec2(texelCoord));
    while (currentInter<maxIterations&&(xy*xy)<1)
    {
        currentInter++;
        xy.xy = xy.xy*xy.xy;
    }
    imageStore(imgOutput,texelCoord,currentInter);
}