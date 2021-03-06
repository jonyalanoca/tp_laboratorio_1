/*
 ============================================================================
 Name        : TP_1.c
 Author      : Alanoca Aduviri Jonathan Gerardo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "validaciones.h"
#include "calculos.h"
#include "informes.h"
#include "otros.h"
#define TAM 5

int main(void) {
	setbuf(stdout,NULL);

	char salir='n';
	int kilometros=0;
	float precioAeroL=0;
	float precioLatam=0;
	float diferencia;
	float costosLatam[TAM];
	float costosAeroL[TAM];
	int opt4Calculos=0;
	char volver='n';

	do{
		switch(menu(kilometros, precioAeroL, precioLatam)){
			case 1:
				if(!enteroPositivo("Ingrese los kilometros",&kilometros)){
					printf("Hubo un error con los punteros.\n");
				}
				else{
					printf("Se cargo los kilometros con exito.\n");
					opt4Calculos=0;
				}
				break;
			case 2:
				do{
					system("cls");
					switch(menuIngresarPrecio()){
					case 1:
						decimalPositivo("Ingrese el precio de vuelo por AeroLineas", &precioAeroL);
						opt4Calculos=0;
						break;
					case 2:
						decimalPositivo("Ingrese el precio de vuelo por Latam", &precioLatam);
						opt4Calculos=0;
						break;
					case 3:
							volver='n';
						break;
					}
				}while(volver=='s');
				printf("Se guardaron los cambios.\n");
				volver='s';
				break;
			case 3:
				if(!precioAeroL || !precioLatam || !kilometros){
					printf("Porfavor primero complete las opciones [1] y/o [2] para continuar.\n");
				}else{
					if(!calcularCostos(kilometros, precioLatam, precioAeroL, costosLatam, costosAeroL, &diferencia)){
						printf("Hubo un error con los punteros.\n");
					}else{
						opt4Calculos=1;
						printf("Se calcularon todos los datos exitosamente.\n");
					}
				}
				break;
			case 4:
				if(!opt4Calculos){
					printf("Porfavor primero complete las opciones [3] para continuar.\n");
				}else{
					if(!informes(kilometros, precioLatam, precioAeroL, costosLatam, costosAeroL, &diferencia)){
						printf("Hubo un error con los punteros.\n");
					}
				}
				break;
			case 5:
				if (forzarCarga(&kilometros,&precioLatam, &precioAeroL)){
					calcularCostos(kilometros, precioLatam, precioAeroL, costosLatam, costosAeroL, &diferencia);
					opt4Calculos=1;
					informes(kilometros, precioLatam, precioAeroL, costosLatam, costosAeroL, &diferencia);
				}else{
					printf("Hubo un error con los punteros.\n");
				}
				break;
			case 6:
				if(!cerrar(&salir)){
					printf("Hubo un error con los punteros.\n");
				}
				break;
		}
		system("pause");
		system("cls");
	}while(salir!='s');
	return EXIT_SUCCESS;
}
