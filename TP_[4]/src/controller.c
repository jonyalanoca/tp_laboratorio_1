
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "parser.h"
#include "cpus.h"
#include "validaciones.h"
#include "auxiliares.h"
int controller_cargarArchivoTexto(char* path, LinkedList* listaCPU){
	int todoOk=-1;
	if(path!=NULL && listaCPU!=NULL){
		FILE* pFile=fopen(path, "r");
		if(pFile!=NULL){

			parser_cargarTexto(pFile, listaCPU);
			printf("Se cargo la lista con exito.\n");
		}
		fclose(pFile);
		todoOk=0;
	}
	return todoOk;
}
int controller_listarCPUs( LinkedList* listaCPU){
	int todoOk=-1;
	int len;
	if(listaCPU!=NULL){
		len=ll_len(listaCPU);
		system("cls");
		printf("  RANK FABRICANTE           PROCESADOR             CACHE FRECUENCIA ZOCALOS     NUCLEOS HILOS LANZAMIENTO\n");
		for(int i=0;i<len;i++){
			mostrarCPU((eCPU*)ll_get(listaCPU,i));
		}
		todoOk=0;
	}
	return todoOk;
}
int controller_tamanioLista(LinkedList* listaCPU){
	int todoOk=-1;
	if(listaCPU!=NULL){
		printf("El tamanio del LinkedList es: %d\n;", ll_len(listaCPU));
		todoOk=0;
	}
	return todoOk;
}
int controller_agregarAlFinal(LinkedList* listaCPU, int* id){
	int todoOk=-1;
	char matriz[9][100];
	eCPU* auxCPU;
	if(listaCPU!=NULL){
		cotroller_pedirDatos(9,100,matriz,id);
		auxCPU=cpu_nuevoParametros(matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6],matriz[7],matriz[8]);
		ll_add(listaCPU, auxCPU);
		printf("Se cargo el registro con exito.\n");
		todoOk=0;
	}
	return todoOk;
}
int controller_insertarReemplazarCPU(LinkedList* listaCPU, int* id){
	int todoOk=-1;
	int len;
	int index;
	char matriz[9][100];
	eCPU* auxCPU;
	if(listaCPU!=NULL){
		len=ll_len(listaCPU);
		enteroEnRango("Ingrese el index donde sera reemplazado",&index,0,len-1);
		cotroller_pedirDatos(9,100,matriz,id);
		auxCPU=cpu_nuevoParametros(matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6],matriz[7],matriz[8]);
		ll_set(listaCPU,index,auxCPU);
		printf("Se cargo el registro con exito.\n");
		todoOk=0;
	}
	return todoOk;
}
int controller_insertarSinReemplazarCPU(LinkedList* listaCPU, int* id){
	int todoOk=-1;
	int len;
	int index;
	char matriz[9][100];
	eCPU* auxCPU;
	if(listaCPU!=NULL){
		len=ll_len(listaCPU);
		enteroEnRango("Ingrese el index donde sera insertado",&index,0,len-1);
		cotroller_pedirDatos(9,100,matriz,id);
		auxCPU=cpu_nuevoParametros(matriz[0],matriz[1],matriz[2],matriz[3],matriz[4],matriz[5],matriz[6],matriz[7],matriz[8]);
		ll_push(listaCPU,index,auxCPU);
		printf("Se cargo el registro con exito.\n");
		todoOk=0;
	}
	return todoOk;
}
int cotroller_pedirDatos(int fila,int col, char matriz[][col], int* id){
	int todoOk=-1;
	int intAux;
	float floatAux;
	if(matriz!=NULL){
		sprintf(matriz[0], "%d",*id);
		(*id)++;
		cargarValidarCadena("Ingrese el fabricante(texto)",10,matriz[1]);
		printf("Ingrese el nombre del microprocesador(texto): ");
		fflush(stdin);
		gets(matriz[2]);
		cargarValidarEnteroPositivo("Ingrese la cantidad de Cache L3(entero)",&intAux);
		sprintf(matriz[3],"%d",intAux);
		cargarValidarDecimalPositivo("Ingrese la frecuencia(flonte)",&floatAux);
		sprintf(matriz[4],"%f",floatAux);
		cargarValidarAlfaNumerico("Ingrese el zocalo(alfanumerico)",20,matriz[5]);
		cargarValidarEnteroPositivo("Ingrese la cantidad de nucleos(entero)",&intAux);
		sprintf(matriz[6],"%d",intAux);
		cargarValidarEnteroPositivo("Ingrese la cantidad de hilos(entero)",&intAux);
		sprintf(matriz[7],"%d",intAux);
		cargarValidarEnteroPositivo("Ingrese el anio de lanzamiento(entero)",&intAux);
		sprintf(matriz[8],"%d",intAux);
		todoOk=0;
	}
	return todoOk;
}
int controller_obtenerIndex(LinkedList* listaCPU){
	int todoOk=-1;
	int len;
	eCPU* aux;
	int numero;
	if(listaCPU!=NULL){
		len=ll_len(listaCPU);
		numero=numeroRandom(0,len-1);
		aux=(eCPU*)ll_get(listaCPU, numero);
		printf("El index obtenido es: %d\n",ll_indexOf(listaCPU,aux));
		mostrarCPU(aux);
		todoOk=0;
	}
	return todoOk;
}
int controller_comprarListas(LinkedList* listaCPU, LinkedList* listaCPUClon){
	int todoOk=-1;
	int resultado;
	if(listaCPU!=NULL &&listaCPUClon!=NULL){
		resultado=ll_containsAll(listaCPU,listaCPUClon);
		if(resultado==1){
			printf("Las listas son identicas.\n");

		}else if(resultado==0){
			printf("Las listas son diferentes.\n");
		}
		todoOk=0;
	}
	return todoOk;
}

int controller_compararUnElemento(LinkedList* listaCPU, LinkedList* listaCPUClon){
	int todoOk=-1;
	int len;
	int numero;
	int resultado;
	eCPU* aux=NULL;
	if(listaCPU!=NULL &&listaCPUClon!=NULL){
		len=ll_len(listaCPUClon);
		numero=numeroRandom(0,len-1);
		aux=(eCPU*)ll_get(listaCPUClon,numero);
		resultado=ll_contains(listaCPU, aux);
		if(resultado){
			printf("La lista principal contiene el elemento.\n");
		}else if(!resultado){
			printf("La lista principal no  contiene el elemento.\n");
		}

		todoOk=0;
	}
	return todoOk;
}
int controller_eliminarUnElemento(LinkedList* listaCPUClon){
	int todoOk=-1;
	int idAux;
	int indexAux;
	eCPU* aux;
	if(listaCPUClon!=NULL){
		controller_listarCPUs(listaCPUClon);
		cargarValidarEntero("Ingrese el id del registro a eliminar",&idAux);
		indexAux=controller_obtenerIndexPorId(listaCPUClon, idAux);
		if(indexAux!=-1){
			ll_remove(listaCPUClon, indexAux);
			printf("Se borro el resgistro con exito.\n");
			aux=(eCPU*)ll_get(listaCPUClon,indexAux);
			free(aux);
		}else{
			printf("No se encontro el id seleccionado.\n");
		}
		todoOk=0;
	}
	return todoOk;
}

int controller_limpiarElementos(LinkedList* listaCPU){
	int todoOk=-1;
	int len;
	if(listaCPU!=NULL){
		len=ll_len(listaCPU);
		for (int i=0;i<len;i++){
			free((eCPU*)ll_get(listaCPU,i));
		}
		todoOk=0;
	}
	return todoOk;
}
int controller_obtenerIndexPorId(LinkedList* listaCPUClon, int id){
	int todoOk=-1;
	int len;
	eCPU* aux;
	if(listaCPUClon!=NULL){
		len=ll_len(listaCPUClon);
		for(int i=0;i<len;i++){
			aux=(eCPU*)ll_get(listaCPUClon,i);
			if(aux->rank==id){
				todoOk=i;
			}
		}
	}
	return todoOk;
}

int controller_limpiarListaClon10(LinkedList* listaCPUs){
	int todoOk=-1;
	if(listaCPUs!=NULL){
		controller_limpiarElementos(listaCPUs);
		ll_clear(listaCPUs);
		printf("Se eliminaron todos los nodos y elemetos de la memoria dinamica.\n");
		todoOk=0;
	}
	return todoOk;
}
int controller_eliminarElementoYAgregarloAlPrincipal(LinkedList* listaCPUs,LinkedList* listaCPUsClon, int id){
	int todoOk=-1;
	int idAux;
	int indexAux;
	eCPU* aux;
	if(listaCPUs!=NULL && listaCPUsClon!=NULL){
		controller_listarCPUs(listaCPUsClon);
		cargarValidarEnteroPositivo("Ingrese el id del elemento a eliminar",&idAux);
		indexAux=controller_obtenerIndexPorId(listaCPUsClon,idAux);
		if(indexAux!=-1){
			aux=(eCPU*)ll_pop(listaCPUsClon,indexAux);
			printf("Se borro el elemento de la lista clon.\n");
			aux->rank=id;
			if(ll_add(listaCPUs, aux)==0){
				printf("Se agrego a la lista principal con exito.\n");
			}
		}else{
			printf("No se encontro el id seleccionado.\n");
		}

		todoOk=0;
	}
	return todoOk;
}
int controller_guardarComoTexto(char* path, LinkedList* listaCPUs){
	int todoOk=-1;
	eCPU* aux;
	int len;
	if(listaCPUs!=NULL && path!=NULL){
		FILE* pfile=fopen(path,"w");
		len=ll_len(listaCPUs);
		for(int i=0;i<len;+i++){
			aux=(eCPU*)ll_get(listaCPUs,i);
			fprintf(pfile,"%d,%s,%s,%d,%f,%s,%d,%d,%d\n",aux->rank,aux->fabricante,aux->procesador,aux->cache,aux->frecuencia,aux->zocalos,aux->nucleos,aux->hilos,aux->lanzamiento);
		}
		printf("Se guardaron los datos con exito.\n");
		fclose(pfile);
		todoOk=0;
	}
	return todoOk;
}

