#include "src/color.h"
#include "src/vec3.h"
#include "src/ray.h"

#include <iostream>

//definicion de stb_image
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STBI_ONLY_PNG

#include "stb_image.h"
#include "stb_image_write.h"



/*if a unit-length normal vector is ever required, 
then you might as well do it up front once, 
instead of over and over again “just in case” for every location where unit-length is required
*/


double hit_sphere(const point3& center, double radius,const ray& r)
{
	vec3 oc = center - r.origin();
	auto a = dot(r.direction(), r.direction());
	auto b = -2.0 * dot(r.direction(),oc);
	auto c = dot(oc, oc) - radius * radius;
	auto discriminant = b*b - 4*a*c;
	if(discriminant < 0)
	{
		return -1.0;
	} else {
		return (-b - std::sqrt(discriminant) )/ (2.0*a);
	}
}



color ray_color(const ray& r)
{
	auto t = hit_sphere(point3(0,0,-1), 0.5, r);
	if(t > 0){
		vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
		return 0.5 * color(N.x()+1, N.y()+1, N.z()+1);
	}
	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5 *(unit_direction.y() + 1.0);
	return (1.0-a) * color(1.0,1.0,1.0) + a * color(0.5, 0.7, 1.0);
}

bool isSuffix(std::string s1, std::string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if (n1 > n2)
        return false;
    for (int i = 0; i < n1; i++)
        if (s1[n1 - i - 1] != s2[n2 - i - 1])
            return false;
    return true;
}


int validate_image(char * file)
{
	if(isSuffix(".png",file)){
		return  1;
	}
	else
	{
		return -1;
	}
}



int main(int argc, char * argv[])
{
	if(argc != 2)
	{
		perror("Flaco te falto el argumento de la imagen");
		return 0;
	}
	int img_type = validate_image(argv[1]);
	if(img_type == -1)
	{
		perror("no es un archivo soportado solo \"nombre del archivo\".png");
		return 0;
	}
	auto aspect_ratio = 16.0 / 9.0;
	int imagen_ancho = 400;
	//calcular el alto de la camara
	int imagen_alto = int(imagen_ancho / aspect_ratio);
	imagen_alto = (imagen_alto < 1)? 1 : imagen_alto;

	unsigned char * buff = (unsigned char *)malloc(imagen_alto * imagen_ancho * 3);//largo * ancho * canales


	//camara
	auto focal_lenght = 1.0;
	auto viewport_alto = 2.0;
	auto viewport_ancho = viewport_alto * (double(imagen_ancho) / imagen_alto);
	auto camera_center = point3(0, 0, 0);

	//calcular los vectores atravez del tamaño horizontal y el vertical por los bordes del viewport
	auto viewport_u = vec3(viewport_ancho, 0, 0);
	auto viewport_v	= vec3(0, -viewport_alto, 0);

	//calcular las coordenas horizontales y verticales de loz delta vectore de pixel a pixel
	auto pixel_delta_u = viewport_u / imagen_ancho;
	auto pixel_delta_v = viewport_v / imagen_alto;

	//calcular la posicion del pixel de la esquina superior izquierda
	auto viewport_upper_left = camera_center - vec3(0, 0, focal_lenght) - viewport_u/2 - viewport_v/2;
	auto pixel00_loc = viewport_upper_left + 0.5 *(pixel_delta_u + pixel_delta_v);

	// Renderizado

	//std::cout << "P3\n" << imagen_ancho << " " << imagen_alto << "\n255\n";
	for(int j = 0 ; j < imagen_alto; j++)
	{
		std::clog << "\r Lineas restantes" << (imagen_ancho - j) << ' ' << std::flush;
		for (int i = 0; i < imagen_ancho; i++)
		{	
			size_t pixel_offset = (j * imagen_ancho + i) * 3;
		    /*  //Imagen con 3 colore
			double x = (double(j)/(imagen_alto-1));
			color pixel_color = color(double(i)/(imagen_ancho-1)
									,x
									,-1*(x - 255));
			*/
			
			auto pixel_center = pixel00_loc + (i * pixel_delta_u) +(j * pixel_delta_v);
			auto ray_direction = pixel_center - camera_center;
			ray r(camera_center, ray_direction);
			color pixel_color = ray_color(r);
			
			write_color(buff, pixel_color, pixel_offset);
		}
	}
	stbi_write_png(argv[1], imagen_ancho, imagen_alto, 3, buff, imagen_ancho * 3);
    free(buff);
	std::clog << "\rTERMINATOR					\n";
}