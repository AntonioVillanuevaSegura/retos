//Traductor decimal binario
#include <iostream>
#include <cmath>
using namespace std;
#define MIN 0
#define MAX 255


/*----------------------------------------------------------------------*/
string binario(int decimal){//calculo binario
	string bin("");//cadena representa binario
	int exp(0);//exponente maximo 2^exp en el rango del numero decimal
	
	while (pow(2,++exp) <=decimal) {};//Maxima potencia de 2 relativa al numero

	while (exp>=0){bin+= (decimal & (int)(pow(2,exp--)) ) ? "1" :"0";}//and ultimo bit}
	
	return bin;
};
/*----------------------------------------------------------------------*/
/*----------------------------------------------------------------------*/
int main (){
	for (int decimal=MIN ;decimal<=MAX;decimal++){		
		cout <<"num =" <<decimal<< " bin= "<< binario(decimal)<<endl;
	}
}
