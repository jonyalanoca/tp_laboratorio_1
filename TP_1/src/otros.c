/*
 * otros.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "otros.h"

int forzarCarga(int* kilometros, float* pPrecioLatam, float* pPrecioAeroL){
	int todoOk=0;
	if(kilometros!=NULL && pPrecioLatam!=NULL && pPrecioAeroL!=NULL){
		*kilometros=7090;
		*pPrecioLatam=159339;
		*pPrecioAeroL=162965;
		todoOk=1;
	}
	return todoOk;
}
int cerrar(char* pSalir){
	int todoOk=0;
	if(pSalir!=NULL){
		system("cls");
		printf("ATENCION.\nEsta por salir del programa.\nPara confirmar presione (s): ");
		fflush(stdin);
		scanf("%c", pSalir);
		*pSalir=tolower(*pSalir);
	}
	return todoOk;
}
