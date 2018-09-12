#include <stdio.h>
#include <stdlib.h>

//version fgets en lugar de scanf  desaconsejable por cuestiones de seguridad ,desbordamiento del buffer ..
int main(){
	float altura,base;
	char str[64];//cadena de x chars ,utilizo el primer char str[0] para lectura s n y el resto para floats
	printf ("\n Desear continuar con el calculo del area del triangulo: ");fgets(str,2,stdin);
	
	while (str[0]!='n'){
			getchar();//Borra salto de linea caracter \n de la lectura
			
			printf("\n Ingresa la base: ");fgets(str,30,stdin);//lectura string base 
			base=atof(str);//Conversion de un string a un float			
			
			printf("\n Ingresa la altura: ");fgets(str,30,stdin);//lectura string altura
			altura=atof(str);//Conversion de un string a un float
			
			printf ("\n El area del Triangulo es %.2f \n",(base*altura)/2);

			printf ("\n Desear calcular el el area del triangulo: ");fgets(str,2,stdin);				
	}

	printf ("\n fin del Programa");
	return 0;
}
