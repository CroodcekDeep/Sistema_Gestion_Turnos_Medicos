cmake_minimum_required(VERSION 3.25)
project(Doctores_Pacientes C)

set(CMAKE_C_STANDARD 11)

add_executable(Doctores_Pacientes main.c Doctor/doctor.c Doctor/doctor.h Paciente/paciente.c Paciente/paciente.h Valoracion/valoracion.c Valoracion/valoracion.h Acuerdo/acuerdo.c Acuerdo/acuerdo.h)
