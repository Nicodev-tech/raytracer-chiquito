#ifndef __COLOR_H__
#define __COLOR_H__

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(unsigned char * out, const color& pixel_color, const size_t pixel_offset){
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();
	//tranformar linealmente los valores de [0,1] a el rango [0,255]
	char rbyte = char(255.999 * r);
	char gbyte = char(255.999 * g);
	char bbyte = char(255.999 * b);

	//out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';//ppm
	out[pixel_offset] = rbyte;
	out[pixel_offset+1] = gbyte;
	out[pixel_offset+2] = bbyte;
}

#endif