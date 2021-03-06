/*
 * menus.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "validaciones.h"

int menu(int emptyKM, float emptyAeroL, float emptyLatam){
	int opcion;
	printf("----------------------------------------\n");
	printf(" \t..[MENU AGENCIA DE VIAJES]..\n");
	printf("========================================\n\n");
	if(!emptyKM){
		printf("  [1]  Ingresar Kilometros:(km=x) \n");
	}
	else{
		printf("  [1]  Ingresar Kilometros:(km=%d) \n", emptyKM);
	}
	if(!emptyAeroL ||!emptyLatam){
		printf("  [2]  Ingresar Precio de Vuelos:(AeroLineas= y , Latam=z)\n");
	}else{
		printf("  [2]  Ingresar Precio de Vuelos:(AeroLineas= %.2f , Latam= %.2f)\n", emptyAeroL, emptyLatam);
	}
	printf("  [3]  Calcular todos los costos:\n");
	printf("  [4]  Informar resultados.\n");
	printf("  [5]  Carga forzada de datos.\n");
	printf("  [6]  Salir.\n");
	printf("________________________________________\n\n");

	if(!enteroEntreDos("Ingrese una opciones del menu",&opcion,1,6)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuIngresarPrecio(){
	int opcion;
	printf("----------------------------------------\n");
	printf(" \t..[MENU PRECIO DE VUELOS]..\n");
	printf("========================================\n\n");
	printf("  [1]  Ingresar Precio de Vuelo por Aerolineas.\n");
	printf("  [2]  Ingresar Precio de Vuelo por Latam.\n");
	printf("  [3]  Volver al menu principal.\n");

	printf("________________________________________\n\n");

	if(!enteroEntreDos("Ingrese una opciones del menu",&opcion,1,3)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}

