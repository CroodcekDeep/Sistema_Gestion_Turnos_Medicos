# Sistema de Gestión de Turnos Médicos

## Descripción del Repositorio:

Este repositorio contiene un sistema de gestión de turnos médicos desarrollado en lenguaje de programación "C". El
sistema ofrece una interfaz de texto en la terminal para pacientes y doctores, permitiendo la programación y
visualización de turnos, así como la valoración del servicio y comentarios por parte de los pacientes.

## Explicación del Código:

Si deseas obtener una explicación detallada del código que se ha desarrollado, te invitamos a visitar el siguiente
enlace. En este recurso encontrarás una descripción paso a paso de cada función y su finalidad dentro del programa.
Además, se brindarán detalles sobre el proceso de inicio de sesión de los doctores, la visualización de los turnos
asociados a cada médico y otras características relevantes:

[Explicacion del Codigo](Documentacion/00General.md)

## Características:

- Registro y visualización de información de doctores.
- Tomar turnos con selección de doctor y horario.
- Valoración del servicio médico con puntuación del 1 al 5 y comentarios.
- Visualización de los turnos tomados por cada doctor.
- Visualización de valoraciones y comentarios de los pacientes.

Este sistema se ha desarrollado sin utilizar estructuras (struct), y se ha enfocado en proporcionar una experiencia de
uso intuitiva y eficiente para la gestión de turnos médicos.

### Historias de Usuario del Paciente:

| Código | 	Título                        | Prioridad | Descripción                                                                               | Criterio de Aceptación                                                                                                                                                                          |
|--------|--------------------------------|-----------|-------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| P-1    | Ver información de doctores    | Alta      | Como paciente, quiero poder ver la información de los doctores registrados en el sistema. | El paciente puede acceder a la lista de doctores y visualizar su información detallada, incluyendo nombre, especialidad y horarios de atención.                                                 |
| P-2    | Tomar turno con un doctor      | Alta      | Como paciente, quiero poder tomar un turno con un doctor específico.                      | El paciente puede seleccionar un doctor disponible y reservar un turno en un horario conveniente. El turno queda registrado en el sistema.                                                      |
| P-3    | Valorar y comentar el servicio | Media     | Como paciente, quiero poder valorar el servicio médico recibido y dejar un comentario.    | El paciente puede dar una puntuación del 1 al 5 al servicio recibido y opcionalmente dejar un comentario para expresar su opinión. La valoración y comentario quedan registrados en el sistema. |

### Historias de Usuario del Doctor:

| Código | 	Título            | Prioridad | Descripción                                                                    | Criterio de Aceptación                                                                                                       |
|--------|--------------------|-----------|--------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------|
| D-1    | Ver turnos tomados | Alta      | Como doctor, quiero poder ver los turnos que han tomado los pacientes conmigo. | El doctor puede acceder a una lista de los turnos tomados por los pacientes con él, mostrando la fecha y hora de cada turno. |
| D-2    | Iniciar sesión     | Alta      | Como doctor, quiero poder iniciar sesión en el sistema.                        | El doctor puede ingresar su identificación y contraseña para acceder a las funcionalidades específicas para doctores.        | 

### Historias de Usuario del Administrador:

| Código | 	Título                               | Prioridad | Descripción                                                                                  | Criterio de Aceptación                                                                                                                                    |
|--------|---------------------------------------|-----------|----------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| A-1    | Visualizar valoraciones y comentarios | Alta      | Como administrador, quiero poder visualizar las valoraciones y comentarios de los pacientes. | El administrador puede acceder a las valoraciones y comentarios realizados por los pacientes, lo que le permite evaluar la calidad del servicio brindado. |

## Autor

- [Ginno Taimal](https://github.com/CroodcekDeep)