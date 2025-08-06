//      PROYECTO # 2 Sistema De Farmacia
//           Justin Paniagua Solano
//            Fecha 4 Abril 2024
//            Primer Cuatrimestre 2024


#include <iostream>//Libreria Principal
#include <fstream>//libreria Para el Manejo de Archivos
#include <iomanip>//Libreiria para el uso del setw()
#include <limits>//libreria Para el Uso Del "cin.ignore(numeric_limits<streamsize>::max(), '\n');"
#include<string.h>//libreria para el uso del strcpy

using namespace std;

//prototipos de las funciones a Usar
void Registro_Medicamentos();//funcion para el registro de medicamentos
void Asociaciones_Medicamentos();//funcion para el registro de asociciaciones
void Buscar_Codigo(int, const char*const, int);//funcion para la busqueda el producto mediante el codigo
void Registro_Receta();//funcion para el registro de recetas
void Reporte_Productos();//funcion para la opcion 4
void Mostrar_Productos(int, const char*const , int);//funciosn para la impresion de los medicamentos
void Reporte_Recetas();//funcion para la impresion de las recetas
void Buscar_Nombre(int, const char*const, int);//funcion para verificar nombre unico del medicamento mediante el nombre del mismo
void Validacion_Numero_Receta(int);//funcion para verificar numero de receta unico
void Validacion_Asociacion(int, const string & Asociacion);//funcion para validar la correcta asociacion


//variables Globales Para Funcion Registro_Medicamentos();
int CodigoMedicamento;
char NombreMedicamento[30];
int CantidadMedicamento;
int CodigoMedicamentoAux;

int ConsultaCodigo;//Variables Globales Para La Funcion Buscar_Codigo(int,const char* const,int);

char ConsultaNombre[30];//variable para la consula del nombre
int ConsultaNumeroReceta;//variable para la consulta del numero de receta
int ConsultaValidacionCodigo;//variable para la consulta de la asociacion

//variables para realizar las validaciones existente
int ValidacionNombre;
int ValidacionCodigo;
int ValidacionNumeroReceta;
int ValidacionAsociacion;

//variables Globales Para Funcion Registro_Receta();
int NumeroReceta;
int CodigoReceta;
int CantidadReceta;
string Paciente;
string Indicacion;

string Asociacion;//Variable Global para guardar la Asociacion

char Respuesta;//variable global para el guardado de los archivos
bool Salir = false; //Bandera para salir del programa

//funcion Principal
int main(){

    int Eleccion;//variable para el manejo del switcg

    //do while para el manejo del menu principal
do{
    system ("cls");
    cout<<"Sistema Farmacia \n 1.Ingresar Productos \n 2.Ingresar Asociaciones \n 3.Registro Recetas \n 4.Reporte De Catalogos De Productos \n 5.Reporte De Impresion Recetas \n 6.Salir"<<endl;
    cout<<"Por favor Seleccione La Opcion A Trabajar:";
    cin >> Eleccion;

    //switch de acuerdo a la eleccion del usuario
    switch (Eleccion) {

        case 1:
                Registro_Medicamentos();//llamado de la funcion
                break;

        case 2:
                Asociaciones_Medicamentos();//llamado de la funcion
                break;

        case 3:
                Registro_Receta();//llamado de la funcion
                break;

        case 4:
                Reporte_Productos();//llamado de la funcion
                break;

        case 5:
                Reporte_Recetas();//llamado de la funcion
                break;

        case 6:
                system("cls");
                cout<<"Saliste Del Programa"<<endl;//mensaje de despedida
                Salir=true;//bandera activada
                system("pause");
                break;

        default://default del switch
            system ("cls");
            cout << "Eleccion Incorrecta" << endl;
            cin.clear(); // Elimina lo que este en el cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el butter
            system ("pause");
    }

}while( !Salir );
}

//funcion para registro de medicamentos (Opcion 1)
void Registro_Medicamentos(){
    system ("cls");//limpia pantalla

    //abrir el archivo en modo lectura
    ifstream Consultar( "MEDICAMENTOS.TXT" ,ios::in);

    cout << "         Bienvenido A La Opcion 1" << endl;

    //Variables para el Manejo del Archivo MEDICAMENTOS.TXT
    string NombreArchivo = "MEDICAMENTOS.TXT" ;
    ofstream Archivo;

    //abrir el Archivo de Texto Medicamentos.txt en modo edicion
    Archivo.open(NombreArchivo.c_str(),fstream::out | ios::app);

    //validar que Medicamentos.txt se abra correctamente
    if(!Archivo){
        cout << "No Se Pudo Abrir El Documento MEDICAMENTOS.TXT";
        exit(1);
    }


    //try catch para Saber si el codigo es numeral
    try{
        cout << "Digite El Codigo Del Medicamento: " ; cin >> CodigoMedicamento;

    //if para validar que el codigo sea numero
    if (cin.fail()) throw 1;{
        cin.clear(); // limpia el cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //limpia del buffer
    }
    }catch (int e){
        system ("cls");
        cout << "Error:#" << e <<" Por Motivo De Meter Un Caracter Diferente En Codigo" << endl;//mensaje de error
        cout << "Se Esperan Caracteres Numerales Solamente..." << "\n" << endl;

        cin.clear(); // Limpia el cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpia Buffer
        cout << "Digite El Codigo Del Medicamento: "; cin>> CodigoMedicamento;
    }
    CodigoMedicamentoAux = CodigoMedicamento;
        //try catch para validar nombre unico mediante el nombre del medicamento
        try{
            cout << "Digite El Nombre Del Medicamento: "; cin >> NombreMedicamento;
        //strcpy sacado de 42. Programación en C++ || Cadenas || Copiar el contenido de una cadena a otra - Funcion strcpy
        //link=https://www.youtube.com/watch?v=gOeMQRNMucA
            strcpy(ConsultaNombre,NombreMedicamento);

            while (Consultar >> CodigoMedicamento >> NombreMedicamento >> CantidadMedicamento)
                {
                Buscar_Nombre(CodigoMedicamento, NombreMedicamento, CantidadMedicamento);
                }

            strcpy (NombreMedicamento, ConsultaNombre );//para que vulvan sus valores anteriores
            CodigoMedicamento = CodigoMedicamentoAux;
            if ( ValidacionNombre == 1 ) throw 4; {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } catch (int e){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error:#"<<e<<"Motivo Nombre Existe..";
            cout << "El Nombre Del Medicamento Debe De Ser Unico.."<<"\n"<<endl;
            cout << "Digite El Nombre Del Medicamento: "; cin >> NombreMedicamento;
        }

//try catch para Saber si la cantidad es numeral
    try{
        cout << "Digite La Cantidad Del Medicamento: "; cin >> CantidadMedicamento;
        if (cin.fail())throw 2;{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }catch (int e){
        system ("cls");
        cout << "Error:#" << e << " Por motivo de Meter Una Cantidad Invalida " << endl;//mensaje de error
        cout << "Solo Se Espera Numeros En La Cantidad Del Producto..." << "\n" << endl;
        cin.clear(); // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
        cout << "Digite La Cantidad Del Medicamento: "; cin >> CantidadMedicamento;

        }
        system ("cls");
//mensaje para guardar los datos
        cout << "Decea Guardar Este Medicamento(S/N): "; cin >> Respuesta;

    if( (Respuesta == 'S') or (Respuesta == 's') ){
        Archivo << CodigoMedicamento << " " << NombreMedicamento << " " << CantidadMedicamento << "\n";//guardado de los datos
        Archivo.close();//Cerrar archivo

        system ("cls");

        cout << "Medicamento Guardado Con Exito" << endl;
        system ("pause");
    }else {
        cout << "Se Te Volvera Al Menu Principal..." <<endl ;
        system ("pause");
        }
}

//Funcion para Eleccion 2
void Asociaciones_Medicamentos(){

    system ("cls");
    cout << "         Bienvenido A La Opcion #2" << endl;
    bool seguir = false;//variable bool para el do while

//Abrir el Archivo de medicamentos.txt en solo lectura
    ifstream Consultar( "MEDICAMENTOS.TXT" ,ios::in);

//En caso de que MEDICAMENTOS.TXT no se abra
    if( !Consultar ){
        cout << "El archivo de texto MEDICAMENTOS.TXT no se pudo abrir....";
        exit(1);
    }

//do while con un try catch dentro para el manejo del codigo no sea numeral
    do{
        try{
            cout << " Digite el Codigo del Producto a Buscar: "; cin >> CodigoMedicamento;
            if(cin.fail()) {
                throw 3;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else {
                seguir = true;//bandera activada
    }
        } catch (int e){
            system ("cls");
            cout << "Error:#" << e << " Por motivo de Meter Caracter Diferente En EL Codigo  " << endl;//mensaje de error
            cout << "Se Espera Solo Numeros En El Codigo a Buscar...." << "\n"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while( !seguir );
    CodigoMedicamentoAux = CodigoMedicamento;    //Guardamos el codigoMedicamento en la variable auxiliar

    ConsultaCodigo = CodigoMedicamento;  //pasamos el codigoMedicamento a la variable ConsultaCodigo

    //Llamado y pasar las variables a la funcion Buscar_Codigo
         while(Consultar >> CodigoMedicamento >> NombreMedicamento >> CantidadMedicamento)
            {
            Buscar_Codigo(CodigoMedicamento, NombreMedicamento, CantidadMedicamento);
            }
    //do while con un try catch para validacion del codigo, codigo motificado pero con base a la presentacion del profesor
 //sacado de Sesión Virtual Nº3 - Introducción a la Programación - I Cuatrimestre 2024 (minuto 1:08:24)
//link https://www.youtube.com/watch?v=kmrGdE-j0y4
do {
    try{
        if( ValidacionCodigo != 1 ){
            throw 4;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            seguir = true;
            }
    }catch(int e){
        cout << "Error: " << e << " Codigo No existe" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite El Codigo Del Producto a Buscar:"; cin >> CodigoMedicamento;
    }

}while( !seguir );
    CodigoMedicamento=CodigoMedicamentoAux;
// solicitar la palabra a asociar
    cout << "Digite la Palabra A Asociar: "; cin >> Asociacion;

//Variables para el Manejo del Archivo CLAVES.TXT
    string NombreArchivo = "CLAVES.TXT";
    ofstream Archivo;

//abrir el archivo de texto CLAVES.TXT en modo edicion
    Archivo.open(NombreArchivo.c_str(),fstream::out |ios::app);

//en caso de que Claves.txt no se abra
    if( !Archivo ){
        cout << "El Documento de texto CLAVES.TXT No Se Pudo Abrir.....";
        exit(1);
    }
    system ("cls");

  //Guardado de la Asociacion
    cout << "Decea Guardar La Asociacion(S/N): "; cin >> Respuesta;
    if( (Respuesta == 'S') or (Respuesta == 's') ){
        Archivo << CodigoMedicamento << " " << Asociacion << "\n";//guardado de la asociacion
        Archivo.close();//cerrar archivo
        system ("cls");
        cout << "Asociacion Guardado Con Exito" << endl;
        system ("pause");
    }else{
        system ("cls");
        cout << "Se Te Volvera Al Menu Principal...." << endl;
        system ("pause");
    }
}


//funcion para la eleccion 3
void Registro_Receta(){

    //variables auxiliares
    int NumeroRecetaAux;
    int CodigoRecetaAux;

//abrir recetas para realizacion de la consulta
 ifstream RecetaConsulta( "RECETAS.TXT" ,ios::in);

    system ("cls");

    cout << "     Bienvenido a la Opcion #3" << endl;

//variables para el manejo de archivos  Receta.txt
    string NombreArchivo= "RECETAS.TXT" ;
    ofstream Archivo;

//abrir el archivo de texto receta.txt
    Archivo.open(NombreArchivo.c_str(),fstream::out|ios::app);

//do while y trty para el manejo del numero <1000
    bool seguir = false;
    do{
            cout << "Por Favor Digite El Numero De La Receta: "; cin >> NumeroReceta;
        try{
            if( NumeroReceta <= 999 ){
                throw 5;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }else {
                seguir = true;
    }
    } catch(int e){
        cout << "Error:#" << e << " Numero Menor de 1000" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    NumeroRecetaAux=NumeroReceta;
}while( !seguir );

ConsultaNumeroReceta = NumeroReceta;

            while (RecetaConsulta >> NumeroReceta)
            {
            Validacion_Numero_Receta(NumeroReceta);
            }

//Try catch para verificacion de numero de receta Unico
 try{
        if (ValidacionNumeroReceta == 1 ){
            throw 7;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }catch(int e){
    //system("cls");
    cout << "Error :# " << e << " Numero de Receta En Uso " << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Por Favor Digite El Numero De La Receta: "; cin>>NumeroReceta;
    }

    NumeroReceta=NumeroRecetaAux;

//solicitar nombre
    cin.ignore();
    cout << "Por Favor Digite El Nombre Del Paciente: ";
    getline(cin,Paciente);

//try catch para el manejo de codigo sea numeral
try{
    cout<<"Por Favor Digite El Codigo Para La Receta: ";cin>>CodigoReceta;
    if(cin.fail())throw 1;{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}catch (int e){
    system ("cls");
    cout << "Error:#" << e << " Por motivo de Meter Un Codigo Invalido " <<endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Por Favor Digite El Codigo Para La Receta: "; cin >> CodigoReceta;
}
    CodigoRecetaAux=CodigoReceta;
//solicitar indicacion
    cout << "Por Favor Digite La Indicacion: ";
    getline(cin,Indicacion);

//try catch para el manejo de cantidad numeral
    try{
        cout << "Por Favor Digite La Cantidad: "; cin >> CantidadReceta;
        if (cin.fail())throw 2;{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }catch (int e){
        cout << "Error:#"<<e<<" Por motivo de Meter Una Cantidad Invalida " <<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite La Cantidad Del Medicamento: "; cin >> CantidadReceta;
        }


//abrir el archivo de texto Medicamentos.txt
    ifstream Medicamentos( "MEDICAMENTOS.TXT" ,ios::in);

    ConsultaCodigo = CodigoReceta;//sacar lo del codigo a la variable consulta

//idea sacada de Sesión Virtual Nº3 - Introducción a la Programación - I Cuatrimestre 2024
//link https://www.youtube.com/watch?v=kmrGdE-j0y4
    while (Medicamentos >> CodigoMedicamento >> NombreMedicamento >> CantidadMedicamento)
    {
        Buscar_Codigo(CodigoMedicamento, NombreMedicamento, CantidadMedicamento);
    }

    system ("cls");
    cout<<"¿Decea Guardar La Receta(S/N):?";cin>>Respuesta;
    if( (Respuesta == 'S') or(Respuesta == 's')){

         ifstream Claves("CLAVES.TXT", ios::in);
         ConsultaValidacionCodigo= CodigoReceta;

        while(Claves >>CodigoReceta >>Asociacion)
        {
            Validacion_Asociacion(CodigoReceta,Asociacion);


        }

        try{
            if(ValidacionAsociacion !=1){
                throw 8;
            }else{
                CodigoReceta=CodigoRecetaAux;

                Archivo << NumeroReceta << " , "<< Paciente <<" , " << CodigoReceta << " , " << Indicacion << " , " << CantidadReceta << "\n";//guardado de la Receta

                Archivo.close();//cerrar archivo
                system ("cls");
                cout << "Receta Guardada Con Exito" << endl;
                }
        }catch(int e){
            cout<<"Error #"<< e << "Motivo Asociacion Incorrecta";
            cout<<"Se Te Sacara Del Programa"<<endl;
            system("pause");
            exit(1);
        }
    }else{
        system("cls");
        cout<<"Se Te Volvera Al Menu Principal..."<<endl;
        system("pause");
    }
}

//funcion para la eleccion 4
void Reporte_Productos(){
    system ("cls");

    cout <<"     Bienvenidos a la Opcion 4" << endl;

//abrimos el archivo de texto MEDICAMENTOS.TXT
    ifstream Medicamentos( "MEDICAMENTOS.TXT",ios::in );

    cout<<"Los Medicamentos Ingresados Al Sistema Son Los Siguientes"<<endl;
    cout<<"                     Lista De Medicamentos"<<endl;
    cout<< left << setw(15) << " Codigos Productos    " << setw(10) << "     Nombres Productos   " << setw(10) <<"     Cantidad Producto"<<endl;

//while para llamado de la funcion Mostrar productos
    while (Medicamentos >> CodigoMedicamento >> NombreMedicamento >> CantidadMedicamento)
        {
        Mostrar_Productos(CodigoMedicamento, NombreMedicamento, CantidadMedicamento);
        }
    system ("pause");
}

//funcion para mostrar los productos guardados ,eleccion 4
//idea sacadada del void buscar dada por el profesor Ivan molida en Sesión Virtual Nº3 - Introducción a la Programación - I Cuatrimestre 2024
//pero sin validacion
void Mostrar_Productos(int CodigoMedicamento,const char*const NombreMedicamento,int CantidadMedicamento){
 cout << left << "     " << setw(25) << CodigoMedicamento << setw(20) << NombreMedicamento << "        "<< setw(25) << CantidadMedicamento<<endl;//mostrar lo guardado
}

//funcion para la impresion de las recetas guardadas ,eleccion 5
void Reporte_Recetas(){
    system ("cls");
    int i = 0;
    //idea sacada del profesor Danilo en Sesión Virtual Nº2 - Introducción a la programación - I Cuatrimestre 2024(minuto 1:29:41)
    //link https://www.youtube.com/watch?v=z5hIyUro1Js

    //ifstream Recetas("RECETAS.TXT",ios::in);
    string NombreArchivo = "RECETAS.TXT";
    ifstream Archivo (NombreArchivo.c_str());
    string linea;

    cout<<"Las Recetas Ingresadas Al Sistema Son Las sigueintes"<<endl;
    cout<<"                              Recetas"<<endl;
    cout<<"     #     Numero         Paciente   Codigo    Indicacion      Cantidad  "<<endl;
    while (getline (Archivo,linea)){
        i+=1;
       cout <<" Receta# "<< i <<"     " << linea <<"   "<<endl;
    }
    system ("pause");
}

//funcion para buscar mediante el uso del codigo
//idea principal sacada de la presentacion del tutor Ivan Molina
//en Sesión Virtual Nº3 - Introducción a la Programación - I Cuatrimestre 2024
//link:https://www.youtube.com/watch?v=kmrGdE-j0y4
void Buscar_Codigo(int CodigoMedicamento, const char*const NombreMedicamento, int CantidadMedicamento){
    int Valor;
    Valor = CodigoMedicamento;
    if (Valor == ConsultaCodigo){
        cout<<"\n" << left << setw(10) << "    Codigo Medicamento    " << setw(10) << "   Nombre Medicamento  " << setw(10) << "   Cantidad Medicamento" << endl;
        cout<<"          " << CodigoMedicamento << "                   " << NombreMedicamento << "              " << CantidadMedicamento << endl;
        ValidacionCodigo = 1;
        system ("pause");
}
}

//funcion parecido a la buscar_Codigo pero con la variante que hace la comparacion por el nombre y no muestra el producto
void Buscar_Nombre(int CodigoMedicamento, const char*const NombreMedicamento, int CantidadMedicamento){
    char Valor [30];

//funcion strcpy sacada de 42. Programación en C++ || Cadenas || Copiar el contenido de una cadena a otra - Funcion strcpy
//link:https://www.youtube.com/watch?v=gOeMQRNMucA
   strcpy (Valor , NombreMedicamento);

//funcion strcmp sacado de Comparar dos cadenas en c++ strcmp
//link:https://www.youtube.com/watch?v=rw8S3R_UYYA
    if (strcmp (Valor, ConsultaNombre) == 0){
            cout<<" MEDICAMENTO YA GUARDADO"<<endl;
            cout<<"\n" << left << setw (10) <<"    Codigo Medicamento    " << setw(10) << "   Nombre Medicamento  " << setw(10) << "   Cantidad Medicamento" << endl;
            cout<<"          " << CodigoMedicamento << "                   " << NombreMedicamento << "              " << CantidadMedicamento << endl;
            ValidacionNombre = 1;
            system ("pause");
    }
}

//Funcion para la validacion de numero unico
//funcion parecida a la de buscar_Codigo
void Validacion_Numero_Receta(int NumeroReceta){
    int ValorNumero;
    ValorNumero = NumeroReceta;
    if ( ValorNumero == ConsultaNumeroReceta )
        {
        ValidacionNumeroReceta = 1;
        }
    }

//funcion para validar la asociacion sacado de :Check if a string contains a string in C++
//link: https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
void Validacion_Asociacion(int CodigoReceta,const string & Asociacion){
    int Valor;
    Valor=CodigoReceta;
    if (Valor==ConsultaValidacionCodigo)
    {
        if (Indicacion.find(Asociacion) != std::string::npos){
            ValidacionAsociacion=1;
            cout<<"Asociacion Correcta"<<endl;
            system("pause");
        }
    }
}
