/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "Estado.h"
#include "Tipo.h"
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[7];
	int estadoVuelo;

}Passenger;

/// @fn Passenger Passenger_new*()
/// @brief crea una estructura Passenger en la memoria dinamica y valida que no sea NULL
///
/// @return devuelve un puntero a la estructura Passenger
Passenger* Passenger_new();
/// @fn Passenger Passenger_newParametros*(char*, char*, char*, char*, char*, char*, char*, eTipo[], eEstado[], int, int)
/// @brief Crea una estructura Passenger en la memoria dinamica y carga sus tados pasados por parametros.
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param estadoVueloStr
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return devuelve un puntero a la estructura Passenger
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr, eTipo tipos[], eEstado estados[], int tamT, int tamE);

void Passenger_delete();
/// @fn int Passenger_setId(Passenger*, int)
/// @brief carga el valor de id en el puntero Passenger de forma segura
///
/// @param this
/// @param id
/// @return	retorna -1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int Passenger_setId(Passenger* this,int id);
/// @fn int Passenger_getId(Passenger*, int*)
/// @brief  saca el valor id del puntero Passenger de forma segura.
///
/// @param this
/// @param id
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getId(Passenger* this,int* id);

/// @fn int Passenger_setNombre(Passenger*, char*)
/// @brief carga el valor nombre dentro del puntero Passenger
///
/// @param this
/// @param nombre
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_setNombre(Passenger* this,char* nombre);
/// @fn int Passenger_getNombre(Passenger*, char*)
/// @brief saca de forma segura el valor nombre del puntero Passenger y lo guarda en el puntero nombre
///
/// @param this
/// @param nombre
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getNombre(Passenger* this,char* nombre);
/// @fn int Passenger_setApellido(Passenger*, char*)
/// @brief carga el string apellido en el puntero Passenger de forma segura
///
/// @param this
/// @param apellido
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien

int Passenger_setApellido(Passenger* this,char* apellido);
/// @fn int Passenger_getApellido(Passenger*, char*)
/// @brief saca el valor apellido del puntero Passenger y lo carga el puntero apellido de forma segura
///
/// @param this
/// @param apellido
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getApellido(Passenger* this,char* apellido);
/// @fn int Passenger_setCodigoVuelo(Passenger*, char*)
/// @brief  carga el string de codigoVuelo en el puntero  Passenger de forma segura
///
/// @param this
/// @param codigoVuelo
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @fn int Passenger_getCodigoVuelo(Passenger*, char*)
/// @brief  saca el valor codigoVuelo  del puntero Passenger y lo carga en codigoVuelo de forma segura
///
/// @param this
/// @param codigoVuelo
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/// @fn int Passenger_setTipoPasajero(Passenger*, int)
/// @brief carga el valor de entero en el puntero Passenger de forma segura
///
/// @param this
/// @param tipoPasajero
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
/// @fn int Passenger_getTipoPasajero(Passenger*, int*)
/// @brief saca el valor tipoPasajero del puntero Passenger y lo carga en tipoPasajero de forma segura
///
/// @param this
/// @param tipoPasajero
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
/// @fn int Passenger_setPrecio(Passenger*, float)
/// @brief carga el valor precio en el puntero Passenger de forma segura
///
/// @param this
/// @param precio
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_setPrecio(Passenger* this,float precio);
/// @fn int Passenger_getPrecio(Passenger*, float*)
/// @brief saca el valor precio del puntero Passenger y lo carga en precio de forma segura
///
/// @param this
/// @param precio
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getPrecio(Passenger* this,float* precio);

/// @fn int Passenger_setEstadoVuelo(Passenger*, int)
/// @brief  carga el valor estadoVuelo  en el puntero Passenger de forma segura
///
/// @param this
/// @param estadoVuelo
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
/// @fn int Passenger_getEstadoVuelo(Passenger*, int*)
/// @brief saca el valor estadoVuelo del puntero Passenger y lo carga en estadoVuelo de forma segura
///
/// @param this
/// @param estadoVuelo
/// @return	retorna -1: si falla la validacion
/// 				 0: si todo salio bien
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

/// @fn void mostrarPasajero(Passenger*, eTipo[], eEstado[], int, int)
/// @brief muestra los valores de la estructura Passenger en forma encolumnada, tambien transforma los valores estado de vuelo y tipos de pasajeros
///
/// @param pasajero
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
void mostrarPasajero(Passenger* pasajero, eTipo tipos[], eEstado estados[], int tamT, int tamE);

/// @fn int Passenger_modificarNombre(Passenger*)
/// @brief carga y valida el dato nombre para luego cargarlo en la estructura Passenger
///
/// @param pasajero
/// @return
int Passenger_modificarNombre(Passenger* pasajero);
/// @fn int Passenger_modificarApellido(Passenger*)
/// @brief carga y valida el dato apellido para luego cargarlo en la estructura Passenger
///
/// @param pasajero
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int Passenger_modificarApellido(Passenger* pasajero);
/// @fn int Passenger_modificarCodigoVuelo(Passenger*)
/// @brief carga y valida el dato codigoVuelo para luego cargarlo en la estructura Passenger
///
/// @param pasajero
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int Passenger_modificarCodigoVuelo(Passenger* pasajero);
/// @fn int Passenger_modificarPrecio(Passenger*)
/// @brief carga y valida el dato precio para luego cargarlo en la estructura Passenger
///
/// @param pasajero
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int Passenger_modificarPrecio(Passenger* pasajero);
/// @fn int Passenger_modificarTipoPasajero(Passenger*, eTipo[], int)
/// @brief carga y valida el dato tipoPasajero para luego cargarlo en la estructura Passenger
///
/// @param pasajero
/// @param tipos
/// @param tamT
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int Passenger_modificarTipoPasajero(Passenger* pasajero,eTipo tipos[], int tamT);
/// @fn int Passenger_modificarEstadoVuelo(Passenger*, eEstado[], int)
/// @brief carga y valida el dato estadoVuelo para luego cargarlo en la estructura Passenger
///
/// @param pasajero
/// @param estados
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 				 0: si todo salio bien
int Passenger_modificarEstadoVuelo(Passenger* pasajero,eEstado estados[], int tamE);

/// @fn int compararPorId(void*, void*)
/// @brief tiene como finalidad comparar dos valores enteros y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que valor1 es mayor que valor2.
/// 				-1: indica que valor1 es menor que valor2.
/// 				 0: hubo un error el las validacones NULL
int compararPorId(void* pasajero1, void* pasajero2);
/// @fn int compararPorNombre(void*, void*)
/// @brief  tiene como finalidad comparar dos valores string y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que string1 es mayor que string2.
/// 				-1: indica que string1 es menor que string2.
/// 				 0: hubo un error el las validacones NULL
int compararPorNombre(void* pasajero1, void* pasajero2);
/// @fn int compararPorApellido(void*, void*)
/// @brief  tiene como finalidad comparar dos valores string y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que string1 es mayor que string2.
/// 				-1: indica que string1 es menor que string2.
/// 				 0: hubo un error el las validacones NULL
int compararPorApellido(void* pasajero1, void* pasajero2);
/// @fn int compararPorCodigo(void*, void*)
/// @brief  tiene como finalidad comparar dos valores string y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que string1 es mayor que string2.
/// 				-1: indica que string1 es menor que string2.
/// 				 0: hubo un error el las validacones NULL
int compararPorCodigo(void* pasajero1, void* pasajero2);
/// @fn int compararPorPrecio(void*, void*)
/// @brief  tiene como finalidad comparar dos valores flotantes y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que valor1 es mayor que valor2.
/// 				-1: indica que valor1 es menor que valor2.
/// 				 0: hubo un error el las validacones NULL
int compararPorPrecio(void* pasajero1, void* pasajero2);
/// @fn int compararPorTipo(void*, void*)
/// @brief  tiene como finalidad comparar dos valores enteros y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que valor1 es mayor que valor2.
/// 				-1: indica que valor1 es menor que valor2.
/// 				 0: hubo un error el las validacones NULL
int compararPorTipo(void* pasajero1, void* pasajero2);
/// @fn int compararPorEstado(void*, void*)
/// @brief  tiene como finalidad comparar dos valores enteros y devolver el resultado
///
/// @param pasajero1
/// @param pasajero2
/// @return retorna  1: indica que valor1 es mayor que valor2.
/// 				-1: indica que valor1 es menor que valor2.
/// 				 0: hubo un error el las validacones NULL
int compararPorEstado(void* pasajero1, void* pasajero2);

#endif /* PASSENGER_H_ */
