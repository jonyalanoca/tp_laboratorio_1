/*
 * validaciones.h
 *
 *  Created on: 4 abr. 2022
 *      Author: Jony
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */
/// @fn int validarCargarEntero(char[], int*)
/// @brief 	pide numeros enteros, valida que se traten solamente de numeros, evita que se exceda el maximo pormitido por (int)
/// 		al final una vez validado guarda el valor numerico dentro de nustra variable pasado por paramentro (puntero)
///
/// @param mensaje: mesaje para especificar que dato queremos recibir
/// @param varNumero: (puntero) aca guardamos los numeros luego de validar
/// @return 0 sale mal la validacion paramentros, 1 todo salio bien
int validarCargarEntero(char mensaje[], int* pVarNumero);
/// @fn int validarCargarDecimal(char[], float*)
/// @brief pide ingresar un numero flotante hasta que un ingrese un flotante, admite numeros y un punto. Una vez validado
/// 		carga el valor del flotante en nuestro puntero float
///
/// @param mensaje: mensaje para especificar que dato queremos recibir
/// @param varNumero (puntero) aca guardamos los numeros (flotante) luego de validar
/// @return 0 sale mal la validacion paramentros, 1 todo salio bien
int validarCargarDecimal(char mensaje[], float* pVarNumero);
/// @fn int enteroEntreDos(char[], int*, int, int)
/// @brief Usa la funcion validaCargarEntero y valida que ese numero este  entre el rango del numero1 y numero2
///
/// @param mensaje Es el mensaje que recive el usario para saber lo que tiene que ingresar
/// @param varNumero Aca se guarda la numero validado
/// @param numero1	El numero no puede ser menor a numero1
/// @param numero2	El numero no puede ser mayor a numero2
/// @return			Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int enteroEntreDos(char mensaje[], int* pVarNumero, int numero1, int numero2);
/// @fn int enteroPositivo(char[], int*)
/// @brief 				Usa la funcion validaCargarEntero y valida que ese numero sea mayor a cero
///
/// @param mensaje		Es el mensaje que recive el usario para saber lo que tiene que ingresar
/// @param varNumero	Aca se guarda la numero validado
/// @return				Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int enteroPositivo(char mensaje[], int* pVarNumero);
/// @fn int decimalPositivo(char[], float*)
/// @brief				Usa la funcion validarCargarDecimal y valida que el numero sea mayor a cero.
///
/// @param mensaje		Es el mensaje que recive el usario para saber lo que tiene que ingresar
/// @param varNumero	Aca se guarda la numero validado
/// @return				Devuelve 1 si todo salido bien , devuelve 0 si hubo problemas con la validacion de punteros.
int decimalPositivo(char mensaje[], float* pVarNumero);
