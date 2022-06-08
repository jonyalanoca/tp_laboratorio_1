#include "Tipo.h"
#include "Estado.h"
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
int controller_editPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger, eTipo tipos[], eEstado estados[], int tamT, int tamE);
void controller_showHeadList(void);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_searchMaxId(LinkedList* pArrayListPassenger);
int controller_findIndexById(LinkedList* pArrayListPassenger, int id);

