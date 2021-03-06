/*
 * validaciones.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Jony
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int enteroEntreDos(char mensaje[], int* pVarNumero, int numero1, int numero2){
	int todoOk=0;
	if(mensaje!=NULL && pVarNumero!=NULL){
		validarCargarEntero(mensaje, pVarNumero);
		while(*pVarNumero<numero1 || *pVarNumero>numero2){
			printf("El numero esta fuera de rango. ");
			validarCargarEntero(mensaje, pVarNumero);
		}
		todoOk=1;
	}
	return todoOk;
}
int enteroPositivo(char mensaje[], int* pVarNumero){
	int todoOk=0;
	if(mensaje!=NULL && pVarNumero!=NULL){
		validarCargarEntero(mensaje, pVarNumero);
		while(*pVarNumero<=0){
			printf("No se admiten cero o negativos. ");
			validarCargarEntero(mensaje, pVarNumero);
		}
		todoOk=1;
	}
	return todoOk;
}
int decimalPositivo(char mensaje[], float* pVarNumero){
	int todoOk=0;
	if(mensaje!=NULL && pVarNumero!=NULL){
		validarCargarDecimal(mensaje, pVarNumero);
		while(*pVarNumero<=0){
			printf("No se admiten cero o negativos. ");
			validarCargarDecimal(mensaje, pVarNumero);
		}
		todoOk=1;
	}
	return todoOk;
}
int validarCargarEntero(char mensaje[], int* pVarNumero){
	int todoOk=0;
	int i;
	char auxString[50];
	int maximoPermitido=10;
	if(mensaje!= NULL && pVarNumero!=NULL){
		todoOk=1;
		do{
			todoOk=1;
			printf("%s: ", mensaje);
			fflush(stdin);
			gets(auxString);
			if(auxString[0]=='\0'){
				printf("No ingreso nada aun. ");
				todoOk=0;
			}
			else{
				i=0;
				if(auxString[0]=='-'){
					i=1;
					maximoPermitido=11;
					if(auxString[1]=='\0'){
						printf("No ingreso nada aun. ");
						todoOk=0;
					}
				}
				while(auxString[i]!='\0' && todoOk==1){
					if(auxString[i]<'0' || auxString[i]>'9'){
						printf("Caracteres no validos. ");
						todoOk=0;
						break;
					}
					i++;
				}
				if((strlen(auxString))>maximoPermitido && todoOk==1){
					printf("El numero es muy alto. ");
					todoOk=0;
				}

			}
		}while(!todoOk);
		*pVarNumero=atoi(auxString);
	}
	return todoOk;
}

int validarCargarDecimal(char mensaje[], float* pVarNumero){
	int todoOk=0;
		int i;
		char auxString[50];
		if(mensaje!= NULL && pVarNumero!=NULL){
			todoOk=1;
			do{
				todoOk=1;
				printf("%s: ", mensaje);
				fflush(stdin);
				gets(auxString);
				if(auxString[0]=='\0'){
					printf("No ingreso nada aun. ");
					todoOk=0;
				}
				else{
					i=0;
					if(auxString[0]=='-'){
						i=1;
						if(auxString[1]=='\0'){
							printf("No ingreso nada aun. ");
							todoOk=0;
						}
					}
					while(auxString[i]!='\0' && todoOk==1){
						if(auxString[i]=='.'){
							i++;
							continue;

						}
						if(auxString[i]<'0' || auxString[i]>'9'){
							printf("Caracteres no validos. ");
							todoOk=0;
							break;
						}
						i++;
					}
				}
			}while(!todoOk);
			*pVarNumero=atof(auxString);
		}
		return todoOk;
}
