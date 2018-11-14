/*
 * Crea un programa que compare dos archivos de entrada y encuentre la diferencia del contenido 
 * del archivo A con el archivo B .Objetivo obtener las diferencias de los contenidos
 * A) Posicio B)Palabra
 * cargar los ficheros a.txt y b.txt en el mismo directorio
 * compilacion g++ -std=c++11 -o ejecutable fichero.cpp
 */

/**************************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream> //http://www.cplusplus.com/doc/tutorial/files/

//Nombre de los ficheros texto archivo A y archivo B

#define ARCHIVO_A "a.txt"
#define ARCHIVO_B "b.txt"

using namespace std;
/**************************************************************************************************************/
void compara(string* a,string* b){//Funcion de comparacion 
	int posicion(0);
	
	string::iterator aa=a->begin();//https://en.cppreference.com/w/cpp/iterator/iterator
	string::iterator bb=b->begin();	
	
	for (; (aa< a->end()) && (bb <b->end()); aa++,bb++,posicion++){//Recorre los archivos e incrementa su posicion
		
		if ( (char) (*aa) !=  (char) (*bb) ){//si el caracter de A es diferente de B , imprime posicion y hasta el espacio ;)
			
			cout <<"["<<posicion<<"] = "<< a->substr (posicion, (a->find(" ",posicion,1)-posicion) ) <<endl<<endl;
		}
	}
}

/**************************************************************************************************************/

int main (){
	string linea,textoA,textoB;
	
 	ifstream ficheroA (ARCHIVO_A,ios::in);
 	ifstream ficheroB (ARCHIVO_B,ios::in); 	

	//Test ficheros si han sido correctamente abiertos 
	if (!ficheroA.is_open()) { cout <<" Error "<<ARCHIVO_A <<endl; }
	if (!ficheroB.is_open()) { cout <<" Error "<<ARCHIVO_B <<endl; }
		
	//Recupera ficheros en string textoA,B
	while ( getline (ficheroA,linea) ){textoA+=linea;}
	while ( getline (ficheroB,linea) ){textoB+=linea;}	
		
	//Compara
	compara (&textoA,&textoB);
	
	//Cierra ficheros
	if (ficheroA.is_open()){ficheroA.close();}
	if (ficheroB.is_open()){ficheroB.close();}	
	
	return 0;
}
