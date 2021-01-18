//Este es el pinchi programa del primer parcial
/*Esta belleza hace todo lo que tu quieras...
OKNO :v ;
Este programa está diseñado para ingresar datos de un determinado docente y
calcula el valor a  y realiza los respectivos descuentos y tambien el pago extras si
amerita la situación.
*/
#include <stdio.h>//printf y scanf
#include <conio.h>//para gets y getch
#include <stdlib.h>//para la 
#include <locale.h>
#include <ctype.h>

#define PPHDC 14.50 // Pago por hora docente contratado
#define PPHDN 15.80 // Pago por hora docente nombramiento

int main(void){
	setlocale(LC_ALL,"spanish");
	int select, case1, horas=0;
	float sub_total, total, dscto, add, pago_adicional, adicional=0;
	char name[50], lname[50], id[10], address[50], email[50], phone[50];
		//funcion para validar letra:

		//Menu Principal: Lista de Opciones
		mod:
		printf("\n **SISTEMA DE PAGOS**");
		printf("\n 1. Datos del Docente");
		printf("\n 2. Pago por Contrato");
		printf("\n 3. Pago por Nombramiento");
		printf("\n 4. Salir");
		printf("\n Opción: ");
		scanf ("%d",&select);
		fflush(stdin);
		system("cls");
		
		switch(select){
			//Primer Menú: Docente Contratado
			case 1:	
			/*system("cls");
			printf("\n **Ingreso de Datos**");
			fflush(stdin);
			printf("\n Nombres: ");
			do{
			scanf ("%[^\n]",name);
			if(!isalpha(name)){
				printf("\n Ingreso Invalido...");
			}
			}while (!isalpha(name));
			fflush(stdin);
			printf("\n Apellidos: ");
			do{
			scanf ("%[^\n]",lname);
			if(!isalpha(lname)){
				printf("\n Ingreso Invalido...");
			}
			}while (!isalpha(lname));
			printf("\n Cédula: ");
			scanf ("%s",&id);
			fflush(stdin);
			printf("\n Dirección: ");
			gets(address);
			//scanf ("%[^\n]",address);
			printf("\n Correo: ");
			scanf ("%s",&email);
			printf("\n Número de Teléfono: ");
			scanf ("%s",&phone);
			printf("\n");
			system("pause");*/
			goto mod;
			//Segundo Menú
			case 2:
				system("cls");
				printf("\n **Cálculo de valor a pagar** ");
				do{
					printf("\n Ingrese horas trabajadas: ");
					scanf ("%d",&horas);
					fflush(stdin);
				}while(horas<0);
				
				add=0; pago_adicional=0; adicional=0;
				if(horas>=0){
				if (horas > 160){
						fflush(stdin);
						add = (PPHDC * 0.13) + PPHDC;
						pago_adicional = horas - 160;
						adicional = pago_adicional * add;
						sub_total = horas * add;
						dscto = (sub_total * 10.13) / 100;	
					}else if(horas <= 160){
						sub_total = horas * PPHDN;	
						dscto = (sub_total * 10.13) / 100;		
					}	
				total = sub_total - dscto;	
				}else if(horas < 0){
						printf("Ingreso Inválido!...");
				}
				
				
				system("pause");
				system("cls");
				printf("\n **Docente Contratado** ");
				printf("\n Nombres: %s", name);
				
				printf("\n Apellidos: %s", lname);
				
				printf("\n Cédula: %s", id);
				
				printf("\n Dirección: %s", address);
				printf("\n Correo: %s", email);
				printf("\n Teléfono: %s", phone);
				printf("\n");
				printf("\n Horas trabajadas:************* %d", horas);
				printf("\n Sub Total: *******************$%.2f", sub_total);
				printf("\n Descuento Seguro (11.45%):*** -$%.2f", dscto);
				printf("\n");
				printf("\n Total a Pagar:*************** $%.2f", total);
				printf("\n \n");
				system("pause");
				system("cls");
				goto mod;
			//Tercer Menu: Docente de Nombramiento	
			case 3:
				fflush(stdin);
				system("cls");
				printf("\n **Cálculo de valor a pagar** ");
				do{
					printf("\n Ingrese horas trabajadas: ");
					scanf ("%d",&horas);
					add=0; pago_adicional=0; adicional=0;
					if(horas>=0){
						if (horas > 160){
							fflush(stdin);
							add = (PPHDN * 0.15) + PPHDN;
							pago_adicional = horas - 160;
							adicional = pago_adicional * add;
							sub_total = horas * add;
							dscto = (sub_total * 10.15) / 100;	
						}else if(horas <= 160){
							sub_total = horas * PPHDN;	
							dscto = (sub_total * 10.15) / 100;		
						}	
						total = sub_total - dscto;
					}else if(horas < 0){
						printf("Ingreso Invalido!...");
					}
				}while(horas<0);
				system("pause");
				system("cls");
				printf("\n **Docente Nombramiento** ");
				printf("\n Nombres: %s", name);
				printf("\n Apellidos: %s", lname);
				printf("\n Cédula: %s", id);
				printf("\n Dirección: %s", address);
				printf("\n Correo: %s", email);
				printf("\n Teléfono: %s", phone);
				printf("\n");
				printf("\n Horas trabajadas:************** %d", horas);
				printf("\n Sub Total:******************** $%.2f", sub_total);
				printf("\n Descuento Seguro (10.15%):**** -$%.2f", dscto);
				printf("\n");
				printf("\n Total a Pagar:*****************$%.2f", total);
				printf("\n \n");
				system("pause");
				goto mod;
		
			//Salir
			case 4:
			system("pause");	
			system("exit");
			break;
			//default
			default: goto mod;
			}
			
		getch();
}
