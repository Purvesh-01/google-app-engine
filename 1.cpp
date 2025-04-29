#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS
void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &result)
{
    visited[node] = 1;
    result.push_back(node);

    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited, result);
        }
    }
}

// Function to perform BFS
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    queue<int> q;
    vector<int> result;

    visited[0] = 1;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (auto neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    return result;
}

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the result of BFS or DFS
void printResult(const vector<int> &result)
{
    for (int node : result)
    {
        cout << node << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    vector<int> adj[6]; // Graph with 6 vertices

    // Adding edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    // BFS traversal
    vector<int> bfsResult = bfsOfGraph(5, adj);
    cout << "BFS Traversal: ";
    printResult(bfsResult);

    // DFS traversal
    vector<int> visited(6, 0);
    vector<int> dfsResult;
    dfs(0, adj, visited, dfsResult);
    cout << "DFS Traversal: ";
    printResult(dfsResult);

    return 0;
}