/*	Trabajo Práctico N° 3
	Alumna: Micaela B. Alfieri
	Materia: Programación de Videojuegos I
	Institución: Universidad Nacional del Litoral
	Año: 2020 */

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Juego.h"

using namespace std;
using namespace sf;


int main(int argc, char* args[]) {

	srand(time(NULL));//Randomizador.

	Juego Jugador1({ 800, 600 }, "Train Tracks"); //Tamaño y nombre de la Pantalla.

	return 0;

}