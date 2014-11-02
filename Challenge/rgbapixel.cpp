/**
 * @file rgbapixel.cpp
 * Implementation of the RGBAPixel class for the EasyPNG library.
 *
 * @author Chase Geigle
 * @date Spring 2012
 */
#include "rgbapixel.h"

RGBAPixel::RGBAPixel() : red(127), green(127), blue(127), alpha(127)
{
	/* nothing */
}

RGBAPixel::RGBAPixel(signed char r, signed char g, signed char b)
	: red(r), green(g), blue(b), alpha(127)
{
	/* nothing */
}

RGBAPixel::RGBAPixel(signed char r, signed char g, signed char b,
		signed char a) : red(r), green(g), blue(b), alpha(a)
{
	/* nothing */
}

bool RGBAPixel::operator==(RGBAPixel const & other) const
{
	return red == other.red && green == other.green && blue == other.blue &&
		alpha == other.alpha;
}

bool RGBAPixel::operator!=(RGBAPixel const & other) const
{
	return !(*this == other);
}

bool RGBAPixel::operator<(RGBAPixel const & other) const
{
	if (red != other.red)
		return red < other.red;
	if (green != other.green)
		return green < other.green;
	return blue < other.blue;
}

std::ostream & operator<<(std::ostream & out, RGBAPixel const & pixel)
{
	out << "(" << (int) pixel.red << "," << (int) pixel.green << ","
		<< (int) pixel.blue << ")";
	if (pixel.alpha != 127)
		out << " a:" << pixel.alpha;
	return out;
}
