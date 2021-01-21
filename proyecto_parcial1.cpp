/*
Este programa está diseñado para ingresar datos de un determinado docente y
calcula el valor a  pagar, realiza los respectivos descuentos y tambien el pago extras si
amerita la situación.
*/

#include <stdio.h>//printf y scanf
#include <conio.h>//para gets y getch
#include <stdlib.h>//para las funciones system
#include <locale.h>//se declara el idioma español, para ñ y acentos
#include <string.h>//se usa para usar funcion strle que valida el largo de una cadena
#include <ctype.h>//se usa para declarar funcion para validar que una variable sea solo tipo cadena de letras

#define PPHDC 14.50 // Pago por hora docente contratado
#define PPHDN 15.80 // Pago por hora docente nombramiento

//funcion para validar caracteres tipo letra
int validacion_letras(char cadena[]) {
    int i = 0;
    while (cadena[i]) {
        // Si no es del alfabeto y no es un espacio regresamos false o 0
        if (
                !isalpha(cadena[i])
                && cadena[i] != ' '// El espacio cuenta como válido, si no, simplemente quita la condición
                )
            return 0;
        i++;
    }
    // Si terminamos de recorrer la cadena y no encontramos errores, regresamos 1 o true
    return 1;
}
//inicio del programa
int main(void){
	system("color 8f");//funcion para definir color de la consola
	setlocale(LC_ALL,"spanish");//Declaro funcion de idioma español
	int select, case1, exit, horas, horas_extra, horas_falta=0; // Se declaran los enteros
	float sub_total, total, dscto, add, pago_extra, pago_corriente, adicional=0; //Se declaran los reales
	char name[50], lname[50], id[10], address[50], email[50], phone[50]; //Se declaran las cadenas
	
		//Menu Principal: Lista de Opciones
		mod://Se declara la etiqueta mod para ser llamada cuando se necesite
		printf("\n **SISTEMA DE PAGOS**");
		printf("\n 1. Datos del Docente");
		printf("\n 2. Pago por Contrato");
		printf("\n 3. Pago por Nombramiento");
		printf("\n 4. Salir");
		printf("\n Opción: ");
		scanf ("%d",&select);//ingreso de valor a variable select
		fflush(stdin);//funcion para limpieza de buffer
		system("cls");//funcion para limpiar pantalla
		
		switch(select){//Inicia sentencia de selectiva multiple switch
			//Primer Menú: Ingreso de Datos
			case 1:	
				printf("\n **Ingreso de Datos**");
				fflush(stdin);//limpieza de buffer
				do{//Sentencia para validar el correcto ingreso del caracter entero
					printf("\n Nombres: ");
					gets(name);//funcion que recoge datos y la guarda en una variable, en este caso variable name
				    if (!validacion_letras(name)) {//sentencia para validar que el ingreso haya sido tipo cadena de letras unicamente
				        printf("\n Ingreso Inválido!");
				        printf("\n Solo Letras...");
				        printf("\n");
				    }
				}while(!validacion_letras(name));//condicional de bucle de repeticion
				fflush(stdin);//limpieza de buffer
				do{
					printf("\n Apellidos: ");
					gets(lname);//recoge los datos para guardar en lname
				    if (!validacion_letras(lname)) {//sentencia para validar que el ingreso en la variable haya sido cadena de letras
				        printf("\n Ingreso Inválido!");//aviso de alerta
				        printf("\n Solo Letras...");
				    printf("\n");
				    }
				}while(!validacion_letras(lname));//condicional de bucle de repeticion
				do {//sentencia para validar el numero maximo de caracteres en cedula
					printf("\n Cédula: "); 
					gets(id);//recoge los datos para guardar en id
					if(strlen(id)>10){//sentencia para validar el largo de una cadena
						printf("\n Ingreso Inválido!");
						printf("\n Deben ser 10 dígitos...");
						printf("\n");
					}else if(strlen(id)<10){
						printf("\n Ingreso Inválido!");
						printf("\n Deben ser 10 dígitos...");
						printf("\n");
					}
				} while (strlen(id)>10 || strlen(id)<10); //mientras la cadena cedula mida mas de 10 espacios, se repite
				fflush(stdin);//limpieza de buffer
				printf("\n Dirección: ");
				gets(address);//guarda datos en variable address
				printf("\n Correo: ");
				scanf ("%s",&email);//guarda datos en variable email
				printf("\n Número de Teléfono: ");
				scanf ("%s",&phone);//guarda datos en variable phone
				printf("\n");
				system("pause");//funcion que pausa la ejecución del programa
				system("cls");
				goto mod;//llama a la etiqueta mod
			//Segundo Menú: Docente Contratado
			case 2:
				printf("\n **Cálculo de valor a pagar** ");
				add=0; pago_extra=0; horas_extra=0;//Se declaran las variables en 0, de tipo float para descuento
				do{
					printf("\n Ingrese horas trabajadas: ");
					scanf ("%d",&horas);//recoge datos para guardar en la variable horas
					fflush(stdin);
					if(horas<=0){//Validacion para que las horas sean mayores a 0
						printf("\n Ingreso Inválido!");
					}
				}while(horas<=0);
				
				if (horas > 160){//condicional para efectuar el calcula de tarifa de pago extra si las horas superan las 160
					fflush(stdin);
					horas_extra = horas - 160;
					add = (PPHDC * 0.13) + PPHDC;//Realiza el calculo para tarifa horas extras
					pago_extra = horas_extra * add;
					pago_corriente = horas * PPHDC;
					sub_total = pago_corriente + pago_extra;
					dscto = (sub_total * 11.45) / 100;//calcula las horas por el pago adicional
					total = sub_total - dscto;//efectua el total a pagar
				}else if(horas <= 160){//condicion que se ejecuta si las horas son menores a 160
					if(horas<160){
						horas_falta = 160 - horas;
					}
					sub_total = horas * PPHDC;	
					dscto = (sub_total * 11.45) / 100;	
					total = sub_total - dscto;//efectua el total a pagar	
				}	
				
				//Muestra los datos ingresados					
				system("pause");
				system("cls");
				printf("\n **Docente por Contrato** ");
				printf("\n Nombres: %s", name);
				printf("\n Apellidos: %s", lname);
				printf("\n Cédula: %s", id);
				printf("\n Dirección: %s", address);
				printf("\n Correo: %s", email);
				printf("\n Teléfono: %s", phone);
				printf("\n");
					printf("\n Horas Trabajadas:************* %d ", horas);
				printf("horas");
					if(horas>160){
					printf("\n Horas Extras:***************** %d ", horas_extra);
					printf("horas");
					printf("\n Pago Por Horas Extras:******** $%.2f", pago_extra);
					printf("\n Pago Por Horas Corrientes:**** $%.2f", pago_corriente);
					}else if(horas<=160){
						if(horas<160){
							printf("\n Horas Faltadas:*************** %d ", horas_falta);
							printf("horas");
						}
					printf("\n Tarifa Por Horas:************* $%.2f", PPHDC);
					}
				printf("\n Sub Total:******************** $%.2f", sub_total);
				printf("\n Descuento Seguro (10.15%%):****-$%.2f", dscto);
				printf("\n");
				printf("\n Total a Pagar:**************** $%.2f", total);
				printf("\n \n");
				system("pause");
				system("cls");
				goto mod;
			//Tercer Menu: Docente de Nombramiento	
			case 3:
				printf("\n **Cálculo de valor a pagar** ");
				add=0; pago_extra=0; horas_extra=0;//Se declaran las variables en 0, de tipo float para descuento
				do{
					printf("\n Ingrese horas trabajadas: ");
					scanf ("%d",&horas);//recoge datos para guardar en la variable horas
					fflush(stdin);
					if(horas<=0){//Validacion para que las horas sean mayores a 0
						printf("\n Ingreso Inválido!");
					}
				}while(horas<=0);//condicion para validar que las horas sean solo positivas

				if (horas > 160){//condicional para efectuar el calcula de tarifa de pago extra si las horas superan las 160
					fflush(stdin);
					horas_extra = horas - 160;
					add = (PPHDN * 0.15) + PPHDN;//Realiza el calculo para tarifa horas extras
					pago_extra = horas_extra * add;
					pago_corriente = horas * PPHDN;
					sub_total = pago_corriente + pago_extra;
					dscto = (sub_total * 10.15) / 100;//calcula las horas por el pago adicional
					total = sub_total - dscto;//efectua el total a pagar
				}else if(horas <= 160){//condicion que se ejecuta si las horas son menores a 160
					if(horas<160){
						horas_falta = 160 - horas;
					}
					sub_total = horas * PPHDN;	
					dscto = (sub_total * 10.15) / 100;	
					total = sub_total - dscto;//efectua el total a pagar	
					}
					
				//Muestra los datos ingresados
				system("pause");
				system("cls");
				printf("\n **Docente por Nombramiento** ");
				printf("\n Nombres: %s", name);
				printf("\n Apellidos: %s", lname);
				printf("\n Cédula: %s", id);
				printf("\n Dirección: %s", address);
				printf("\n Correo: %s", email);
				printf("\n Teléfono: %s", phone);
				printf("\n");
				printf("\n Horas Trabajadas:************* %d ", horas);
				printf("horas");
					if(horas>160){
					printf("\n Horas Extras:***************** %d ", horas_extra);
					printf("horas");
					printf("\n Pago Por Horas Extras:******** $%.2f", pago_extra);
					printf("\n Pago Por Horas Corrientes:**** $%.2f", pago_corriente);
					}else if(horas<=160){
						if(horas<160){
							printf("\n Horas Faltadas:*************** %d ", horas_falta);
							printf("horas");
						}
					printf("\n Tarifa Por Horas:************* $%.2f", PPHDN);
					}
				printf("\n Sub Total:******************** $%.2f", sub_total);
				printf("\n Descuento Seguro (10.15%%):****-$%.2f", dscto);
				printf("\n");
				printf("\n Total a Pagar:**************** $%.2f", total);
				printf("\n \n");
				system("pause");
				system("cls");
				goto mod;//llama a la etiqueta mod
		
			//Menú de Salir
			case 4:
				//Alerta de confirmación de salida
				printf("\n**CONFIRMAR SALIDA**");
				printf("\n 1. SI");
				printf("\n 2. NO");//aviso, por el caso de haber ingresado por error la opción salir
				do{//Sentencia para validar el correcto ingreso del menu
					printf("\n Opción: ");
					scanf ("%d",&exit);//ingreso de datos en variable exit
					if(exit <= 0 || exit > 2){
						printf("\n Opción Inválida!...");//Aviso de entrada incorrecta
					}
					if(exit==1){//Condicion para efectuar el proceso de salir del programa
						system("exit");
						printf("\n **PROGRAMA FINALIZADO**");//Mensaje de Programa Finalizado
					}else if(exit==2){//Condicion para retornar a menu principal
					fflush(stdin);//limpieza de buffer
					add=0; pago_extra=0; horas_extra=0;//Se declaran las variables en 0, de tipo float para descuento
					system("cls");//funcion para limpiar pantalla
					goto mod;//llama la etiqueta mod
					}
				/*Condicion para verificar el correcto ingreso de datos,
				si es mayor de dos se repite para ingresar datos correctos*/
				}while(exit <= 0 || exit > 2);
			break;//break para terminar y cerrar caso 4
			//default
			default: goto mod;//llama a etique mod(menu principal) si se ingresa un numero que incorrecto.
			}
			
		getch();//funcion para pausar el programa antes de finalizar
}
