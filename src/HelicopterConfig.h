#ifndef HELICOPTERCONFIG_H
#define HELICOPTERCONFIG_H

// general
const float initialX = 400.0;
const float initialY = 350.0;
const float scale = 100.0;

// body
const float bodyHeight = 1.0;
const float bodyWidth = 0.8;

// tail
const float tailHeight = 1.0;
const float tailWidth = 0.20;
const float tailY = bodyHeight;
const float tailX = (bodyWidth/2.0) - tailWidth/2.0;

const float tailLeftHeight = 0.4;
const float tailLeftWidth = 0.15;
const float tailLeftX = tailX - tailLeftWidth;
const float tailLeftY = tailY + tailHeight*4.0/5.0;

const float tailRightHeight = 0.4;
const float tailRightWidth = 0.15;
const float tailRightX = tailX + tailWidth;
const float tailRightY = tailY + tailHeight*4.0/5.0;


#endif