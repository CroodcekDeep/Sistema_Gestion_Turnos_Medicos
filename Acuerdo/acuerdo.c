#include <stdio.h>
#include <stdlib.h>

int acuerdo() {
    int acuerdo_tratamiento_de_datos;

    do {
        system("cls");
        // Establecimiento de acuerdo de tratamiento de datos personales //
        printf(".........................................................................................."
               "...........................................\n");
        printf("ACUERDO DE TRATAMIENTO DE DATOS:\n");
        printf("La Fundacion Salud Para Todos basa el tratamiento de datos de sus usuarios bajo la Ley de "
               "Proteccion de Datos Personales instaurada en 2021 en el Ecuador.\n");
        printf("\n");
        printf("Por ello, es fundamental conocer si se encuentra o no de acuerdo que la fundacion maneje "
               "sus datos personales rigiendose en la LOPDP\n");
        printf(".........................................................................................."
               "...........................................\n");
        printf("\n");
        printf("\nPor favor digite la opcion que se aducue a su opinion:\n");
        printf("1.- Si estoy de acuerdo   --   2.- No estoy de acuerdo\n");
        printf("\nOpcion: ");
        scanf("%d", &acuerdo_tratamiento_de_datos);

        switch (acuerdo_tratamiento_de_datos) {
            case 1:
                return 1;
            case 2:
                printf("Programa finalizado.\n");
                exit(0);
            default:
                system("cls");
                printf("Opcion invalida. Intente nuevamente.\n");
                system("pause");
        }
    } while (acuerdo_tratamiento_de_datos != 1 && acuerdo_tratamiento_de_datos != 2);

    return 0;
}