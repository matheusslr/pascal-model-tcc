#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

void BFS(vector<vector<int>> &graph, int start)
{
    vector<bool> visited(graph.size(), false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        #pragma omp parallel for
        for (int i = 0; i < graph[current].size(); ++i)
        {
            int adjacent = graph[current][i];
            {
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

    int initial_vertices = atoi(argv[1]);

    vector<vector<int>> graph(initial_vertices);

    for (int j = 0; j < initial_vertices - 1; ++j)
    {
        graph[j].push_back(j + 1);
        graph[j + 1].push_back(j);
    }

    BFS(graph, 0);

    cout << "Number of vertices: " << initial_vertices << endl;

    return 0;
}
