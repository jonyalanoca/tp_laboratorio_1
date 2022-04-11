/*
 * otros.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Jony
 */

#ifndef OTROS_H_
#define OTROS_H_



#endif /* OTROS_H_ */
/// @fn int forzarCarga(int*, float*, float*)
/// @brief 				Llena los datos kilometros, precio por latam, precio por aerolineas, realiza los calculos y muetra el informe automaticamente con un solo click.
///
/// @param kilometros	Entero son los kilometros de vuelo
/// @param precioLatam	Flotante, es el precio de vuelo por Latam
/// @param precioAeroL	Flotante, es el precio de vuelo por Latam
/// @return				Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int forzarCarga(int* kilometros, float* pPrecioLatam, float* pPrecioAeroL);
/// @fn int cerrar(char*)
/// @brief 			Una advertecia de que esta por cerrar el programa. Se confirma con una 's' o 'S' unicamente
///
/// @param salir	Puntero char, guarda el caracter de confirmacion.
/// @return			Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int cerrar(char* pSalir);
