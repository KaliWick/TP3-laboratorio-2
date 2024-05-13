#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
void menuReportes()
{
while(true)
    {
        int opc;
        system("cls");
        cout<<"MENU DE REPORTES"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1- INGRESAR CATEGORIA Y BUSCAR EMPRESA"<<endl;
        cout<<"2- EMPRESAS CON MAS DE 50 EMPLEADOS"<<endl;
        cout<<"3- CANT DE MUNICIPIOS SIN EMPRESAS"<<endl;
        cout<<"4- CANT MUNICIPIOS CON MAS DE 5 EMPRESAS"<<endl;
        cout<<"5- CATEGORIA CON MAS EMPRESAS"<<endl;
        cout<<"0- VOLVER"<<endl;
        cout<<"---------------"<<endl;
        cout<<"INGRESE LA OPCION: "<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            reporte1();
            break;
        case 2:
            reporte2();
            break;
        case 3:
            reporte3();
            break;
        case 4:
            reporte4();
            break;
        case 5:
            reporte5();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"OPCION INVALIDA"<<endl;
        }
        system("pause");
    }
}

#endif // MENUREPORTES_H_INCLUDED
