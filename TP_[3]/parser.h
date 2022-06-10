
/// @fn int parser_PassengerFromText(FILE*, LinkedList*, eTipo[], eEstado[], int, int)
/// @brief 	Recorre el file y toma los datos en con valores string exeptuando las comas.
/// 		Los carga en una matriz provicional y los manda a ser validados y cargados dentro de los las estructuras Pasenger
/// 		Finalmente los añade a nuestro likedList
///
/// @param pFile
/// @param pArrayListPassenger
/// @param tipos
/// @param estados
/// @param tamT
/// @param tamE
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger,eTipo tipos[], eEstado estados[], int tamT, int tamE);
/// @fn int parser_PassengerFromBinary(FILE*, LinkedList*)
/// @brief crea nuevos punters dinamicos Passenger y los carga directamente(binario) luego los añade al linked list
///
/// @param pFile
/// @param pArrayListPassenger
/// @return retorna	-1: si falla la validacion o tam menor a uno
/// 		 		 0: si todo salio bien
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);
