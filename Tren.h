#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "imageManager.h"
#include "Vagon.h"

//----------------------------------------Clase "Tren". Es la locomotora.

using namespace std;
using namespace sf;

class Tren{

private:

	friend class Juego; //Calse amiga "Juego".
	friend class Vagones; //Clase amiga "Vagones".

	Vagon *Vagones; //Instancia del objeto Vagones

	Texture t_tren; //Textura del Tren.
	Sprite s_tren; //Sprite del Tren.

	int cantidadVagones = 0; //Es la cantidad de Vagones que est�n agarrados a la locomotora.
	
public:

	Tren(); //Constructor
	void Insertar(int c,int d); //Inserta un Vag�n a la locomotora.
	void Eliminar(int numeroAux); //Elimina un Vag�n de la locomotora.
	void dibujar(RenderWindow& ventana); //Dibuja los gr�ficos.
	void OrdenarVagones(); //Ordena los Vagones.

};