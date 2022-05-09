/*
 * ArrayPassenger.c
 *
 *  Created on: 25 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "otros.h"
#include "menus.h"
#include "VueloEstado.h"


int initPassengers(Passenger* list, int len){
	int todoOk=-1;
	if(list!=NULL && len>0){
		for(int i=0;i<len; i++){
			list[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFly){
	int todoOk=-1;
	int idLibre;
	if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && flycode!=NULL){
		idLibre=buscarLibreUOcupado(list, len,1);
		if(idLibre==-1){
			printf("Hubo un error en validar los punteros o no hay lugar disponible.\n");
		}else{
			capitalizar(name);
			capitalizar(lastName);

			list[idLibre].id=id;
			strcpy(list[idLibre].name,name);
			strcpy(list[idLibre].lastName,lastName);
			list[idLibre].price=price;
			list[idLibre].typePassenger=typePassenger;
			strcpy(list[idLibre].flycode, flycode);
			list[idLibre].statusFlight=statusFly;
			list[idLibre].isEmpty=0;

			todoOk=0;
		}
	}
	return todoOk;
}

int buscarLibreUOcupado(Passenger* list, int len,int criterio){// 1-libre, 0-Ocupado
	int todoOk=-1;
	if(list!=NULL && len>0){
		for(int i =0; i<len;i++){
			if(list[i].isEmpty==criterio){
				todoOk=i;
				break;
			}
		}
	}
	return todoOk;
}

void printfPassenger(Passenger pasajero, eVueloEstado estados[], int lenEstados){
	printf("%4d %12s %12s  $%9.2f %6d %10s %10s\n",pasajero.id, pasajero.name,pasajero.lastName, pasajero.price, pasajero.typePassenger, pasajero.flycode, estados[buscarIndexPorId(estados,lenEstados, pasajero.statusFlight,1)].estado);

}
int printfPassengers(Passenger pasajeros[], int length,eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	if(pasajeros!=NULL && length>0){
		system("cls");
		printf(".......................................................................\n");
		printf("  ID       NOMBRE     APELLIDO      PRECIO  CLASE     CODIGO     ESTADO\n");
		for(int i=0; i<length;i++){
			if(pasajeros[i].isEmpty==0){
				printfPassenger(pasajeros[i], estados, lenEstados);
			}
		}
		todoOk=0;
	}
	return todoOk;
}
int findPassengerById(Passenger* list, int len,int id){
	int todoOk=-1;
	if(list!=NULL && len>0){
		for(int i=0; i<len;i++){
			if(list[i].isEmpty==0 && list[i].id==id){
				todoOk=i;
			}
		}
	}
	return todoOk;
}
int removePassenger(Passenger* list, int len, int id, eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	int auxId;
	char confirmo;
	if(list!=NULL && len>0 && estados!=NULL && lenEstados>0){
		auxId=findPassengerById(list, len, id);
		if(auxId==-1){
			printf("No se encontro el id seleccionado.\n");
		}else{
			system("cls");
			printf("\nATENCION\nEsta por borrar el siguiente registro:\n");
			printf(".......................................................................\n");
			printf("  ID       NOMBRE     APELLIDO      PRECIO  CLASE     CODIGO     ESTADO\n");
			printfPassenger(list[auxId], estados, lenEstados);
			cargarValidarCharEntreDos("Porfavor confirme si o no (s/n)",&confirmo,'s','n');
			if(confirmo=='s'){
				list[auxId].isEmpty=1;
				printf("Se removio al pasajero con exito.\n");
			}else{
				printf("No se realizaon cambios.\n");
			}

		}
		todoOk=0;
	}
	return todoOk;
}
int modificarPasajero(Passenger* list, int len, int id,int tamName, int tamFly, eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	int index;
	int auxIdEstado;
	int auxEntero;
	if(list!=NULL && len>0){
		index=findPassengerById(list, len, id);
		if(index==-1){
			printf("No se encontro el id seleccionado.\n");
		}else{
			switch(menuModificar()){
				case 1:
					cargarValidarCadena("Ingrese el nombre del pasajero",tamName,list[index].name);
					capitalizar((list[index].name));
					break;
				case 2:
					cargarValidarCadena("Ingrese el apellido del pasajero",tamName,list[index].lastName);
					capitalizar((list[index].lastName));
					break;
				case 3:
					cargarValidarDecimalPositivo("Ingrese el precio", &(list[index].price));
					break;
				case 4:
					enteroEnRango("Ingrese en que clase viaja(1/2/3)",&(list[index].typePassenger), 1,3);
					break;
				case 5:
					printfEstados(estados, lenEstados);
					do{
						cargarValidarEntero("Ingrese el ID del del vuelo", &auxIdEstado);
						auxEntero= buscarIndexPorId(estados, lenEstados, auxIdEstado,1);
						if(auxEntero==-1){
							printf("No se encontro el id. Vuelva a intentear.\n");
						}
					}while(auxEntero==-1);
					strcpy(list[index].flycode,estados[auxEntero].codigoDeVuelo);
					list[index].statusFlight=auxIdEstado;
					break;
			}
			printf("Se modifico el usuario con exito.\n");
		}

		todoOk=0;
	}
	return todoOk;
}

int informes(Passenger* list, int len, eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	int auxEntero;
	if(list!=NULL && len>0){
		switch(menuInformes()){
		case 1:
			printfPassengers(list, len, estados, lenEstados);
			break;
		case 2:
			auxEntero=ascendenteDescendente();
			sortPassengers(list, len,auxEntero, estados, lenEstados);
			break;
		case 3:
			auxEntero=ascendenteDescendente();
			sortPassengersByCode(list, len,auxEntero, estados, lenEstados);
			break;
		case 4:
			informarPrecioPromedio(list, len, estados, lenEstados);
			break;
		}
		todoOk=0;
	}
	return todoOk;
}
int sortPassengers(Passenger* list, int len, int order, eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	Passenger aux;
	if(list!=NULL && len>0){
		for(int i=0; i<len-1;i++){
			for(int u=i+1; u<len; u++){
				switch(order){
				case 1:
					if(strcmp(list[i].lastName, list[u].lastName)==1){
						aux=list[i];
						list[i]=list[u];
						list[u]=aux;
					}else if(strcmp(list[i].lastName, list[u].lastName)==0 && list[i].typePassenger>list[u].typePassenger){
						aux=list[i];
						list[i]=list[u];
						list[u]=aux;
					}
					break;
				case 2:
					if(strcmp(list[i].lastName, list[u].lastName)==-1){
						aux=list[i];
						list[i]=list[u];
						list[u]=aux;
					}else if(strcmp(list[i].lastName, list[u].lastName)==0 && list[i].typePassenger<list[u].typePassenger){
						aux=list[i];
						list[i]=list[u];
						list[u]=aux;
					}
					break;
				}
			}
		}
		printfPassengers(list, len, estados, lenEstados);
		todoOk=0;
	}
	return todoOk;
}
int sortPassengersByCode(Passenger* list, int len, int order, eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	Passenger aux;
	if(list!=NULL && len>0){
		for(int i=0; i<len-1;i++){
			for(int u=i+1; u<len; u++){
				switch(order){
				case 1:
					if(strcmp(list[i].flycode, list[u].flycode)==1){
						aux=list[i];
						list[i]=list[u];
						list[u]=aux;
					}
					break;
				case 2:
					if(strcmp(list[i].flycode, list[u].flycode)==-1){
						aux=list[i];
						list[i]=list[u];
						list[u]=aux;
					}
					break;
				}
			}
		}
		system("cls");
		printf(".......................................................................\n");
		printf("  ID       NOMBRE     APELLIDO      PRECIO  CLASE     CODIGO     ESTADO\n");
		for(int i=0; i<len;i++){

			if(list[i].isEmpty==0 && strcmp(estados[buscarIndexPorId(estados, lenEstados,list[i].statusFlight,1)].estado,"ACTIVO")==0){
				printfPassenger(list[i], estados, lenEstados);
			}
		}
		todoOk=0;
	}
	return todoOk;
}
int informarPrecioPromedio(Passenger* list, int len, eVueloEstado estados[], int lenEstados){
	int todoOk=-1;
	int contador=0;
	float precioTotal=0;
	float precioPromedio=0;
	if(list!=NULL && len>0){
		for(int i=0; i<len;+i++){
			if(list[i].isEmpty==0){
				contador++;
				precioTotal+=list[i].price;
			}
		}
		precioPromedio=precioTotal/contador;
		contador=0;
		for(int i=0; i<len;+i++){
			if(list[i].isEmpty==0 && list[i].price>=precioPromedio){
				contador++;
			}
		}
		system("cls");
		printf(" \t..[PRECIO PROMEDIO]..\n\n");
		printf("La suma total de pasajes es: $%.2f\n", precioTotal);
		printf("El promedio de los pasajes es: $%.2f\n", precioPromedio);
		printf("La cantidad de pasajeros que superan el precio promedio son: %d\n", contador);
		printf(".......................................................................\n");
		printf("  ID       NOMBRE     APELLIDO      PRECIO  CLASE     CODIGO     ESTADO\n");
		for(int i=0; i<len;i++){
			if(list[i].isEmpty==0 && list[i].price>=precioPromedio){
				printfPassenger(list[i], estados, lenEstados);
			}
		}
		todoOk=0;
	}
	return todoOk;
}

