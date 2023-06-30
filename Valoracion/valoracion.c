//
// Created by ACER I7 GAMER on 26/06/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int score;
char comment[100];

void valoracionMenu() {
    system("cls");
    int opcion;
    do {
        printf("\n-- Menu Valoracion y Comentarios --\n");
        printf("1. Visualizar valoracion y comentarios de los pacientes\n");
        printf("2. Regresar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Score: %d\n", &score);
                printf("Comentario: %s\n", &comment);
                break;
            case 2:
                system("cls");
                printf("Saliendo del menu Valoracion y Comentarios...\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                system("cls");
                break;
        }
    } while (opcion != 2);
}
