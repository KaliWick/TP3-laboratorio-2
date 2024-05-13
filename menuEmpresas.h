#ifndef MENUEMPRESAS_H_INCLUDED
#define MENUEMPRESAS_H_INCLUDED
void menuEmpresas(){
while(true)
    {
        int opc;
        system("cls");
        cout<<"MENU EMPRESAS"<<endl;
        cout<<"---------------"<<endl;
        cout<<"1- AGREGAR EMPRESA"<<endl;
        cout<<"2- LISTAR EMPRESA POR NUMERO"<<endl;
        cout<<"3- LISTAR TODAS LAS EMPRESAS"<<endl;
        cout<<"4- MODIFICAR FECHA DE CREACION"<<endl;
        cout<<"5- ELIMINAR REGISTRO"<<endl;
        cout<<"7- LIMPIAR EL ARCHIVO"<<endl;
        cout<<"0- VOLVER"<<endl;
        cout<<"---------------"<<endl;
        cout<<"INGRESE LA OPCION: "<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
        case 1:
            altaEmpresa();
            break;
        case 2:
            buscarRegistro();
            break;
        case 3:
            listarEmpresas();
            break;
        case 4:
            modificarRegistro();
            break;
        case 5:
            bajaLogica();
            break;
        case 7:
            limpiarEmpresa();
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

#endif // MENUEMPRESAS_H_INCLUDED
