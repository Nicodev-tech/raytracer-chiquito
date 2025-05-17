#ifndef __COLOR_H__
#define __COLOR_H__

#include "vec3.h"

#include <iostream>

using color = vec3;

void write_color(std::ostream& out, const color& pixel_color ){
	auto r = pixel_color.x();
	auto g = pixel_color.y();
	auto b = pixel_color.z();
	//tranformar linealmente los valores de [0,1] a el rango [0,255]
	int rbyte = int(255.999 * r);
	int gbyte = int(255.999 * r);
	int bbyte = int(255.999 * r);

	out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif