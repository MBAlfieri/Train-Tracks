/*	Trabajo Pr�ctico N� 3
	Alumna: Micaela B. Alfieri
	Materia: Programaci�n de Videojuegos I
	Instituci�n: Universidad Nacional del Litoral
	A�o: 2020 */

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include "Juego.h"

using namespace std;
using namespace sf;


int main(int argc, char* args[]) {

	srand(time(NULL));//Randomizador.

	Juego Jugador1({ 800, 600 }, "Train Tracks"); //Tama�o y nombre de la Pantalla.

	return 0;

}