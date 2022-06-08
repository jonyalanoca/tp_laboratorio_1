/*
 * Tipo.h
 *
 *  Created on: 2 jun. 2022
 *      Author: Jony
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

#endif /* TIPO_H_ */
int hardCodearTipos(eTipo tipos[],int tamT);
int obtenerIdPorDescripcionTipo(eTipo tipos[], int tamT, char* descripcionTipo);
int obtenerDescripcionPorIdTipo(eTipo tipos[], int tamT, int id , char* descripcion);
int mostrarTipos(eTipo tipos[], int tamT);
int buscarIdExistenteTipo(eTipo tipos[], int tamT, int* id);