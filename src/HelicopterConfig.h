#ifndef HELICOPTERCONFIG_H
#define HELICOPTERCONFIG_H

// general
const float initialX = 400.0;
const float initialY = 350.0;
const float scale = 100.0;

/*// body
const float bodyHeight = 1.0;
const float bodyWidth = 0.8;

// tail
const float tailHeight = 1.0;
const float tailWidth = 0.20;
const float tailY = bodyHeight/2.0 + tailHeight/2.0;
const float tailX = 0.0;

const float tailLeftHeight = 0.4;
const float tailLeftWidth = 0.15;
const float tailLeftX = -tailWidth/2.0 - tailLeftWidth/2.0;
const float tailLeftY = bodyHeight/2.0 + tailHeight;

const float tailRightHeight = 0.4;
const float tailRightWidth = 0.15;
const float tailRightX = tailWidth/2.0 + tailRightWidth/2.0;
const float tailRightY = tailLeftY;
*/
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

const float raioHeliceBase = 10.0;
const float heliceWidth = 12.0;
const float heliceHeight = 200.0;

const float gunHeight = 40.0;
const float gunWidth = 10.0;
#endif