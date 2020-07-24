#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>

using namespace std;
using namespace sf;

//----------------------------------------Clase "Vagon". Es el Vagón individual.

class Vagon {

private:

	friend class Tren; //Clase Amiga "Tren".
	friend class Juego; //Clase Amiga "Juego".

	int numero; //Es el número al azar que tendrá el Vagon.

	Text textoNumero; //Es el texto que muestra los puntos.
	String Stringnumero; //String que contiene el texto.
	Font font; //Es la fuente del texto.

	Texture t_vagon;//Textura del Vagón.
	Sprite s_vagon;//Sprite del Vagón.

public:
	Vagon(int numeroAzar, int posicion); //Constructor.

	int getNumero() { return numero; }; //Me devuelve el número del Vagón.

	void posicionNueva(int aux); //Son las posiciones nuevas del vagón una vez que se han ordenado de mayor a menor.

	Vagon *siguiente = NULL;//Apunta al Vagón siguiente.



};





