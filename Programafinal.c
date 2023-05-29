#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define NUM_ANIOS 5
#define NUM_CARRERAS 7
#define NUM_GENEROS 2

const char *Carreras[NUM_CARRERAS] = {"Ingenieria de Software","Matematicas","Ingenieria Industrial","Contabilidad","Administracion","Relaciones Internacionales","Economia"};

void calcularMax(int cantmax[], int size, int *maxIndex, int *maxValue){
    *maxIndex = 0;
    for(int i = 1; i < size; i++) {
        if(cantmax[i] > cantmax[*maxIndex]) {
            *maxIndex = i;
        }
    }
    *maxValue = cantmax[*maxIndex];
}

void op1(int alumnosMatri[NUM_ANIOS][NUM_CARRERAS][NUM_GENEROS]){
    int maxIndex, maxValue;
    int cantmax[NUM_ANIOS] = {0};

    for (int i = 0; i < NUM_ANIOS; i++) {
        for (int j = 0; j < NUM_CARRERAS; j++) {
            for (int k = 0; k < NUM_GENEROS; k++) {
                cantmax[i] += alumnosMatri[i][j][k];
            }
        }
    }

    calcularMax(cantmax, NUM_ANIOS, &maxIndex, &maxValue);

    printf("Respuesta: El anio en que ingreso la mayor cantidad de alumnos fue %d con un total de %d alumnos\n\n", maxIndex+1, maxValue);
}

void op2(int alumnosMatri[NUM_ANIOS][NUM_CARRERAS][NUM_GENEROS]){
    int maxIndex, maxValue;
    int cantmax[NUM_CARRERAS] = {0};

    for (int i = 0; i < NUM_CARRERAS; i++) {
        for (int j = 0; j < NUM_GENEROS; j++) {
            cantmax[i] = alumnosMatri[NUM_ANIOS-1][i][j];
        }
    }

    calcularMax(cantmax, NUM_CARRERAS, &maxIndex, &maxValue);

    printf("Respuesta: La Carrera que recibio la mayor cantidad de alumnos en el ultimo anio es %s con un total de %d alumnos\n\n", Carreras[maxIndex], maxValue);
}

void op3(int alumnosMatri[NUM_ANIOS][NUM_CARRERAS][NUM_GENEROS]){
    int maxIndex, maxValue;
    int cantmax[NUM_ANIOS] = {0};

    for (int i = 0; i < NUM_ANIOS; i++) {
        for (int j = 0; j < NUM_GENEROS; j++) {
            cantmax[i] = alumnosMatri[i][0][j];
        }
    }

    calcularMax(cantmax, NUM_ANIOS, &maxIndex, &maxValue);

    printf("Respuesta: El anio en que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos fue el %d con %d alumnos\n\n", maxIndex+1, maxValue);
}

int menumostrar(int flag, int alumnosMatri[NUM_ANIOS][NUM_CARRERAS][NUM_GENEROS]) {
    int opc, result;

    do {
        printf("------------------Bienvenido-------------------\n");
        printf("Seleccione una de las opciones:\n 1. El ano en que ingreso la mayor cantidad de alumnos a la universidad.\n 2.La Carrera que recibio la mayor cantidad de alumnos en el ultimo anio.\n 3.Ano en que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos\n 4. Salir del programa\n");
        result = scanf("%d", &opc);

        while (result != 1) {
            while (getchar() != '\n');
            printf("\nOpcion incorrecta. Ingrese un numero de nuevo: ");
            result = scanf("%d", &opc);
        }

        switch (opc) {
        case 1:
            op1(alumnosMatri);
            break;
        case 2:
            op2(alumnosMatri);
            break;
        case 3:
            op3(alumnosMatri);
            break;
        case 4:
            flag = 0;
            break;
        default:
            printf("\nRespuesta invalida. Ingrese de nuevo\n");
            break;
        }

        getchar();
        printf("Presione ENTER para regresar al menu...");
        getchar();
        system("clear");
    } while (flag);

    return flag;
}

int main(){

    srand(time(NULL));

    int flag = 1;
    int alumnosMatri[NUM_ANIOS][NUM_CARRERAS][NUM_GENEROS];

    for (int i = 0; i < NUM_ANIOS; i++) {
        for (int j = 0; j < NUM_CARRERAS; j++) {
            for (int k = 0; k < NUM_GENEROS; k++) {
                alumnosMatri[i][j][k] = rand()%101;
            }
        }
    }

    while (flag) {
        flag = menumostrar(flag, alumnosMatri);
    }

    return 0;
}