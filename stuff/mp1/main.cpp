#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

// This function rotates the input image by 180 degrees.

PNG rotate180(PNG original){
	int wi = original.width();
	int hi = original.height();
	PNG copy(wi,hi);
	for (size_t x = 0; x < wi; x++){
		for (size_t y = 0; x < hi; y++){
			*copy(wi - x,hi - y) = *original(x,y);
		}
	}
	return copy;
}

int main(){
	// Open image from in.png.
	PNG image("in.png");
	// Rotate image read from image.png.
	image = rotate180(image);
	// Write image from image.png to out.png.
	image.writeToFile("out.png");
	return 0;
}
