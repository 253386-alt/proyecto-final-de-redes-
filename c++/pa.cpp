#include<iostream>
#include<fstream>
using namespace std;

string nombre[3];
float precio[3];

void LeerArchivos (){ 
int indice = 0;

ifstream archivoEntrada("porductos.txt",ios::in);

if(!archivoEntrada){
    cerr<<" no se puede abrir el archivo"<< endl;
    return;   
} 

while (indice < 3 && archivoEntrada >> nombre[indice] >> )
{
   cout<<nombre"\t\t"<<precio<<endl; 
}
return 0;
}





int main (){
LeerArchivos();

 for (int i =0; i < 3; i++){
    cout << "nombre:" << nombre[i] << endl;
    cout << "precio:" << precio[i] << endl;
 }
}
