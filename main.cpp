#include <iostream>
#include <ctime>

using namespace std;
/*
 * struct tm {
 * int tm_sec; // second of minutes from 8 to 61
 * int tm_min; // minutes of hour from 0 to 59
 * int tm_hour; // hours of day from 0 to 24
 * int tm_mday; // day of year from 1 to 31
 * int tm_mon; // month of year from  0 to 11
 * int tm_year; // year since 1900
 * int tm_wday; // days since sunday
 * int tm_yday; // day since January 1st
 * int tm_isdst, // hours of dayLight savings time
 * }
 */
string edadendiasmesesyanios(int dia, int mes, int anio, string nombre) {

    time_t now = time(0);
    tm *time = localtime(&now);

    int anioactual = 1900 + (time->tm_year), mesactual = (1 + time->tm_mon);
    int diaactual = time->tm_mday;
    int diaactuales = anioactual * 360 + mesactual * 30 + diaactual;
    int diapersona = anio * 360 + mes * 30 + dia;

    double difdias = diaactual - diapersona;

    div_t anios_vida = div(difdias, 360);
    div_t mes_vida = div(anios_vida.rem, 30);


    string aux = "Bienvenido, " + nombre + ", tu tienes " + to_string(anios_vida.quot) + " anios ";
    aux = aux + ", meses: " + to_string(mes_vida.quot);
    aux = aux + ", dias: " + to_string(mes_vida.rem);
    return aux;
}

int paso_por_valor(int a)
{
    a=a*5;
    cout<<"Dentro de la funcion,el valor de la variable a: "<<a;
    return 1;
}
int paso_por_referencia(int &a)
{
    a=a*5;
    cout<<endl<<"Por referencia el valor de la variable a: "<<a;
    return 1;
}
string saludos()
{
    return "Bienvenidos..";
}
string saludos(string nombre)
{
    return "Bienvenido " + nombre;
}
string saludos(string nombre, int edad)
{
    if(edad>=18)
        return "Bienvenido señor "+ nombre;
    else
            return"Bienvenido joven"+ nombre;
}


int main()
{
    string edad= edadendiasmesesyanios(11,11,2003,"Lisbeth");
    cout<<endl<<edad;
    cout<<endl<<edadendiasmesesyanios(19,04,2001,"Adrian");


    int a=2;
    paso_por_valor(a);
    cout<<endl<<"En el main,el valor de la variable a: "<<a;

    cout<<endl;
    paso_por_referencia(a);
    cout<<endl<<"En el main por referencia el valor de la variable a: "<<a;

    cout<<endl<<saludos("Juan");
    cout<<endl<<saludos();
    cout<<endl<<saludos("Jose");
    cout<<endl<<saludos("Pedro",20);

    return 0;
}
