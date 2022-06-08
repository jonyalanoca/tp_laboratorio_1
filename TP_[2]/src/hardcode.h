/*
 * hardcode.h
 *
 *  Created on: 3 may. 2022
 *      Author: Jony
 */

#ifndef HARDCODE_H_
#define HARDCODE_H_



#endif /* HARDCODE_H_ */
/// @fn int hardcodear(Passenger*, eVueloEstado*, int, int, int*, int)
/// @brief  Carga automaticamente datos dentro en nuestro array de estructura
///
/// @param list
/// @param listaEstados
/// @param len
/// @param lenEstados
/// @param ids
/// @param cantidad
/// @return retorna -1: puntero NULL o len menor a 0,retorna  0 si todo salio bien
int hardcodear(Passenger* list,eVueloEstado* listaEstados, int len,int lenEstados, int* ids, int cantidad);
