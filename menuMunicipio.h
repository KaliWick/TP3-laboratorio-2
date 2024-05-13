#ifndef MENUMUNICIPIO_H_INCLUDED
#define MENUMUNICIPIO_H_INCLUDED
void menuMunicipio()
{

    while(true)
    {
       int opc;
       system("cls");
       cout<<"MENU MUNICIPIOS"<<endl;
       cout<<"----------------------------------------------"<<endl;
       cout<<"1- AGREGAR MUNICIPIOS"<<endl;
       cout<<"2- LISTAR MUNICIPIO POR NUMERO"<<endl;
       cout<<"3- LISTAR TODOS LOS MUNICIPIOS"<<endl;
       cout<<"4- MODIFICAR CANT HABITANTES DE UN MUNICIPIO"<<endl;
       cout<<"5- ELIMINAR MUNICIPIO"<<endl;
       cout<<"6- LIMPIAR ARCHIVO"<<endl;
       cout<<"0- VOLVER"<<endl;
       cout<<"----------------------------------------------"<<endl;
       cout<<"INGRESE LA OPCION: "<<endl;
       cin>>opc;
       system("cls");

       switch(opc)
       {
        case 1:
            cargarMunicipio();
            break;
        case 2:
            buscarMunicipio();
            break;
        case 3:
            listarMunicipio();
            break;
        case 4:
             habMunicipio();
            break;
        case 5:
            bajaMunicipio();
            break;
        case 6:
            limpiarMunicipio();
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


#endif // MENUMUNICIPIO_H_INCLUDED
