/*
 * Tipo.c
 *
 *  Created on: 2 jun. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tipo.h"
#include "validaciones.h"
int hardCodearTipos(eTipo tipos[],int tamT){
	int todoOk=-1;
	int id=1000;
	char descripcion[3][20]={"EconomyClass","ExecutiveClass","FirstClass"};
	if(tipos!=NULL && tamT>0){
		for(int i =0; i<tamT;i++){
			tipos[i].id=id;
			strcpy(tipos[i].descripcion, descripcion[i]);
			id++;
		}
		todoOk=0;
	}
	return todoOk;
}
int obtenerIdPorDescripcionTipo(eTipo tipos[], int tamT, char* descripcionTipo){
	int todoOk=-1;
	if(tipos!=NULL && tamT>0){
		for(int i=0; i<tamT; i++){
			if(strcmp(tipos[i].descripcion,descripcionTipo)==0){
				todoOk=tipos[i].id;
				break;
			}
		}
	}
	return todoOk;
}
int obtenerDescripcionPorIdTipo(eTipo tipos[], int tamT, int id , char* descripcion){
	int todoOk=-1;
	if(tipos!=NULL && tamT>0 && descripcion !=NULL){
		for(int i=0; i<tamT; i++){
			if(tipos[i].id==id){
				strcpy(descripcion, tipos[i].descripcion);
				break;
			}
		}
		todoOk=0;
	}
	return todoOk;
}
int mostrarTipos(eTipo tipos[], int tamT){
	int todoOk=-1;
	if(tipos!=NULL && tamT>0){
		system("cls");
		printf("LISTA TIPOS DE PASAJEROS\n");
		printf("-----------------------\n");
		printf("|  ID | DESCRIPCION   |\n");
		printf("-----------------------\n");
		for(int i=0; i<tamT;i++){
			printf("|%4d | %-14s|\n",tipos[i].id, tipos[i].descripcion);
			printf("-----------------------\n");
		}
		todoOk=0;
	}
	return todoOk;
}
int buscarIdExistenteTipo(eTipo tipos[], int tamT, int* id){
	int todoOk=-1;
	if(tipos!=NULL && tamT>0){
		do{
			cargarValidarEnteroPositivo("Ingrese el id el tipo de pasajero",id);
			for(int i=0;i<tamT;i++){
				if(tipos[i].id==*id){
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
