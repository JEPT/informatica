#include<iostream>
#include <string>
#include<vector>
#include<conio.h>
#include <cstdlib>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
#define uno 49
#define dos 50
#define tres 51
#define cuatro 52
#define es 27
using namespace std;

int main (int argc, char *argv[]) {
	//se me hace mas sencillo el uso de vectores, pero se puede con array de string, incluso con una matris de  n por 2 .... 
	//si uso array # (sizeof(array)/sizeof(array[0])) # usare en linea 16 para saber el tamaño del array o definirlo inicialmente....
	
	string usuario, password;
	vector<string> usuarios={"luis","pepe","lucho","juan"}; //cada las posiciones de usuario corresponde a la misma posicion para su contraseña
	vector<string> claves={"123","abc","111","333"};
	string inventario[20][3];
	
	
	int contador = 0;
	bool ingresa = false;
	
	do{/*iniciamos con el  do while por necesito ingresar y luego despues evaluar*/
	cout << "\t\t\tLOGIN DE USUARIO" << endl;
	cout << "\t\t\t----------------" << endl;
	cout << "\n\tUsuario: ";
	getline(cin, usuario); 
	char caracter;
	cout << "\tPassword: ";
	caracter=getch();
	password="";
	while(caracter!=ENTER){
		if(caracter!= BACKSPACE){
			password.push_back(caracter);/*CRea  o pones los asteriscos al ir digitando la contraseña*/
			cout<<"*";}
		else{
			if(password.length()>0) //length ayuda a saber el tamaño del string o cadena de carACTERES
			{
				cout<<"\b \b";                                   /*ayuda a eliminar caracteres de mas en la contraseña*/
				password=password.substr(0,password.length()-1); // SUBSTRAC AYUDA A EXTRAEER UNA SECUENCIA DE DATOS DE UNA CADENA DE CARACTERES O STRING DANDO COMO DATOS EL INICIO Y CUANTOS SE SACAN
			}
		}
			caracter=getch();
		}
	for (int i = 0; i< usuarios.size(); i++) //sisze numero de elmentpos del vector
	{
		if (usuarios[i] == usuario && claves[i] == password)
		{
			ingresa = true;
			break;//NO ME GUSTA USAR BREAK
		}
	}
	if (!ingresa){//AYUDA A ELEVAR EL CONTADIOR 
		cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
		system("pause");
		system("cls");
		contador++; // PORCIERTO EL COMNTADOR ESTA DEFINIDO
	}
	} while (ingresa == false && contador < INTENTOS);  //EL WHILE DE DO DONDE SE EVALUA  SI ACCEDE O NO  SI NPO AUMENTA EL CONTADOR EN 1
	if (ingresa == false)
	{
		cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;//MENMSAJE ALK ALCANZAR EL LIMITRE DE TRES OPORTUNIODADES
	}
	else
	{
		cout << "\n\n\tBienvenido al sistema" << endl;//LOGRO ACCEDER Y PUEDE EMPEZAR A TRABAJAR
		
		//acceso para poder editar el inventario 
		system("cls");// borra pantalla
		char caracter;
		do{
		cout << "\t\t\tCONTROL DE INVENTARIO" << endl;
			
			cout << "\n\t 1. REGISTRAR INGRESO DE PRODUCTO ";
			cout << "\n\t 2. REGISTRAR SALIDA DE PRODUCTO ";
			cout << "\n\t 3. BUSCAR PRODUCTO ";
			cout << "\n\t 4. RESUMEN DE INVENTARIO ACTUAL ";
			cout << "\n\t 5. PRESIONE ESC PARA SALIR ";
			//
				caracter=getch();
				system("cls");// borra pantalla
				//######################################################
				if(caracter==uno){
					int pos=0;
					char continuar='s';
					while(continuar=='s'){
						
							cout<<"\n\t Ingresar los datos del producto a ingresar"<<endl;
							cout<<"\nIngrese codigo: ";
							cin>>inventario[pos][0];
							cout<<"\n Nombre:  ";
							cin>>inventario[pos][1];
							cout<<"\n Fecha:  ";
							cin>>inventario[pos][2];
						
					cout<<"\t\tCodigo:"<<inventario[pos][0];
					cout<<"\t\tNombre:"<<inventario[pos][1];
					cout<<"\t\tFecha: "<<inventario[pos][2];
					pos++;
					cout<<"\n Presione n si no desea seguir agregando o s para continuar  :";
					cin>>continuar;
					}
				}
				if(caracter==dos){
					
				}
				//######################################################
				if(caracter==tres){
					string comprobar,metodo;
					int pos;
					cout<<"\n\t Ingresa el dato buscar por codigo , nombre o fecha ";
					cin>>metodo;
					if(metodo=="codigo"){
						pos=0;
					}
					if(metodo=="nombre"){
						pos=1;
					}
					if(metodo=="fecha"){
						pos=2;
					}
					cout<<"Ingrese el "<<metodo<<endl;
					cin>>comprobar;
					bool f=true;
						for(int i=0;i<20;i++){
							if(inventario[i][pos]==comprobar){
								cout<<"\n \t\t Se encontro:"<<endl;
								cout<<"\t\tCodigo:"<<inventario[i][0];
								cout<<"\t\tNombre:"<<inventario[i][1];
								cout<<"\t\tFecha: "<<inventario[i][2];
								f=false;
								break;
								
							}
							else{
								f=false;
							}
						}
					if(f==false){
							char continuar;
							cout<<"\n Presione n si no desea  agregarlo o s para agregar  :";
							cin>>continuar;
							while(continuar=='s'){
								for(int i=0;i<20;i++){
									if(inventario[i][1]==""){
										pos=i;
									}
								}
								
								cout<<"\n\t Ingresar los datos del producto a ingresar"<<endl;
								cout<<"\nIngrese codigo: ";
								cin>>inventario[pos][0];
								cout<<"\n Nombre:  ";
								cin>>inventario[pos][1];
								cout<<"\n Fecha:  ";
								cin>>inventario[pos][2];
								
								cout<<"\t\tCodigo:"<<inventario[pos][0];
								cout<<"\t\tNombre:"<<inventario[pos][1];
								cout<<"\t\tFecha: "<<inventario[pos][2];
								pos++;
								cout<<"\n Presione n si no desea seguir agregando o s para continuar  :";
								cin>>continuar;
							}	
							
						}
						
				}
				//#######################################################
				if(caracter==cuatro){
					for(int i=0;i<20;i++){
						if(inventario[i][1]!=""){
						cout << "\t\t\tRESUMEN DE INVENTARIO" << endl;
						cout<<"\t\tCodigo:"<<inventario[i][0];
						cout<<"\t\tNombre:"<<inventario[i][1];
						cout<<"\t\tFecha: "<<inventario[i][2];}
					}
				}
			   
			}while(caracter!=es);
			
		//añadir seleccion por teclado o por numero ??
		//luego de acceder a alguna opcion dejar la opcion de volver atras en casa una 
			//otraves tengo que evaluar si lo hago por teclado o por algun valor entero a comparar
	}
	return 0;
}
