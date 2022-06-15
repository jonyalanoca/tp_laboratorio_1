/*
 * controller.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Jony
 */
#include "../inc/LinkedList.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
int controller_cargarArchivoTexto(char* path,LinkedList* listaCPU);
int controller_listarCPUs( LinkedList* listaCPU);
int controller_tamanioLista(LinkedList* listaCPU);
int controller_agregarAlFinal(LinkedList* listaCPU, int* id);
int controller_insertarReemplazarCPU(LinkedList* listaCPU, int* id);
int controller_insertarSinReemplazarCPU(LinkedList* listaCPU, int* id);
int cotroller_pedirDatos(int fila,int col, char matriz[][col], int* id);
int controller_obtenerIndex(LinkedList* listaCPU);
int controller_comprarListas(LinkedList* listaCPU, LinkedList* listaCPUClon);
int controller_compararUnElemento(LinkedList* listaCPU, LinkedList* listaCPUClon);
int controller_eliminarUnElemento(LinkedList* listaCPUClon);
int controller_obtenerIndexPorId(LinkedList* listaCPUClon, int id);
int controller_limpiarListaClon10(LinkedList* listaCPUs);
int controller_limpiarElementos(LinkedList* listaCPU);
int controller_eliminarElementoYAgregarloAlPrincipal(LinkedList* listaCPUs,LinkedList* listaCPUsClon, int id);
int controller_guardarComoTexto(char* path, LinkedList* listaCPUs);
