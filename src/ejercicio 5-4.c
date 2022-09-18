/*
 ============================================================================
 Name        : ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Ejercicio 5-4: Pedir 10 números entre -100 y 100, guardarlos en un Array.
 Determinar:
a) Cantidad de negativos.
b) Sumatoria de los impares.
c) El mayor de los pares.
d) Listado de los números ingresados.
e) Listado de los números mayores a 15.
f) Listado de los números de las posiciones impares.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define  T 5

int pedirNumero();
int validarNumero(int numero,char mensaje[],int minmo, int maximo,char mensajeError[]);
void cargarArray(int listaNumeros[],int tam);
void mostrarArray(int listaNumeros[],int tam);
void cantNegativos(int listaNumeros[],int tam);
void listaNumeros15(int listaNumeros[],int tam);


void listadoNumImpares(int listaNumeros[],int tam);
void mayorPares(int listaNumeros[],int tam);
void posicionesImpares(int listaNumeros[],int tam);
int determinarParidad(int entero);


int main(void)
{
	setbuf(stdout,NULL);
	int listaNumeros[T];


	cargarArray(listaNumeros, T);
	mostrarArray(listaNumeros,T);
	cantNegativos(listaNumeros,T);
	listaNumeros15(listaNumeros,T);
	listadoNumImpares(listaNumeros,T);
	mayorPares(listaNumeros,T);
	posicionesImpares(listaNumeros,T);

	return 0;
}

void cargarArray(int listaNumeros[],int tam)
 {
	 int i;

	 for(i=0;i<tam;i++)
	 {
		 listaNumeros[i]=pedirNumero();
	 }

 }

 int pedirNumero()
 {
	 int numero;

	 printf("ingrese numero");
	 scanf("%d",&numero);

	 numero=validarNumero(numero,"ingrese numero",-100,100,"error reingrese");

	 return numero;
 }

 int validarNumero(int numero,char mensaje[],int minmo, int maximo,char mensajeError[])
 {
	 while(numero < -100 || numero > 100)
	 {
		 printf("%s",mensajeError);
		 scanf("%d",&numero);
	 }

	 return numero;
 }

 void mostrarArray(int listaNumeros[],int tam)
 {
	 int i;
	 for(i=0;i<tam;i++)
		 {
			printf("%d\n", listaNumeros[i]);
		 }
 }

 void cantNegativos(int listaNumeros[],int tam)
 {
	 int i;
	 int flag;
	 flag=0;
	 int contadorNegativos;
	 contadorNegativos=0;

	 for(i=0;i<tam;i++)
	 {
	 	if(listaNumeros[i]<0)
	 	{
	 		contadorNegativos++;
			flag=1;
	 	}
	 }

	 if(flag==0)
	 {
		 printf("no se ingresaron numeros negativos\n");
	 }
	 else
	 {
		 printf("la cantidad de numeros negativos es de %d\n",contadorNegativos);
	 }

 }

 void listaNumeros15(int listaNumeros[],int tam)
 {
	 int i;
	 int flag;
	 flag = 0;

	 for(i=0;i<tam;i++)
	 {
		 if(listaNumeros[i]>15)
		 {
			 printf("%d\n",listaNumeros[i]);
			 flag=1;
		 }
	 }

	 if(flag==0)
	 {
		 printf("no se ingresaron numeros mayores a 15\n");
	 }
 }

  void listadoNumImpares(int listaNumeros[],int tam)
 {
	 int flag;
	 int i;
	 int acumuladorImpares;
	 acumuladorImpares=0;
	 flag=0;

	 for(i=0;i<tam;i++)
	 {
	 	  switch(determinarParidad(listaNumeros[i]))
	 	  {

	 	  case 0:
	 		  	  	  acumuladorImpares+=listaNumeros[i];
	 		  	  	  flag=1;
	 		 break;

	 	  }

	  }
	 if(flag==0)
	 {
		 printf("no se ingresaron numeros impares\n");
	 }
	 else
	 {
		 printf("la suma de los impares es %d\n",acumuladorImpares);
	 }
 }

  void mayorPares(int listaNumeros[],int tam)
  {
	  int i;
	  int flag;
	  int maximoPar;
	  flag=0;

	  for(i=0;i<tam;i++)
	  {
		  switch(determinarParidad(listaNumeros[i]))
		  {
		  	  case 1:
		  		  	  if(flag==0 || listaNumeros[i]>maximoPar)
		  		  	  {
		  		  		  maximoPar=listaNumeros[i];
		  		  		  flag=1;
		  		  	  }
			  break;
		  }
	  }
	  if(flag==0)
	  {
		  printf("no se ingresaron pares\n");
	  }
	  else
	  {
		  printf("el maximo par es  %d\n",maximoPar);
	  }

  }

  void posicionesImpares(int listaNumeros[],int tam)
  {
	  int flag;
	  int i;
	  flag=0;

	  	 for(i=0;i<tam;i++)
	  	 {
	  	 	  switch(determinarParidad(i))
	  	 	  {

	  	 	  case 0:
	  	 		  	  	  printf("numeros en las posiciones impares %d\n",listaNumeros[i]);
	  	 		  	  	  flag=1;
	  	 		 break;

	  	 	  }

	  	  }
	  	 if(flag==0)
	  	 {
	  		 printf("no se ingresaron numeros impares\n");
	  	 }
  }

 int determinarParidad(int entero)
 {
	 int retorno;
	 retorno=0;

	 if(entero % 2 == 0)
	 {
		 retorno=1;
	 }

	 return retorno;
 }
