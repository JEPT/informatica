#include<iostream>
#include <string>
#include<conio.h>//para usar el getch
#include <cstdlib>//system()

#define ENTER 13//DEFINIENDO CALRIABLES PARA USAR EL TECLADO GRACIAS AL CODIGO ACCII
#define BACKSPACE 8
#define INTENTOS 3
#define uno 49
#define dos 50
#define tres 51
#define cuatro 52
#define es 27
using namespace std;

int main () {
	string usuario, password;
	string user[3][2]={{"usuario","contra"},{"admin","123"},{"user","1111"}};//UNA MATRIZ QUE CONTINE TRES USURARIOS CON SUS CONTRASEÑAS
	int T=10;//TAMAÑO DE LISTA para la lectura de los for en todo el codigo filas
	string inventario[10][6]; //deberia coicidir con la te las filas
	//la cadena de strings de abajo es para probar con datos ya proporcionados....... activar el strin inventario de arriva para rellenar manualmente la m,atriz de 10*6
	//string inventario[10][6]={{"N21","CLAVOS","15","S/14","12-10-22","PABLITO"},{"N211","TABLAS","122","S/24","11-10-22","PEPE"},{"N24","CHINCHES","95","S/3","12-09-22","PABLITO"},{"N33","MARTILLO","50","S/35","02-10-22","PEPE"},{"N21","CLAVOS","51","S/14","12-10-22","PABLITO"},{"N21","CLAVOS","7","S/14","12-10-22","PABLITO"},{"N21","CLAVOS","11","S/14","12-10-22","PABLITO"},{"N21","CLAVOS","35","S/14","12-10-22","PABLITO"},{"N21","CLAVOS","23","S/14","12-10-22","PABLITO"},{"","","0","","",""}};
	
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
	for (int i = 0; i< 3; i++) 
	{
		if (user[i][0] == usuario && user[i][1] == password)
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
				//Opocion uno es para rellenar la matriz o agregar, y puedes seguir agregando hasta que  dijites N O S
				if(caracter==uno){
					int pos=0;
					char continuar='s';
					while(continuar=='s'){
						
							cout<<"\n\t Ingresar los datos del producto a ingresar"<<endl;
							cout<<"\nIngrese Codigo: ";
							cin>>inventario[pos][0];
							cout<<"\n Nombre:  ";
							cin>>inventario[pos][1];
							cout<<"\n Cantidad:  ";
							cin>>inventario[pos][2];
							cout<<"\n Precio: ";
							cin>>inventario[pos][3];
							cout<<"\n Fecha de ingreso:  ";
							cin>>inventario[pos][4];
							cout<<"\n Proveedor:  ";
							cin>>inventario[pos][5];
						
					cout<<"\t\tCodigo:"<<inventario[pos][0];
					cout<<"\t\tNombre:"<<inventario[pos][1];
					cout<<"\t\tCntidad: "<<inventario[pos][2];
					cout<<"\t\tPrecio:"<<inventario[pos][3];
					cout<<"\t\tFecha de ingreso:"<<inventario[pos][4];
					cout<<"\t\tProveedor: "<<inventario[pos][5];
					pos++;
					cout<<"\n Presione n si no desea seguir agregando o s para continuar  :";
					cin>>continuar;
					}
				}
				//########################################################
				//opcion 2 busqueda para realizar el descuento de la cantidad, adicional indica alerta de stock y permite añadir si no encuetra el producto
				
				if(caracter==dos){
					string comprobar,metodo;
					int pos;
					cout<<"\n\t Ingresa el dato buscar por codigo , nombre ";
					cin>>metodo;
					if(metodo=="codigo"){
						pos=0;
					}
					if(metodo=="nombre"){
						pos=1;
					}
					/*if(metodo=="fecha"){
					pos=2;*/ //OTRO SE PODRIA AGREGAR OTRO METODO DE BUSQUEDA
					//}
					cout<<"Ingrese el "<<metodo<<endl;
					cin>>comprobar;
					bool f=true;
					int position;
					for(int i=0;i<T;i++){//RECORRIENDO LA MATRIZ 
						if(inventario[i][pos]==comprobar){//BUSCA COICIDENCIA
							cout<<"\t\tCodigo:"<<inventario[i][0];
							cout<<"\t\tNombre:"<<inventario[i][1];
							cout<<"\t\tCntidad: "<<inventario[i][2];
							cout<<"\t\tPrecio:"<<inventario[i][3];
							cout<<"\t\tFecha de ingreso:"<<inventario[i][4];
							cout<<"\t\tProveedor: "<<inventario[i][5];
							cout<<"\n"<<endl;
							cout<<"\n"<<endl;
							f=true;
							position=i;
							break;
						}
						else{
							f=false;
						}
						}
						if(f==true){//SI ENCUENTRA INDICARA CUANTAS UNIDADES DESEA SACAR
							int salida;
						
						cout<<"\t\tCuatas unidades desea sacar??"<<endl;
						cin>>salida;
							if(stoi(inventario[position][2])<salida || stoi(inventario[position][2])<10){
							cout<<"alerta EStock Insuficiente"<<endl;//ALERTA SI NO HAY STOCK SUFICIENTE
							}
							else{
								int nuevo =stoi(inventario[position][2])-(salida);//CONTINUA SI EL ESTOCK NO ES PROBLEMA DESCONTAMOS CON AYUDA DE STOI PARA VOLVERLO UN INT
								inventario[position][2]=to_string(nuevo);//LA FUNCION TO_STRING ME AYUDA A COMBERTIR UN INT A STRING 
								
								cout<<"\t\tCodigo:"<<inventario[position][0]<<endl;;//IMPRIMO LOS DATOS CON LA MODIFICACION DE CANTIDAD
								cout<<"\t\tNombre:"<<inventario[position][1]<<endl;
								cout<<"\t\tCantidad: "<<inventario[position][2];
								if(stoi(inventario[position][2])<10)//ALERTA SI YA NO HAY STOCK MAYOR A 10
								{
									cout<<"\t\t-->ALERTA STOCK BAJO!!!!";
								}
								cout<<"\n\t\tPrecio:"<<inventario[position][3]<<endl;
								cout<<"\t\tFecha de ingreso:"<<inventario[position][4]<<endl;
								cout<<"\t\tProveedor: "<<inventario[position][5]<<endl;
								
								cout<<"\n"<<endl;
							}
						}
						
						if(f==false){//EN CASO NO ENCUENTRE EL PRODUCTO
							char continuar;
							cout<<"\t\tNo se encontro :"<<endl;
							cout<<"\n Presione n si NO desea  agregarlo o s para agregar  :"<<endl;
							cin>>continuar;
							while(continuar=='s'){//CPONDICION S O N SI SE QUIERE AGREGAR
								for(int i=0;i<T;i++){
									if(inventario[i][1]==""){//PREFIERO BUSCAR UN LUGAR LIBRE PARA PODER AÑADIR Y NO SOBRE ESCRIBIR Y PERDER DATOS
										pos=i;
									}
								}
								
								cout<<"\n\t Ingresar los datos del producto a ingresar"<<endl;// PIDO LOS DATOS A INGRESAR CON POS QUE AYUDA AL LA POSICION DONDE SE AGRGA
								cout<<"\nIngrese Codigo: ";
								cin>>inventario[pos][0];
								cout<<"\n Nombre:  ";
								cin>>inventario[pos][1];
								cout<<"\n Cantidad:  ";
								cin>>inventario[pos][2];
								cout<<"\n Precio: ";
								cin>>inventario[pos][3];
								cout<<"\n Fecha de ingreso:  ";
								cin>>inventario[pos][4];
								cout<<"\n Proveedor:  ";
								cin>>inventario[pos][5];
								
								cout<<"\n\t\tCodigo:"<<inventario[pos][0];//IMPRIMO LOS DATOS INGRESADO
								cout<<"\n\t\tNombre:"<<inventario[pos][1];
								cout<<"\n\t\tCntidad: "<<inventario[pos][2];
								cout<<"\n\t\tPrecio:"<<inventario[pos][3];
								cout<<"\n\t\tFecha de ingreso:"<<inventario[pos][4];
								cout<<"\n\t\tProveedor: "<<inventario[pos][5];
								cout<<"\n"<<endl;
								continuar='n';
					}
						}}
				
				//######################################################
				//busqueda de producto por dos metodos  codigo o nombre, adicional si no encuetra permite agregar
				
				
				if(caracter==tres){
					string comprobar,metodo;
					int pos;
					cout<<"\n\t Ingresa el dato buscar por codigo o nombre :"<<endl;
					cin>>metodo;//    EXAMINO EL METODO POR EL CUAL SERA LA BUSQUEDA
					if(metodo=="codigo"){
						pos=0;
					}
					if(metodo=="nombre"){
						pos=1;
					}
					/*if(metodo=="fecha"){
						pos=2;*/ //OTRO SE PODRIA AGREGAR OTRO METODO DE BUSQUEDA
					//}
					cout<<"\nIngrese el "<<metodo<<endl;//YA OPTENIDO EL METODO REALIZA LA BUSQUEDA
					cin>>comprobar;
					bool f=true;
						for(int i=0;i<T;i++){//RECORREMOS LA MATRIZ
							if(inventario[i][pos]==comprobar){
								cout<<"\n\t\tCodigo:"<<inventario[i][0];
								cout<<"\n\t\tNombre:"<<inventario[i][1];
								cout<<"\n\t\tCantidad: "<<inventario[i][2];
								cout<<"\n\t\tPrecio:"<<inventario[i][3];
								cout<<"\n\t\tFecha de ingreso:"<<inventario[i][4];
								cout<<"\n\t\tProveedor: "<<inventario[i][5];
								cout<<"\n"<<endl;
								cout<<"\n"<<endl;
								f=true;
								break;//NO ME GUSTA USAR, PERO AYUDA A DETENER EL FOR CUADO ENCUENTRA EL VALOR
								
							}
							else{
								f=false;
							}
						}
					if(f==false){//AL NO ENCONTRA RELIZA LA CONSULTA DE S O N PARA INGRESAR LOS DATOS
							char continuar;
							cout<<"\t\tNo se encontro :"<<endl;
							cout<<"\n Presione n si no desea  agregarlo o s para agregar  :";
							cin>>continuar;
							while(continuar=='s'){
								for(int i=0;i<T;i++){
									if(inventario[i][1]==""){//IGUAL QUE ANTES PREFIERO AGREGAR EN UN LIGAR VACIO
										pos=i;
									}
								}
								
								cout<<"\n\t Ingresar los datos del producto a ingresar"<<endl;//PEDIMOS TODOS LOS DATOS PARA SEER INGRESADOS POR TECLADO
								cout<<"\nIngrese Codigo: ";
								cin>>inventario[pos][0];
								cout<<"\n Nombre:  ";
								cin>>inventario[pos][1];
								cout<<"\n Cantidad:  ";
								cin>>inventario[pos][2];
								cout<<"\n Precio: ";
								cin>>inventario[pos][3];
								cout<<"\n Fecha de ingreso:  ";
								cin>>inventario[pos][4];
								cout<<"\n Proveedor:  ";
								cin>>inventario[pos][5];
								
								cout<<"\n\t\tCodigo:"<<inventario[pos][0];// IMPRIME LOS DATOS INGRESADO
								cout<<"\n\t\tNombre:"<<inventario[pos][1];
								cout<<"\n\t\tCntidad: "<<inventario[pos][2];
								cout<<"\n\t\tPrecio:"<<inventario[pos][3];
								cout<<"\n\t\tFecha de ingreso:"<<inventario[pos][4];
								cout<<"\n\t\tProveedor: "<<inventario[pos][5];
								pos++;
								cout<<"\n Presione n si no desea seguir agregando o s para continuar  :";
								cin>>continuar;
							}	
							
						}
					}	
				//#######################################################
				//Opcion 4 para acceder a esta debemos precionar la tecla 4
				if(caracter==cuatro){
					for(int i=0;i<T;i++){
						if(inventario[i][1]==""){//ME AYUDA A PONER UN LIMITE SI ESTA VACIO YA NO LO CONCIDERARA
							T=i;
						}
					}
				for( int i = 1 ; i < T ; i++ ){ //LIMITE ES T
				//##metodo insert sort
					
				//ordenado seun la cantidad de productos
				// Obtenemos el elemento pivote que vamos a insertar
				int elemento = stoi(inventario[i][2]);
				string co = inventario[i][0];//USO VARIBLES TEMPORALES APRA NO PERDER LOS DATOS AL HACER EL INTERCAMBIO
				string no = inventario[i][1];
				string ca = inventario[i][2];
				string pre = inventario[i][3];
				string fe = inventario[i][4];
				string pro = inventario[i][5];
				int j = i;
				// Verificamos si aún no estamos en la posición que le corresponde al elemento
				for( ; j >= 1 && stoi(inventario[j-1][2]) > elemento ; j-- ){ //EVALUAMOS CON AYUDA DE STOI COMO SI FUERA UN INT CADA UNO DE LAS CANTIDADES
					// Hacemos un corrimiento del elemento en j-1 a j ya que este es mayor que el pivote
					inventario[j][0] = inventario[j-1][0]; //UNA VEZ EVALUADO REALIZAMOS EL ORDENAMIENTO OJO NO SOLO DE LA CANTIDAD SINO TODOS SU DATOS
					inventario[j][1] = inventario[j-1][1];
					inventario[j][2] = inventario[j-1][2];
					inventario[j][3] = inventario[j-1][3];
					inventario[j][4] = inventario[j-1][4];
					inventario[j][5] = inventario[j-1][5];
				}
					// Colocamos al pivote en su posición correspondiente
					inventario[j][0] = co;
					inventario[j][1] = no;
					inventario[j][2] = ca;
					inventario[j][3] = pre;
					inventario[j][4] = fe;
					inventario[j][5] = pro;
					}
			
					for(int i=0;i<T;i++){//IMPRIMIMOS YA ORDENADO LOS DATOS SGUN LAS CANTIDADES
						if(inventario[i][1]!=""){
						cout << "\n\t\t\tRESUMEN DE INVENTARIO" << endl;
						cout<<"\n\t\tCodigo:"<<inventario[i][0];
						cout<<"\n\t\tNombre:"<<inventario[i][1];
						cout<<"\n\t\tCntidad: "<<inventario[i][2];
						if(stoi(inventario[i][2])<10)
						{
							cout<<"\t\t-->ALERTA STOCK BAJO!!!!";//DARA UNA ALERTA SI ENCUENTRA UNA CANTIDAD MENOR A 10
						}
						cout<<"\n\t\tPrecio:"<<inventario[i][3]<<endl;
						cout<<"\t\tFecha de ingreso:"<<inventario[i][4]<<endl;
						cout<<"\t\tProveedor: "<<inventario[i][5]<<endl;
						
						cout<<"\n"<<endl;
						}
					}
				}
			   
			system("pause");//AYUDA A ESPERAR  Y DEJA VISUALIZAR
			system("cls");// CADA VEZ QUE TERMINA UNA DE LAS 5 OPCIONES BORRA Y REGRESA AL MENU INICIAS
			}while(caracter!=es);//ESPERA HASTA QUE SE PRESIONE LA TECLA ESCAPE PARA SALIR 
		//PARA CADA UNA DE LAS 5 OPCIONES USO CODIGO ACCI COMO VALOR DE ENTRDA GRACIAS AL getc
			
	}
	return 0;
}
