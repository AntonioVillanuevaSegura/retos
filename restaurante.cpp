#include <iostream>
#include <limits> //limites float  std::numeric_limits<float>::max()
#include <vector> //http://www.cplusplus.com/reference/vector/vector/
//uso ./ejecutable <input.txt
using namespace std;
/*-------------------------------------------------------------------------------*/
struct codigo{char cod;float ingreso;};//Creo un "array" de estructura codigo
/*-------------------------------------------------------------------------------*/
string codigoToCategoria (const char codigo){//retorna el STRING correspondiente a una CATEGORIA
	switch (codigo) {
		case 'D':return "DESAYUNOS";break;
		case 'A':return "COMIDAS";break;
		case 'M':return "MERIENDAS";break;
		case 'I':return "CENAS";break;
		case 'C':return "COPAS";break;	
		default:break;									
	}
	return "";
}
/*-------------------------------------------------------------------------------*/
bool empate(vector <codigo> cat){//varias categorias en EMPATE ?
	int encontrado(0);
	
	if (cat.size()<=3 ){return true;} //al menos dos elementos son igual a 0
	
	for (std::vector<codigo>::iterator it = cat.begin() ; it != cat.end(); ++it){
			for (std::vector<codigo>::iterator it2 = cat.begin() ; it2 != cat.end(); ++it2){
				
				if (it->ingreso==it2->ingreso) {encontrado++;}//Compara un elemento con todos				
				if (encontrado >=2){return true;} //Se han econtrado dos valores iguales 
			}
			encontrado=0;//Nueva busqueda de num. de encontrados
	}	
	return false;//No hay empate 	
}
/*-------------------------------------------------------------------------------*/
//string evaluacion (int size,float codigo[]){//evalua los datos de entrada crea la salida 
string evaluacion (vector <codigo> cat){//evalua los datos de entrada crea la salida 
	string dia;	
	float media(0),comida(0);
	float maximo(0),minimo(std::numeric_limits<float>::max());//En los limites del float

	string max(""),min("");
	
	for (std::vector<codigo>::iterator it = cat.begin() ; it != cat.end(); ++it)
	{
		if (it->cod=='A'){comida=it->ingreso;}//INGRESO COMIDA
		
		if (it->ingreso<minimo){//INGRESO MININMO 
			minimo=it->ingreso;
			min=codigoToCategoria(it->cod);//Escribo la categoria minima
		}
		
		if (it->ingreso>maximo){//INGRESO MAXIMO 
			maximo=it->ingreso;
			max=codigoToCategoria(it->cod);//Escribo la categoria maxima
		}
			media+=it->ingreso;//SUMA para evaluar la MEDIA 	
	}
		
	//Construccion de la cadena "string" de salida , dia 	
	//INGRESO MAXIMO del dia 
	dia+=max;
	dia+="#";
	
	//Empate (si varios resultados son iguales ) o INGRESO MINIMO ?
	dia+= (empate(cat)) ? "EMPATE": min;		
	dia+="#";
	
	//Las comidas han superado la MEDIA ? SI o NO	
	dia+= comida > (media/5) ?"SI":"NO"; //5 si se tienen en cuenta los 5 codigos 
	//dia+= comida > (media/cat.size()) ?"SI":"NO"; //Media en funcion de datos introducidos

	return dia;
}
/*-------------------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------*/
int main(){
	string str;
	vector <codigo> categorias;//usor del container vector http://www.cplusplus.com/reference/vector/vector/	
	while  (getline(cin, str)){ //lee una linea del fichero de entrada <input.txt
		
		//Crea un un vector de informacion hasta encontrar 'N'
		if (str[0]!='N'){ categorias.push_back ( codigo {str[0],stof( &str[1] )});}//Crea vector de informacion
		else {	
			cout<<evaluacion(categorias)<<endl ;//evalua el vector ha encontrado 'N'
			categorias.clear();//limpia el vector 
		}		
	}						
}

/*Contenido imput.txt
D 2.80 DESAYUNOS
C 48.0 COPAS
A 8.0	COMIDAS
N 0		FIN
 
EMPATE M==I==0
COMIDAS <MEDIA -> No 2.8+48.0+8=58.8  MEDIA =58.8/5=11.76
COPAS#EMPATE#NO

D 15.33 DESAYUNOS
A 60.00 COMIDAS mayor
M 12.00 MERIENDAS menor
I 25.00 CENAS
N 0		FIN

15.33+60+12+25=112.23 MEDIA= 112.23/5=22,466 COMIDAS >MEDIA
COMIDAS#MERIENDAS#
 
*/
