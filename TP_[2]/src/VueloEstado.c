/*
 * VueloEstado.c
 *
 *  Created on: 1 may. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VueloEstado.h"
#include "validaciones.h"

int printfEstados(eVueloEstado lista[], int len){
	int todoOk=-1;
	if(lista!=NULL && len>0){
		printf("\n\n  ID  COD-VUELO     ESTADO\n");
		printf("..........................\n");
		for(int i=1;i<len;i++){
			printfEstado(lista[i]);
		}
		printf("..........................\n");
		todoOk=0;
	}
	return todoOk;
}
void printfEstado(eVueloEstado lista){
	printf("%4d %10s %10s\n", lista.id, lista.codigoDeVuelo, lista.estado);
}

int validarDatos(int id,char name[], char lastName[], float* price,char flycode[], int* idEstado, int* typePassenger, int tamName, int tamFly, eVueloEstado listaEstados[], int tamEstados, int* statusFly){
	int todoOk=0;
	int seccion=0;
	char confirmar;
	int auxEntero=0;

	int auxId=id;
	char auxName[51]="-";
	char auxLastName[51]="-";
	float auxPrice=0;
	int auxTypePassenger=0;
	int auxIdEstado=0;
	if(name!=NULL && lastName!=NULL && price!=NULL && typePassenger!=NULL &&idEstado &&flycode && tamName>0 && tamFly>0){
		do{
			printfPassengerParam(listaEstados, tamEstados,auxId, auxName,auxLastName, auxPrice, auxTypePassenger, auxIdEstado);
			switch(seccion){
			case 0:
				cargarValidarCadena("Ingrese el nombre del pasajero",tamName,auxName);
				break;
			case 1:
				cargarValidarCadena("Ingrese el apellido del pasajero",tamName,auxLastName);
				break;
			case 2:
				cargarValidarDecimalPositivo("Ingrese el precio", &auxPrice);
				break;
			case 3:
				enteroEnRango("Ingrese en que clase viaja(1/2/3)",&auxTypePassenger, 1,3);
				break;
			case 4:
				printfEstados(listaEstados, tamEstados);
				do{
					cargarValidarEntero("Ingrese el ID del del vuelo", &auxIdEstado);
					auxEntero= buscarIndexPorId(listaEstados, tamEstados, auxIdEstado,1);
					if(auxEntero==-1){
						printf("No se encontro el id. Vuelva a intentear.\n");
					}
				}while(auxEntero==-1);
				break;
			}
			seccion++;
		}while(seccion<6);
		cargarValidarCharEntreDos("??Desea guardar el pasajero?.Porfavor confirme si o no (s/n)",&confirmar,'s','n');
		if(confirmar=='s'){
			strcpy(name, auxName);
			strcpy(lastName, auxLastName);
			*price=auxPrice;
			*typePassenger=auxTypePassenger;
			*idEstado= auxIdEstado;
			strcpy(flycode, listaEstados[auxEntero].codigoDeVuelo);
			*statusFly=auxIdEstado;
			todoOk=2;
		}else{
			todoOk=1;
		}
	}
	return todoOk;
}
int buscarIndexPorId(eVueloEstado* lista, int tam, int id, int inicio){
	int todoOk=-1;
	if(lista!=NULL && tam>0){
		for(int i=inicio; i<tam; i++){
			if(lista[i].id==id){
				todoOk=i;
			}
		}
	}
	return todoOk;
}
void printfPassengerParam(eVueloEstado lista[],int tamEstado, int id,char name[], char lastName[], float price, int typePassenger, int idEstado){
	if(lista!=NULL && tamEstado>0 && name!=NULL && lastName!=NULL){
		system("cls");
		printf(".......................................................................\n");
		printf("  ID       NOMBRE     APELLIDO      PRECIO  CLASE     CODIGO     ESTADO\n");
		printf("%4d %12s %12s  $%9.2f %6d %10s %10s\n",id, name,lastName, price, typePassenger, lista[buscarIndexPorId(lista,tamEstado, idEstado,0)].codigoDeVuelo,lista[buscarIndexPorId(lista,tamEstado, idEstado,0)].estado);
		printf(".......................................................................\n");
	}
}


