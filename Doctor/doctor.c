#include <stdio.h>
#include <stdlib.h>

char **obtenerDoctores() {
    static char *doctores[] = {
            // Doctor A
            "\tNombre y Apellidos: Dr. John Smith\n"
            "\tCorreo: doctora@example.com\n"
            "\tTelefono: +1234567890 ext. 123\n"
            "\tEspecialidad: Cardiologia",

            // Doctor B
            "\tNombre y Apellidos: Dr. Maria Garcia\n"
            "\tCorreo: doctorb@example.com\n"
            "\tTelefono: +0987654321 ext. 456\n"
            "\tEspecialidad: Dermatologia",

            // Doctor C
            "\tNombre y Apellidos: Dr. David Johnson\n"
            "\tCorreo: doctorc@example.com\n"
            "\tTelefono: +1112223333 ext. 789\n"
            "\tEspecialidad: Pediatria"
    };

    return doctores;
}

void visualizarDoctores() {
    char **doctores = obtenerDoctores();

    printf("Lista de doctores:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, doctores[i]);
    }
}

void visualizarTurnosDoctor() {

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
