#include "image.h"


//flips the image across vertical line through its center.
void Image::flipleft(){
    RGBAPixel * left = new RGBAPixel;
    RGBAPixel * right = new RGBAPixel;
    RGBAPixel temp;
	for (size_t x = 0; x < width()/2; x++) //loop x through 0 to wi/2-1 (half of image)
	{
		for(size_t y = 0; y < height(); y++) //loop y through 0 to hi-1
		{
            //assign left to point to the same thing as the current pixel.
            left = (*this)(x,y);
            //assign right to point to the pixel directly across the from it.
            right = (*this)(width()-1-x,y);
            //create new temporary pointer to store the value of the current pixel.
            temp = *left;
            //make the value of the current pixel equal to the value that right points to.
            *(*this)(x,y) = *right;
            //assign the pixel accross with the the value pointed by temp.
            *(*this)(width()-1-x,y) = temp;
        }
	}
}

//adds specified red, blue, and green values to the image.
void Image::adjustbrightness(int r, int g, int b){
    for (size_t x = 0; x < width(); x++) //loop x through 0 to wi-1
	{
		for(size_t y = 0; y < height(); y++) //loop y through 0 to hi-1
		{
            //add user input values of r g and b to (*this)(x,y)->color. If this is greater than 255 or lower than 0, set the value to 255 or 0 respectively.
            if ((*this)(x,y)->green + g > 255)
                (*this)(x,y)->green = 255;
            else if ((*this)(x,y)->green + g < 0)
                (*this)(x,y)->green = 0;
            else
                (*this)(x,y)->green = (*this)(x,y)->green + g;
            
            if ((*this)(x,y)->red + r > 255)
                (*this)(x,y)->red = 255;
            else if ((*this)(x,y)->red + r < 0)
                (*this)(x,y)->red = 0;
            else
                (*this)(x,y)->red = (*this)(x,y)->red + r;
            
            if ((*this)(x,y)-> blue + b > 255)
                (*this)(x,y)->blue = 255;
            else if ((*this)(x,y)->blue + b < 0)
                (*this)(x,y)->blue = 0;
            else
                (*this)(x,y)->blue = (*this)(x,y)->blue + b;
        }
	}


}

//make pixels of image equal to 255 - original.
void Image::invertcolors(){
    for (size_t x = 0; x < width(); x++) //loop x through 0 to wi-1
	{
		for(size_t y = 0; y < height(); y++) //loop y through 0 to hi-1
		{
            //subtract current value from 255.
            (*this)(x,y)->red = 255-(*this)(x,y)->red;
            (*this)(x,y)->green = 255- (*this)(x,y)->green;
            (*this)(x,y)->blue = 255-(*this)(x,y)->blue;

        }
	}
    
    


}
