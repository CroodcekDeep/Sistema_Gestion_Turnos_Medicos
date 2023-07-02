# Archivo Doctor

## Source Code

El código que has proporcionado es un archivo llamado "Acuerdo.c" en lenguaje C. A continuación, se explica cada parte
del código:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

Estas son las directivas de preprocesador que incluyen las bibliotecas estándar de entrada y salida (`stdio.h`), gestión
de memoria dinámica (`stdlib.h`) y manipulación de cadenas (`string.h`).

```c
#define MAX_USUARIO 20
#define MAX_CONTRASENA 20
```

Estas son constantes definidas mediante una macro. Establecen el tamaño máximo de la cadena para el nombre de usuario y
la contraseña.

```c
int doctorLogeado;
```

Declaración de una variable global llamada `doctorLogeado`. Esta variable se utiliza para indicar si un doctor ha
iniciado sesión o no.

```c
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
```

La función `arregloDoctores` se encarga de leer el archivo "doctores.txt" y recopilar los nombres y apellidos de los
doctores en un arreglo dinámico de cadenas.

1. Se abre el archivo en modo lectura y se verifica si se abrió correctamente.
2. Se cuenta la cantidad de doctores en el archivo leyendo línea por línea y buscando una cadena específica que indica
   el inicio de la información de cada doctor.
3. Se vuelve a colocar el puntero de archivo al principio del archivo.
4. Se crea un arreglo dinámico para almacenar los nombres y apellidos de los doctores.
5. Se lee nuevamente el archivo, se extraen los nombres y apellidos de cada línea que contiene información de un doctor
   y se almacenan en el arreglo dinámico.
6. Finalmente, se cierra el archivo y se devuelve el arreglo de doctores.

```c
void visualizarDoctores() {
    FILE *archivo = fopen("../Archivos/doctores.txt", "r");
    if (archivo ==

 NULL) {
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
```

La función `visualizarDoctores` muestra en pantalla la lista de doctores y sus detalles, leídos desde el archivo "
doctores.txt".

1. Se abre el archivo en modo lectura y se verifica si se abrió correctamente.
2. Se muestra en pantalla el encabezado "Lista de doctores:".
3. Se lee línea por línea del archivo y se muestra cada línea en pantalla, omitiendo las líneas en blanco.
4. Si una línea contiene la cadena "Nombre y Apellidos:", se muestra un número de doctor y se imprime la línea.
5. Si una línea contiene la cadena "Especialidad:", se incrementa el número de doctor.
6. Al finalizar, se muestra un mensaje indicando que no se encontraron más líneas en el archivo y se cierra el archivo.

```c
int login() {
    char usuario[MAX_USUARIO];
    char contrasena[MAX_CONTRASENA];

    printf("Usuario: ");
    scanf("%s", usuario);
    printf("Contraseña: ");
    scanf("%s", contrasena);

    // Abrir el archivo de credenciales
    FILE *archivo = fopen("../Archivos/credenciales.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de credenciales.\n");
        return 0;  // Indicar error de login
    }

    char usuarioArchivo[MAX_USUARIO];
    char contrasenaArchivo[MAX_CONTRASENA];
    int encontrado = 0;  // Indicador de si se encontró la credencial del doctor

    // Buscar las credenciales en el archivo
    while (fscanf(archivo, "%s %s", usuarioArchivo, contrasenaArchivo) == 2) {
        if (strcmp(usuario, usuarioArchivo) == 0 && strcmp(contrasena, contrasenaArchivo) == 0) {
            encontrado = 1;
            break;
        }
    }

    fclose(archivo);

    if (encontrado) {
        printf("¡Login exitoso!\n");
        char ultimoCaracter = usuario[strlen(usuario) - 1];

        char **doctores = arregloDoctores();
        if (doctores == NULL) {
            printf("Error al obtener la lista de doctores.\n");
            return 0;  // Indicar error de login
        }

        printf("Bienvenido, %s.\n", doctores[ultimoCaracter - '1']);
        doctorLogeado = (int) ultimoCaracter - 48;
        return 1;  // Indicar login exitoso y devolver el número de doctor
    } else {
        printf("Usuario o contraseña incorrectos.\n

");
        return 0;  // Indicar error de login
    }
}
```

La función `login` se encarga de solicitar al usuario un nombre de usuario y una contraseña, y luego verifica si
coinciden con las credenciales almacenadas en el archivo "credenciales.txt".

1. Se solicita al usuario que ingrese un nombre de usuario y una contraseña.
2. Se abre el archivo "credenciales.txt" en modo lectura y se verifica si se abrió correctamente.
3. Se declara un par de arreglos para almacenar las credenciales leídas del archivo.
4. Se busca en el archivo las credenciales que coincidan con las ingresadas por el usuario.
5. Si se encuentra una coincidencia, se muestra un mensaje de "login exitoso" y se obtiene el último carácter del nombre
   de usuario ingresado.
6. Se llama a la función `arregloDoctores` para obtener la lista de doctores y se verifica si se obtuvo correctamente.
7. Se muestra un mensaje de bienvenida con el nombre y apellido del doctor correspondiente al último carácter del nombre
   de usuario.
8. Se actualiza la variable `doctorLogeado` con el número de doctor correspondiente.
9. Se devuelve 1 para indicar un inicio de sesión exitoso y se devuelve el número de doctor.
10. Si no se encuentra una coincidencia, se muestra un mensaje de "usuario o contraseña incorrectos" y se devuelve 0
    para indicar un error de inicio de sesión.

```c
void mostrarTurnosDoctor() {
    char nombreArchivo[50];
    char **doctores = arregloDoctores();


    for (int numeroArchivo = 1; numeroArchivo < 10; numeroArchivo++) {
        sprintf(nombreArchivo, "../Archivos/turno%02d_%s.txt", numeroArchivo, doctores[doctorLogeado - 1]);

        FILE *archivo = fopen(nombreArchivo, "r");
        if (archivo == NULL) {
            printf("No se encuentran mas turno o se presento un error al abrir el archivo de turno.\n");
            break;
        }

        printf("Turnos del Doctor %s:\n", doctores[doctorLogeado - 1]);

        char turno[1000];
        while (fgets(turno, sizeof(turno), archivo) != NULL) {
            printf("%s", turno);
        }

        fclose(archivo);

        numeroArchivo++;
    }
}
```

La función `mostrarTurnosDoctor` muestra los turnos asociados al doctor que ha iniciado sesión.

1. Se declara una cadena de caracteres `nombreArchivo` y un arreglo `doctores` utilizando la función `arregloDoctores`
   para obtener la lista de doctores.
2. Se utiliza un bucle `for` para iterar a través de los archivos de turnos del doctor. El nombre de cada archivo se
   construye utilizando el número de archivo, el nombre y apellido del doctor obtenido del arreglo `doctores`.
3. Se abre el archivo de turno correspondiente en modo lectura y se verifica si se abrió correctamente.
4. Se muestra un encabezado indicando los turnos del doctor.
5. Se lee línea por línea del archivo y se muestra cada turno en pantalla.
6. Se cierra el archivo.
7. Se incrementa el número de archivo para buscar el siguiente turno.
8. Al finalizar el bucle, se muestra un mensaje indicando que no se encontraron más turnos o se produjo un error al
   abrir el archivo de turno.

```c
void doctorMenu

() {
    int opcion;

    do {
        printf("\n---- Menú del Doctor ----\n");
        printf("1. Visualizar lista de doctores\n");
        printf("2. Mostrar mis turnos\n");
        printf("3. Cerrar sesión\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                visualizarDoctores();
                break;
            case 2:
                mostrarTurnosDoctor();
                break;
            case 3:
                doctorLogeado = 0;
                printf("Sesión cerrada.\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);
}
```

La función `doctorMenu` muestra el menú de opciones para el doctor que ha iniciado sesión y ejecuta las acciones
correspondientes según la opción seleccionada.

1. Se declara una variable `opcion` para almacenar la opción seleccionada por el usuario.
2. Se muestra el menú del doctor con las opciones disponibles.
3. Se solicita al usuario que ingrese una opción.
4. Se utiliza una estructura de control `switch` para ejecutar las acciones correspondientes según la opción
   seleccionada.
    - Si la opción es 1, se llama a la función `visualizarDoctores` para mostrar la lista de doctores.
    - Si la opción es 2, se llama a la función `mostrarTurnosDoctor` para mostrar los turnos del doctor.
    - Si la opción es 3, se cierra la sesión del doctor y se muestra un mensaje de sesión cerrada.
    - Si la opción no coincide con ninguna de las anteriores, se muestra un mensaje de opción inválida.
5. El bucle `do-while` se repite hasta que la opción seleccionada sea 3 (cerrar sesión).

Esto es un resumen detallado del código proporcionado. Cada función se encarga de realizar una tarea específica y se
utilizan estructuras de control y funciones auxiliares para lograr el flujo deseado del programa.

## Header File

El código que has compartido muestra un archivo de encabezado en C llamado "doctor.h". Este archivo contiene las
declaraciones de funciones relacionadas con la gestión de doctores en el sistema de doctores y pacientes. A
continuación, se explica en detalle el código:

```c
#ifndef DOCTORES_PACIENTES_DOCTOR_H
#define DOCTORES_PACIENTES_DOCTOR_H
```

Estas líneas de código forman parte de las directivas del preprocesador y se utilizan para evitar la inclusión múltiple
del archivo de encabezado. Estas líneas verifican si la macro `DOCTORES_PACIENTES_DOCTOR_H` no está definida y, si es
así, define esta macro y continúa con el contenido del archivo. Si la macro ya está definida, significa que el archivo
de encabezado ya ha sido incluido anteriormente y se evita la inclusión duplicada.

```c
#define NUM_DOCTORES 4
```

Esta línea define una constante `NUM_DOCTORES` con el valor 4. Esta constante se utiliza para indicar el número de
doctores en el archivo "doctores.txt". Si se agrega o elimina doctores del archivo, este valor debe actualizarse en
consecuencia.

```c
char **arregloDoctores();
```

Esta línea declara una función llamada `arregloDoctores` que devuelve un puntero a un puntero de caracteres (`char**`).
Esta función se utiliza para obtener un arreglo dinámico que contiene los nombres y apellidos de los doctores
almacenados en el archivo "doctores.txt".

```c
void visualizarDoctores();
```

Esta línea declara una función llamada `visualizarDoctores` que no devuelve ningún valor (`void`). Esta función se
utiliza para mostrar en pantalla la lista de doctores y su información almacenada en el archivo "doctores.txt".

```c
void doctorMenu();
```

Esta línea declara una función llamada `doctorMenu` que no devuelve ningún valor (`void`). Esta función se utiliza para
mostrar el menú de opciones del doctor y manejar las interacciones con el usuario para realizar acciones relacionadas
con su cuenta y turnos.

```c
#endif //DOCTORES_PACIENTES_DOCTOR_H
```

Estas líneas de código cierran las directivas del preprocesador. Indican el final del archivo de encabezado y evitan
cualquier inclusión adicional del archivo fuera de este punto.

En resumen, el archivo de encabezado "doctor.h" proporciona las declaraciones de funciones necesarias para trabajar con
los doctores en el sistema de doctores y pacientes. Incluye funciones para obtener la lista de doctores, visualizar la
información de los doctores y mostrar el menú de opciones para los doctores. Estas funciones se definen y se implementan
en otros archivos del programa para lograr la funcionalidad completa del sistema.