#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Aresta {
    int origem, destino, peso;
};

class Grafo {
public:
    int numVertices;
    vector<Aresta> arestas;

    Grafo(int V) : numVertices(V) {}

    void adicionarAresta(int origem, int destino, int peso) {
        Aresta aresta = {origem, destino, peso};
        arestas.push_back(aresta);
    }

    int encontrar(int subsets[], int i) {
        if (subsets[i] == -1)
            return i;
        return encontrar(subsets, subsets[i]);
    }

    void unir(int subsets[], int x, int y) {
        int raiz_x = encontrar(subsets, x);
        int raiz_y = encontrar(subsets, y);
        subsets[raiz_x] = raiz_y;
    }

    void kruskal() {
        vector<Aresta> arvore;
        int numArestas = arestas.size();
        sort(arestas.begin(), arestas.end(), [](const Aresta &a, const Aresta &b) {
            return a.peso < b.peso;
        });

        int *subsets = new int[numVertices];
        for (int i = 0; i < numVertices; i++) {
            subsets[i] = -1;
        }

        for (int i = 0; i < numArestas; i++) {
            int raiz_origem = encontrar(subsets, arestas[i].origem);
            int raiz_destino = encontrar(subsets, arestas[i].destino);

            if (raiz_origem != raiz_destino) {
                arvore.push_back(arestas[i]);
                unir(subsets, raiz_origem, raiz_destino);
            }
        }

        cout << "Arvore Geradora Minima:" << endl;
        for (const Aresta &aresta : arvore) {
            cout << aresta.origem << " - " << aresta.destino << " Peso: " << aresta.peso << endl;
        }
    }
};

int main() {
    int numVertices, numArestas;
    cout << "Informe o numero de vertices e arestas: ";
    cin >> numVertices >> numArestas;

    Grafo grafo(numVertices);

    for (int i = 0; i < numArestas; i++) {
        int origem, destino, peso;
        cout << "Informe a origem, destino e peso da aresta " << i + 1 << ": ";
        cin >> origem >> destino >> peso;
        grafo.adicionarAresta(origem, destino, peso);
    }

    grafo.kruskal();

    return 0;
}
