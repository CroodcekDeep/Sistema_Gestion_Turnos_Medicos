#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../Doctor/doctor.h"
#include "../Valoracion/valoracion.h"


int seleccionarDoctor() {
    printf("Seleccione un doctor:\n");
    visualizarDoctores();

    int seleccionDoctor;
    do {
        printf("Ingrese el número del doctor seleccionado: ");
        scanf("%d", &seleccionDoctor);
    } while (!(seleccionDoctor >= 1 && seleccionDoctor <= 3));

    return seleccionDoctor;
}

int seleccionarDia() {
    printf("Seleccione un día de la semana:\n");
    printf("1. Lunes\n2. Martes\n3. Miércoles\n4. Jueves\n5. Viernes\n");

    int seleccionDia;
    do {
        printf("Ingrese el número del día seleccionado: ");
        scanf("%d", &seleccionDia);
    } while (!(seleccionDia >= 1 && seleccionDia <= 5));

    return seleccionDia;
}

int seleccionarHorario() {
    printf("Seleccione un horario de atención (desde las 09:00 hasta las 16:00):\n");
    printf("1. 09:00 - 10:00\n2. 10:00 - 11:00\n3. 11:00 - 12:00\n4. 12:00 - 13:00\n5. 13:00 - 14:00\n");
    printf("6. 14:00 - 15:00\n7. 15:00 - 16:00\n");

    int seleccionHorario;
    do {
        printf("Ingrese el número del horario seleccionado: ");
        scanf("%d", &seleccionHorario);
    } while (!(seleccionHorario >= 1 && seleccionHorario <= 7));

    return seleccionHorario;
}

void visualizarTurno(int doctor, int dia, int horario) {
    char **doctores = obtenerDoctores();
    printf("\nVisualización final:\n");
    printf("Nombre del Doctor:\n%s\n", doctores[doctor - 1]);
    printf("Día: ");
    switch (dia) {
        case 1:
            printf("Lunes");
            break;
        case 2:
            printf("Martes");
            break;
        case 3:
            printf("Miércoles");
            break;
        case 4:
            printf("Jueves");
            break;
        case 5:
            printf("Viernes");
            break;
    }
    printf("\nHorario: ");
    switch (horario) {
        case 1:
            printf("09:00 - 10:00");
            break;
        case 2:
            printf("10:00 - 11:00");
            break;
        case 3:
            printf("11:00 - 12:00");
            break;
        case 4:
            printf("12:00 - 13:00");
            break;
        case 5:
            printf("13:00 - 14:00");
            break;
        case 6:
            printf("14:00 - 15:00");
            break;
        case 7:
            printf("15:00 - 16:00");
            break;
    }
    printf("\n");
    mostrarDatosPaciente();
}

void tomarTurno() {
    system("cls");
    int seleccionDoctor = seleccionarDoctor();
    system("cls");
    int seleccionDia = seleccionarDia();
    system("cls");
    int seleccionHorario = seleccionarHorario();

    system("cls");
    if (verificarHorarioOcupado(seleccionDoctor, seleccionDia, seleccionHorario)) {
        printf("El horario seleccionado ya está ocupado. Por favor, seleccione otro horario.\n");
        return;
    }

    marcarHorarioOcupado(seleccionDoctor, seleccionDia, seleccionHorario);

    system("cls");
    visualizarTurno(seleccionDoctor, seleccionDia, seleccionHorario);
}

void pacienteMenu() {
    system("cls");
    datosPaciente();
    system("pause");
    system("cls");
    mostrarDatosPaciente();
    system("pause");
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
                system("cls");
                visualizarDoctores();
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                tomarTurno();
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                valorarServicio();
                system("pause");
                system("cls");
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
