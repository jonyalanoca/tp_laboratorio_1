/*
 * Estado.c
 *
 *  Created on: 2 jun. 2022
 *      Author: Jony
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Estado.h"
#include "validaciones.h"
int hardCodearEstados(eEstado estados[],int tamE){
	int todoOk=-1;
	int id=5000;
	char descripcion[4][20]={"Aterrizado","En Horario","Demorado", "En Vuelo"};
	if(estados!=NULL && tamE>0){
		for(int i =0; i<tamE;i++){
			estados[i].id=id;
			strcpy(estados[i].descripcion, descripcion[i]);
			id++;
		}
		todoOk=0;
	}
	return todoOk;
}
int obtenerIdPorDescripcionEstado(eEstado estados[],int tamE, char* descripcionEstado){
	int todoOk=-1;
	if(estados!=NULL && tamE>0){
		for(int i=0; i<tamE; i++){
			if(strcmp(estados[i].descripcion,descripcionEstado)==0){
				todoOk=estados[i].id;
				break;
			}
		}
	}
	return todoOk;
}
int obtenerDescripcionPorIdEstado(eEstado estados[], int tamE, int id , char* descripcion){
	int todoOk=-1;
	if(estados!=NULL && tamE>0 && descripcion !=NULL){
		for(int i=0; i<tamE; i++){
			if(estados[i].id==id){
				strcpy(descripcion, estados[i].descripcion);
				break;
			}
		}
		todoOk=1;
	}
	return todoOk;
}
int mostrarEstados(eEstado estados[], int tamE){
	int todoOk=-1;
	if(estados!=NULL && tamE>0){
		system("cls");
		printf("LISTA ESTADOS DE VUELO\n");
		printf("-----------------------\n");
		printf("|  ID | DESCRIPCION   |\n");
		printf("-----------------------\n");
		for(int i=0; i<tamE;i++){
			printf("|%4d | %-14s|\n",estados[i].id, estados[i].descripcion);
			printf("-----------------------\n");
		}
		todoOk=0;
	}
	return todoOk;
}
int buscarIdExistenteEstado(eEstado estados[], int tamE, int* id){
	int todoOk=-1;
	if(estados!=NULL && tamE>0){
		do{
			cargarValidarEnteroPositivo("Ingrese el id el tipo de pasajero",id);
			for(int i=0;i<tamE;i++){
				if(estados[i].id==*id){
					todoOk=0;
					break;
				}
			}
			if(todoOk==-1){
				printf("El id ingresado no existe. Vuela a intentarlo\n");
			}

		}while(todoOk==-1);
	}
	return todoOk;
}
