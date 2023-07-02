# Archivo Valoración

## Source Code

Este código muestra una implementación de valoración y comentarios de servicio en un sistema de pacientes. Aquí está la
explicación detallada del código:

```c
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
```

- En primer lugar, se incluyen las bibliotecas necesarias, como `stdio.h`, `stdlib.h` y `string.h`. Estas bibliotecas
  proporcionan las funciones estándar de entrada/salida, manejo de memoria y manipulación de cadenas, respectivamente.

```c
char valoracionPaciente[1000];
```

- Se declara una variable global llamada `valoracionPaciente` que almacena las valoraciones y comentarios de los
  pacientes. Esta variable se utiliza para almacenar múltiples valoraciones y comentarios, y se le asigna un tamaño de
  1000 caracteres.

```c
void valorarServicio() {
    system("cls");
    printf("Valoracion y comentario del servicio:\n");

    int valoracion;
    do {
        printf("Ingresa la valoracion del 1 al 5:\n");
        scanf("%d", &valoracion);
    } while (!(valoracion >= 1 && valoracion <= 5));
```

- La función `valorarServicio()` permite a los pacientes ingresar su valoración y comentario sobre el servicio. Primero,
  se utiliza la función `system("cls")` para limpiar la pantalla y luego se muestra un mensaje solicitando la
  valoración.

- Se utiliza un bucle `do-while` para solicitar al paciente que ingrese una valoración entre 1 y 5. El bucle se
  ejecutará hasta que se ingrese una valoración válida.

```c
    char comentario[100];
fflush(stdin);
printf("Ingrese un comentario:\n");
fgets(comentario, sizeof(comentario), stdin);

comentario[strcspn(comentario, "\n")] = '\0';

char valoracionComentario[1000];
sprintf(valoracionComentario, "Valoracion: %d\nComentario: %s\n", valoracion, comentario);
strcat(valoracionPaciente, valoracionComentario);
```

- A continuación, se solicita al paciente que ingrese un comentario. Se utiliza la función `fflush(stdin)` para limpiar
  el búfer de entrada antes de leer el comentario con `fgets()`. Después de leer el comentario, se utiliza la
  función `strcspn()` para eliminar el carácter de nueva línea al final del comentario.

- Luego, se declara una variable `valoracionComentario` y se utiliza la función `sprintf()` para formatear la valoración
  y el comentario en una cadena y almacenarla en `valoracionComentario`.

- Finalmente, se utiliza la función `strcat()` para concatenar `valoracionComentario` con `valoracionPaciente`, lo que
  permite almacenar múltiples valoraciones y comentarios en la variable global `valoracionPaciente`.

```c
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
                system("cls");
                printf("Visualizar valoracion y comentarios de los pacientes:\n");
                printf("%s\n", valoracionPaciente);
                system("pause");
                system("cls");
                break;
            case

 2:
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
```

- La función `valoracionMenu()` muestra un menú para que el usuario elija entre diferentes opciones. Utiliza un
  bucle `do-while` para repetir el menú hasta que se seleccione la opción de "Regresar" (2).

- Dependiendo de la opción seleccionada, se realizan las siguientes acciones:
    - Si se selecciona la opción 1, se muestra el contenido de `valoracionPaciente`, que contiene las valoraciones y
      comentarios de los pacientes. Luego, se utiliza la función `system("pause")` para pausar la ejecución y esperar a
      que el usuario presione una tecla antes de limpiar la pantalla y volver al menú.
    - Si se selecciona la opción 2, se muestra un mensaje de salida y se realiza una pausa antes de limpiar la pantalla
      y volver al menú.
    - Si se selecciona una opción no válida, se muestra un mensaje de error y se limpia la pantalla antes de volver al
      menú.

En resumen, este código permite a los pacientes ingresar valoraciones y comentarios sobre el servicio, y proporciona un
menú para visualizar las valoraciones y comentarios almacenados. Utiliza variables globales para almacenar la
información y funciones para interactuar con los usuarios y mostrar la información almacenada.

## Header File

Este código es un ejemplo de un archivo de encabezado en lenguaje C llamado "valoracion.h". Aquí se encuentra la
declaración de dos funciones: `valorarServicio()` y `valoracionMenu()`. A continuación, se explica en detalle el código:

```c
#ifndef DOCTORES_PACIENTES_VALORACION_H
#define DOCTORES_PACIENTES_VALORACION_H
```

- Estas líneas utilizan directivas de preprocesador para evitar problemas de inclusión múltiple. Cuando un archivo de
  encabezado se incluye en varios archivos fuente, estas directivas se utilizan para asegurarse de que el contenido del
  archivo de encabezado solo se incluya una vez. Si `DOCTORES_PACIENTES_VALORACION_H` no está definido, se incluirá el
  contenido del archivo.

```c
void valorarServicio();
```

- Esta línea declara la función `valorarServicio()`. La función no tiene argumentos de entrada ni valor de retorno. La
  implementación de la función se realizará en otro archivo fuente.

```c
void valoracionMenu();
```

- Esta línea declara la función `valoracionMenu()`. Al igual que la función anterior, no tiene argumentos de entrada ni
  valor de retorno. La implementación de la función se realizará en otro archivo fuente.

```c
#endif //DOCTORES_PACIENTES_VALORACION_H
```

- Estas líneas cierran la directiva de preprocesador `#ifndef` y `#define`. Indican el final de las definiciones del
  archivo de encabezado.

En resumen, este archivo de encabezado proporciona las declaraciones de las funciones `valorarServicio()`
y `valoracionMenu()`, que se pueden utilizar en otros archivos fuente para incluir y utilizar estas funciones.