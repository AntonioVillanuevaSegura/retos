#include <iostream>
using namespace std;

char binToChar(string bin){
	char salida(0);
	for (size_t pos=0;pos< bin.size();pos++){//izq -> der string
		salida|=  (bin[7-pos]=='1' ? 1 :0)<<pos;
	}	
	return salida;
}
string CharToBin(char c){
	string salida("");

	//for (int pos=1;pos<256 ;pos*=2){//izq -> der string
		for (int pos=128 ;pos>=1 ;pos/=2) {//izq -> der string

		salida+= (c & pos)!=0 ? "1" :"0";

	}	
	return salida;
	
}
int main (){
	string str;
	//string respuesta ("Feliz dia del programador y felicidades por la decodificacion ;) !!");
	
//Decodificador 

	while (cin >> str){
	 cout <<binToChar(str);
	}


//Codificador 
/*
	for ( std::string::iterator it=respuesta.begin(); it!=respuesta.end(); ++it){
	 cout <<CharToBin(*it)<<" ";
	}
*/	
}
