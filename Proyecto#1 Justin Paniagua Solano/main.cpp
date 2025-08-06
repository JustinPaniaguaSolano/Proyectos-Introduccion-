//proyecto #1 Programa para sacar el IMC de una persona
//Justin Paniagua Solano

//librerias a usar
#include <iostream>//libreria basica de c++
#include<limits>//usada para la 51,71
#include <string>//usada en linea 104 a 107
#include <iomanip>//usado en la linea 145,147 y 149
using namespace std;

int main()
{
    //variables a utilizar
    bool Salir=false;

    int Eleccion=0;
    int Cedula;

    string Estado;

    float IMC;
    float Talla,Peso;

//sacado de https://www.aprendeaprogramar.com/cursos/verApartado.php?id=16006
    char Nombre[40],Primer_Apellido[40],Segundo_Apellido[40];

    //do while usado para mostrar el menu
    do{

    //menu de inicio
    system("CLS");
    cout<<"         Bienvenido al programa para calcular el IMC de una persona"<<endl;
    cout<<" 1.Ingresar los datos de la persona"<<endl;
    cout<<" 2.Ingresar los datos fisico"<<endl;
    cout<<" 3.Calcular el indice de masa corporal"<<endl;
    cout<<" 4.Reporte de informacion del paciente"<<endl;
    cout<<" 5.Salir"<<endl;

    //if para ver la ultima opcion seleccionada
    if(Eleccion!=0){
        cout<<"Ultima opcion seleccionada: "<<Eleccion<<endl;
    }

    cout<<" Eliga la opcion deceada: ";
    cin>>Eleccion;
// linea de 42 a la 49 sacado de youtube min 1:28:25
// https://www.youtube.com/watch?v=8WxjOzIFK8o&list=PLZZf5oxDbpsDC2iySTPYKujpzZmzxiERb&index=5&ab_channel=C%C3%A1tedraTecnolog%C3%ADadeSistemas%2FInform%C3%A1ticaUNEDCR
    if(!cin.good()){
        cout<<"Solo debe poner numeros en el menu"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
       system("Pause");
       system("CLS");
    }

    switch(Eleccion)
    {
    case 1:{
            system("CLS");
        cout<<"BIENVENIDO  LA OPCION 1"<<endl;
        cout<<"Aqui se ingresaran los datos de la persona"<<endl;

        cout<<"\nPor favor digite su cedula (sin espacios): ";
        cin>>Cedula;

        //linea 64 a la 71 sacada de:
//https://stackoverflow.com/questions/32556114/cin-fail-while-loop-input-re-entry
  while (cin.fail()){
        cout<<"Solo debe poner numeros en la cedula"<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Digite su cedula sin espacios: ";
        cin>>Cedula;
    }

        cout<<"\nPor favor digite su nombre con sus dos apellidos: ";
        cin>>Nombre>>Primer_Apellido>>Segundo_Apellido;

        system("CLS");
        cout<<"DATOS RECOLECTADOS CORRECTAMENTE PRESIONE ENTER PARA VOLVER AL MENU PRINCIPAL"<<endl;
        system("Pause");
        break;
    }
    case 2:{
        system("CLS");
        cout<<"BIENVENIDO A LA OPCION 2"<<endl;
        cout<<"Aqui se ingresaran los datos fisicos de la persona"<<endl;

        cout<<"\nPor favor digite su talla en metros(M): ";
        cin>>Talla;

        cout<<"\nPor favor digite su peso en Kilogramos(KG): ";
        cin>>Peso;

        system("CLS");

        cout<<"DATOS RECOLECTADOS CORRECTAMENTE PRESIONE ENTER PARA VOLVER AL MENU PRINCIPAL"<<endl;
        system("Pause");
         break;
    }
    case 3:{
        system("CLS");
        //variables string con sus respectivos textos
        string Peso_Insuficiente="Tienes peso insuficiente";
        string Peso_Normal="Tienes peso normal";
        string Sobre_Peso="Tienes Sobrepeso";
        string Obesidad="Tienes Obesidad";

        cout<<"BIENVENIDO A LA OPCION 3"<<endl;
        cout<<"La cual se basa en calcular el IMC"<<endl;
        cout<<"Un segundo por favor"<<endl;

        //formula para sacar el IMC
        IMC=Peso/(Talla*Talla);

        cout<<"\nDATOS SACADOS CORRECTAMENTE PRESIONE ENTER PARA VOLVER AL MENU PRINCIPAL"<<endl;
        system("Pause");
        //Se pasa el texto de la variable string a la variable estado  dependiendo en que if entre
         if(IMC<18.5){
            Estado=Peso_Insuficiente;
         }
         else if(IMC>18.5 and IMC<24.9){
             Estado=Peso_Normal;
         }
         else if(IMC>25 and IMC<29.9){
            Estado=Sobre_Peso;
         }
         else{
            Estado=Obesidad;
         }

         break;
    }

    case 4:{
        system("CLS");
        //Reporte del Paciente
        cout<<"BIENVENIDO A LA OPCION 4"<<endl;
        cout<<"\nCONTROL DE PESO DEL PACIENTE"<<endl;
        cout<<"\n   Cedula del Paciente: "<<Cedula<<endl;
        cout<<"Nombre Completo: "<<Nombre<<" "<<Primer_Apellido<<" "<<Segundo_Apellido<<endl;

        cout<<"\nPeso"<<"     "<<"Talla"<<"     " <<"IMC"<<endl;

        //comando para poner dos digitos despues del punto
  //sacado de  https://www.delftstack.com/es/howto/cpp/how-to-use-setprecision-in-cpp/
        cout << fixed << setprecision(2) <<Peso << "   ";

        cout << fixed << setprecision(2) <<" "<<Talla<<"   ";

        cout << fixed << setprecision(2) <<" "<<IMC<<"   "<<"\n";

        cout<<"\nEstado del Paciente: ";
        cout<<Estado<<endl;
        system("\nPause");
         break;
    }
    case 5:{
        system("CLS");
        //despedida
        cout<<"ESCOGISTE LA OPCION 5"<<endl;
        cout<<"\nLa cual sale del progrma"<<endl;
        cout<<"Gracias por usar nuestro programa"<<endl;
        cout<<"BYE.....";
        system("Pause");
        //bandera activada
        Salir=true;
         break;
    }
    }
}
while(!Salir);
return 0;
}
