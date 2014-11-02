#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "png.h"


class Image : public PNG{
	public:
		//flips the image across vertical line through its center.
		void flipleft();
		//adds specified red, blue, and green values to the image.
		void adjustbrightness(int r, int g, int b);
		//make pixels of image equal to 255 - original.
		void invertcolors();
};
#endif
