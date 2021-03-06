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
	printf("  [1]  Alta de pasajero.\n");
	printf("  [2]  Forzar carga de pasajeros.\n");
	printf("  [3]  Modificar pasajero.\n");
	printf("  [4]  Baja Pasajero.\n");
	printf("  [5]  Informes.\n");
	printf("  [6]  Salir.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,6)){
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
	printf("  [3]  Modificar precio.\n");
	printf("  [4]  Modificar tipo de pasaje.\n");
	printf("  [5]  Modificar codigo de vuelo.\n");


	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,5)){
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
