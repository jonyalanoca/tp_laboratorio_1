/*
 * informes.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Jony
 */

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */
/// @fn int informes(int, float, float, float[], float[], float*)
/// @brief 					Nos hace un informe por pantalla de los datos pedidos en el TP1. Los datos son previamente validados y calculados.
///
/// @param kilometros		Son los kilometros de viajes
/// @param precioLatam		Es el precio de vuelo por Latam
/// @param precioAeroL		Es el precio de vuelo por AeroLineas
/// @param costosLatam		Lista, Tiene guardado los precios calculados(%10 descuento, 25%interes, precio en bitcoins, precio unitario) correspodiente a Latam
/// @param costosAeroL 		Lista, Tiene guardado los precios calculados(%10 descuento, 25%interes, precio en bitcoins, precio unitario) correspodiente a AeroLineas
/// @param diferencia		Es el precio de diferencia entre AeroLineas y Latam
/// @return					Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int informes(int kilometros, float precioLatam, float precioAeroL, float costosLatam[], float costosAeroL[], float* pDiferencia);
/// @fn int informe(float[])
/// @brief					Crea un informe con los datos de una lista.
///
/// @param costo			Lista con los precios calculados.
/// @return					Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int informe(float costo[]);
