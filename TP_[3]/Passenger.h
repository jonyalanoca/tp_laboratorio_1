/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "Estado.h"
#include "Tipo.h"
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[7];
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr, eTipo tipos[], eEstado estados[], int tamT, int tamE);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

void mostrarPasajero(Passenger* pasajero, eTipo tipos[], eEstado estados[], int tamT, int tamE);

int Passenger_modificarNombre(Passenger* pasajero);
int Passenger_modificarApellido(Passenger* pasajero);
int Passenger_modificarCodigoVuelo(Passenger* pasajero);
int Passenger_modificarPrecio(Passenger* pasajero);
int Passenger_modificarTipoPasajero(Passenger* pasajero,eTipo tipos[], int tamT);
int Passenger_modificarEstadoVuelo(Passenger* pasajero,eEstado estados[], int tamE);

#endif /* PASSENGER_H_ */