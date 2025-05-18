cmake_minimum_required(VERSION 3.28)

project(RRIOW)

#setea la version del estandar de c++ a 11,
#para no tener que incluir todas la librerias <iostream>
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )

set(SOURCE_ONE_WEEKEND
	main.cpp
	src/vec3.h
	src/color.h
)

add_executable(${PROJECT_NAME} ${SOURCE_ONE_WEEKEND})