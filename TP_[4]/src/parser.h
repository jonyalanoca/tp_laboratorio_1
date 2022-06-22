/*
 * parser.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Jony
 */
#include "../inc/LinkedList.h"
#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */
/// @fn int parser_cargarTexto(FILE*, LinkedList*)
/// @brief  funcion encargada de cargar los datos de un archivo csv en un linkedlist
///
/// @param pFile
/// @param listaCPU
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int parser_cargarTexto(FILE* pFile, LinkedList* listaCPU);
