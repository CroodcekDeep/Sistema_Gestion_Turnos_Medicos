#include <stdio.h>
#include <stdlib.h>

#include "../Doctor/doctor.h"
#include "../Valoracion/valoracion.h"

void tomarTurno() {
    printf("Tomar turno:\n");
    // Aquí va el código para tomar el turno
}

void valorarServicio() {
    system("cls");
    printf("Valoracion y comentario del servicio:\n");

    // Valoracion
    int value;
    printf("Ingresa la valoracion del 1 al 5:\n");
    scanf("%d", &value);
    setPuntuacion(value);

    // Comentario
    char comentario[100];
    fflush(stdin); // Limpiar el búfer de entrada antes de leer el comentario
    printf("Ingrese un comentario:\n");
    fgets(comentario, sizeof(comentario), stdin);
    setComment(comentario);
}

void pacienteMenu() {
    system("cls");
    int opcion;
    do {
        printf("\n-- Menu Paciente --\n");
        printf("1. Visualizar informacion de los doctores\n");
        printf("2. Tomar turno\n");
        printf("3. Valorar el servicio\n");
        printf("4. Regresar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                visualizarInformacionDoctores();
                break;
            case 2:
                tomarTurno();
                break;
            case 3:
                valorarServicio();
                break;
            case 4:
                system("cls");
                printf("Saliendo del menu Paciente...\n");
                system("pause");
                system("cls");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                system("cls");
                break;
        }
    } while (opcion != 4);
}
