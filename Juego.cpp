#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "Juego.h"
#include "Vagon.h"
#include "imageManager.h"

using namespace std;
using namespace sf;

Juego::Juego(Vector2f ResolucionPantalla, String TituloDelJuego) { //Constructor.

	VentanaJuego = new RenderWindow(VideoMode(ResolucionPantalla.x, ResolucionPantalla.y), TituloDelJuego);  //Resolucion de la pantalla y el título de la ventana.
	VentanaJuego->setFramerateLimit(60); //Limito los FPS.
	VentanaJuego->setMouseCursorVisible(false); //Escondo el mouse.

	setrandomizarcuenta(); //Randomiza la cuenta matemática.

	font.loadFromFile("GILB.ttf"); //Carga la fuente

	textoContador.setFont(font); //Define la fuente a utilizar.
	textoContador.setCharacterSize(20);//Define el tamaño de la letra.
	textoContador.setOutlineColor(sf::Color::Black);//Define el color del borde del texto.
	textoContador.setOutlineThickness(2);//Define el grosor del borde del texto.

	Jugador1 = new Tren; // Instancia del Tren.

	cargarSonidos(); //Carga los sonidos.
	cargarGráficos(); //Carga los gráficos.
	
	LoopJuego(); //Loop principal del juego.

}

void Juego::LoopJuego() { //Loop principal del juego.

	VentanaJuego->setIcon(256, 256, Icono.getPixelsPtr()); //Defino el ícono del Juego.

	musica.setVolume(20); //Le cambio el volumen al sonido.
	Reloj.setVolume(0); //Idem.
	s_fanfare.setVolume(20); //Idem.
	s_Explosion.setVolume(50); //Idem.
	s_ObtenerVagon.setVolume(50); //Idem.
	s_GameOver.setVolume(70); //Idem.

	Reloj.setLoop(true); //Hago que el loop de la música sea true.
	musica.setLoop(true); //Idem.

	musica.play(); //Reproduzco la música.
	Reloj.play(); //Idem.

	//---------------------------------------------------------------Loop principal.
	while (GameOn == true) { //Inicia el juego.

		VentanaJuego->clear(); //Limpio la ventana.

		dibujarGraficos(); //Dibujo los gráficos.

		movimientoTren(); //Defino el movimiento permanente del Tren.

		colisiones(); //Manejo las colisiones en el juego.

		VentanaJuego->display(); //Muestro en la ventan.

	}

	//---------------------------------------------------------------Loop secundario.
	while (GameOn == false) {

		//-----------------------------------------------------------Condición de Victoria.
		while(PantallaWin == true) {

			VentanaJuego->clear();
			VentanaJuego->draw(Win);
			VentanaJuego->display();
		}

		//-----------------------------------------------------------Condición de Derrota.
		while (PantallaGameOver == true) {

			VentanaJuego->clear();
			VentanaJuego->draw(GameOver);
			VentanaJuego->display();
		}
	}
}

void Juego::setrandomizarcuenta() { //Randomiza la cuenta matemática.

	num1 = (rand() % 9); //Defino un número al azar.
	Stringnumero = to_string(num1); //Me deposita el número en el String.
	textoNumero.setFont(font); //Define la fuente a utilizar.
	textoNumero.setScale(1.2, 1.2); //Define el tamaño del texto.
	textoNumero.setString(Stringnumero); //Define qué va a mostrar el texto.
	textoNumero.setOutlineThickness(2); //Define el grosor del borde del texto.
	textoNumero.setOutlineColor(sf::Color::Black); //Define el color del borde del texto.
	textoNumero.setPosition(284, 276); //Define la posición del texto.

	num2 = (rand() % 9); //Defino un número al azar.
	Stringnumero2 = to_string(num2); //Me deposita el número en el String.
	textoNumero2.setFont(font); //Define la fuente a utilizar.
	textoNumero2.setScale(1.2, 1.2); //Define el tamaño del texto.
	textoNumero2.setString(Stringnumero2); //Define qué va a mostrar el texto.
	textoNumero2.setOutlineThickness(2); //Define el grosor del borde del texto.
	textoNumero2.setOutlineColor(sf::Color::Black); //Define el color del borde del texto.
	textoNumero2.setPosition(353, 276); //Define la posición del texto.

	num3 = (rand() % 9); //Defino un número al azar.
	Stringnumero3 = to_string(num3); //Me deposita el número en el String.
	textoNumero3.setFont(font); //Define la fuente a utilizar.
	textoNumero3.setScale(1.2, 1.2); //Define el tamaño del texto.
	textoNumero3.setString(Stringnumero3); //Define qué va a mostrar el texto.
	textoNumero3.setOutlineThickness(2); //Define el grosor del borde del texto.
	textoNumero3.setOutlineColor(sf::Color::Black); //Define el color del borde del texto.
	textoNumero3.setPosition(425, 276); //Define la posición del texto.
}

void Juego::cargarGráficos() { //Cargo los gráficos.

	Icono.loadFromFile("Assets/Icono.png"); //Es el Icono del juego.

	img_mgr.addResourceDirectory("Assets/"); //Ubicación fuente de las imágenes.

	fondo.setTexture(img_mgr.getImage("Fondo.PNG")); //Es el Fondo.

	casita.setTexture(img_mgr.getImage("Casita.png")); //Es la "Estación".
	casita.setPosition(668, 453);//Es la posición de la "Estación".

	pregunta.setTexture(img_mgr.getImage("FondoPregunta.png")); //Es el fondo de la pregunta matemática.

	Win.setTexture(img_mgr.getImage("Win.png")); //Es el fondo de la pantalla de Victoria.

	GameOver.setTexture(img_mgr.getImage("GameOver.png")); //Es el fondo de la pantalla de Derrota.


	for (int i = 0; i < 4; i++) { //Cargo las texturas de los Vagones auxiliares.
	
		VagonesAux[i].setTexture(img_mgr.getImage("vagon.png")); //Son los Vagones.
	
	}

	VagonesAux[0].setPosition(350, 245); //Defino la posición del vagón auxiliar.
	VagonesAux[1].setPosition(520, 335); //Idem
	VagonesAux[2].setPosition(200, 425); //Idem
	VagonesAux[3].setPosition(370, 512); //Idem

	for (int i = 0; i < 4; i++) { //Cargo las texturas de las explosiones.

		Fuego[i].setTexture(img_mgr.getImage("Explosion.png")); //Es la textura de la explosión.

	}

	Fuego[0].setPosition(350, 243);//Defino la posición del fuego.
	Fuego[1].setPosition(520, 333);//Idem
	Fuego[2].setPosition(200, 423);//Idem
	Fuego[3].setPosition(370, 509);//Idem

}

void Juego::cargarSonidos() { //Carga los Sonidos del juego.

	b_ObtenerVagon.loadFromFile("Vagon.WAV"); //Es el sonido que suena cuando se obtiene un Vagón.
	s_ObtenerVagon.setBuffer(b_ObtenerVagon); //Buffer del sonido que suena cuando se obtiene un Vagón.

	b_Explosion.loadFromFile("Explosion.WAV"); //Sonido de la explosión.
	s_Explosion.setBuffer(b_Explosion);//Buffer del sonido de la explosión.

	b_fanfare.loadFromFile("Win.WAV"); //Sonido de la pantalla de Victoria.
	s_fanfare.setBuffer(b_fanfare); // Buffer del sonido de la pantalla de Victoria.

	b_GameOver.loadFromFile("GameOver.WAV"); //Sonido de la pantalla de GameOver.
	s_GameOver.setBuffer(b_GameOver); //Buffer del sonido de la pantalla de GameOver.

	musica.openFromFile("OST.WAV");//Cargo la música.
	Reloj.openFromFile("Reloj.WAV");//Idem.
}

void Juego::dibujarGraficos() { //Dibujo los gráficos.

	VentanaJuego->draw(fondo); //Dibujo el fondo.

	for (int i = 0; i < 4; i++) { //Dibujo el Fuego.
		VentanaJuego->draw(Fuego[i]);
	}

	for (int i = 0; i < 4; i++) { //Dibujo los Vagones Auxiliares.
		VentanaJuego->draw(VagonesAux[i]);
	}

	VentanaJuego->draw(Jugador1->s_tren); //Dibujo el Tren.

	Jugador1->dibujar(*VentanaJuego); //Dibujo los Vagones.

	VentanaJuego->draw(casita); //Dibujo la "Estación".

}

void Juego::colisiones() {

	musica.setVolume(20);//Le cambio el volumen al sonido.
	Reloj.setVolume(0);//Idem

	FloatRect colisionTren = Jugador1->s_tren.getGlobalBounds(); //Defino los Bounds del Tren.
	FloatRect colisionCasita = casita.getGlobalBounds(); //Defino los Bounds de la "Estación"
	FloatRect colisionVagonesAux[4]; //Defino los Bounds de los Vagones Auxiliares.


	for (int i = 0; i < 4; i++) { //Obtengo los valores de todos los Vagones.
		colisionVagonesAux[i] = VagonesAux[i].getGlobalBounds();
	}

	tiempoInicio = reloj.getElapsedTime().asSeconds() + tiempoJuego; //Inicia el reloj.

	setrandomizarcuenta(); //Randomiza la suma.
	setgenerarResultadoSuma(); //Genera el resultado de la suma de los 3 números al azar.


	//Todas las colisiones funcionan de igual manera, por lo tanto explicaré sólo la primera. :P
	while (colisionTren.intersects(colisionVagonesAux[0]) && PosicionesVagonesAux == 0) { //Cuando se colisiona con el Vagón Auxiliar.
		
		actualizarContador(); //Inicia el contador.

		preguntaMatematica(); //Se muestra la pantalla de pregunta matemática.

		if (NumeroIngresado == NumeroResultado) { //Si el numero que ingresamos es igual al resultado real.
		
			Jugador1->s_tren.setPosition(255, 245); //Acomoda el Tren.
		}
	}

	setVaciarRespuesta(); //Vacío la respuesta para la próxima colisión.

	while (colisionTren.intersects(colisionVagonesAux[1]) && PosicionesVagonesAux == 1) {

		actualizarContador();

		preguntaMatematica();

		if (NumeroIngresado == NumeroResultado) {

			Jugador1->s_tren.setPosition(255, 335);
		}
	}

	while (colisionTren.intersects(colisionVagonesAux[2]) && PosicionesVagonesAux == 2) {

		actualizarContador(); 

		preguntaMatematica();

		if (NumeroIngresado == NumeroResultado) {

			Jugador1->s_tren.setPosition(255, 425);
		}
	}

	while (colisionTren.intersects(colisionVagonesAux[3]) && PosicionesVagonesAux == 3) {

		actualizarContador();

		preguntaMatematica();

		if (NumeroIngresado == NumeroResultado) {

			Jugador1->s_tren.setPosition(255, 515);

		}
	}

	if(colisionTren.intersects(colisionCasita) && Jugador1->s_tren.getPosition().y == 515) { //Si se colisiona con la "Estación".
	
		musica.stop(); //Detiene la música.
		Reloj.stop(); //Idem.
		s_fanfare.play(); //Reproduce la música de Victoria.
		PantallaWin = true; //Se muestra la pantalla de Victoria.
		GameOn = false; //Se termina el Loop principal.
	}
}

void Juego::setgenerarResultadoSuma() { //Realiza la suma de los números randomizados.

	resultado = (num1 + num2 + num3); //El resultado es igual a la suma de los 3 números.

	NumeroResultado = to_string(resultado); //Me deposita el número en el String.

}

void Juego::setVaciarRespuesta() {//Limpia la respuesta una vez que ya se ha respondido una vez.

	NumeroIngresado = ""; //Vacío el String.
	TextoNumeroIngresado.setString(NumeroIngresado); //Defino el Sting.
	TextoNumeroIngresado.setFont(font); //Define la fuente a utilizar.
	TextoNumeroIngresado.setScale(1.2, 1.2); //Define el tamaño del texto.
	TextoNumeroIngresado.setOutlineThickness(2); //Define el grosor del borde del texto.
	TextoNumeroIngresado.setOutlineColor(sf::Color::Black); //Define el color del borde del texto.
	TextoNumeroIngresado.setPosition(500, 276); //Posicion del texto.

}

void Juego::EventosJuego() { //Son los eventos del juego.

	while (VentanaJuego->pollEvent(eventos)) {

		if (eventos.type == sf::Event::Closed) { //Permite cerrar la ventana.
			VentanaJuego->close();
		}

		if (eventos.type == sf::Event::TextEntered) //Detecta lo que se excribe.
		{
			NumeroIngresado += eventos.text.unicode; //Paso el número ingresado a texto.
			TextoNumeroIngresado.setString(NumeroIngresado);//Defino el String.
			TextoNumeroIngresado.setFont(font); //Define la fuente a utilizar.
			TextoNumeroIngresado.setScale(1.2, 1.2); //Define el tamaño del texto.
			TextoNumeroIngresado.setOutlineThickness(2); //Define el grosor del borde del texto.
			TextoNumeroIngresado.setOutlineColor(sf::Color::Black); //Define el color del borde del texto.
			TextoNumeroIngresado.setPosition(500, 276); //Posicion del texto.
		}
	}
}
	
void Juego::preguntaMatematica(){ //Ventana que muestra la pregunta matemática.
	
	VentanaJuego->clear(); //Limpio la ventana.

	VentanaJuego->draw(pregunta); //Es la ventana donde se realiza la pregunta.

	VentanaJuego->draw(textoNumero); //Numero al azar 1
	VentanaJuego->draw(textoNumero2); //Numero al azar 2
	VentanaJuego->draw(textoNumero3); //numero al azar 3

	VentanaJuego->draw(textoContador); //Es el texto del reloj.

	VentanaJuego->draw(TextoNumeroIngresado); //Es el texto de nuestra respuesta.

	VentanaJuego->display(); //Muestro lo dibujado.

	EventosJuego(); //Son los eventos del juego.


	if (NumeroIngresado == NumeroResultado) { //Si el nuestra respuesta es correcta.

		s_ObtenerVagon.play(); //Se reproduce el sonido del Vagón obtenido.

		Jugador1->Insertar((rand() % 10), PosicionesTren); //Inserto un vagón con un número al azar, en cierta posición.

		VagonesAux[PosicionesVagonesAux].setPosition(-200, -200); //Hago "desaparecer" el Vagón Auxiliar.
		Fuego[PosicionesVagonesAux].setPosition(-300, -343); //Hago "desaparecer" el fuego.

		PosicionesTren += 1; //Le sumo a las posibles posiciones del Tren.
		PosicionesVagonesAux += 1; //Le sumo a las posiciones de los Vagones Auxiliares.
	}
}

void Juego::actualizarContador() { //Es el Contador/Reloj. Sacado de los apuntes anteriores y modificado para este TP.

	musica.setVolume(10); //Le bajo el sonido a la música.
	Reloj.setVolume(70); //Le subo el sonido a la música.

	tiempoFin = reloj.getElapsedTime().asSeconds(); //Hago correr el reloj.

	int seconds = ((int)(tiempoInicio - tiempoFin)); //Son los segundos transcurridos.

	if (seconds >= 0) { //Muestra el tiempo.

		char buffer[20];
		sprintf_s(buffer, "Tiempo: %i", seconds);
		textoContador.setString(buffer);
	}

	else { //Si se termina el tiempo.

		s_Explosion.play(); //Se reproduce el sonido de la explosión.

		if (Jugador1->Vagones != NULL) { //Si el Vagón no es NULL.

			if (Jugador1->cantidadVagones > 1) {
				
				Vagon* actual = Jugador1->Vagones;

				while(actual != NULL)
				{
					auxiliar2 = actual->getNumero();

					actual = actual->siguiente;
				}
				
				Jugador1->Eliminar(auxiliar2);
			}

			else if (Jugador1->cantidadVagones == 1) { //Si tan solo me queda un Vagón, directamente borro el primer Vagón.

				Jugador1->Eliminar(Jugador1->Vagones->getNumero()); //Borro el vagón.

			}
			
			VagonesAux[PosicionesVagonesAux].setPosition(-200, -200);//"Escondo" el Vagón Auxiliar.
			PosicionesTren -= 1; //Le resto a las posibles posiciones de los Vagones.
			PosicionesVagonesAux += 1; //Le sumo a las posibles posiciones de los Vagones Auxiliares.
			Jugador1->s_tren.setPosition(255, Jugador1->s_tren.getPosition().y); //Acomodo el Tren.
		}

		else {  //Si no quedan más Vagones para eliminar.

			musica.stop(); //Detiene la música.
			Reloj.stop(); //Idem.

			s_GameOver.play(); //Reproduce la música de Game Over.

			PosicionesVagonesAux += 1; //Le sumo a las posibles posiciones de los Vagones Auxiliares.

			GameOn = false; //Termino el Loop Principal del Juego.
			PantallaGameOver = true; //Inicio la pantalla de Game Over.
		}
	}
}

void Juego::movimientoTren() { //Es el movimiento del Tren. Basicamente los Vagones "siguen" a la Locomotora.

	Vagon* actual = Jugador1->Vagones;

	if (Jugador1 != NULL && Jugador1->s_tren.getPosition().x > -2000) //Siempre que los elementos se mantengan dentro de ese rango, se moverán.
	{
		Jugador1->s_tren.setPosition(Jugador1->s_tren.getPosition().x + 3, Jugador1->s_tren.getPosition().y); //Defino la velocidad en la que se moverá el Tren.

		while (actual != NULL) { //Mientras exista un Vagón.

			actual->s_vagon.setPosition(actual->s_vagon.getPosition().x + 3, Jugador1->s_tren.getPosition().y); //Defino la velocidad en la que se moverán los Vagones.


				while (piso1 == true && actual->s_vagon.getPosition().x > 1600) { //Manejo los primeros dos pisos de los Vagones.
					actual->s_vagon.setPosition(-200, 245);
						if (actual->s_vagon.getPosition().x == 1600) {
						piso1 = false;
						}
				}

				while (piso2 == true && actual->s_vagon.getPosition().x > 1600) {

					actual->s_vagon.setPosition(-200, 335);
				}

			actual = actual->siguiente;

		}

	}


	if (Jugador1 != NULL && Jugador1->s_tren.getPosition().x > 1600 && piso == 0) { //A partir de acá, defino las posiciones nuevas cada vez que se cambie de Piso.
		piso = 1;
	}


	if (piso == 1 && Jugador1->s_tren.getPosition().x > 1600) {

		Jugador1->s_tren.setPosition(-200, 245);
		piso = 2;
	}

	if (piso == 2 && Jugador1->s_tren.getPosition().x > 1600) {

		Jugador1->s_tren.setPosition(-200, 335);
		piso = 3;
	}

	if (piso == 3 && Jugador1->s_tren.getPosition().x > 1600) {

		Jugador1->s_tren.setPosition(-200, 425);
		piso = 4;
	}

	if (piso == 4 && Jugador1->s_tren.getPosition().x > 1600) {

		Jugador1->s_tren.setPosition(-200, 515);
		piso = 5;
	}

}