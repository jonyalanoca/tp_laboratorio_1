/*
 * VueloEstado.h
 *
 *  Created on: 1 may. 2022
 *      Author: Jony
 */
#ifndef VUELOESTADO_H_
#define VUELOESTADO_H_

typedef struct{
	int id;
	char codigoDeVuelo[15];
	char estado[15];
} eVueloEstado;

#endif /* VUELOESTADO_H_ */
/// @fn int printfEstados(eVueloEstado[], int)
/// @brief muestra por pantalla la lista de vuelos llamando a la funcion printfEstado.
///
/// @param lista
/// @param len
/// @return retorna -1: puntero NULL o len menor a 0,retorna  0 si todo salio bien
int printfEstados(eVueloEstado lista[], int len);
/// @fn void printfEstado(eVueloEstado)
/// @brief recibe una estructura y lo muestra en fila.
///
/// @param lista
void printfEstado(eVueloEstado lista);
/// @fn int validarDatos(char[], char[], float*, char[], int*, int, int)
/// @brief pide y valida los datos necesarios, es un paso previo a agregar los datos a nuestro array de estructura.
///
/// @param name
/// @param lastName
/// @param price
/// @param flycode
/// @param typePassenger
/// @param tamName
/// @param tamFly
/// @return retorna -1 para puntero nulo o tam menor a cero, 0 si todo salio bien.
int validarDatos(int id,char name[], char lastName[], float* price,char flycode[], int* idEstado, int* typePassenger, int tamName, int tamFly, eVueloEstado listaEstados[], int tamEstados, int* statusFly);
/// @fn void printfPassengerParam(eVueloEstado[], int, int, char[], char[], float, int, int)
/// @brief recibe parametros con datos y los muetra en columnados y el fila de manera ordenada
///
/// @param lista
/// @param tamEstado
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param idEstado
void printfPassengerParam(eVueloEstado lista[],int tamEstado, int id,char name[], char lastName[], float price, int typePassenger, int idEstado);
/// @fn int buscarIndexPorId(eVueloEstado*, int, int, int)
/// @brief recive un index. Compara si existe dentro de la array estructura lista y si hay una coincidencia lo manda en el return.
///
/// @param lista
/// @param tam
/// @param id
/// @param inicio
/// @return -1: si no hubo coincidencia. mayor a -1 devuelve el index donde es encuentra ese ID.
int buscarIndexPorId(eVueloEstado* lista, int tam, int id, int inicio);
