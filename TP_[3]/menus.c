/*
 * menus.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "validaciones.h"
int menu(void){
	int opcion;
	printf("----------------------------------------\n");
	printf(" \t..[MENU AGENCIA DE VIAJES]..\n");
	printf("========================================\n\n");
	printf("  [1] CARGAR LOS PASAJEROS EN MODO TEXTO.\n");
	printf("  [2] CARGAR LOS PASAJEROS EN MODO BINARIO.\n");
	printf("  [3] ALTA PASAJEROS .\n");
	printf("  [4] MODIFICAR DATOS DE PASAJERO.\n");
	printf("  [5] BAJA DE PASAJEROS.\n");
	printf("  [6] LISTAR PASAJEROS.\n");
	printf("  [7] ORDENAR PASAJEROS.\n");
	printf("  [8] GUARDAR LOS DATOS EN UN ARCHIVO data.csv.\n");
	printf("  [9] GUARDAR LOS DATOS EN UN ARCHIVO data.bin.\n");
	printf("  [10] SALIR.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,10)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuModificar(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[MENU MODIFICAR PASAJERO]..\n");
	printf("========================================\n\n");
	printf("  [1]  Modificar nombre.\n");
	printf("  [2]  Modificar apellido.\n");
	printf("  [3]  Modificar codigo de vuelo.\n");
	printf("  [4]  Modificar precio.\n");
	printf("  [5]  Modificar tipo de pasaje.\n");
	printf("  [6]  Modificar estado de vuelo.\n");
	printf("  [7]  Volver al menu principal.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,7)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int menuInformes(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[MENU DE INFORMES]..\n");
	printf("========================================\n\n");
	printf("  [1]  Litas pasajeros.\n");
	printf("  [2]  Listar por apellido y tipo de pasajero.\n");
	printf("  [3]  Listar por codigo de vuelo y estado de vuelo (ACTIVO).\n");
	printf("  [4]  Listar pasajeros superando el precio promedio.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,4)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
int ascendenteDescendente(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[TIPO DE ORDENAMIENTO]..\n");
	printf("========================================\n\n");
	printf("  [1]  Ordenar ascendente.\n");
	printf("  [2]  Ordenar descendente\n");

	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,2)){
		printf("Algo ha salido mal.\n");
	}
	return opcion;
}
