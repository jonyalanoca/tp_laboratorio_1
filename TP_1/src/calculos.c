/*
 * calculos.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int calcularCostos(int kilometros, float precioLatam, float precioAeroL, float costosLatam[], float costosAeroL[], float* pDiferencia){
	int todoOk=0;
	if(costosLatam!=NULL && costosAeroL!=NULL && pDiferencia!=NULL){

		costosLatam[0]=conDevito(precioLatam);
		costosLatam[1]=conCredito(precioLatam);
		costosLatam[2]=conBitcoins(precioLatam);
		costosLatam[3]=precioLatam/kilometros;

		costosAeroL[0]=conDevito(precioAeroL);
		costosAeroL[1]=conCredito(precioAeroL);
		costosAeroL[2]=conBitcoins(precioAeroL);
		costosAeroL[3]=precioAeroL/kilometros;

		diferenciaLatamAeroL(precioLatam,precioAeroL,pDiferencia);
		todoOk=1;

	}
	return todoOk;

}
float conDevito(float precio){
	return precio-(precio*10/100);
}
float conCredito(float precio){
	return precio+(precio*25/100);
}
float conBitcoins(float precio){
	return precio*1/4606954.55;
}
int diferenciaLatamAeroL(float precioLatam, float precioAeroL,float* pDiferencia){
	int todoOk=0;
	if(pDiferencia!=NULL){
		todoOk=1;
		*pDiferencia=precioLatam-precioAeroL;
		if(*pDiferencia<0){
			*pDiferencia*=-1;
		}
	}
	return todoOk;
}
