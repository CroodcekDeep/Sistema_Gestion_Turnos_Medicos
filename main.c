#include <stdio.h>

#include "Doctor/doctor.h"
#include "Paciente/paciente.h"
#include "Valoracion/valoracion.h"

int main() {
    int opcion;
    do {
        printf("-- Menu Principal --\n");
        printf("1. Paciente\n");
        printf("2. Doctor\n");
        printf("3. Valoracion y Comentarios\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%i", &opcion);

        switch (opcion) {
            case 1:
                pacienteMenu();
                break;
            case 2:
                doctorMenu();
                break;
            case 3:
                valoracionMenu();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
