#include "rgbapixel.h"

// Set default pixel to completely opaque white.
RGBAPixel::RGBAPixel(){
	red = 255;
	blue = 255;
	green = 255;
	alpha = 255;
}

// set pixel to user specified values at opaque.
RGBAPixel::RGBAPixel(unsigned char red1, unsigned char green1, unsigned char blue1){
	red = red1;
	green = green1;
	blue = blue1;
	alpha = 255;
}
	
