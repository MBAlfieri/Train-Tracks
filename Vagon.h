#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>

using namespace std;
using namespace sf;

//----------------------------------------Clase "Vagon". Es el Vag�n individual.

class Vagon {

private:

	friend class Tren; //Clase Amiga "Tren".
	friend class Juego; //Clase Amiga "Juego".

	int numero; //Es el n�mero al azar que tendr� el Vagon.

	Text textoNumero; //Es el texto que muestra los puntos.
	String Stringnumero; //String que contiene el texto.
	Font font; //Es la fuente del texto.

	Texture t_vagon;//Textura del Vag�n.
	Sprite s_vagon;//Sprite del Vag�n.

public:
	Vagon(int numeroAzar, int posicion); //Constructor.

	int getNumero() { return numero; }; //Me devuelve el n�mero del Vag�n.

	void posicionNueva(int aux); //Son las posiciones nuevas del vag�n una vez que se han ordenado de mayor a menor.

	Vagon *siguiente = NULL;//Apunta al Vag�n siguiente.



};





