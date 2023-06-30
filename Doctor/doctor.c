#include <stdio.h>
#include <stdlib.h>

void visualizarInformacionDoctores() {
    printf("Informacion de los doctores:\n");
    // Aquí va el código para mostrar la información de los doctores registrados
}

void visualizarTurnosDoctor() {
    printf("Turnos tomados por el doctor:\n");
    // Aquí va el código para mostrar los turnos tomados por el doctor
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
                visualizarInformacionDoctores();
                break;
            case 2:
                visualizarTurnosDoctor();
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
