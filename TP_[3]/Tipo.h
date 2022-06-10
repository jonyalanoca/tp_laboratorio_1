/*
 * Tipo.h
 *
 *  Created on: 2 jun. 2022
 *      Author: Jony
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

#endif /* TIPO_H_ */
/// @fn int hardCodearTipos(eTipo[], int)
/// @brief  Recoree el array estructua eTipos y los hardcodea
///
/// @param tipos
/// @param tamT
/// @return retorna	-1: si falla la validacion o tam menos a uno
/// 				 0: si todo salio bien
int hardCodearTipos(eTipo tipos[],int tamT);
/// @fn int obtenerIdPorDescripcionTipo(eTipo[], int, char*)
/// @brief recorre y busca el la descripcion igual al string pasado por parametro y gurda su id
///
/// @param tipos
/// @param tamT
/// @param descripcionTipo
/// @return retorna:     -1: si falla la validacion o tam menor a uno. Si no se hubo emparejamiento con las descripciones
/// 				 numero: devuelve el id del emparejamiento.
int obtenerIdPorDescripcionTipo(eTipo tipos[], int tamT, char* descripcionTipo);
/// @fn int obtenerDescripcionPorIdTipo(eTipo[], int, int, char*)
/// @brief recorre y busca emparejar el id de la estructura con el id pasado por parametro. lo carga el el parametro descripcion
///
/// @param tipos
/// @param tamT
/// @param id
/// @param descripcion
/// @return	retorna -1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int obtenerDescripcionPorIdTipo(eTipo tipos[], int tamT, int id , char* descripcion);
/// @fn int mostrarTipos(eTipo[], int)
/// @brief recorre el array estructura eTipos y los  muetra en forma encolumnada
///
/// @param tipos
/// @param tamT
/// @return  retorna -1: si falla la validacion o tam menor a uno
/// 				  0: si todo salio bien
int mostrarTipos(eTipo tipos[], int tamT);
/// @fn int buscarIdExistenteTipo(eTipo[], int, int*)
/// @brief busca dentro del array estructura eTipo si existe el id pasado por parametro. Pide un numero entero positivo hsta que haya una conincidencia de ids
///
/// @param tipos
/// @param tamT
/// @param id
/// @return  retorna -1: si falla la validacion o tam menor a uno
/// 				  0: si todo salio bien
int buscarIdExistenteTipo(eTipo tipos[], int tamT, int* id);
