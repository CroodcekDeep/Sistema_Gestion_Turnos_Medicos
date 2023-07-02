# Archivo Main

El código que has proporcionado es un programa principal que muestra un menú de opciones y permite al usuario
seleccionar diferentes acciones relacionadas con pacientes, doctores, valoraciones y comentarios. A continuación, se
explica cada parte del código:

1. Inclusión de bibliotecas:

```c
#include <stdio.h>
#include <stdlib.h>
```

Estas líneas de código incluyen las bibliotecas estándar necesarias para el programa, como `stdio.h` para funciones de
entrada/salida estándar y `stdlib.h` para funciones de utilidad y gestión de memoria.

2. Inclusión de archivos de encabezado:

```c
#include "Doctor/doctor.h"
#include "Paciente/paciente.h"
#include "Valoracion/valoracion.h"
#include "Acuerdo/acuerdo.h"

```

Estas líneas de código incluyen archivos de encabezado personalizados para cada módulo del programa, como "
Doctor/doctor.h", "Paciente/paciente.h", etc. Estos archivos de encabezado contienen las declaraciones de funciones y
estructuras necesarias para cada módulo respectivo.

3. Función principal `main()`:

```c
int main() {
    // Código del programa
    return 0;
}
```

La función `main()` es el punto de entrada del programa. Aquí es donde comienza la ejecución. El tipo de retorno `int`
indica que la función debe devolver un valor entero al sistema operativo al finalizar.

4. Verificación del acuerdo:

```c
if (acuerdo() == 1) {
    // Código del programa
}
```

La función `acuerdo()` se llama para verificar si se ha aceptado un acuerdo específico. Si la función devuelve 1 (
verdadero), se ejecuta el código dentro del bloque `if`.

5. Lógica del menú:

```c
system("cls");
int opcion;
do {
    // Mostrar el menú y obtener la opción seleccionada por el usuario
    printf("-- Menu Principal --\n");
    printf("1. Paciente\n");
    printf("2. Doctor\n");
    printf("3. Valoracion y Comentarios\n");
    printf("4. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%i", &opcion);

    switch (opcion) {
        // Casos para cada opción del menú
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
```

En esta sección, se muestra el menú principal utilizando `printf()` para mostrar las opciones y `scanf()` para obtener
la
opción seleccionada por el usuario. Un bucle `do-while` se utiliza para permitir al usuario seleccionar múltiples
opciones
hasta que seleccione la opción de salida (4).

Dentro del bucle `switch`, se ejecuta el código correspondiente a la opción seleccionada por el usuario. Por ejemplo, si
se selecciona la opción 1, se llama a la función `pacienteMenu()`. Si se selecciona la opción 2, se llama a la función
`doctorMenu()`, y así sucesivamente.

6. Finalización del programa:

```c
return 0;
```

Al final del programa, se devuelve un valor de 0 para indicar que el programa se ha ejecutado correctamente y se cierra.
Esto equivale a indicar al sistema operativo que el programa ha finalizado sin errores.

En resumen, este código representa un programa principal que muestra un menú interactivo y permite a los usuarios
seleccionar diferentes opciones relacionadas con pacientes, doctores, valoraciones y comentarios. El programa se ejecuta
hasta que el usuario seleccione la opción de salida.