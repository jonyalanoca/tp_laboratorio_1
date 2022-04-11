/*
 * informes.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
int informes(int kilometros, float precioLatam, float precioAeroL, float costosLatam[], float costosAeroL[], float* pDiferencia){
	int todoOk=0;
	if(costosLatam!=NULL && costosAeroL!=NULL && pDiferencia!=NULL){
		system("cls");
		printf("KMs ingresados: %d\n\n", kilometros);
		printf("Precio AeroLineas: $%.2f\n", precioAeroL);
		informe(costosAeroL);
		printf("Precio Latam: $%.2f\n", precioLatam);
		informe(costosLatam);
		printf("La diferencia de precios es: $ %.2f\n\n", *pDiferencia);
		todoOk=1;
	}
	return todoOk;
}
int informe(float costo[]){
	int todoOk=0;
	if(costo!=NULL){
		printf("a) Precio con targeta de devito: $ %.2f\n",costo[0]);
		printf("a) Precio con targeta de credito: $ %.2f\n",costo[1]);
		printf("a) Precio pagando con bitcoin: %.5f BTC\n",costo[2]);
		printf("a) Mostrar precio unitario: $ %.2f\n\n",costo[3]);
		todoOk=1;
	}
	return todoOk;
}

