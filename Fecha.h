#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
    private:
    int dia,mes,anio;
    public:
    //SETS:
    void setDia(int d){
        if(d>0 && d<=31){
         dia=d;
        }
    }
    void setMes(int m){
        if(m>0 && m<=12){
        mes=m;
        }
    }
    void setAnio(int a){
        if(a>=1900){
        anio=a;
    }
    }
    //GETS:
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    Fecha()
    {
    time_t t = time(0);
    tm* now = localtime(&t);
    dia=now->tm_mday;
    mes=now->tm_mon+1;
    anio=now->tm_year+1900;
    }
    bool cargar()
    {
        cout<<"FECHA DE CREACION"<<endl;
        cout<<"INGRESE EL DIA: ";
        cin>>dia;
        if(dia<=0||dia>31)
        {
            cout<<"DIA INVALIDO"<<endl;
            system("pause");
            system("cls");
            return false;
        }
        cout<<"INGRESE EL MES: ";
        cin>>mes;
        if(mes<=0||mes>12)
        {
            cout<<"MES INVALIDO"<<endl;
            system("pause");
            system("cls");
            return false;
        }
        cout<<"INGRESE EL ANIO: ";
        cin>>anio;
        if(anio<1900)
        {
            cout<<"ANIO INVALIDO"<<endl;
            system("pause");
            system("cls");
            return false;
        }
        return true;
    }
    void mostrar()
    {
    cout<<"Fecha de creacion: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
};


#endif // FECHA_H_INCLUDED
