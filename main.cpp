#include "src/color.h"
#include "src/vec3.h"

#include <iostream>

//definicion de stb_image
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_ONLY_PNG

#include "stb_image.h"
#include "stb_image_write.h"

int main()
{
	//imagen
	int imagen_largo = 255;
	int imagen_ancho = 255;
	// Renderizado
	std::clog << "\n HOLAAAAAAA \n\n      \n";
	std::cout << "P3\n" << imagen_largo << " " << imagen_ancho << "\n255\n";
	for(int j = 0 ; j < imagen_ancho; j++)
	{
		std::clog << "\r Lineas restantes" << (imagen_ancho - j) << ' ' << std::flush;
		for (int i = 0; i < imagen_largo; i++)
		{
			auto pixel_color = color(double(i)/(imagen_ancho-1)
									,double(j)/(imagen_largo-1)
									,0);
			write_color(std::cout, pixel_color);
		}
	}
	std::clog << "\rTERMINATOR					\n";
}