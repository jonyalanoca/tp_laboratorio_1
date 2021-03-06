/*
 * ArrayPassenger.h
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "VueloEstado.h"
#define TAM_NAME 51
#define TAM_FLY 10
typedef struct{
	int id;
	char name[TAM_NAME];
	char lastName[TAM_NAME];
	float price;
	char flycode[TAM_FLY];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

#endif /* ARRAYPASSENGER_H_ */
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initPassengers(Passenger* list, int len);
/// @fn int buscarLibreUOcupado(Passenger*, int, int)
/// @brief Recorre el array estructura y nos informa el index del primer isEmpty=0 o isEmpty=1 dependiendo del criterio
///
/// @param list
/// @param len
/// @param citerio
/// @return retorna -1 si la lista esta llena o no se valido los punteros y/o tam<0
int buscarLibreUOcupado(Passenger* list, int len, int citerio);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFly);
/// @fn void printfPassenger(Passenger)
/// @brief recive una estructura y lo muetra en fila
///param estados eVueloEstado*
/// param lenEstados int
///
/// @param pasajero
void printfPassenger(Passenger pasajero, eVueloEstado estados[], int lenEstados);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \param estados eVueloEstado*
* \param lenEstados int
* \return int
*/
int printfPassengers(Passenger pasajeros[], int length, eVueloEstado estados[], int lenEstados);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*/
int findPassengerById(Passenger* list, int len,int id);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* param estados eVueloEstado*
/// param lenEstados int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a passenger] - (0) if Ok
*/
int removePassenger(Passenger* list, int len, int id, eVueloEstado estados[], int lenEstados);
/// @fn int modificarPasajero(Passenger*, int, int, int, int)
/// @brief funcion para modificar y actualizar los datos(independientes) de un pasajero. cuenta con su propio submenu y valida los datos antes de cargar.
///
/// @param list
/// @param len
/// @param id
/// @param tamName
/// @param tamFly
/// param estados eVueloEstado*
/// param lenEstados int
/// @return retorna -1 para puntero nulo o len invalido, 0 si todo salio bien.
int modificarPasajero(Passenger* list, int len, int id,int tamName, int tamFly, eVueloEstado estados[], int lenEstados);
/// @fn int informes(Passenger*, int)
/// @brief cuenta con un submenu y llama a las fuciones para realizar los distintos inoformes
///
/// @param list
/// @param len
/// param estados eVueloEstado*
/// param lenEstados int
/// @return retorna -1 para puntero nulo o len invalido, 0 si todo salio bien.
int informes(Passenger* list, int len, eVueloEstado estados[], int lenEstados);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* param estados eVueloEstado*
/// param lenEstados int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengers(Passenger* list, int len, int order, eVueloEstado estados[], int lenEstados);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* param estados eVueloEstado*
/// param lenEstados int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassengersByCode(Passenger* list, int len, int order, eVueloEstado estados[], int lenEstados);
/// @fn int informarPrecioPromedio(Passenger*, int)
/// @brief infoma la suma total de precios, precio promedio y pasajeros que superen ese precio promedio.Muetra un peque??o informe.
///
/// @param list
/// @param len
/// param estados eVueloEstado*
/// param lenEstados int
/// @return retorna -1 para puntero nulo o len invalido, 0 si todo salio bien.
int informarPrecioPromedio(Passenger* list, int len, eVueloEstado estados[], int lenEstados);

