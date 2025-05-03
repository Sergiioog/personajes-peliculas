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


	
typedef struct{

	char nombre[20];
	char clase[10];
	int nivel;
	int vida;
	int poder_ataque;
	int capacidad_defensa;
	int habilidad_magia;

}Personaje;

int insert_character(Personaje personaje);

int insert_character(Personaje personaje){
	
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


int main (int argc, char *argv[]){
	
	Personaje personaje;	
	
	printf("----------------------------------------------------------- \n");
	printf("Bienvenido!!! Por favor, introduzca los datos de un personaje \n");
	printf("Forma -> nombre, clase, nivel, vida, ataque, defensa, magia \n");
	printf("----------------------------------------------------------- \n");
	
	scanf("%s %s %d %d %d %d %d", personaje.nombre, &personaje.clase, &personaje.nivel, &personaje.vida, &personaje.poder_ataque, &personaje.capacidad_defensa, &personaje.habilidad_magia);
	
	int personaje_guardado = insert_character(personaje);
	
	while(1){
		
		if(personaje_guardado == 0){
			printf("Personaje guardado con exito!!! Si desea continuar, pulse 0, si no, pulse 1: \n");
			int respuestaUsuario;
			scanf("%d", &respuestaUsuario);
			printf("--------------------------------------------------------------------------------\n");
			
			if(respuestaUsuario == 0){
				
				printf("Por favor, introduzca los datos de su nuevo personaje: \n");
				printf("Forma -> nombre, clase, nivel, vida, ataque, defensa, magia \n");
				scanf("%s %s %d %d %d %d %d", personaje.nombre, &personaje.clase, &personaje.nivel, &personaje.vida, &personaje.poder_ataque, &personaje.capacidad_defensa, &personaje.habilidad_magia);
				insert_character(personaje);
			
			}else{
				
				printf("Gracias por participar!! Hasta la proxima \n");
				printf("------------------------------------------\n");
				printf("Lista de personajes: \n");
				printf("Estadísticas de los personajes: \n");
				return 0;
				
			}
		}
	
	}
}