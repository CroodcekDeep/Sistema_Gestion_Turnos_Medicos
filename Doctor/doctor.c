#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **arregloDoctores() {
    FILE *archivo = fopen("../Archivos/doctores.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo doctores.txt\n");
        return NULL;
    }

    // Contar la cantidad de doctores en el archivo
    int numDoctores = 0;
    char linea[500];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (strstr(linea, "Nombre y Apellidos: ") != NULL) {
            numDoctores++;
        }
    }
    rewind(archivo);

    // Crear el arreglo dinámico para almacenar los nombres y apellidos
    char **doctores = (char **) malloc(numDoctores * sizeof(char *));
    if (doctores == NULL) {
        printf("Error al asignar memoria para el arreglo de doctores.\n");
        fclose(archivo);
        return NULL;
    }

    // Leer el archivo y guardar los nombres y apellidos en el arreglo
    int i = 0;
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (strstr(linea, "Nombre y Apellidos: ") != NULL) {
            char *nombreApellido = strchr(linea, ':') + 2;
            nombreApellido[strcspn(nombreApellido, "\n")] = '\0'; // Eliminar el salto de línea
            doctores[i] = strdup(nombreApellido);
            i++;
        }
    }

    fclose(archivo);
    return doctores;
}


void visualizarDoctores() {
    FILE *archivo = fopen("../Archivos/doctores.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo doctores.txt\n");
        return;
    }

    printf("Lista de doctores:\n");

    char linea[500];
    int numDoctor = 1;
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (strcmp(linea, "\n") == 0) {
            continue;
        } else if (strstr(linea, "Nombre y Apellidos: ") != NULL) {
            printf("%d. Doctor/a:\n", numDoctor);
            printf("%s", linea);
        } else {
            printf("%s", linea);
        }

        if (strstr(linea, "Especialidad: ") != NULL) {
            numDoctor++;
        }
    }

    printf("No se encontraron mas líneas en el archivo.\n");

    fclose(archivo);
}

void doctorMenu() {
    system("cls");
    int opcion;
    do {
        printf("\n-- Menu Doctor --\n");
        printf("1. Visualizar informacion de los doctores\n");
        printf("2. Visualizar turnos tomados\n");
        printf("3. Regresar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                system("cls");
                visualizarDoctores();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                visualizarTurnosDoctor();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("Saliendo del menu Doctor...\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                system("cls");
                break;
        }
    } while (opcion != 3);
}
