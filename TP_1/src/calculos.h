/*
 * calculos.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Jony
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_



#endif /* CALCULOS_H_ */
/// @fn int calcularCostos(int, float, float, float[], float[], float*)
/// @brief				Calcula los constos correspondiente al TP1, con los datos previamente validados
///
/// @param kilometros	Son los kilometros de viaje
/// @param precioLatam	Es el precio por el vuelo en Latam
/// @param precioAeroL	Es el precio por el vuelo en AeroLineas
/// @param costosLatam	En esta lista se guardan los datos (calculados) correspondiente a Latam
/// @param costosAeroL	En esta lista se guardan los datos (calculados) correspondiente a AeroLineas
/// @param diferencia	Puntero que guarda la diferencia de precio entre Latam y AeroLineas
/// @return				Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int calcularCostos(int kilometros, float precioLatam, float precioAeroL, float costosLatam[], float costosAeroL[], float* pDiferencia);
/// @fn float conDevito(float)
/// @brief 			Realiza el calculo aplicando un 10% de descuento.
///
/// @param precio	Es el precio original
/// @return			Devuelve el Precio total con descuento.
float conDevito(float precio);
/// @fn float conCredito(float)
/// @brief 			Realiza el calculo aplicando un 25% de interes.
///
/// @param precio	Es el precio original
/// @return			Devuelve el Precio total con un interes.
float conCredito(float precio);
/// @fn float conBitcoins(float)
/// @brief			Realiza el calculo pasando de Pesos  a bitcoins (1peso ->4606954.55 BTC)
///
/// @param precio	Es el precio original
/// @return			Devuelve el precio equivalente en bitcois
float conBitcoins(float precio);
/// @fn int diferenciaLatamAeroL(float, float, float*)
/// @brief 				Se realiza la resta entre los precio de latam y AeroLineas, y le aplicamos un modulo
///
/// @param precioLatam	El precio de vuelo en Latam
/// @param precioAeroL	El precio de vuelo en AeroLienas
/// @param diferencia	Puntero. La diferencia de precios entre latam y aerolinas
/// @return				Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int diferenciaLatamAeroL(float precioLatam, float precioAeroL,float* pDiferencia);
