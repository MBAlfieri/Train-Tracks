#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "imageManager.h"
#include "Vagon.h"


Vagon::Vagon(int numeroAzar, int posicion) {

	t_vagon.loadFromFile("Assets\\Vagon.PNG"); //Cargo la textura del Vagón.
	s_vagon.setTexture(t_vagon); //cargo el Sprite del Vagón.

	numero = numeroAzar; //Genera un número del 1 al 9.

	font.loadFromFile("GILB.ttf"); //Carga la fuente
	Stringnumero = to_string(numero); //Me deposita el número en el String.
	textoNumero.setFont(font); //Define la fuente a utilizar.
	textoNumero.setScale(1.2, 1.2); //Define el tamaño del texto.
	textoNumero.setString(Stringnumero); //Define qué va a mostrar el texto.
	textoNumero.setOutlineThickness(2); //Define el grosor del borde del texto.
	textoNumero.setOutlineColor(sf::Color::Black); //Define el color del borde del texto.

	switch (posicion) //Son las posibles posiciones de los Vagones.
	{
	case 0:
		s_vagon.setPosition(125, 170);
		break;

	case 1:
		s_vagon.setPosition(10, 170);
		break;

	case 2:
		s_vagon.setPosition(-207, 245);
		break;

	case 3:
		s_vagon.setPosition(10, 170);
		break;

	case 4:
		s_vagon.setPosition(-350, 170);
		break;

	case 5:
		s_vagon.setPosition(-470, 170);
		break;

	case 6:
		s_vagon.setPosition(-590, 170);
		break;
	}

}


void Vagon::posicionNueva(int aux) { //Son las nuevas posibles posiciones de los Vagones.

	switch (aux)
	{
	case 0:
		s_vagon.setPosition(130, 170);
		break;

	case 1:
		s_vagon.setPosition(10, 170);
		break;

	case 2:
		s_vagon.setPosition(-110, 245);
		break;

	case 3:
		s_vagon.setPosition(-230, 170);
		break;

	case 4:
		s_vagon.setPosition(-350, 170);
		break;

	case 5:
		s_vagon.setPosition(-470, 170);
		break;

	case 6:
		s_vagon.setPosition(-590, 170);
		break;
	}
}