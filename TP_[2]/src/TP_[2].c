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
#define TAM 2000

int main(void) {
	setbuf(stdout,NULL);
	Passenger pasajeros[TAM];

	int id=1000;
	char name[TAM_NAME];
	char lastName[TAM_NAME];
	float price;
	char flycode[TAM_FLY];
	int typePassenger;

	int aux;
	char salir='n';
	if(initPassengers(pasajeros,TAM)==-1){
		printf("Hubo un error con los punteros o el tanio.\n");
	}

	do{
		switch(menu()){
		case 1:
			validarDatos(name, lastName, &price, flycode, &typePassenger, TAM_NAME, TAM_FLY);
			if(!addPassenger(pasajeros, TAM, id, name, lastName, price,typePassenger,flycode)){
				id++;
			}else{
				printf("Hubo un error al validar los punteros.\n");
			}
			break;
		case 2:
			if(buscarLibreUOcupado(pasajeros,TAM,0)!=-1){
				printfPassengers(pasajeros, TAM);
				cargarValidarEntero("Ingrese el id del pasajero a modificar",&aux);
				if(modificarPasajero(pasajeros, TAM, aux, TAM_NAME, TAM_FLY)==-1){
					printf("Error: puntero NULL o len menor a cero.\n");
				}
			}else{
				printf("Primero Carge un pasajero (opcion[1]).\n");
			}

			break;
		case 3:
			if(buscarLibreUOcupado(pasajeros,TAM,0)!=-1){
				printfPassengers(pasajeros, TAM);
				cargarValidarEntero("Ingrese el id del pasajero a remover",&aux);
				if(removePassenger(pasajeros, TAM, aux)==-1){
					printf("Error: puntero NULL o len menor a cero.\n");
				}
			}else{
				printf("Primero Carge un pasajero (opcion[1]).\n");
			}
			break;
		case 4:
			if(buscarLibreUOcupado(pasajeros,TAM,0)!=-1){
				if(informes(pasajeros, TAM)==-1){
					printf("Error: puntero NULL o len menor a cero.\n");
				}

			}else{
				printf("Primero Carge un pasajero (opcion[1]).\n");
			}
			break;
		case 5:
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
