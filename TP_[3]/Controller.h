#include "Tipo.h"
#include "Estado.h"
/// @fn int controller_loadFromText(char*, LinkedList*, eTipo[], eEstado[], int, int)
/// @brief mantiene abierto el archivo scv y lo valida, manda a parser para cargar datos
///
/// @param path
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn int controller_loadFromBinary(char*, LinkedList*)
/// @brief mantiene abierto el archivo bin y lo valida, manda a parser para cargar datos
///
/// @param path
/// @param pArrayListPassenger
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_addPassenger(LinkedList*, eTipo[], eEstado[], int, int)
/// @brief pide y valida datos. manda  a cargar los datos a Passenger. Al final nos pide confirmacion para guardar o desechar el nuevo pasajero
///
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return  retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_addPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn int controller_editPassenger(LinkedList*, eTipo[], eEstado[], int, int)
/// @brief nos crea un submenu para poder modificar los datos de un pasajero seleccionado
///
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return  retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_editPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn int controller_removePassenger(LinkedList*, eTipo[], eEstado[], int, int)
/// @brief lista y nos pide elegir a un usuario mediante su id y nos pide confirmar para eliminar al pasajero
///
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_removePassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn int controller_ListPassenger(LinkedList*, eTipo[], eEstado[], int, int)
/// @brief muestra en forma encolumnada todos los registro de pasajeros
///
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return  retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 	 0: si todo salio bien
int controller_ListPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn void controller_showHeadList(void)
/// @brief muestra la cabecera del listado
///
void controller_showHeadList(void);
/// @fn int controller_sortPassenger(LinkedList*, eTipo[], eEstado[], int, int)
/// @brief Nos permite ordenar por todo tipo de cirterio. Cuentra con submenus para elegir el tipo de ordenamiento
///
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_sortPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn int controller_saveAsText(char*, LinkedList*, eTipo[], eEstado[], int, int)
/// @brief guarda en un archivo txt los datos del linkedlist
///
/// @param path
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);

/// @fn int controller_saveAsBinary(char*, LinkedList*)
/// @brief  guarda en un archivo bin(modo binario) los datos del bin
///
/// @param path
/// @param pArrayListPassenger
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
/// @fn int controller_searchMaxId(LinkedList*)
/// @brief busca el id maximo dento de nuestro linkedlist
///
/// @param pArrayListPassenger
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: no hay registro aun.
/// 				numero: el id maximo
int controller_searchMaxId(LinkedList* pArrayListPassenger);
/// @fn int controller_findIndexById(LinkedList*, int)
/// @brief busca dentro del linkedlist el index que corresponde al id que nos pasaron por parametro
///
/// @param pArrayListPassenger
/// @param id
/// @return retorna	-1: si falla la validacion o tam menor a uno , no hay coincidencia
/// 		 		numero: el index de la conincidencia
int controller_findIndexById(LinkedList* pArrayListPassenger, int id);
/// @fn int controller_liberarMemoria(LinkedList*)
/// @brief recorre el linkedlist y libera la memoria de los punteros malloc.
/// 		librera las memoria malloc de los nodos
/// 		finalmente elimina el la cabeza del linkedlist del la memoria dinamica
///
/// @param pArrayListPassenger
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int controller_liberarMemoria(LinkedList* pArrayListPassenger);

char controller_BorrarYCargar(LinkedList* pArrayListPassenger);
int controller_limpiarElementos(LinkedList* pArrayListPassenger);
