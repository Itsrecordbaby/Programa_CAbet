#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Creacion de las funciones y su declaracion
int menumostrar(int flag, int alumnosMatri[5][7][2]);
void op1(int alumnosMatri[5][7][2]);
void op2(int alumnosMatri[5][7][2]);
void op3(int alumnosMatri[5][7][2]);

// Creacion de un arreglo unidimensional para las 7 carreras
const char *Carreras[7] = {"Ingenieria de Software","Matematicas","Ingenieria Industrial","Contabilidad","Administracion","Relaciones Internacionales","Economia"};

// Primera funcion para la primera funcion que da el anio en que ingreso la mayor cantidad de alumnos a la universidad.
void op1(int alumnosMatri[5][7][2]){
	
	int max;
	int cantmax[5] = {0};
	
	// Doble ciclo For para crear una suma de todos los alumnos que fueron matriculados cada anio
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 2; k++) {
				cantmax[i] += alumnosMatri[i][j][k];
			}
		}
	}
	
	// Uso de un ciclo For y un condicional If para encontrar el anio con una mayor cantidad de alumnos
	max = 0;
	for(int i = 1; i < 5; i++) {
		if(cantmax[i] > cantmax[max]) {
			max = i;
		}
	}
	
	// Imprime el resultado
	printf("Respuesta: El anio en que ingreso lamayor cantidad de alumnos fue %d con un total de %d alumnos\n\n", max+1, cantmax[max]);
}

//Segunda Funcion para la segunda pregunta que muestra la carrera que recibio la mayor cantidad de alumnos en el ultimo anio.
void op2(int alumnosMatri[5][7][2]){
		
		int max;
		int cantmax[7];
		
		// Doble ciclo For para crear una suma de todos los alumnos que fueron matriculados por cada materia en el ultimo anio
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 2; j++) {
				cantmax[i] = alumnosMatri[4][i][j];
			} 
		}
		
		// Encuentra la carrera con mas alumnos
		max = 0;
		for(int i = 1; i < 7; i++) {
			if(cantmax[i] > cantmax[max]) {
				max = i;
			}
		}
		
		// Imprime la respuesta
		printf("Respuesta: La Carrera que recibio la mayor cantidad de alumnos en el ultimo anio es %s con un total de %d alumnos\n\n", Carreras[max], cantmax[max]);
	}
		//Tercera Funcion para la tercera pregunta que dice el anio en que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos
		void op3(int alumnosMatri[5][7][2]){
			
			int max;
			int cantmax[5];
			
			// Doble ciclo For que suma al total de alumnos que fueron matriculados en la carrera de Ingenieria de Software en cada anio
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 2; j++) {
					cantmax[i] = alumnosMatri[i][0][j];
				} 
			}
			
			// Uso de un ciclo For y un condicional If para poder encontrar el anio con mas cantidad de alumnos en la carrera de Ingenieria de Software
			max = 0;
			for(int i = 1; i < 5; i++) {
				if(cantmax[i] > cantmax[max]) {
					max = i;
				}
			}
			
			// Imprime la respuesta
			printf("Respuesta: El anio en que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos fue el %d con %d alumnos\n\n", max+1, cantmax[max]);
			getchar();
			printf("Presione ENTER tecla para regresar al menu...");
			getchar();
			system("clear");
		}
			// Funcion que permite al  usuario ver el menu
			int menumostrar(int flag, int alumnosMatri[5][7][2]) {
				int opc, result;
				int menumostrar = 1; // Variable booleana para observar el menu
				
				// Uso de la variable booleana menumostrar para que cuando sea verdadera, muestre el menu
				while (menumostrar) {
					printf("------------------Bienvenido-------------------\n");
					printf("Seleccione una de las opciones:\n 1. El ano en que ingreso la mayor cantidad de alumnos a la universidad.\n 2.La Carrera que recibio la mayor cantidad de alumnos en el ultimo anio.\n 3.Ano en que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos\n 4. Salir del programa\n");
					result = scanf("%d", &opc);
					
					// En caso de que la entrada ingresada no sea correcta, se limpia el buffer de entrada y se le pide que ingrese de nuevo otro dato
					while (result != 1) {
						while (getchar() != '\n'); // Se encarga de limpiar el buffer de entrada
						
						printf("\nOpcion incorrecta. Ingrese un numero de nuevo: ");
						result = scanf("%d", &opc);
					}
					
					// Dependiendo de la eleccion elegida por el usuario, se llama a una de las funciones o el programa finaliza
					switch (opc) {
					case 1:
						menumostrar = 0; // Se deja de visualizar el menu
						op1(alumnosMatri);
						break;
					case 2:
						menumostrar = 0; // Se deja de visualizar el menu
						op2(alumnosMatri);
						break;
					case 3:
						menumostrar = 0; // Se deja de visualizar el menu
						op3(alumnosMatri);
						break;
					case 4:
						menumostrar = 0; // Se deja de visualizar el menu
						flag = 0;
						break;
					default:
						printf("\nRespuesta invalida. Ingrese de nuevo\n");
						break;
					}
					
					// Se limpia la pantalla despues de mostrar la respuesta
					getchar();
					printf("Presione ENTER para regresar al menu...");
					getchar();
					system("clear");
				}
				
				return flag;
			}

int main(){
	
	int flag = 1;
	
	// Se inicializan los numeros aleatorios
	srand(time(NULL));
	
	int alumnosMatri[5][7][2];
	
	// Uso de triple ciclo For para rellenar la matriz de alumnos matriculados con los datos generados por elcomando rand()
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			for (int k = 0; k < 2; k++) {
				alumnosMatri[i][j][k] = rand()%101;
			}
		}
	}
	
	// Se pone en pantalla el menu hasta que el usuario decida cerrar el programa
	while (flag) {
		flag = menumostrar(flag, alumnosMatri);
	}
	
	return 0;
}