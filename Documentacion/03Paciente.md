# Archivo Paciente

## Source Code

El código que has compartido es un programa en lenguaje C que permite a los pacientes interactuar con un sistema de
doctores y turnos. A continuación, se realiza una explicación detallada de cada parte del código:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../Doctor/doctor.h"
#include "../Valoracion/valoracion.h"
```

Estas líneas de código incluyen los archivos de encabezado necesarios para el programa. `<stdio.h>` es necesario para la
entrada y salida estándar, `<stdlib.h>` para la gestión de memoria dinámica, `<stdbool.h>` para utilizar el tipo de
datos `bool` y `<string.h>` para las funciones de manipulación de cadenas. Además, se incluyen los archivos de
encabezado "doctor.h" y "valoracion.h" que contienen las declaraciones de funciones relacionadas con doctores y
valoraciones respectivamente.

```c
bool horariosOcupados[NUM_DOCTORES][5][7] = {false};
```

Esta línea declara una matriz tridimensional `horariosOcupados` de tipo `bool`. Esta matriz se utiliza para realizar un
seguimiento de los horarios ocupados por los doctores. Tiene dimensiones `[NUM_DOCTORES][5][7]`, donde `NUM_DOCTORES` es
una constante definida anteriormente y representa el número total de doctores. Los índices de la matriz representan el
número de doctor, el día de la semana y el horario respectivamente. Inicialmente, todos los valores de la matriz se
establecen en `false`, lo que indica que todos los horarios están disponibles.

```c
char nombre[50];
char apellido[50];
char genero[10];
int edad;
```

Estas variables globales se utilizan para almacenar los datos del paciente, incluyendo su nombre, apellido, género y
edad.

Claro, a continuación proporcionaré el código completo de cada función y luego explicaré en detalle su funcionamiento:

### Función `datosPaciente()`

```c
void datosPaciente() {
    printf("\n-- Registrese --\n");

    printf("Ingrese el nombre del paciente: ");
    scanf("%s", nombre);

    printf("Ingrese el apellido del paciente: ");
    scanf("%s", apellido);

    printf("Ingrese el género del paciente: ");
    scanf("%s", genero);

    printf("Ingrese la edad del paciente: ");
    scanf("%d", &edad);
}
```

Esta función solicita al paciente que ingrese sus datos personales, como nombre, apellido, género y edad. Sin embargo,
el código real para leer los datos desde la entrada estándar está ausente. La función debería utilizar la
función `printf` para mostrar mensajes en la consola y la función `scanf` para leer los datos ingresados por el usuario.
Luego, los datos se almacenarían en las variables globales `nombre`, `apellido`, `genero` y `edad`.

### Función `mostrarDatosPaciente()`

```c
void mostrarDatosPaciente() {
    printf("\nDatos del paciente:\n");
    printf("\tNombre: %s\n", nombre);
    printf("\tApellido: %s\n", apellido);
    printf("\tGénero: %s\n", genero);
    printf("\tEdad: %d\n", edad);
}
```

Esta función muestra en la consola los datos del paciente almacenados en las variables
globales `nombre`, `apellido`, `genero` y `edad`. Utiliza la función `printf` para mostrar los datos en un formato
legible.

### Función `seleccionarDoctor()`

```c
int seleccionarDoctor() {
    printf("Seleccione un doctor:\n");
    visualizarDoctores();

    int seleccionDoctor;
    do {
        printf("Ingrese el número del doctor seleccionado: ");
        scanf("%d", &seleccionDoctor);
    } while (!(seleccionDoctor >= 1 && seleccionDoctor <= NUM_DOCTORES));

    return seleccionDoctor;
}
```

Esta función muestra la lista de doctores disponibles utilizando la función `visualizarDoctores()` y solicita al usuario
que seleccione un doctor ingresando el número correspondiente. Sin embargo, el código real para leer el número de doctor
seleccionado y devolverlo como resultado está ausente. La función debería utilizar la función `scanf` para leer el
número de doctor seleccionado y luego devolver ese número.

### Función `seleccionarDia()`

```c
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
```

Esta función muestra las opciones de días de la semana y solicita al usuario que seleccione un día ingresando el número
correspondiente. Sin embargo, el código real para leer el número de día seleccionado y devolverlo como resultado está
ausente. La función debería utilizar la función `scanf` para leer el número de día seleccionado y luego devolver ese
número.

### Función `seleccionarHorario()`

```c
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
```

Esta función muestra las opciones de horarios de atención disponibles y solicita al usuario que seleccione un horario
ingres

ando el número correspondiente. Sin embargo, el código real para leer el número de horario seleccionado y devolverlo
como resultado está ausente. La función debería utilizar la función `scanf` para leer el número de horario seleccionado
y luego devolver ese número.

### Función `verificarHorarioOcupado()`

```c
bool verificarHorarioOcupado(int doctor, int dia, int horario) {
    return horariosOcupados[doctor - 1][dia - 1][horario - 1];
}
```

Esta función verifica si un horario específico está ocupado para un doctor, día y horario dados. La función utiliza la
matriz `horariosOcupados` para realizar la verificación. Sin embargo, el código real para realizar la verificación y
devolver el resultado está ausente. La función debería buscar en la matriz `horariosOcupados` el estado del horario
correspondiente y devolver `true` si está ocupado o `false` si está disponible.

### Función `marcarHorarioOcupado()`

```c
void marcarHorarioOcupado(int doctor, int dia, int horario) {
    horariosOcupados[doctor - 1][dia - 1][horario - 1] = true;
}
```

Esta función marca un horario específico como ocupado para un doctor, día y horario dados. Sin embargo, el código real
para marcar el horario como ocupado en la matriz `horariosOcupados` está ausente. La función debería actualizar el valor
correspondiente en la matriz para indicar que el horario está ocupado.

### Función `obtenerTurno()`

```c
char *obtenerTurno(int doctor, int dia, int horario) {
    char **doctores = arregloDoctores();
    char *turno = (char *) malloc(1000 * sizeof(char)); // Reservar memoria para el turno

    sprintf(turno, "\nVisualización final:\nNombre del Doctor:\n%s\nDía: ", doctores[doctor - 1]);

    switch (dia) {
        case 1:
            strcat(turno, "Lunes");
            break;
        case 2:
            strcat(turno, "Martes");
            break;
        case 3:
            strcat(turno, "Miércoles");
            break;
        case 4:
            strcat(turno, "Jueves");
            break;
        case 5:
            strcat(turno, "Viernes");
            break;
    }

    strcat(turno, "\nHorario: ");
    switch (horario) {
        case 1:
            strcat(turno, "09:00 - 10:00");
            break;
        case 2:
            strcat(turno, "10:00 - 11:00");
            break;
        case 3:
            strcat(turno, "11:00 - 12:00");
            break;
        case 4:
            strcat(turno, "12:00 - 13:00");
            break;
        case 5:
            strcat(turno, "13:00 - 14:00");
            break;
        case 6:
            strcat(turno, "14:00 - 15:00");
            break;
        case 7:
            strcat(turno, "15:00 - 16:00");
            break;
    }

    strcat(turno, "\n");

    // Agregar información del paciente
    strcat(turno, "Información del Paciente:");
    strcat(turno, "\nNombre: ");
    strcat(turno, nombre);
    strcat(turno, "\nApellido: ");
    strcat(turno, apellido);
    strcat(turno, "\nGénero: ");
    strcat(turno, genero);
    strcat(turno, "\nEdad: ");
    char edadStr[10];
    sprintf(edadStr, "%d", edad);
    strcat(turno, edadStr);
    strcat(turno, "\n");

    return turno;
}
```

Esta función crea una cadena de caracteres que representa un turno específico. Utiliza la matriz `doctores` para obtener
el nombre del doctor correspondiente al número de doctor dado. Luego, combina los datos del doctor, día, horario y
paciente en la cadena de caracteres utilizando las funciones `sprintf`, `strcat` y `sprintf`. Se reserva memoria
dinámicamente para la cadena de caracteres utilizando la función `malloc`. Finalmente, devuelve la cadena de caracteres
del turno.

### Función `guardarTurnoEnArchivo()`

```c
void guardarTurnoEnArchivo(char *turno, int numeroTurno, char *nombreDoctor) {
    char nombreArchivo[50];
    sprintf(nombreArchivo, "../Archivos/turno%02d_%s.txt", numeroTurno, nombreDoctor); // Generar el nombre del archivo

    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar el turno.\n");
        return;
    }

    fprintf(archivo, "%s", turno); // Escribir el turno en el archivo

    fclose(archivo);
}
```

Esta función genera el nombre del archivo en el que se guarda un turno específico utilizando el número de turno y el
nombre del doctor. Luego, abre el archivo en modo de escritura utilizando la función `fopen`. Si el archivo se abre
correctamente, escribe el contenido del turno en el archivo utilizando la función `fprintf`. Finalmente, cierra el
archivo
utilizando la función `fclose`.

### Función `visualizarTurno()`

```c
void visualizarTurno(int doctor, int dia, int horario) {
    char **doctores = arregloDoctores();
    char *turno = obtenerTurno(doctor, dia, horario);
    static int numeroTurno = 1; // Contador de turno
    guardarTurnoEnArchivo(turno, numeroTurno, doctores[doctor - 1]);
    printf("%s", turno); // Mostrar el turno en la consola
    system("pause");
    system("cls");
    printf("\nEl turno ha sido guardado en el archivo turno%02d_%s.txt\n", numeroTurno, doctores[doctor - 1]);
    numeroTurno++;
    free(turno); // Liberar memoria del turno
}
```

Esta función muestra en pantalla y guarda un turno específico. Recibe como parámetros el número de doctor, el día y el
horario seleccionados.

En primer lugar, se obtiene la lista de doctores utilizando la función `arregloDoctores()`. Luego, se llama a la
función `obtenerTurno()` para obtener la cadena de caracteres que representa el turno seleccionado.

A continuación, se inicializa una variable estática `numeroTurno` que sirve como contador de los turnos. Se llama a la
función `guardarTurnoEnArchivo()` para guardar el turno en un archivo de texto. El número de turno, el nombre del doctor
y la cadena de caracteres del turno se pasan como argumentos a esta función.

Después de guardar el turno, se muestra en la consola utilizando la función `printf`. Luego, se utiliza la
función `system("pause")` para pausar la ejecución del programa y esperar a que el usuario presione una tecla. Se limpia
la pantalla con la función `system("cls")` y se muestra un mensaje indicando que el turno se ha guardado en el archivo
correspondiente.

Por último, se incrementa el contador de turno `numeroTurno` y se libera la memoria reservada para la cadena de
caracteres `turno` utilizando la función `free()`.

### Función `tomarTurno()`

```c
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
```

Esta función permite al paciente seleccionar un turno. Comienza limpiando la pantalla con `system("cls")`.

Luego, se llaman a las funciones `seleccionarDoctor()`, `seleccionarDia()` y `seleccionarHorario()` para obtener el
número de doctor, día y horario seleccionados respectivamente.

Después de obtener las selecciones, se verifica si el horario seleccionado ya está ocupado utilizando la
función `verificarHorarioOcupado()`. Si el horario está ocupado, se muestra un mensaje en la consola

indicando que el horario seleccionado ya está ocupado y se retorna de inmediato.

Si el horario está disponible, se marca como ocupado utilizando la función `marcarHorarioOcupado()`.

Se limpia la pantalla con `system("cls")` y se llama a la función `visualizarTurno()` para mostrar en pantalla y guardar
el turno seleccionado.

### Función `pacienteMenu()`

```c
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
```

Esta función muestra el menú para el paciente y permite realizar diferentes acciones.

Comienza limpiando la pantalla con `system("cls")`. A continuación, se llaman a las funciones `datosPaciente()`
y `mostrarDatosPaciente()` para registrar y mostrar los datos del paciente respectivamente.

Después, se muestra el menú en un bucle `do-while`. El usuario puede seleccionar diferentes opciones ingresando un
número. Las opciones son:

1. Visualizar información de los doctores: Limpia la pantalla, llama a la función `visualizarDoctores()` para mostrar
   los datos de los doctores y pausa la ejecución del programa.
2. Tomar turno: Limpia la pantalla, llama a la función `tomarTurno()` para que el paciente seleccione un turno y pausa
   la ejecución del programa.
3. Valorar el servicio: Limpia la pantalla, llama a la función `valorarServicio()` para que el paciente valore el
   servicio y pausa la ejecución del programa.
4. Regresar: Limpia la pantalla y muestra un mensaje indicando que se está saliendo del menú del paciente. Luego, se
   pausa la ejecución del programa y se limpia la pantalla.

El bucle se repite hasta que el usuario seleccione la opción 4, momento en el cual se sale del bucle y finaliza la
función.

## Header File

Este código muestra un archivo de encabezado llamado "paciente.h" que define la interfaz de la función `pacienteMenu()`
para su uso en otros archivos de código fuente. Aquí está la explicación del código:

```c
#ifndef DOCTORES_PACIENTES_PACIENTE_H
#define DOCTORES_PACIENTES_PACIENTE_H

void pacienteMenu();

#endif //DOCTORES_PACIENTES_PACIENTE_H
```

- La primera línea `#ifndef DOCTORES_PACIENTES_PACIENTE_H` es una construcción del preprocesador que verifica si la
  macro `DOCTORES_PACIENTES_PACIENTE_H` no está definida. Si no está definida, el compilador incluirá el contenido del
  archivo de encabezado. Si está definida, el compilador omitirá el contenido del archivo de encabezado. Esta
  construcción se utiliza para evitar la inclusión duplicada de un archivo de encabezado y prevenir errores de
  redefinición.

- La línea `#define DOCTORES_PACIENTES_PACIENTE_H` define la macro `DOCTORES_PACIENTES_PACIENTE_H`, que se utiliza como
  una marca para indicar que el archivo de encabezado ya ha sido incluido.

- A continuación, se declara el prototipo de la función `pacienteMenu()`. El prototipo indica que la
  función `pacienteMenu()` existe, pero no proporciona su implementación. Esta declaración permite que otros archivos de
  código fuente utilicen la función `pacienteMenu()` sin conocer su implementación interna.

- Finalmente, la última línea `#endif //DOCTORES_PACIENTES_PACIENTE_H` marca el final del bloque condicional `#ifndef` y
  proporciona un comentario descriptivo que indica qué macro se está cerrando. Esto ayuda a mejorar la legibilidad y
  comprensión del código.

En resumen, este archivo de encabezado define la interfaz de la función `pacienteMenu()` para su uso en otros archivos
de código fuente y utiliza construcciones del preprocesador para prevenir la inclusión duplicada del archivo de
encabezado.