#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "dataManagement.h"


///funciones para mostrar la fecha del alquiler en cuestion. Se utilizan funciones que permiten almacenar en strings la fecha actual en la maquina local, y se utilizara para almacenar en la stfecha.
int obtenerMesDesdeCadena(const char *mesStr) {
    if (strcmp(mesStr, "Jan") == 0) return 1;
    if (strcmp(mesStr, "Feb") == 0) return 2;
    if (strcmp(mesStr, "Mar") == 0) return 3;
    if (strcmp(mesStr, "Apr") == 0) return 4;
    if (strcmp(mesStr, "May") == 0) return 5;
    if (strcmp(mesStr, "Jun") == 0) return 6;
    if (strcmp(mesStr, "Jul") == 0) return 7;
    if (strcmp(mesStr, "Aug") == 0) return 8;
    if (strcmp(mesStr, "Sep") == 0) return 9;
    if (strcmp(mesStr, "Oct") == 0) return 10;
    if (strcmp(mesStr, "Nov") == 0) return 11;
    if (strcmp(mesStr, "Dec") == 0) return 12;
    return -1; // Error
}

Fecha obtenerFechaHoraDesdeCadena(const char *cadenaTiempo) {
    char mesStr[4]; // Para almacenar el mes como cadena

    Fecha fechaACambiar;
    // Usamos sscanf para analizar la cadena de tiempo y extraer los componentes de la fecha y la hora
    sscanf(cadenaTiempo, "%*s %3s %d %*d:%*d:%*d %d", mesStr, fechaACambiar.dia, fechaACambiar.anio);

    // Convertir el mes de cadena a número
    fechaACambiar.mes = obtenerMesDesdeCadena(mesStr);

    return fechaACambiar;
}

/// Función para mostrar la fecha y hora actual
void mostrarFechaHoraActual(const char *cadenaTiempo) {
    // Obtener la cadena de tiempo actual
    time_t tiempo_actual = time(NULL);
    cadenaTiempo = ctime(&tiempo_actual);

    // Convertir la cadena de tiempo en una estructura FechaHora
    Fecha fecha_hora_actual = obtenerFechaHoraDesdeCadena(cadenaTiempo);

    // Imprimir los componentes de la fecha y la hora
    printf("Fecha y hora actual: %d/%d/%d %02d:%02d:%02d\n",
        fecha_hora_actual.dia,
        fecha_hora_actual.mes,
        fecha_hora_actual.anio
    );
}

void mostrarFechaHoraAlquiler(Fecha fechaAlquiler){
     printf("Fecha y hora del alquiler: %d/%d/%d\n",
        fechaAlquiler.dia,
        fechaAlquiler.mes,
        fechaAlquiler.anio
    );
}

///---------------------------------------------------------------------------------------///


///FUNCIONES DE MOSTRAR

/// Autos disponibles para renta

/// Muestra un alquiler
void mostrarUnAlquiler(Alquiler *unAlquiler){
        printf("\nDNI del cliente: %d", unAlquiler->dniCliente);
        printf("\nAlquilado del %d/%d/%d al %d/%d/%d", unAlquiler->fechaInicio.dia,unAlquiler->fechaInicio.mes,unAlquiler->fechaInicio.anio,unAlquiler->fechaFin.dia,unAlquiler->fechaFin.mes,unAlquiler->fechaFin.anio);
        printf("\nVehiculo rentado: %s", unAlquiler->vehiculo);
        printf("\nValor total de la renta: %.2f", unAlquiler->precioTotal);
}

/// Muestra el alquiler de un vehiculo cuya patente es pasada por parametro.
void mostrarAlquilerPorVehiculo(Alquiler *alquileres, Patente patenteDelVehiculo, int cantidadRegistrosAlquiler){
    for(int i = 0; i<cantidadRegistrosAlquiler; i++){
            if(strcat(alquileres[i].vehiculo.numeros,alquileres[i].vehiculo.letras)==strcat(patenteDelVehiculo.numeros,patenteDelVehiculo.letras)){
                printf("Alquiler correspondiente a patente %s-%s:\n\n",patenteDelVehiculo.letras,patenteDelVehiculo.numeros);
                mostrarUnAlquiler(&alquileres[i]);
            }
    }
}

/// Muestra todo el registro de historial de alquileres.
void mostrarAlquileres(Alquiler **alquileres, int cantidadRegistrosAlquiler){
    for(int i = 0; i<cantidadRegistrosAlquiler; i++){
        printf("\n\nDATOS DE ALQUILER %d", i+1);
        mostrarUnAlquiler(alquileres[i]);
    }
}

/// Registra un alquiler para un vehiculo, que cambia el valor "disponible" de 1 a 0.(se realiza antes una verificacion dentro de la estructura dinamica de vehiculos, para ver cuales estan actualmente disponibles).
/// El registro modificado de vehiculo, deberia modificarse dentro de su correspondiente registro en el archivo. Esto se hace con una funcion "modificarVehiculo" comparando la patente. Esto permite al mismo tiempo que se guarda el
/// arreglo(no se modifica el malloc, ya que el arreglo dinamico deberi ser el mismo), se guarda el archivo.

/// Función para buscar un vehículo por patente
Vehiculo* buscarVehiculoPorPatente(Vehiculo* vehiculos, int cantidadVehiculos, Patente patente) {
    for (int i = 0; i < cantidadVehiculos; i++) {
        if (strncmp(vehiculos[i].patente.letras, patente.letras, 3) == 0 &&
            strncmp(vehiculos[i].patente.numeros, patente.numeros, 3) == 0) {
            return &vehiculos[i];
        }
    }
    return NULL;
}

/// Función para leer los datos de un nuevo alquiler desde el usuario
Alquiler leerDatosAlquiler(Patente patente, float precioPorDia) {
    Alquiler nuevoAlquiler;
    nuevoAlquiler.vehiculo = patente;

    printf("Ingrese la fecha de inicio del alquiler (dd mm aaaa): ");
    scanf("%d %d %d", &nuevoAlquiler.fechaInicio.dia, &nuevoAlquiler.fechaInicio.mes, &nuevoAlquiler.fechaInicio.anio);

    printf("Ingrese la fecha de fin del alquiler (dd mm aaaa): ");
    scanf("%d %d %d", &nuevoAlquiler.fechaFin.dia, &nuevoAlquiler.fechaFin.mes, &nuevoAlquiler.fechaFin.anio);

    printf("Ingrese el DNI del cliente: ");
    scanf("%d", &nuevoAlquiler.dniCliente);

    int diasDeAlquiler = (nuevoAlquiler.fechaFin.dia - nuevoAlquiler.fechaInicio.dia) +
                         (nuevoAlquiler.fechaFin.mes - nuevoAlquiler.fechaInicio.mes) * 30 +
                         (nuevoAlquiler.fechaFin.anio - nuevoAlquiler.fechaInicio.anio) * 365;

    nuevoAlquiler.precioTotal = diasDeAlquiler * precioPorDia;

    return nuevoAlquiler;
}

/// Función para registrar un alquiler
void registrarAlquiler(Vehiculo **vehiculos, Alquiler **alquileres, Patente patente, int *cantidadVehiculos, int *cantidadAlquileres, char nombreArchAlq[], char nombreArchVehic[]) {
    Vehiculo* vehiculo = buscarVehiculoPorPatente(*vehiculos, *cantidadVehiculos, patente);

    if (vehiculo == NULL) {
        printf("Vehículo no encontrado.\n");
        return;
    }

    if (vehiculo->disponibilidad == 0) {
        printf("El vehículo no está disponible para alquilar.\n");
        return;
    }

    Alquiler nuevoAlquiler = leerDatosAlquiler(patente, vehiculo->precioDeAlquilerDiario);

    vehiculo->disponibilidad = 0; // Marcar el vehículo como no disponible

    FILE *archAlquileres = fopen(nombreArchAlq, "ab");
    if (archAlquileres == NULL) {
        printf("Error al abrir el archivo de alquileres.\n");
        return;
    }
    fwrite(&nuevoAlquiler, sizeof(Alquiler), 1, archAlquileres);
    fclose(archAlquileres);

    *alquileres = (Alquiler*)realloc(*alquileres, (*cantidadAlquileres + 1) * sizeof(Alquiler));
    (*alquileres)[*cantidadAlquileres] = nuevoAlquiler;
    (*cantidadAlquileres)++;

    FILE *archVehiculos = fopen(nombreArchVehic, "r+b");
    if (archVehiculos == NULL) {
        printf("Error al abrir el archivo de vehículos.\n");
        return;
    }
    for (int i = 0; i < *cantidadVehiculos; i++) {
        if (strncmp((*vehiculos)[i].patente.letras, patente.letras, 3) == 0 &&
            strncmp((*vehiculos)[i].patente.numeros, patente.numeros, 3) == 0) {
            fseek(archVehiculos, i * sizeof(Vehiculo), SEEK_SET);
            fwrite(&(*vehiculos)[i], sizeof(Vehiculo), 1, archVehiculos);
            break;
        }
    }
    fclose(archVehiculos);

    printf("Alquiler registrado con éxito.\n");
}



/// Funcion de Administrador y Cliente. Para esta funcion necesitamos varias comprobaciones: desde comprobaciones de fecha(no puede reservar un coche en una fecha anterior a la actual siendo cliente),
/// que el vehiculo a rentar este disponible, hacer una verificacion de toda la lista de vehiculos que, con la patente, podemos verificar el estado de alquiler en el que se encuentra y si ya llego a la fecha de finalizacion
/// de alquiler, cambiando el estado de toda la lista de vehiculos disponibles dependiendo de esto(para esto se trabaja con funcion de lectura y guardado de archivos tambien en esta funcion).
/// Se pide que se determine la fecha de renta del vehiculo. Todo vehiculo rentado pasara a estar "no disponible" con lo cual no figurara en la lista
/// de mostrar disponibles para alquiler, a menos que(continuar con funciones)...





/// FUNCIONES DE REPORTES Y ESTADISTICAS

float calcularIngresosMes(const Alquiler *alquileres, int cantidadAlquileres, int mes, int anio) {
    float ingresos = 0.0;
    for (int i = 0; i < cantidadAlquileres; i++) {
        int inicioMes = alquileres[i].fechaInicio.mes;
        int inicioAnio = alquileres[i].fechaInicio.anio;
        int finMes = alquileres[i].fechaFin.mes;
        int finAnio = alquileres[i].fechaFin.anio;

        // Verificar si el mes y año especificados están dentro del rango de la fecha de inicio y fin
        if ((anio > inicioAnio || (anio == inicioAnio && mes >= inicioMes)) &&
            (anio < finAnio || (anio == finAnio && mes <= finMes))) {
            ingresos += alquileres[i].precioTotal;
        }
    }
    return ingresos;
}




