#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Função BFS
void BFS(vector<vector<int>> &graph, int start)
{
    // Vetor para marcar os vértices visitados
    vector<bool> visited(graph.size(), false);

    // Fila para armazenar os vértices a serem visitados
    queue<int> q;

    // Marca o vértice inicial como visitado e o enfileira
    visited[start] = true;
    q.push(start);

    // Enquanto a fila não estiver vazia
    while (!q.empty())
    {
        // Dequeue a partir do início da fila
        int current = q.front();
        q.pop();

        // Para cada vértice adjacente ao vértice atual
        #pragma omp parallel for
        for (int i = 0; i < graph[current].size(); ++i)
        {
            int adjacent = graph[current][i];
            // Se o vértice adjacente ainda não foi visitado
            if (!visited[adjacent])
            {
                // Marca o vértice adjacente como visitado e o enfileira
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
}

int main(int argc, char *argv[]){
    if (argc != 2){
        std::cerr << "Usage: " << argv[0] << " <initial_vertices>\n";
        return 1;
    }

    // Número de vértices inicial
    int initial_vertices = atoi(argv[1]);
    // Incremento no número de vértices a cada iteração

    // Lista de adjacência para representar o grafo
    vector<vector<int>> graph(initial_vertices);

    // Adiciona arestas ao grafo (arestas bidirecionais em um grafo não dirigido)
    for (int j = 0; j < initial_vertices - 1; ++j)
    {
        graph[j].push_back(j + 1);
        graph[j + 1].push_back(j);
    }

    BFS(graph, 0);

    // Exibe o tempo de execução do BFS para o tamanho atual do grafo
    cout << "Number of vertices: " << initial_vertices << endl;

    return 0;
}
