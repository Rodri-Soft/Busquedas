#ifndef BUSQUEDAS_H
#define BUSQUEDAS_H

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// Definición de nuestro propio tipo de dato (Grafo)
// Contenedor asociativo que almacenará las Ciudades con sus adyacentes
typedef map<string, vector<string>> Grafo;

typedef map<pair<string, string>, int> Mapa;

vector<string> busquedaProfundidad(const Grafo &grafo, const string &origen, const string &objetivo)
{
  // Pila que almacenará los vertices
  stack<string> pila;

  // Lista para guardar los vértices visitados
  vector<string> visitados;

  // Recorrido que regresará la función
  vector<string> recorrido;

  // Se agrega el vertice de origen a la pila y la lista de visitados pues es el actual
  visitados.push_back(origen);
  pila.push(origen);

  // Mientras la pila no se encuentre vacia
  while (!pila.empty())
  {
    // Guardar el vertice que se va a desechar de la pila al recorrido
    auto const &vertice = pila.top();

    // Adyacetes del vertince
    auto const &vecinos = grafo.at(vertice);
    bool esExistente = false;
    // Hacer
    do
    {
      // Si el número de vertices del recorrido es mayor o igual a 1, entonces
      if (recorrido.size() >= 1)
      {
        // Se recorren los vecinos del vertice que se encontraba en el tope de la pila
        for (int i = 0; i < vecinos.size(); i++)
        {
          auto const &vecino = vecinos[i];

          // Si un vecino se encuentra en la ultima posicion del recorrido
          if (vecino == recorrido.at(recorrido.size() - 1))
          {
            // Marcar como existente
            esExistente = true;
            break;
          }
        }

        if (esExistente == false)
        {
          // Se elimina el la ultima posicion del recorrido
          recorrido.erase(recorrido.end());
        }
      }
      // Marcar como existente
      else
      {
        esExistente = true;
      }
      // Mientras sea falso que no exista el vertice en el recorrido
    } while (esExistente == false);

    recorrido.push_back(vertice);
    // Desapilar un vértice de la pila
    pila.pop();
    // Si el vertice es igual al vertice objetivo se termina la función
    if (vertice == objetivo)
    {
      break;
    }

    // Adyacentes del vertice que se desapiló de la pila
    // El método at() retorno lo que hay en tal llave
    auto const &adyacentes = grafo.at(vertice);
    for (size_t i = 0; i < adyacentes.size(); i++)
    {
      // Se obtiene un solo elemento de asyacentes
      auto const &adyacente = adyacentes[i];
      // Se verifica que ese elemento no esté en la lista de visitados
      // find() recibe tres parametros:
      // El primer y segundo parametros es el rango de elementos a examinar, en este caso la lista de visitados
      // El tercer parametro es el valor con el que se compararan los elementos

      if (find(visitados.begin(), visitados.end(), adyacente) == visitados.end())
      {
        // Si no se encuentra el elemento se agrega la lista de visitados y a la pila
        visitados.push_back(adyacente);
        // La pila se empieza a llenar hasta que los vertices visitados ya no se van a agregar y esta se comience a vaciar
        pila.push(adyacente);
      }
    }
  }

  // Retorna el recorrido
  return recorrido;
}

vector<int> busquedaCostoUniforme(const Grafo &grafo, Mapa &costos, const string &origen, vector<string> &objetivos)
{
  int contador = 0;

  // Vector donde se almacenarán los costos, el costo menor se encontrará en la posicion 0 del vector
  vector<int> busquedaCostoUniforme;
  // Asignar el valor máximo del vector de costos
  for (size_t i = 0; i < objetivos.size(); i++)
  {
    busquedaCostoUniforme.push_back(INT_MAX);
  }

  // Vertice raíz
  auto const &vertice = origen;

  // Cola de prioridad
  priority_queue<pair<string, string>> frontera;
  // Agregar vertice raíz
  frontera.push(make_pair("", origen));

  // Mapa de los vertices visitados
  map<string, string> visitados;

  // Mientras la cola no este vacia
  while (frontera.size() > 0)
  {
    // Obtener el elemento de mayor prioridad de la cola
    pair<string, string> tope = frontera.top();

    // Sacar elemento de la cola
    frontera.pop();

    // Obtener el valor original
    tope.first *= -1;

    // Verificar que el vertice es parte del vector de objetivos
    if (find(objetivos.begin(), objetivos.end(), tope.second) != objetivos.end())
    {
      // ??????????????
      int posicion = find(objetivos.begin(), objetivos.end(), tope.second) - objetivos.begin();

      // Si un objetivo es alcanzado
      if (busquedaCostoUniforme[posicion] == INT_MAX)
      {
        contador++;
      }

      // Si el costo es menor
      if (busquedaCostoUniforme[posicion] > tope.first)
      {
        busquedaCostoUniforme[posicion] = tope.first;
      }

      // Sacar de la cola
      frontera.pop();

      // Si se alcanzan todos los objetivos
      if (contador == objetivos.size())
      {
        return busquedaCostoUniforme;
      }
    }
  }

  // Comprobar que los vertices no visitados son adyacentes al vertice actual

  if (visitados[tope.second] == "")
  {
    auto const &adyacentes = grafo.at(tope.second);
    for (size_t i = 0; i < adyacentes.size(); i++)
    {
      // El valor se multiplica por -1 para que la menor prioridad esté en la parte superior

      // frontera.push(make_pair((
      //   tope.first + costos[make_pair(tope.second,
      //   grafo)]) * -1,
      //   grafo));
    }

    // Marcar como visitado
    visitados[tope.second] = 1;
  }

  return busquedaCostoUniforme;
}

#endif