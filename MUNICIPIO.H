#ifndef MUNICIPIO_H_INCLUDED
#define MUNICIPIO_H_INCLUDED
class Municipio
{
 protected:
    int numero;
    char nombre[30];
    int cantidadHab;
    int seccion;
    bool estado;
 public:
        //SETS
    void setNumero(int n){if(n>0){numero=n;}}
    void setNombre(const char *nom){strcpy(nombre,nom);}
    void setCantHab(int hab){if(hab>0){cantidadHab=hab;}}
    void setSeccion(int sec){if(sec>0 && sec<=9){seccion=sec;}}
    void setEstado(bool e){estado=e;}
        //GETS
      int getNumero(){return numero;}
      char getNombre(){return *nombre;}
      int getCantHab(){return cantidadHab;}
      int getSeccion(){return seccion;}
      bool getEstado(){return estado;}
        //CONSTRUCTOR
      Municipio()
       {
           estado=false;
       }
        //METODOS
        void Cargar();
        void Mostrar();
};
void Municipio::Cargar()
{
    cout<<"NUMERO: ";
    cin>>numero;
    if(numero<1)
    {
        return;
    }
    cout<<"INGRESE EL NOMBRE: ";
    cargarCadena(nombre,29);
    cout<<"INGRESE LA CANTIDAD HABITANTES: ";
    cin>>cantidadHab;
    cout<<"INGRESE LA SECCION (1 a 9): ";
    cin>>seccion;
//    Municipio obj;
//    obj.setSeccion(seccion);
    if(seccion<=0||seccion>9)
    {
        cout<<"SECCION INVALIDA"<<endl;
        system("pause");
        return;
    }
    estado=true;
}
void Municipio::Mostrar()
{
   if(estado)
    {
        cout<<"NUMERO: "<<numero<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"CANTIDAD DE HABITANTES: "<<cantidadHab<<endl;
        cout<<"SECCION: "<<seccion<<endl;;
        estado=true;
        cout<<" "<<endl;
    }
}


#endif // MUNICIPIO_H_INCLUDED
