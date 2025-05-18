# raytracer-chiquito
Un raytracer hecho en c++, es un proyecto para aprender como funcionan los algoritmos que se usan para hacer raytracing, probablemente no sea tan eficiente **usar bajo su propio riesgo**  
Permite extraer las imagenes en PPM unicamente :c  
## Compilación
Testeado unicamente en linux  
`cmake -S . -B build/ && cmake --build build/ && build/RRIOW > imagen.ppm`   
## Imagenes
![](imagen.ppm)  
## TODO
[ ] Implementar STB_IMAGES para poder exportar en PNG [^1]
## Bibliografia
[Raytracing in one weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage)
[^1]: [STB_IMAGES](https://github.com/nothings/stb#stb_libs)

