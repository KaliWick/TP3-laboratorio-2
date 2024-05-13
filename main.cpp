#include <iostream>
#include <cstring>
using namespace std;
#include<ctime>
#include "Fecha.h"
#include "prototipos.h"
#include "EMPRESAS.H"
#include "MUNICIPIO.H"
#include "archivos_empresas.h"
#include "Archivos_municipio.h"
#include "funciones.h"
#include "menuEmpresas.h"
#include "menuMunicipio.h"
#include "menuReportes.h"
#include "menuConfig.h"

int main()
{
    while(true)
    {
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1- MENU EMPRESAS"<<endl;
        cout<<"2- MENU MUNICIPIOS"<<endl;
        cout<<"3- MENU DE REPORTES"<<endl;
        cout<<"4- CONFIGURACION"<<endl;
        cout<<"0- SALIR"<<endl;
        cout<<"---------------"<<endl;
        cout<<"INGRESE LA OPCION: "<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            menuEmpresas();
            break;
        case 2:
            menuMunicipio();
            break;
        case 3:
            menuReportes();
            break;
        case 4:
            menuConfig();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<<"OPCION INVALIDA"<<endl;
            system("pause");
            break;
        }
    }
    return 0;
}

