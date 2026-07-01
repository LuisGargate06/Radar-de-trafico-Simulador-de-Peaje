#ifndef SIMULACION_H
#define SIMULACION_H

#include <iostream>
#include "SistemaMonitoreo.h"

//Generamos los archivos
void generarArchivoTrafico(std::ostream& os);

template<typename T>
void ejecutarFlujoSimulacion(T2 limiteVelocidadLegal, std::ostream& os) {
    os << "\n>>> [Modulo Control] Iniciando orquestacion de componentes <<<\n";

    generarArchivoTrafico(os);

    T1 cantidadDetectados = 0;
    vehiculo<T> loteVehiculos[max_vehiculos];
    vehiculo<T>* ptrLote = loteVehiculos;

    os << "[Modulo Control] Leyendo flujo desde 'trafico.txt'...\n";
    loteVehiculos[0].capturarTraficoSimulado(loteVehiculos, &cantidadDetectados);
    os << "[Modulo Control] Sincronizacion exitosa. Vehiculos detectados: " << cantidadDetectados << "\n";
    os << "[Modulo Control] Delegando ordenamiento al algoritmo Bubble Sort...\n";

    ordenarVehiculosPorVelocidad(ptrLote, cantidadDetectados);

    SistemaMonitoreo<T> monitor(limiteVelocidadLegal, os);
    monitor.procesarYReportar(ptrLote, cantidadDetectados, os);
    
    os << ">>> [Modulo Control] Flujo finalizado correctamente. Liberando recursos <<<\n";
}

bool verificarIntegridadDelRadar(std::ostream& os);

void despacharSistemaMonitoreo(std::ostream& os);

#endif