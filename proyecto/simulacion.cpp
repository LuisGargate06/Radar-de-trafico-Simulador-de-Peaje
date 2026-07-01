#include "simulacion.h"
#include "types1.h"
#include <fstream>

void generarArchivoTrafico(std::ostream& os) {
    std::ofstream archivo("trafico.txt");
    if (archivo.is_open()) {
        archivo << "4\n";
        archivo << "1 100.0 0.0 ABC1234\n";
        archivo << "2 150.0 -3.0 XYZ5678\n";
        archivo << "3 120.0 5.0 DEF9012\n";
        archivo << "4 200.0 2.0 GHI3456\n";
        archivo.close();
        os<<"[Disco] Archivo 'trafico.txt' generado correctamente."<<std::endl;
    } else {
        os<< "[Error] No se pudo generar el archivo 'trafico.txt'." << std::endl;
    }   
}

bool verificarIntegridadDelRadar(std::ostream& os) {
    os << "[Hardware] Realizando test de estres en los sensores de barrido...\n";
    std::ifstream prueba("trafico.txt");
    if (!prueba.good()) {
        os << "[CRITICAL] Fallo de hardware: El sensor fisico no responde.\n";
        return false;
    }
    prueba.close();
    os << "[Hardware] Canal I/O operativo. Sensor calibrado al 100%.\n";
    return true;
}

void despacharSistemaMonitoreo(std::ostream& os) {
    os << "========================================================\n";
    os << "  SISTEMA AUTOMATIZADO DE SEGURIDAD VIAL UNI-CC112\n";
    os << "========================================================\n";

    generarArchivoTrafico(os);

    if (verificarIntegridadDelRadar(os)) {
        ejecutarFlujoSimulacion<double>(30.0, os);
    } else {
        os << "[Core] Abortando secuencia por falla en infraestructura.\n";
    }

    os << "\n[Estatus] Saliendo del subproceso de monitoreo de manera limpia.\n";
}