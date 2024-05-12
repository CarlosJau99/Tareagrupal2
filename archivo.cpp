#include <iostream>
using namespace std;
const char *nombre_archivo = "archivo.dat";
	struct Biblioteca{
	char palabra[50];
	char traduccion[50];
	char funcionalidad[500];
};
void Leer();
void Crear();
void Actualizar();
void Borrar();
main() {
	Leer();
  	Crear();
  	Borrar();
	Actualizar();
  	
	system("pause");
}
void Leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Biblioteca biblioteca;
	int id=0; // indice o pocision del registro(fila) dentro del archivo
	fread(&biblioteca,sizeof(Biblioteca),1,archivo);
	cout<<endl;
	cout<<"ID  "<<"|"<<"     Palabra     "<<"|"<<"     Traduccion        "<<"|"<<"         Funcionalidad               "<<endl;
	do{
		cout<<id<<"   |     "<<biblioteca.palabra<<"          |     "<<biblioteca.traduccion<<"                |      "<<biblioteca.funcionalidad<<endl;
		fread(&biblioteca,sizeof(Biblioteca),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	
}
void Crear(){
	
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	Biblioteca biblioteca;
	do{
		fflush(stdin);
		cout<<" Ingrese Palabra: ";
		cin.getline(biblioteca.palabra,50);
		
		cout<<" Ingrese traduccion: ";
		cin.getline(biblioteca.traduccion,50);
		
		cout<<" Ingrese funcionalidad: ";
		cin.getline(biblioteca.funcionalidad,500);
		
		fwrite(&biblioteca,sizeof(Biblioteca),1,archivo);
		cout<<"Desea ingresar otra palabra (s/n):";
		cin>>res;
	}while(res=='s' || res=='S'); 
	fclose(archivo);
	Leer();
}
void Actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b"); 
	Biblioteca biblioteca;
	int id=0;
	cout<<"\nIngrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Biblioteca),SEEK_SET);
		cout<<"Ingrese Codigo:";
		
		cout<<"Ingrese palabra:";
		cin.getline(biblioteca.palabra,50);
		
		cout<<"Ingrese traduccion:";
		cin.getline(biblioteca.traduccion,50);
		
		cout<<"Ingrese funcionalidad:";
		cin.getline(biblioteca.funcionalidad,100);
		
		fwrite(&biblioteca,sizeof(Biblioteca),1,archivo);
	
	
	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Biblioteca biblioteca;
	int id=0,id_n=0;
	cout<<"\nIngrese el ID a eliminar:";
	cin>>id;
	while(fread(&biblioteca,sizeof(Biblioteca),1,archivo)){
		if (id_n !=id ){
			fwrite(&biblioteca,sizeof(Biblioteca),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&biblioteca,sizeof(Biblioteca),1,archivo_temp)){
		fwrite(&biblioteca,sizeof(Biblioteca),1,archivo);
		
	}
		fclose(archivo);
	fclose(archivo_temp);
	Leer();
}
/*
 
 
 Otros ejemplos para busqueda por medio de codigo indice etc
 
 
 */
void buscar_codigo(){
		FILE* archivo = fopen(nombre_archivo,"rb");	
	int pos=0,indice=0,cod=0;
	cout<<"\nQue codigo desea ver: ";
	cin>>cod;
	
	Biblioteca biblioteca;
	fread(&biblioteca,sizeof(Biblioteca),1,archivo);	
	do{
	   fread(&biblioteca,sizeof(Biblioteca),1,archivo);	
	} while(feof(archivo)==0);
	
	
	
	fclose(archivo);
}
/*void buscar_codigo(){
	
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Estudiante estudiante;
	
	fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		
		do{
			
			if (estudiante.codigo == cod){
			pos = indice;
			}
	
		fread ( &estudiante, sizeof(Estudiante), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Estudiante), SEEK_SET );
    fread ( &estudiante, sizeof( Estudiante ), 1, archivo );
    	cout << "Codigo: " << estudiante.codigo << endl;
        cout << "Nombre: " << estudiante.nombre << endl;
        cout << "Apellido: " << estudiante.apellido << endl;
        cout << "Telefono: " << estudiante.telefono << endl;
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}
*/

void buscar_indice(){
	FILE* archivo = fopen(nombre_archivo, "rb");
	
	int pos=0;
	cout<<"\nQue registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Biblioteca), SEEK_SET );
	
	Biblioteca biblioteca;
	
    fread ( &biblioteca, sizeof( Biblioteca ), 1, archivo );

        cout << "Palabra: " << biblioteca.palabra<< endl;
        cout << "Traduccion: " << biblioteca.traduccion << endl;
        cout << "Funcionalidad: " << biblioteca.funcionalidad << endl;
        cout << endl;
	
	fclose(archivo);

}