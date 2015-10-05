#ifndef HELICOPTERCONFIG_H
#define HELICOPTERCONFIG_H

// general
const float initialX = 100.0;
const float initialY = 100.0;

const float scale = 60.0;

// body
const float bodyHeight =scale* 1.0;
const float bodyWidth =scale* 0.8;

// tail
const float tailHeight = scale*1.0;
const float tailWidth = scale*0.20;
const float tailY = bodyHeight/2.0 + tailHeight/2.0;
const float tailX = 0.0;

const float tailLeftHeight = scale*0.4;
const float tailLeftWidth = scale*0.15;
const float tailLeftX = -tailWidth/2.0 - tailLeftWidth/2.0;
const float tailLeftY = bodyHeight/2.0 + tailHeight;

const float tailRightHeight = scale*0.4;
const float tailRightWidth = scale*0.15;
const float tailRightX = tailWidth/2.0 + tailRightWidth/2.0;
const float tailRightY = tailLeftY;

const float raioHeliceBase = scale*0.1;
const float heliceWidth = scale*0.12;
const float heliceHeight = scale*2.0;

const float gunHeight = 0.4 * scale;
const float gunWidth = 0.1 * scale;
#endif