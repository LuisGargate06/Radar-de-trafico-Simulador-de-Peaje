#ifndef RADAR_H
#define RADAR_H
#include "types1.h"
#include <cstddef>

//Suponemos que el hardware tiene un alcance de 50 metros 
//Por ende en un carril tiene como capacidad máxima de 12 vehículos
const T1 max_vehiculos = 10;

//Creamos un struct
//Usamos templates para variar los valores de la velocidad si queremos que sea mas exacto usamos double y sino un float
template <typename T>
struct vehiculo {
    private:
        T1 id;
        T velocidadActual;
        char placa[8];
    
    public:
        //Constructor
        vehiculo() {
            id = 0;
            velocidadActual = 0.0f;
            placa[0] = '\0';
        }

        void llenarDatos(T1 m_id, T m_velocidad, const char* m_placa){
            id = m_id;
            velocidadActual = m_velocidad;
            for(size_t i = 0; i < 7; i++){
                *(placa + i) = m_placa[i];
            }
            *(placa + 7) = '\0';
        }
}