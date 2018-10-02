#include <iostream>
using namespace std;

int longMatrix(char *mat){
    int longitud=0;
    while(*mat++!='\0'){longitud++;}
    return longitud;
}

int main(){
	char matriz[]={"123456789"};
	cout <<"longitud = "<<longMatrix(matriz);
	return 0;
}
