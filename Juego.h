#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream> 
#include <cstdlib>
#include "imageManager.h"
#include "Vagon.h"
#include "Tren.h"

using namespace std;
using namespace sf;

//----------------------------------------Clase "Juego". Basicamente maneja el funcionamiento del juego.

class Juego {

private:

	RenderWindow* VentanaJuego; //Es la ventana del juego.

	imageManager img_mgr;//Se crea una instancia del objeto imageManager.

	Image Icono; //Es el Icono del juego.

	Sprite fondo; //Sprite del fondo.
	Sprite casita; //Sprite de la "Estaci�n".
	Sprite pregunta; //Pantalla donde se hace la pregunta matem�tica
	Sprite Win; //Pantalla de Victoria.
	Sprite GameOver; //Pantalla de Game over.
	Sprite Fuego[4]; //Sprites del fuego.
	Sprite VagonesAux[4]; //Son los Sprites de los vagones ANTES de que se unan al Tren.

	Event eventos; //Eventos del juego

	bool GameOn = true; //Bool de inicio del juego.
	bool PantallaWin = false; //Bool de la condici�n de Victoria.
	bool PantallaGameOver = false; //Bool de Game Over
	bool piso1 = true; //Piso donde se mueven los vagones.
	bool piso2 = true; //Piso donde se mueven los vagones.

	Tren * Jugador1 = NULL; // Instancia del Tren.
	
	int PosicionesTren = 3; //Son las posiciones de los Vagones que se ir�n agregando.
	int PosicionesVagonesAux = 0; //Son las Posiciones de los Vagones ANTES de que se unan al Tren.
	int piso; //Piso donde se mueve el tren.
	int num1; //Numero al azar 1.
	int num2; //Numero al azar 2.
	int num3; //Numero al azar 3.
	int resultado; //Resultado de la suma de los n�meros al azar.
	int auxiliar2; //Auxiliar que permite almacenar los valores num�ricos del Nodo.

	const int tiempoJuego = 6; //Tiempo que dura el juego. Puse 6 para que arranque desde el 5 completo en la pantalla.

	float tiempoInicio; //Inicio del tiempo.
	float tiempoFin; //Fin del tiempo.

	sf::Text textoContador; // Es el texto del contador de tiempo.
	sf::String StringContador; //String que contiene el texto del Contador.
	sf::Clock reloj; //Es el reloj del juego.

	Font font; //Es la fuente del texto.

	sf::Text TextoNumeroIngresado;//Es el texto que contiene el n�mero ingresado por el jugador.
	sf::String NumeroIngresado; //String que contiene el n�mero ingresado por el jugador.
	sf::Text TextoNumeroResultado; //Es el texto que contiene el n�mero del resultado de la suma de los n�meros al azar.
	sf::String NumeroResultado; //String que contiene el resultado de la suma de los n�meros al azar.
	sf::Text textoNumero; //Es el texto que muestra al n�mero al azar 1.
	sf::String Stringnumero; //String que contiene al n�mero al azar 1.
	sf::Text textoNumero2; //Es el texto que muestra al n�mero al azar 2.
	sf::String Stringnumero2; //String que contiene al n�mero al azar 2.
	sf::Text textoNumero3; //Es el texto que muestra al n�mero al azar 3.
	sf::String Stringnumero3; //String que contiene al n�mero al azar 3.

	sf::SoundBuffer b_ObtenerVagon; //Buffer del sonido que suena cuando se obtiene un vag�n.
	sf::Sound s_ObtenerVagon; //Sonido que suena cuando se obtiene un vag�n
	sf::SoundBuffer b_Explosion; //Buffer del sonido de explosi�n.
	sf::Sound s_Explosion; //Sonido de explosi�n.
	sf::SoundBuffer b_fanfare; //Buffer del sonido de Victoria.
	sf::Sound s_fanfare; //Sonido de Victoria.
	sf::SoundBuffer b_GameOver; //Buffer del sonido de GameOver.
	sf::Sound s_GameOver; //Sonido de GameOver.

	Music musica; //M�sica del juego.
	Music Reloj; //M�sica del reloj.


public:

	Juego(Vector2f ResolucionPantalla, String TituloJuego); //Constructor.
	void LoopJuego(); //Loop principal del juego.
	void cargarGr�ficos(); //Carga los gr�ficos del juego.
	void cargarSonidos(); //Carga los sonidos del juego.
	void dibujarGraficos(); //Dibuja los gr�ficos cargados.
	void EventosJuego(); //Son los eventos del juego.
	void movimientoTren(); //Maneja el movimiento del Tren + Vagones.
	void setrandomizarcuenta(); //Randomiza la cuenta matem�tica.
	void setgenerarResultadoSuma(); //Realiza la suma de los n�meros randomizados.
	void setVaciarRespuesta(); //Limpia la respuesta una vez que ya se ha respondido una vez.
	void preguntaMatematica(); //Ventana que muestra la pregunta matem�tica.
	void actualizarContador(); //Es el reloj/contador en reversa.
	void colisiones(); //Colisiones del juego.

};