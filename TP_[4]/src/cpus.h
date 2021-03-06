/*
 * cpus.h
 *
 *  Created on: 14 jun. 2022
 *      Author: Jony
 */

#ifndef SRC_CPUS_H_
#define SRC_CPUS_H_
typedef struct{
	int rank;
	char fabricante[10];
	char procesador[30];
	int cache;
	float frecuencia;
	char zocalos[10];
	int nucleos;
	int hilos;
	int lanzamiento;
}eCPU;
#endif /* SRC_CPUS_H_ */
/// @fn eCPU cpu_nuevo*(void)
/// @brief  crea un Elemento en la memoria dinamica
///
/// @return retorna el nuevo puntero a la estructura.
eCPU* cpu_nuevo(void);
/// @fn eCPU cpu_nuevoParametros*(char*, char*, char*, char*, char*, char*, char*, char*, char*)
/// @brief Crea un nuevo puntero a estructura en la memoria dinamica y lo carga con los valores pasador por referencia.
///
/// @param rank
/// @param fabricante
/// @param procesador
/// @param cache
/// @param frecuencia
/// @param zocalos
/// @param nucleos
/// @param hilos
/// @param lanzamiento
/// @return retorna el nuevo puntero a estructura.
eCPU* cpu_nuevoParametros(char* rank, char* fabricante, char* procesador, char* cache, char* frecuencia, char* zocalos, char* nucleos, char* hilos, char* lanzamiento);
/// @fn int cpu_setRank(eCPU*, int)
/// @brief carga de manera segura el valor rank en el la estructura pEstructura
///
/// @param pEstructura
/// @param rank
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setRank(eCPU* pEstructura, int rank);
/// @fn int cpu_setFabricante(eCPU*, char*)
/// @brief carga de manera segura el valor fabricante en el la estructura pEstructura
///
/// @param pEstructura
/// @param fabricante
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setFabricante(eCPU* pEstructura, char* fabricante);
/// @fn int cpu_setProcesador(eCPU*, char*)
/// @brief carga de manera segura el valor procesador en el la estructura pEstructura
///
/// @param pEstructura
/// @param procesador
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setProcesador(eCPU* pEstructura, char* procesador);
/// @fn int cpu_setCache(eCPU*, int)
/// @brief carga de manera segura el valor cache en el la estructura pEstructura
///
/// @param pEstructura
/// @param cache
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setCache(eCPU* pEstructura, int cache);
/// @fn int cpu_setFrecuencia(eCPU*, float)
/// @brief carga de manera segura el valor frecuencia en el la estructura pEstructura
///
/// @param pEstructura
/// @param frecuencia
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setFrecuencia(eCPU* pEstructura, float frecuencia);
/// @fn int cpu_setZocalos(eCPU*, char*)
/// @brief carga de manera segura el valor zocalos en el la estructura pEstructura
///
/// @param pEstructura
/// @param zocalos
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setZocalos(eCPU* pEstructura, char* zocalos);
/// @fn int cpu_setNucleos(eCPU*, int)
/// @brief carga de manera segura el valor nucleos en el la estructura pEstructura
///
/// @param pEstructura
/// @param nucleos
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setNucleos(eCPU* pEstructura, int nucleos);
/// @fn int cpu_setHilos(eCPU*, int)
/// @brief carga de manera segura el valor hilos en el la estructura pEstructura
///
/// @param pEstructura
/// @param hilos
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setHilos(eCPU* pEstructura, int hilos);
/// @fn int cpu_setLanzamiento(eCPU*, int)
/// @brief carga de manera segura el valor lanzamiento en el la estructura pEstructura
///
/// @param pEstructura
/// @param lanzamiento
/// @return retorna -1: si falla la validacion NULL
/// 		retorna  0: si todo salio bien
int cpu_setLanzamiento(eCPU* pEstructura, int lanzamiento);
/// @fn int compararPorId(void*, void*)
/// @brief compara dos valores y el resultado lo retorna al final
///
/// @param cpu1
/// @param cpu2
/// @return retorna  0: si fallo la verificaion NULL o si son iguales
/// 		retorna -1: si si el primer valor es mayor que el primero.
/// 		retorna  1: si si el segundo valor es mayor que el  primero.
int compararPorId(void* cpu1, void* cpu2);
/// @fn int compararPorProcesador(void*, void*)
/// @brief	compara dos valores y el resultado lo retorna al final
///
/// @param cpu1
/// @param cpu2
/// @return retorna  0: si fallo la verificaion NULL o si son iguales
/// 		retorna -1: si si la primera cadena es mayor que la segunda
/// 		retorna  1: si si la sugunda cadena es mayor que la primera
int compararPorProcesador(void* cpu1, void* cpu2);
/// @fn int filtrarPorAMD(void*)
/// @brief compara los el valor fabricante de la estructura con "AMD" y el resultado lo retorna al final
///
/// @param pEstructura
/// @return retorna  0: si fallo la verificaion NULL o  no hubo coincidencia
/// 		retorna  1: hubo coincidencia.
int filtrarPorAMD(void* pEstructura);
/// @fn void mostrarCPU(eCPU*)
/// @brief muestra en forma enculumnada los valores de la estructura.
///
/// @param eEstructura
void mostrarCPU(eCPU* eEstructura);
