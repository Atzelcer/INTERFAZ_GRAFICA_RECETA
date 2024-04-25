#include "RECETAS_LAB05.h"
using namespace std;


Receta::Receta(int id, string nombre, Ingrediente* ingredientes, int num_ingredientes, int tiempo_preparacion, int tiempo_coccion, int porciones, string nivel_dificultad, string categoria, string origen, ValorNutricional valor_nutricional)
    : id(id), nombre(nombre), ingredientes(ingredientes), num_ingredientes(num_ingredientes), tiempo_preparacion(tiempo_preparacion), tiempo_coccion(tiempo_coccion), porciones(porciones), nivel_dificultad(nivel_dificultad), categoria(categoria), origen(origen), valor_nutricional(valor_nutricional), siguiente(nullptr) {}

ListaRecetas::ListaRecetas() : cabeza(nullptr) {}

void ListaRecetas::agregarReceta(Receta* nueva_receta) {
    if (!cabeza) {
        cabeza = nueva_receta;
    }
    else {
        Receta* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }
        temp->siguiente = nueva_receta;
    }
}

void ListaRecetas::imprimirRecetas() {
    Receta* temp = cabeza;
    cout << "|*|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|*|" << endl;

    while (temp) {
        cout << "ID ==>  " << temp->id << endl;
        cout << "Nombre ==>  " << temp->nombre << endl;
        cout << "Ingrediente : " << endl;
        for (int i = 0; i < temp->num_ingredientes; ++i) {
            cout << "  - " << temp->ingredientes[i].nombre << ": " << temp->ingredientes[i].cantidad << endl;
        }
        cout << "Tiempo de preparacion ==> " << temp->tiempo_preparacion << " minutos" << endl;
        cout << "Tiempo de coccion ==> " << temp->tiempo_coccion << " minutos" << endl;
        cout << "Porciones ==> " << temp->porciones << endl;
        cout << "Nivel de dificultad ==> " << temp->nivel_dificultad << endl;
        cout << "Categoria ==> " << temp->categoria << endl;
        cout << "Origen ==> " << temp->origen << endl;
        cout << endl;
        cout << "----Valor nutricional----" << endl;
        cout << "*  Calorias: " << temp->valor_nutricional.calorias << endl;
        cout << "*  Grasas: " << temp->valor_nutricional.grasas << "g" << endl;
        cout << "*  Proteinas: " << temp->valor_nutricional.proteinas << "g" << endl;
        cout << "*  Carbohidratos: " << temp->valor_nutricional.carbohidratos << "g" << endl;
        cout << "*  Otros: " << temp->valor_nutricional.otros << "g" << endl;
        cout << endl;
        temp = temp->siguiente;
        cout << "|*|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|*|" << endl;
    }
}


int main() {
    Ingrediente ingredientes_helado[] = { {"Leche", 3}, {"Azucar", 200}, {"Crema", 1} };
    Ingrediente ingredientes_albondigas[] = { {"Carne", 1}, {"Pan rallado", 2}, {"Huevo", 1} };

    Receta* helado = new Receta(1, "HELADO", ingredientes_helado, 3, 30, 0, 4, "Facil", "Postres", "Internacional", ValorNutricional{ 200, 8, 4, 25, 3 });
    Receta* albondigas = new Receta(2, "ALBONDIGAS", ingredientes_albondigas, 3, 45, 20, 6, "Media", "Platos Principales", "Nacional", ValorNutricional{ 350, 15, 20, 10, 2 });

    ListaRecetas listaRecetas;
    listaRecetas.agregarReceta(helado);
    listaRecetas.agregarReceta(albondigas);

    listaRecetas.imprimirRecetas();

    delete helado;
    delete albondigas;

    return 0;
}
