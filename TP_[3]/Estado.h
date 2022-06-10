/*
 * Estado.h
 *
 *  Created on: 2 jun. 2022
 *      Author: Jony
 */

#ifndef ESTADO_H_
#define ESTADO_H_

typedef struct{
	int id;
	char descripcion[20];
}eEstado;

#endif /* ESTADO_H_ */
/// @fn int hardCodearEstados(eEstado[], int)
/// @brief carga los valores del array de strcutura eEstado
///
/// @param estados
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int hardCodearEstados(eEstado estados[],int tamE);
/// @fn int obtenerIdPorDescripcionEstado(eEstado[], int, char*)
/// @brief Tiene como objetivo encontrar coincidencia entre la descripcion de la estructura y la descripcion pasado por parametro
///
/// @param estados
/// @param tamE
/// @param descripcionEstado
/// @return  retorna	-1: si falla la validacion o tam menor a uno
/// 		 			 numero: el id de la coincidencia
int obtenerIdPorDescripcionEstado(eEstado estados[],int tamE, char* descripcionEstado);
/// @fn int obtenerDescripcionPorIdEstado(eEstado[], int, int, char*)
/// @brief Tiene como objetivo encontrar coincidencia entre el id de la estructura y el id pasado por parametro
/// 		Se carga el string  de la descripcion en el puntero pasado  por paramtro una vez encontrado la coincidencia
/// @param estados
/// @param tamE
/// @param id
/// @param descripcion
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int obtenerDescripcionPorIdEstado(eEstado estados[], int tamE, int id , char* descripcion);
/// @fn int mostrarEstados(eEstado[], int)
/// @brief recorre y lista en forma encolumnada los valores del array estructura eEstado
///
/// @param estados
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int mostrarEstados(eEstado estados[], int tamE);
/// @fn int buscarIdExistenteEstado(eEstado[], int, int*)
/// @brief pide y valida un entero hasta que se ingrese alguno de los ids
///
/// @param estados
/// @param tamE
/// @param id
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien y hubo coincidencia
int buscarIdExistenteEstado(eEstado estados[], int tamE, int* id);
