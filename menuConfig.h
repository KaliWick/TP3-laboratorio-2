#ifndef MENUCONFIG_H_INCLUDED
#define MENUCONFIG_H_INCLUDED
void menuConfig()
{
while(true)
    {
        int opc;
        system("cls");
        cout<<"MENU DE CONFIGURACION"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1- BACKUP EMPRESAS"<<endl;
        cout<<"2- BACKUP MUNICIPIOS"<<endl;
        cout<<"3- RESTAURAR EMPRESAS"<<endl;
        cout<<"4- RESTAURAR MUNICIPIOS"<<endl;
        cout<<"5- ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"5- "<<endl;
        cout<<"0- VOLVER"<<endl;
        cout<<"---------------"<<endl;
        cout<<"INGRESE LA OPCION: "<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            backupEmpresas();
            break;
        case 2:
            break;
        case 3:
            restaurarEmpresas();
            break;
        case 4:
            break;
        case 5:
        establecerDatosInicio();
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
#endif // MENUCONFIG_H_INCLUDED
