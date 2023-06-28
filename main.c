#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int dimCol = 30;
int filas = 20;
///FUNCIONES:
int cargarArrayParalelo(int legajos[filas], char nombre[filas][dimCol], int anios[filas]);
int buscarLegajo(int legajo[filas],int validos, int dato);
void buscarDatoConlegajo(int legajo[filas], char nombre[filas][dimCol], int validos, int legajoPosicion);
int posicionMenor(int legajo[filas], char nombre[filas][dimCol], int anio[filas], int validos, int posInicio);
void ordenacionSeleccion(int legajo[filas], char nombre[filas][dimCol], int anio[filas], int validos);

int main()
{
    int legajos[filas];
    char nombres[filas][dimCol];
    int anios[filas];

///1-Crear una función que los cargue, hasta que el usuario lo decida.
int validos = cargarArrayParalelo(legajos, nombres, anios);

/**2-Crear una función que busque dentro del arreglo de legajos y
retorne la posición de un determinado valor. */
int legajoBuscar;
printf(" \n Ingrese el numero de su legajo: ");
fflush(stdin);
scanf("%i", &legajoBuscar);
buscarLegajo(legajos, validos, legajoBuscar);

int legajoPosicion = buscarLegajo(legajos, validos, legajoBuscar);
printf("\n La posicion del legajo es: %i ", legajoPosicion);
printf("\n");
printf("\n");

/**3-Hacer una función que reciba como parámetro todos los arreglos y
encuentre el nombre correspondiente a un determinado legajo y lo imprima
por pantalla. Se debe invocar la función 2.*/
buscarDatoConlegajo(legajos, nombres, validos, legajoPosicion);
printf("\n");
/**Hacer una función que reciba como parámetro todos los arreglos y
los ordene por nombre. (por el método de selección o inserción).*/
printf("\n Ordenando los legajos por nombre... \n");

}
///FUNC EJERCICIO 1: CARGAR ARREGLOS/MATRICES
int cargarArrayParalelo(int legajos[filas], char nombre[filas][dimCol], int anios[filas]){
    int i = 0;
    char eleccion = 's';

    while(i < filas && eleccion == 's'){
        printf("\n Ingrese el numero de legajo: ");
        fflush(stdin);
        scanf("%i", &legajos[i]);

        printf("\n Ingrese su nombre: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("\n Ingrese su edad: ");
        fflush(stdin);
        scanf("%i", &anios[i]);

        i++;

        printf("\n Ingrese 's' si desea continuar: ");
        fflush(stdin);
        scanf("%c", &eleccion);

    }
    return i;
}

///FUNC PARA BUSCAR UN NUMERO DE LEGAJO:
int buscarLegajo(int legajo[filas],int validos, int dato){
    int i;
    for(i = 0; i < validos; i++){
        if(legajo[i] == dato){
                return i;
        }
    }

}
///FUNC PARA MOSTRAR LOS DATOS CON RESPECTO A LEGAJOS:
void buscarDatoConlegajo(int legajo[filas], char nombre[filas][dimCol], int validos, int legajoPosicion){
    int i = 0;
    for( i = 0; i < validos; i++){
        if(legajo[i] == legajoPosicion){
            printf("\t |Legajo: %i |", legajo[i]);
            printf("\t |Nombre: %s |", nombre[i]);
            printf("\n");
        }
    }
}

///FUNC PARA ORDENAR LOS LEJAGOS EN BASE AL NOMBRE:
void ordenacionSeleccion(int legajo[filas], char nombre[filas][dimCol], int anio[filas], int validos){
    int posMenor;
    char aux;
    int i = 0;
    while(i < validos -1){
        posMenor = posicionMenor(legajo, nombre, anio, validos, i);
        aux = nombre[posMenor];
        nombre[posMenor] = nombre[i];
        nombre[i] = aux;
        i++;
    }
}
int posicionMenor(int legajo[filas],char nombre[filas][dimCol],int anio[filas],int validos,int posInicio){
    char menor = nombre[posInicio];
    int posMenor = posInicio;
    int i = posInicio + 1;
    while(i < validos){
        if(menor > nombre[i]){
            menor = nombre[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}
