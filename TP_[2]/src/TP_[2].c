/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alanoca Aduviri Jonathan Gerardo (Div-1A)
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "otros.h"
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "vueloEstado.h"
#include "hardcode.h"
#include "animacion.h"
#define TAM 2000
#define TAM_ESTADO 11

int main(void) {
	setbuf(stdout,NULL);

	Passenger pasajeros[TAM];
	eVueloEstado estados[TAM]={
			{0, "-","-"},
			{2000, "HE47WX20","ACTIVO"},
			{2001, "47WX2000","CANCELADO"},
			{2002, "HH20502","DEMORADO"},
			{2003, "JON2394E","ACTIVO"},
			{2004, "848FJX20","ACTIVO"},
			{2005, "E47WX20","CANCELADO"},
			{2006, "HE47WX20","DEMORADO"},
			{2007, "HE22YF20","ACTIVO"},
			{2008, "TY47WX20","ACTIVO"},
			{2009, "6847WX20","DEMORADO"}
	};

	int id=1000;
	char name[TAM_NAME];
	char lastName[TAM_NAME];
	float price;
	char flycode[TAM_FLY];
	int typePassenger;
	int idEstado;
	int statusFly;
	int aux;

	int cantidadHardcodeo;
	char salir='n';
	if(initPassengers(pasajeros,TAM)==-1){
		printf("Hubo un error con los punteros o el tanio.\n");
	}
	vuelo();
	do{
		switch(menu()){
		case 1:
			switch(validarDatos(id,name, lastName, &price, flycode,&idEstado, &typePassenger, TAM_NAME, TAM_FLY, estados, TAM_ESTADO, &statusFly)){
			case 0:
				printf("Hubo un error al validar los punteros.\n");
				break;
			case 1:
				printf("No se guardaron los cambios.\n");
				break;
			case 2:
				if(!addPassenger(pasajeros, TAM, id, name, lastName, price,typePassenger,flycode, statusFly)){
					id++;
					printf(".......................................\n");
					printf("Se guardaron los datos con exito.\n");
				}else{
					printf("Hubo un error al validar los punteros.\n");
				}
				break;
			}
			break;
		case 2:
			enteroEnRango("Cuantos datos desea hard codear(1-50)", &cantidadHardcodeo,1,50);
			if(hardcodear(pasajeros,estados,TAM,TAM_ESTADO, &id,cantidadHardcodeo)==-1){
				printf("Error: puntero NULL o len menor a cero.\n");
			}else{
				printf(".......................................\n");
				printf("Se guardaron los datos con exito.\n");
			}
			break;
		case 3:
			if(buscarLibreUOcupado(pasajeros,TAM,0)!=-1){
				printfPassengers(pasajeros, TAM, estados, TAM_ESTADO);
				cargarValidarEntero("Ingrese el id del pasajero a modificar",&aux);
				if(modificarPasajero(pasajeros, TAM, aux, TAM_NAME, TAM_FLY, estados, TAM_ESTADO)==-1){
					printf("Error: puntero NULL o len menor a cero.\n");
				}
			}else{
				printf("Primero Carge un pasajero (opcion[1]).\n");
			}

			break;
		case 4:
			if(buscarLibreUOcupado(pasajeros,TAM,0)!=-1){
				printfPassengers(pasajeros, TAM, estados, TAM_ESTADO);
				cargarValidarEntero("Ingrese el id del pasajero a remover",&aux);
				if(removePassenger(pasajeros, TAM, aux, estados, TAM_ESTADO)==-1){
					printf("Error: puntero NULL o len menor a cero.\n");
				}
			}else{
				printf("Primero Carge un pasajero (opcion[1]).\n");
			}
			break;
		case 5:
			if(buscarLibreUOcupado(pasajeros,TAM,0)!=-1){
				if(informes(pasajeros, TAM, estados, TAM_ESTADO)==-1){
					printf("Error: puntero NULL o len menor a cero.\n");
				}

			}else{
				printf("Primero Carge un pasajero (opcion[1]).\n");
			}
			break;
		case 6:
			if(!cerrar(&salir)){
				printf("Hubo un problema con la validacion.\n");
			}
			break;
		}
		system("pause");
		system("cls");
	}while(salir!='s');
	return EXIT_SUCCESS;
}

