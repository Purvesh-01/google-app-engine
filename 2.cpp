#include <bits/stdc++.h>
using namespace std;

struct Node
{
    vector<vector<int>> state;
    int g, h, f;
    int blankRow, blankCol;
};

// Goal state for 8-puzzle
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};

// Manhattan Distance heuristic
int calculateHeuristic(vector<vector<int>> &state)
{
    int h = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (state[i][j] != 0)
                for (int x = 0; x < 3; x++)
                    for (int y = 0; y < 3; y++)
                        if (state[i][j] == goal[x][y])
                            h += abs(i - x) + abs(j - y);
    return h;
}

// Generate possible moves
vector<Node> generateMoves(Node &node)
{
    vector<Node> moves;
    int row = node.blankRow, col = node.blankCol;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (auto dir : directions)
    {
        int newRow = row + dir.first, newCol = col + dir.second;

        if (newRow >= 0 && newRow < 3 && newCol >= 0 && newCol < 3)
        {
            Node newNode = node;
            swap(newNode.state[row][col], newNode.state[newRow][newCol]);
            newNode.blankRow = newRow;
            newNode.blankCol = newCol;
            newNode.g = node.g + 1;
            newNode.h = calculateHeuristic(newNode.state);
            newNode.f = newNode.g + newNode.h;
            moves.push_back(newNode);
        }
    }
    return moves;
}

// A* algorithm
void solvePuzzle(vector<vector<int>> &initialState)
{
    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq([](Node a, Node b)
                                                                      { return a.f > b.f; });

    Node startNode = {initialState, 0, calculateHeuristic(initialState), calculateHeuristic(initialState), 0, 0};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (initialState[i][j] == 0)
                startNode.blankRow = i, startNode.blankCol = j;

    pq.push(startNode);
    unordered_set<string> visited;

    while (!pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        if (current.state == goal)
        {
            cout << "Solution found in " << current.g << " moves!" << endl;
            return;
        }

        string stateStr;
        for (auto row : current.state)
            for (auto num : row)
                stateStr += to_string(num);

        if (visited.count(stateStr))
            continue;
        visited.insert(stateStr);

        for (auto nextMove : generateMoves(current))
            pq.push(nextMove);
    }

    cout << "No solution found!" << endl;
}

// Driver Code
int main()
{
    vector<vector<int>> initialState = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 5, 8}};

    solvePuzzle(initialState);
    return 0;
}