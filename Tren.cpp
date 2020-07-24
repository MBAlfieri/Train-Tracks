#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "imageManager.h"
#include "Tren.h"

Tren::Tren() { //Constructor.

	Vagones = NULL; //Los Vagones arrancan vacíos.

	t_tren.loadFromFile("Assets\\locomotora.PNG"); //Cargo la textura de la Locomotora.
	s_tren.setTexture(t_tren); //Armo el Sprite.
	s_tren.setPosition(260, 170); //Defino la posición inicial de la Locomotora.

	for (int i = 0; i < 2; i++) { //Inserto los dos primeros Vagones.

		Insertar((rand() % 10), i);
	}
}

void Tren::OrdenarVagones() { //Ordena los Vagones, de mayor a menor, de izquierda a derecha.

	int posiciones = 0;

	Vagon* actual = Vagones;
	
	while (actual != NULL)
	{
		actual->posicionNueva(posiciones);
		actual = actual->siguiente;
		posiciones += 1;

	}
}

void Tren::Insertar(int numeroAzar, int posicion) { //Inserta un vagón, bajo los parámetros dados.

	Vagon* player = new Vagon(numeroAzar, posicion);

	Vagon* firstAuxiliar = Vagones;

	Vagon* secondAuxiliar = NULL;

	while (firstAuxiliar != NULL && firstAuxiliar->numero < numeroAzar)
	{
		secondAuxiliar = firstAuxiliar;

		firstAuxiliar = firstAuxiliar->siguiente;
	}

	if (Vagones == firstAuxiliar)
	{
		Vagones = player;
	}
	else

	{
		secondAuxiliar->siguiente = player;
	}

	player->siguiente = firstAuxiliar;

	firstAuxiliar = Vagones;

	while (firstAuxiliar != NULL) {

		firstAuxiliar = firstAuxiliar->siguiente;
	}

	cantidadVagones += 1; //Le sumo a la cantidad de Vagones existentes.

	OrdenarVagones(); //Ordeno los Vagones.
}


void Tren::Eliminar(int numeroAux) { //Elimino los Vagones, de acuerdo a los parámetros dados.

	if (Vagones != NULL)
	{

		Vagon* auxiliarBorrado = Vagones;

		Vagon* referenciaAnterior = NULL;

		while(auxiliarBorrado != NULL && auxiliarBorrado->numero != numeroAux && cantidadVagones > 1){
	
			referenciaAnterior = auxiliarBorrado;

			auxiliarBorrado = auxiliarBorrado->siguiente;
		}

		if(auxiliarBorrado != NULL && auxiliarBorrado->numero != numeroAux  && cantidadVagones == 1)
		{
			referenciaAnterior = auxiliarBorrado;

			auxiliarBorrado = auxiliarBorrado->siguiente;
		}

		if (auxiliarBorrado == NULL)
		{
			delete auxiliarBorrado;
			return;
		}

		else if (referenciaAnterior == NULL)
		{
			Vagones = Vagones->siguiente;
			delete auxiliarBorrado;
		}

		else
		{
			referenciaAnterior->siguiente = auxiliarBorrado->siguiente;
			delete auxiliarBorrado;
		}

	cantidadVagones -= 1;//Le resto a la cantidad de Vagones existentes.

	OrdenarVagones(); //Ordeno los Vagones.

	}
}


void Tren::dibujar(RenderWindow &ventana) { //Dibujo los Vagones.

	Vagon* actual = Vagones;

	while (actual != NULL)
	{
		actual->textoNumero.setPosition(actual->s_vagon.getPosition().x + 60, actual->s_vagon.getPosition().y);
		ventana.draw(actual->s_vagon);
		ventana.draw(actual->textoNumero);
		actual = actual->siguiente;
	}
}

