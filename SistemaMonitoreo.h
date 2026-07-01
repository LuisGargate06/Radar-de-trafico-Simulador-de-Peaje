#ifndef SISTEMA_MONITOREO_H
#define SISTEMA_MONITOREO_H

#include <iostream>
#include <iomanip>
#include "radar.h"

//En el arreglo de los auto los ordenamos por velocidad
template<typename T>
void ordenarVehiculosPorVelocidad(vehiculo<T>* arreglos, UT1 tamaño) {
    for (size_t i = 0; i < tamaño - 1; ++i) {
        for (size_t j = 0; j < tamaño - i - 1; ++j) {
            //Comparamos los valores
            if(arreglos[j].esMasRapidoQue(arreglos[j+1])){
                vehiculo<T> temp1 = arreglos[j];
                arreglos[j] = arreglos[j + 1];
                arreglos[j + 1] = temp1;
            }
        }
    }
}

//Generamos un struct
template <typename T>
struct SistemaMonitoreo {
    T2 limite;

    SistemaMonitoreo(T2 lim, std::ostream& os) : limite(lim) {
        os <<"[SistemaMonitoreo] Inicializacion con limite de: " << limite << " m/s" << std::endl;
    }
    ~SistemaMonitoreo() {
        std::cout <<"[SistemaMonitoreo] Destructor invocado de manera segura (RAII)" << std::endl;
    }
    void procesarYReportar(vehiculo<T> listaAutos[], T1 cantidad, std::ostream& os) {
        os << " Reporte de trafico y captura de infractores" << std::endl;
        os << std::left << std::setw(6) << "ID" << std::setw(12) << "PLACA" << std::setw(10) << "VELOCIDAD" << "ESTADO\n";
        os << std::endl;

        for (T1 i = 0; i < cantidad; ++i) {
            listaAutos[i].mostrarFilaReporte(limite, os);
        }
        os << std::endl;
    }
}; 

#endif