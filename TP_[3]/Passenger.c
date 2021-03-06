/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <ctype.h>
#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"
#include "validaciones.h"

Passenger* Passenger_new(){
	Passenger* auxPassenger=(Passenger*) malloc(sizeof(Passenger));
	if (auxPassenger==NULL){
		printf("No hay espacio en la memoria dinamica.\n");
		exit(1);
	}
	return auxPassenger;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr, eTipo tipos[], eEstado estados[], int tamT, int tamE){
	Passenger* auxPassenger= Passenger_new();
	verificarNULL(auxPassenger);
	if(idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL && estadoVueloStr!=NULL && tipos!=NULL && tamT>0){
		Passenger_setId(auxPassenger, atoi(idStr));
		Passenger_setNombre(auxPassenger,nombreStr);
		Passenger_setApellido(auxPassenger, apellidoStr);
		Passenger_setPrecio(auxPassenger, atof(precioStr));
		Passenger_setCodigoVuelo(auxPassenger, codigoVueloStr);
		Passenger_setTipoPasajero(auxPassenger, obtenerIdPorDescripcionTipo(tipos, tamT, tipoPasajeroStr));
		Passenger_setEstadoVuelo(auxPassenger, obtenerIdPorDescripcionEstado(estados, tamE, estadoVueloStr));
	}
	return auxPassenger;
}
int Passenger_setId(Passenger* this,int id){
	int todoOk=-1;
	if(this!=NULL && id>0){
		this->id=id;
		todoOk=0;
	}
	return todoOk;
}
int Passenger_getId(Passenger* this,int* id){
	int todoOk=-1;
	if(this!=NULL){
		*id=this->id;
		todoOk=0;
	}
	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int todoOk=-1;
	int lenNombre;
	if(this!=NULL && nombre!=NULL){
		lenNombre=strlen(nombre);
		if(lenNombre>1 && lenNombre<20){
			strlwr(nombre);
			nombre[0]=toupper(nombre[0]);
			strcpy(this->nombre,nombre);
		}
		todoOk=0;
	}
	return todoOk;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int todoOk=-1;
	if(this!=NULL && nombre!=NULL){
		strlwr(nombre);
		nombre[0]=toupper(nombre[0]);
		strcpy(nombre, this->nombre);
		todoOk=0;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int todoOk=-1;
	int lenApellido;
	if(this!=NULL && apellido!=NULL){
		lenApellido=strlen(apellido);
		if(lenApellido>1 && lenApellido<20){
			strlwr(apellido);
			apellido[0]=toupper(apellido[0]);
			strcpy(this->apellido,apellido);
		}
		todoOk=0;
	}
	return todoOk;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int todoOk=-1;
	if(this!=NULL && apellido!=NULL){
		strlwr(apellido);
		apellido[0]=toupper(apellido[0]);
		strcpy(apellido, this->apellido);
		todoOk=0;
	}
	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int todoOk=-1;
	int lenCodigoVuelo;
	if(this!=NULL && codigoVuelo!=NULL){
		lenCodigoVuelo=strlen(codigoVuelo);
		if(lenCodigoVuelo>1 && lenCodigoVuelo<8){
			strupr(codigoVuelo);
			strcpy(this->codigoVuelo,codigoVuelo);
		}
		todoOk=0;
	}
	return todoOk;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int todoOk=-1;
	if(this!=NULL && codigoVuelo!=NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		todoOk=0;
	}
	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int todoOk=-1;
	if(this!=NULL){
		this->tipoPasajero=tipoPasajero;
		todoOk=0;
	}
	return todoOk;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int todoOk=-1;
	if(this!=NULL){
		*tipoPasajero=this->tipoPasajero;
		todoOk=0;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int todoOk=-1;
	if(this!=NULL){
		if(precio>0){
			this->precio=precio;
		}else{
			this->id=0;
		}

		todoOk=0;
	}
	return todoOk;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int todoOk=-1;
	if(this!=NULL){
		*precio=this->precio;
		todoOk=0;
	}
	return todoOk;
}
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo){
	int todoOk=-1;
	if(this!=NULL){
		this->estadoVuelo=estadoVuelo;
		todoOk=0;
	}
	return todoOk;
}
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo){
	int todoOk=-1;
	if(this!=NULL){
		*estadoVuelo=this->estadoVuelo;
		todoOk=0;
	}
	return todoOk;
}

void mostrarPasajero(Passenger* pasajero, eTipo tipos[], eEstado estados[], int tamT, int tamE){
	int id;
	char name[20];
	char lastName[20];
	float price;
	char flyCode[10];
	char typePassenger[20];
	char statusFlight[20];
	int aux;
	Passenger_getId(pasajero, &id);
	Passenger_getNombre(pasajero, name);
	Passenger_getApellido(pasajero, lastName);
	Passenger_getPrecio(pasajero,&price);
	Passenger_getCodigoVuelo(pasajero, flyCode);
	Passenger_getTipoPasajero(pasajero, &aux);
	obtenerDescripcionPorIdTipo(tipos, tamT, aux, typePassenger);
	Passenger_getEstadoVuelo(pasajero, &aux);
	obtenerDescripcionPorIdEstado(estados, tamE, aux, statusFlight);
	printf("| %4d | %-11s | %-10s | $%8.2f | %7s | %-14s | %-11s |\n",id, name, lastName, price, flyCode, typePassenger, statusFlight);

}
int Passenger_modificarNombre(Passenger* pasajero){
	int todoOk=-1;
	char nombre[20];
	if(pasajero!=NULL){
		cargarValidarCadena("Ingrese el nuevo nombre",20, nombre);
		Passenger_setNombre(pasajero,nombre);
		todoOk=0;
	}
	return todoOk;
}
int Passenger_modificarApellido(Passenger* pasajero){
	int todoOk=-1;
	char apellido[20];
	if(pasajero!=NULL){
		cargarValidarCadena("Ingrese el nuevo apellido",20, apellido);
		Passenger_setApellido(pasajero,apellido);
		todoOk=0;
	}
	return todoOk;
}
int Passenger_modificarCodigoVuelo(Passenger* pasajero){
	int todoOk=-1;
	char string[20];
	if(pasajero!=NULL){
		cargarValidarAlfaNumerico("Ingrese el nuevo codigo de vuelo",20, string);
		Passenger_setCodigoVuelo(pasajero,string);
		todoOk=0;
	}
	return todoOk;
}
int Passenger_modificarPrecio(Passenger* pasajero){
	int todoOk=-1;
	float precio;
	if(pasajero!=NULL){
		cargarValidarDecimalPositivo("Ingrese el nuevo precio",&precio);
		Passenger_setPrecio(pasajero,precio);
		todoOk=0;
	}
	return todoOk;
}
int Passenger_modificarTipoPasajero(Passenger* pasajero,eTipo tipos[], int tamT){
	int todoOk=-1;
	int id;
	if(pasajero!=NULL){
		mostrarTipos(tipos, tamT);
		buscarIdExistenteTipo(tipos,tamT, &id);
		Passenger_setTipoPasajero(pasajero,id);
		todoOk=0;
	}
	return todoOk;
}
int Passenger_modificarEstadoVuelo(Passenger* pasajero,eEstado estados[], int tamE){
	int todoOk=-1;
	int id;
	if(pasajero!=NULL){
		mostrarEstados(estados, tamE);
		buscarIdExistenteEstado(estados,tamE, &id);
		Passenger_setEstadoVuelo(pasajero,id);
		todoOk=0;
	}
	return todoOk;
}


int compararPorId(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		if(((Passenger *)pasajero1)->id>((Passenger*)pasajero2)->id)
		{
		 auxReturn= 1;
		}
		if(((Passenger *)pasajero1)->id<((Passenger*)pasajero2)->id)
		{
		 auxReturn= -1;
		}
	}
	return auxReturn;
}
int compararPorNombre(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		auxReturn=strcmp(((Passenger*)pasajero1)->nombre, ((Passenger*)pasajero2)->nombre);
	}
	return auxReturn;
}
int compararPorApellido(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		auxReturn=strcmp(((Passenger*)pasajero1)->apellido, ((Passenger*)pasajero2)->apellido);
	}
	return auxReturn;
}
int compararPorCodigo(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		auxReturn=strcmp(((Passenger*)pasajero1)->codigoVuelo, ((Passenger*)pasajero2)->codigoVuelo);
	}
	return auxReturn;
}

int compararPorPrecio(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		if(((Passenger *)pasajero1)->precio>((Passenger*)pasajero2)->precio)
		{
		 auxReturn= 1;
		}
		if(((Passenger *)pasajero1)->precio<((Passenger*)pasajero2)->precio)
		{
		 auxReturn= -1;
		}
	}
	return auxReturn;
}
int compararPorTipo(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		if(((Passenger *)pasajero1)->tipoPasajero>((Passenger*)pasajero2)->tipoPasajero)
		{
		 auxReturn= 1;
		}
		if(((Passenger *)pasajero1)->tipoPasajero<((Passenger*)pasajero2)->tipoPasajero)
		{
		 auxReturn= -1;
		}
	}
	return auxReturn;
}
int compararPorEstado(void* pasajero1, void* pasajero2){
	int auxReturn=0;
	if(pasajero1!=NULL && pasajero2!=NULL){
		if(((Passenger *)pasajero1)->estadoVuelo>((Passenger*)pasajero2)->estadoVuelo)
		{
		 auxReturn= 1;
		}
		if(((Passenger *)pasajero1)->estadoVuelo<((Passenger*)pasajero2)->estadoVuelo)
		{
		 auxReturn= -1;
		}
	}
	return auxReturn;
}
