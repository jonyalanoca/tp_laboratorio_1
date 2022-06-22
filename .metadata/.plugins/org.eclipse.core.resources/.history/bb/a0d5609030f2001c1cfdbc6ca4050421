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
	printf("-----------------------------------------------------------------------------\n");
	printf(" \t..[ MEJORES CPUs 2022]..\n");
	printf("========================================\n\n");
	printf("  [1] CARGAR EL RANKING DE CPUs EN MODO TEXTO.\n");
	printf("  [2] AGREGAR NUEVO CPU AL FINAL DE LA LISTA.\n");
	printf("  [3] INFORMAR EL TAMAÑO DE LA LISTA.\n");
	printf("  [4] AGREGAR Y REEPLAZAR NUEVO CPU EN UN INDEX DETERMINADO.\n");
	printf("  [5] INSERTAR UN NUEVO CPU EN UN INDEX DETERMINADO.\n");
	printf("  [6] OBTENER UN INDEX DE UN ELEMENTO ALEATORIO.\n");
	printf("  [7] ORDENAR POR ID\n");
	printf("  [8] ORDENAR POR PROCESADOR\n");
	printf("  [9] LISTAR CPUs.\n");
	printf("  [10] GURDAR EN UN ARCHIVO CSV.\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("  [11] CLONAR UN LISTA DE CPUs DE RESPALDO.\n");
	printf("  [12] LISTAR CPUs DE RESPALDO.\n");
	printf("  [13] COMPARAR LISTA DE RESPALDO CON LA PRINCIPAL.\n");
	printf("  [14] TOMAR UN ELEMENTO ALETORIO Y COMPARAR SI EXISTE EN LA LISTA PRINCIPAL.\n");
	printf("  [15] ELIMINAR UN ELEMENTO DE LA LISTA DE RESPALDO.\n");
	printf("----------------------------------------\n");
	printf("  [16] CLONAR LOS 10 CPUs PRIMEROS.\n");
	printf("  [17] LISTAR LOS 10 CPUs PRIMEROS.\n");
	printf("  [18] LIMPIAR LISTA.\n");
	printf("  [19] SELECCIONAR UN ELEMENTO, ELIMINARLO Y AGREAGARLO A LA LISTA PRINCIPAL.\n");
	printf("-----------------------------------------------------------------------------\n");
	printf("  [20] SALIR.\n");
	printf("-----------------------------------------------------------------------------\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,20)){
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
int menuOrdenar(void){
	int opcion;
	system("cls");
	printf("----------------------------------------\n");
	printf(" \t..[MENU DE ORDENAMIENTO]..\n");
	printf("========================================\n\n");
	printf("  [1]  Ordenar por id.\n");
	printf("  [2]  Ordenar por Nombre.\n");
	printf("  [3]  Ordenar por Apellido.\n");
	printf("  [4]  Ordenar por precio.\n");
	printf("  [5]  Ordenar por Codigo de vuelo.\n");
	printf("  [6]  Ordenar por Tipo de pasajero.\n");
	printf("  [7]  Ordenar por Estado de vuelo.\n");
	printf("  [8]  Volver al menu principal.\n");
	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,1,8)){
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
	printf("  [0]  Ordenar descendente.\n");
	printf("  [1]  Ordenar ascendente\n");

	printf("________________________________________\n\n");

	if(!enteroEnRango("Ingrese una opciones del menu",&opcion,0,1)){
		printf("Algo ha salido mal.\n");
	}
	printf("Estamos trabajando muy duro. Por favor, espere..\n");
	return opcion;
}
