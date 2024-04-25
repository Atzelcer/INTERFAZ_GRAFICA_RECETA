// Recetas.h
#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Ingrediente {
    string nombre;
    int cantidad;
};

struct ValorNutricional {
    int calorias;
    int grasas;
    int proteinas;
    int carbohidratos;
    int otros;
};

struct Receta {
    int id;
    string nombre;
    Ingrediente* ingredientes;
    int num_ingredientes;
    int tiempo_preparacion;
    int tiempo_coccion;
    int porciones;
    string nivel_dificultad;
    string categoria;
    string origen;
    ValorNutricional valor_nutricional;
    Receta* siguiente;

    Receta(int id, string nombre, Ingrediente* ingredientes, int num_ingredientes, int tiempo_preparacion, int tiempo_coccion, int porciones, string nivel_dificultad, string categoria, string origen, ValorNutricional valor_nutricional);
};

class ListaRecetas {
private:
    Receta* cabeza;

public:
    ListaRecetas();
    void agregarReceta(Receta* nueva_receta);
    void imprimirRecetas();
};
