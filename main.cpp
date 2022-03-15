#include <iostream>
#include <map>
#include <vector>
#include "busquedas.hpp"

using namespace std;

int main()
{
    // Entrada de datos para saber el vertice origen y objetivo
    string origen = "";
    string objetivo = "";

    // Asignación de valores del grafo
    // Ciudad con sus adyacentes
    Grafo grafo;

    grafo["Arad"] = {"Zerind", "Sibiu", "Timisoara"};
    grafo["Timisoara"] = {"Arad", "Lugoj"};
    grafo["Sibiu"] = {"Arad", "Oradea", "Fagaras", "Rimnicu Vilcea"};
    grafo["Zerind"] = {"Arad", "Oradea"};
    grafo["Lugoj"] = {"Timisoara", "Mehadia"};
    grafo["Rimnicu Vilcea"] = {"Sibiu", "Pitesti", "Craiova"};
    grafo["Fagaras"] = {"Sibiu", "Bucarest"};
    grafo["Oradea"] = {"Zerind", "Sibiu"};
    grafo["Mehadia"] = {"Lugoj", "Dobreta"};
    grafo["Pitesti"] = {"Rimnicu Vilcea", "Bucarest", "Craiova"};
    grafo["Bucarest"] = {"Fagaras", "Urziceni", "Giurgiu", "Pitesti"};
    grafo["Dobreta"] = {"Mehadia", "Craiova"};
    grafo["Giurgiu"] = {"Bucarest"};
    grafo["Urziceni"] = {"Bucarest", "Vaslui", "Hirsova"};
    grafo["Craiova"] = {"Dobreta", "Rimnicu Vilcea", "Pitesti"};
    grafo["Hirsova"] = {"Urziceni", "Eforie"};
    grafo["Vaslui"] = {"Urziceni", "Iasi"};
    grafo["Eforie"] = {"Hirsova"};
    grafo["Iasi"] = {"Vaslui", "Neamt"};
    grafo["Neamt"] = {"Iasi"};

    // // Vertices pares con sus costes
    Mapa costos;

    costos[make_pair("Arad", "Timisoara")] = 118;
    costos[make_pair("Arad", "Sibiu")] = 140;
    costos[make_pair("Arad", "Zerind")] = 75;
    costos[make_pair("Timisoara", "Lugoj")] = 111;
    costos[make_pair("Sibiu", "Rimnicu Vilcea")] = 80;
    costos[make_pair("Sibiu", "Fagaras")] = 99;
    costos[make_pair("Sibiu", "Oradea")] = 151;
    costos[make_pair("Zerind", "Oradea")] = 71;
    costos[make_pair("Lugoj", "Mehadia")] = 70;
    costos[make_pair("Rimnicu Vilcea", "Craiova")] = 146;
    costos[make_pair("Rimnicu Vilcea", "Pitesti")] = 97;
    costos[make_pair("Fagaras", "Bucarest")] = 211;
    costos[make_pair("Mehadia", "Dobreta")] = 75;
    costos[make_pair("Pitesti", "Craiova")] = 138;
    costos[make_pair("Pitesti", "Bucarest")] = 101;
    costos[make_pair("Bucarest", "Giurgiu")] = 90;
    costos[make_pair("Bucarest", "Urziceni")] = 85;
    costos[make_pair("Dobreta", "Craiova")] = 120;
    costos[make_pair("Urziceni", "Hirsova")] = 98;
    costos[make_pair("Urziceni", "Vaslui")] = 142;
    costos[make_pair("Hirsova", "Eforie")] = 86;
    costos[make_pair("Vaslui", "Iasi")] = 92;
    costos[make_pair("Iasi", "Neamt")] = 87;

    cout << "\n> Ingresa el origen: ";
    getline(cin, origen);

    cout << "> Ingresa el objetivo: ";
    getline(cin, objetivo);

    //Verificación de la existencia del origen y destino
    if ((grafo.find(origen) != grafo.end()) && (grafo.find(objetivo) != grafo.end())) {
        // Función aplicada, su retorno se guarda en un vector
        vector<string> recorrido = busquedaProfundidad(grafo, origen, objetivo);

        // Impresión de la ruta obtenida
        cout << "\n\tLa ruta obtenida es:\n";
        for (size_t i = 0; i < recorrido.size(); i++)
        {
            cout << recorrido[i];
            if (i != (recorrido.size() - 1))
            {
                cout << " => ";
            }
        }
    }else{
        //Impresión de resultados inválidos
        if(grafo.find(origen) == grafo.end()){
            cout<<"\nNo existe el origen en el mapa"<<endl;
        }else{
            cout<<"\nNo existe el destino en el mapa"<<endl;
        }     
    }

    

    vector<string> objetivos;
    objetivos.push_back(objetivo);

    vector<int> costoUniforme = busquedaCostoUniforme(grafo, costos, origen, objetivos);

    cout << "\n\n\n\nEl costo uniforme es: " << costoUniforme[0];

    return 0;
}