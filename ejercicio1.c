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
#include <stdlib.h>


typedef struct{

	char nombre[21];
	char clase[11];
	int nivel;
	int vida;
	int poder_ataque;
	int capacidad_defensa;
	int habilidad_magia;

}Personaje;

int insert_character(Personaje personaje);
int read_file();
int get_level_media(int nivel, int valor_contador);
int insert_characters_level(Personaje * array_personajes, int valor_contador);
int read_fileLevels();

//Metodo para insertar un personaje en txt
int insert_character(Personaje personaje){
	
	FILE *file = fopen("personajes.txt", "a");
	
	if(file == NULL){
		printf("Error al abrir el file.\n");
		return 1;
	}
	
	fprintf(file, "%s %s %d %d %d %d %d", personaje.nombre, personaje.clase, personaje.nivel, personaje.vida, personaje.poder_ataque, personaje.capacidad_defensa,  personaje.habilidad_magia);
	
	fclose(file);
	return 0;
}

//Metodo para leer los personajes del txt
int read_file(){
	
	FILE *file = fopen("personajes.txt", "r");
	
	if(file == NULL){
		printf("Lo sentimos, no se pudo leer, el archivo esta vacío");
		return 1;
	}
	
	Personaje *personajes_mayor_siete = NULL; //Inicializo a null ya que para crear un array donde guardar los registros cuyo nivel > 7 necesito tener un cuantificador que se declara mas abajo 

	
	Personaje p;
	int contador = 0; //Contador registros normal
	int contador_mayor_siete = 0; //Contador registros nivel > 7
	int valor_niveles = 0;
	
	
	while(fscanf(file, "%s %s %d %d %d %d %d", p.nombre, p.clase, &p.nivel, &p.vida, &p.poder_ataque, &p.capacidad_defensa, &p.habilidad_magia) == 7){ //Bucle que muestra los resultados del txt por consola
		
		printf("Nombre: %s, Clase: %s, Nivel: %d, HP: %d, ATK: %d, DEF: %d, MAG: %d \n", p.nombre, p.clase, p.nivel, p.vida, p.poder_ataque, p.capacidad_defensa, p.habilidad_magia);
		contador++;
		valor_niveles += p.nivel; //Variable para realizar la media mas adelante

		if(p.nivel > 7){
			
			personajes_mayor_siete = realloc(personajes_mayor_siete, (contador_mayor_siete + 1) * sizeof(Personaje)); //Realloc para reasignar memoria en funcion de los registros que cumplan la condicion, que se vaya encontrando
			
			if(personajes_mayor_siete == NULL){
				printf("Error al redimensionar memoria");
				return 1;
			}
			
			personajes_mayor_siete[contador_mayor_siete] = p;
			contador_mayor_siete++;
		}
	}
	
	fclose(file);

	get_level_media(valor_niveles ,contador);
	insert_characters_level(personajes_mayor_siete, contador_mayor_siete);
	
	free(personajes_mayor_siete);
	
	return 0;
}

//Función para calcular la media de los niveles
int get_level_media(int suma_niveles, int valor_contador){
	
	if(valor_contador <= 0){
		printf("Valor del contador no válido: %d\n", valor_contador);
		return 1;
	}
	
	int *personajes_niveles = (int*)malloc(valor_contador * sizeof(int));
	
	if (personajes_niveles == NULL) {
        printf("Error de asignacion de memoria\n");
		return 1;
    }
	
	float media = (float)suma_niveles / valor_contador;  
	
	printf("\n");
	printf("Estadisticas de los personajes: \n");
	printf("Media -> %.2f\n", media); //Formateamos a 2 decimales
	
	free(personajes_niveles);  
	
	return 0;
}

//Funcion para insertar los personajes cuyo nivel > 7 encontrados en otro fichero
int insert_characters_level(Personaje *array_personajes, int valor_contador){
	
FILE * fileLevels = fopen("personajesLevel.txt", "w");
	
	if(fileLevels == NULL){
		printf("Error al abrir el archivo para escritura.\n");
		return 1;
	}
	
	for(int i = 0; i < valor_contador; i++){
		fprintf(fileLevels, "%s %s %d %d %d %d %d\n", array_personajes[i].nombre, 
		array_personajes[i].clase, array_personajes[i].nivel, array_personajes[i].vida, array_personajes[i].poder_ataque, 
		array_personajes[i].capacidad_defensa, array_personajes[i].habilidad_magia);
	}
	
	fclose(fileLevels);
		
	return 0;
}

int read_fileLevels(){
	
	FILE * fileLevels = fopen("personajesLevel.txt", "r");
	
	if(fileLevels == NULL){
		printf("Lo sentimos, no se pudo leer, el archivo esta vacío");
		return 1;
	}
	
	Personaje p;

	printf("\n");
	printf("Lista de personajes cuyo nivel >7 provenientes de personajesLevel.txt: \n");
	while(fscanf(fileLevels, "%s %s %d %d %d %d %d", p.nombre, p.clase, &p.nivel, &p.vida, &p.poder_ataque, &p.capacidad_defensa, &p.habilidad_magia) == 7){ //Bucle que muestra los resultados del txt por consola
		printf("Nombre: %s, Clase: %s, Nivel: %d, HP: %d, ATK: %d, DEF: %d, MAG: %d \n", p.nombre, p.clase, p.nivel, p.vida, p.poder_ataque, p.capacidad_defensa, p.habilidad_magia);
	}
	printf("\n");
	
	fclose(fileLevels);
	
	return 0;
}

int main (int argc, char *argv[]){
	
	Personaje personaje;	
	
	printf("----------------------------------------------------------- \n");
	printf("Bienvenido!!! Por favor, introduzca los datos de un personaje \n");
	printf("Forma -> nombre, clase, nivel, vida, ataque, defensa, magia \n");
	printf("----------------------------------------------------------- \n");
	
	scanf("%s %s %d %d %d %d %d", personaje.nombre, &personaje.clase, &personaje.nivel, &personaje.vida, &personaje.poder_ataque, &personaje.capacidad_defensa, &personaje.habilidad_magia);
	
	//VALIDACIONES
	if(strlen(personaje.nombre) > 20){
		printf("Lo sentimos, el nombre es demasiado largo (>20)");
		return 0;
	}
	
	if(strlen(personaje.clase) > 10){
		printf("Lo sentimos, la clase es demasiado larga (>20)");
		return 0;
	}
	

	/*if (personaje.nivel != 3 || personaje.vida != 3 || personaje.poder_ataque != 3 || personaje.capacidad_defensa != 3 || personaje.habilidad_magia != 3){
		printf("Lo sentimos en la parte de vida, ataque, defensa o magia, no has introducido un numero o es > 3, intentalo de nuevo.\n"); 
		return 0; REVISAR CONDICIONAL Y MIRAR PERSONAJE.CLASE 
	}*/

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
				printf("---------------------------------------------------------------------------\n");
				read_file();
				read_fileLevels();
 				return 0;
				
			}
		}
	}
}