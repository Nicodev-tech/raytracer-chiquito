#include "color.h"
#include "vec3.h"

#include <iostream>

int main()
{
	//imagen
	int imagen_largo = 1024;
	int imagen_ancho = 1024;
	// Renderizado
	std::cout << "P3\n" << imagen_largo << " " << imagen_ancho << "\n255\n";
	for(int j = 0 ; j < imagen_ancho; j++)
	{
		std::clog << "\r Lineas restantes" << (imagen_ancho - j) << ' ' << std::flush;
		for (int i = 0; i < imagen_largo; i++)
		{
			auto r = double(i) / (imagen_ancho-1);
			auto g = double(j) / (imagen_ancho-1);
			auto b = 0.0;

			int ir = int(255.999 * r);
			int ig = int(255.999 * r);
			int ib = int(255.999 * g);

			std::cout << ir << ' ' << ig << ' ' << ib << "\n";
		}
	}
	std::clog << "\rTERMINATOR					\n";
}