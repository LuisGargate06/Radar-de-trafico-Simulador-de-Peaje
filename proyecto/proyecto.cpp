#include "types.h"

struct Vehiculo {
    STR placa;
    T2 x0, x1, t, velocidad;

    Vehiculo() : placa(""), x0(0), x1(0), t(0), velocidad(0) {}

    Vehiculo(STR p, T2 pos0, T2 pos1, T2 tiempo) 
        : placa(p), x0(pos0), x1(pos1), t(tiempo) {
        velocidad = (x1 - x0) / t;
        } 
};

bool operator>(const Vehiculo& v, T2 limite) {
    return v.velocidad > limite;
}

struct Radar {
    Vehiculo* registros;
    UT1 capacidad;
    UT1 cantidad;   