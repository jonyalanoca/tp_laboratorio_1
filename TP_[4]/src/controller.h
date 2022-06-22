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
/// @fn int controller_cargarArchivoTexto(char*, LinkedList*)
/// @brief abre el archivo de texto y lo mantiene abierto hasta que se cargen o no los datos al linked list
///
/// @param path
/// @param listaCPU
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_cargarArchivoTexto(char* path,LinkedList* listaCPU);
/// @fn int controller_listarCPUs(LinkedList*)
/// @brief recorre el linked lista y muestra todos los elemtos que contiene en forma encolumnada.
///
/// @param listaCPU
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_listarCPUs( LinkedList* listaCPU);
/// @fn int controller_tamanioLista(LinkedList*)
/// @brief informa el tamanio del linked list
///
/// @param listaCPU
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_tamanioLista(LinkedList* listaCPU);
/// @fn int controller_agregarAlFinal(LinkedList*, int*)
/// @brief pide y valida los datos y los agrega al final de la lista
///
/// @param listaCPU
/// @param id
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_agregarAlFinal(LinkedList* listaCPU, int* id);
/// @fn int controller_insertarReemplazarCPU(LinkedList*, int*)
/// @brief Usa la funcion ll_set(). Se piden y validan datos luego se pide un index a donde reemplazar para posteriormemte reemplazarlo.
///
/// @param listaCPU
/// @param id
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_insertarReemplazarCPU(LinkedList* listaCPU, int* id);
/// @fn int controller_insertarSinReemplazarCPU(LinkedList*, int*)
/// @brief usa la funcion ll_push(). Se piden y validan datos, luego se pide un index a donde insertarlo. no reemplaza
///
/// @param listaCPU
/// @param id
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_insertarSinReemplazarCPU(LinkedList* listaCPU, int* id);
/// @fn int cotroller_pedirDatos(int, int, char[][], int*)
/// @brief pide datos y los valida
///
/// @param fila
/// @param col
/// @param matriz
/// @param id
/// @return  retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cotroller_pedirDatos(int fila,int col, char matriz[][col], int* id);
/// @fn int controller_obtenerIndex(LinkedList*)
/// @brief usamos la funcion ll_indexOf() comparamos las estructuras del linked list con otra estructura.
/// 		en caso de haber conicidencia no s devuelve el index del linkedlist en donde hubo coincidencia.
///
/// @param listaCPU
/// @return  retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_obtenerIndex(LinkedList* listaCPU);
/// @fn int controller_comprarListas(LinkedList*, LinkedList*)
/// @brief compara dos linkedlist e informa si son iguales o no
///
/// @param listaCPU
/// @param listaCPUClon
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_comprarListas(LinkedList* listaCPU, LinkedList* listaCPUClon);
/// @fn int controller_compararUnElemento(LinkedList*, LinkedList*)
/// @brief copara un elemento con todos los elementos del linkedlist e informa si hubo o no coincidencia
///
/// @param listaCPU
/// @param listaCPUClon
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_compararUnElemento(LinkedList* listaCPU, LinkedList* listaCPUClon);
/// @fn int controller_eliminarUnElemento(LinkedList*)
/// @brief elimina un elemento del linked list
///
/// @param listaCPUClon
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_eliminarUnElemento(LinkedList* listaCPUClon);
/// @fn int controller_obtenerIndexPorId(LinkedList*, int)
/// @brief obtiene el index del linked list por su id pasado por parametro
///
/// @param listaCPUClon
/// @param id
/// @return retorna -1: si falla la validacion NULL o no hubo coincidencia
/// 		retorna  numero: el index de la coincidencia.
int controller_obtenerIndexPorId(LinkedList* listaCPUClon, int id);
/// @fn int controller_limpiarListaClon10(LinkedList*)
/// @brief borra todos lo nodos y elementos de la memoria dinamica del linked list pasado por parametro
///
/// @param listaCPUs
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_limpiarListaClon10(LinkedList* listaCPUs);
/// @fn int controller_limpiarElementos(LinkedList*)
/// @brief borra todos del linked list pasado por parametro
///
/// @param listaCPU
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_limpiarElementos(LinkedList* listaCPU);
/// @fn int controller_eliminarElementoYAgregarloAlPrincipal(LinkedList*, LinkedList*, int)
/// @brief se usa la fucion ll_pop. borra un elemento de la lista clon, obtenemos la direccion del elemento borrado y lo agrega alfinal de la lita principal.
///
/// @param listaCPUs
/// @param listaCPUsClon
/// @param id
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_eliminarElementoYAgregarloAlPrincipal(LinkedList* listaCPUs,LinkedList* listaCPUsClon, int id);
/// @fn int controller_guardarComoTexto(char*, LinkedList*)
/// @brief abre un archivo, si no hay lo crea, y guarda todos los valores del linked list en un archivo csv
///
/// @param path
/// @param listaCPUs
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int controller_guardarComoTexto(char* path, LinkedList* listaCPUs);
