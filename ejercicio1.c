/*
Se pide crear un programa que pueda administrar los datos de los personajes de un videojuego. 
Para ello contamos con un fichero que contiene la información de estos personajes. 
En el caso de que no exista se debe pedir al usuario la información de los personajes y guardarla en dicho fichero. 

Los datos que incluye son:
	o Nombre
	o Clase del personaje (Únicamente pueden ser de los tipos: guerrero, mago, arquero, paladín
		y rogue)
	o Nivel
	o Vida
	o Poder de ataque
	o Capacidad de defensa
	o Habilidad de magia

El formato del fichero:
	Por cada línea, se tienen los datos de un personaje:
	
Se debe mostrar por pantalla:
	- Todos los personajes leídos del fichero, 
	- La media de los niveles
	- Se deben guardar en un fichero aquellos personajes cuyo nivel sea mayor que 7.

*/

/*

1) Crear fichero que contenga la info de los personajes

2) Pedir al usuario la info de los personajes

3) Datos que debe incluir el usuario (mirar arriba)

4) Mirar foto de los datos introducidos por el usuario

*/

#include <stdio.h>
#include <string.h>


typedef enum {

	GUERRERO,
	MAGO,
	ARQUERO,
	PALADIN,
	ROGUE

}Clase;	

	
typedef struct{

	char nombre[20];
	Clase clase;
	int nivel;
	int vida;
	int poder_ataque;
	int capacidad_defensa;
	int habilidad_magia;

}Personaje;


int main (int argc, char * argv[]){
	
	Personaje personaje;	
	
	printf("----------------------------------------------------------- \n");
	printf("Bienvenido!!! Por favor, introduzca los datos de un personaje \n");
	printf("Forma -> nombre, clase, nivel, vida, ataque, defensa, magia \n");
	printf("----------------------------------------------------------- \n");
	
	scanf("%s %s %d %d %d %d %d", personaje.nombre, personaje.clase, &personaje.nivel, &personaje.vida, &personaje.poder_ataque, &personaje.capacidad_defensa, &personaje.habilidad_magia);
	
	printf("\nLos datos del personaje introducidos son:\n");
    printf("Nombre: %s\n", personaje.nombre);
    printf("Clase: %s\n", personaje.clase);
    printf("Nivel: %d\n", personaje.nivel);
    printf("Vida: %d\n", personaje.vida);
    printf("Poder de ataque: %d\n", personaje.poder_ataque);
    printf("Capacidad de defensa: %d\n", personaje.capacidad_defensa);
    printf("Habilidad de magia: %d\n", personaje.habilidad_magia);	
	
	return 0;
}