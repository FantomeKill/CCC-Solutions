//
// Created by trist on 2022-12-03.
//

#include <iostream>
#include <queue>
#include <map>
#include <utility>
#include <vector>

// define a structure to represent a position on the chessboard
struct Position
{
    int x;
    int y;

    // define the less-than operator for the Position struct
    // so that we can use the map class to store and compare Position objects
    bool operator<(const Position& other) const
    {
        if (x != other.x)
        {
            return x < other.x;
        }

        return y < other.y;
    }
};

// check if a position is inside the chessboard
bool check(const Position& pos)
{
    if (pos.x >= 1 && pos.x <= 8 && pos.y >= 1 && pos.y <= 8)
    {
        return true;
    }

    return false;
}

// get the neighbors of a given position
std::vector<Position> getNeighbors(const Position& pos)
{
    std::vector<Position> neighbors;

    // possible moves of the knight in an eight by eight chessboard
    std::vector<std::pair<int, int>> moves = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

    // calculate the positions of the knight's neighbors
    for (const auto& move : moves)
    {
        Position neighbor = {pos.x + move.first, pos.y + move.second};
        if (check(neighbor))
        {
            neighbors.push_back(neighbor);
        }
    }

    return neighbors;
}

// find the minimum number of moves needed to reach the destination
// using a breadth-first search algorithm
int bfs(const Position& src, const Position& dest)
{
    // create a queue to hold the positions we need to explore
    std::queue<Position> q;

    // push the starting position onto the queue
    q.push(src);

    // create a map to keep track of which positions have been visited
    std::map<Position, bool> visited;

    // mark the starting position as visited
    visited[src] = true;

    // create a map to keep track of the number of moves needed
    // to reach each position on the chessboard
    std::map<Position, int> distance;

    // the starting position is 0 moves from itself
    distance[src] = 0;

    // keep looping until the queue is empty
    while (!q.empty())
    {
        // get the next position to explore from the queue
        Position curr = q.front();
        q.pop();

        // if we have reached the destination, return the number of moves needed
        if (curr.x == dest.x && curr.y == dest.y)
        {
            return distance[curr];
        }

        // get the neighbors of the current position
        std::vector<Position> neighbors = getNeighbors(curr);

        // loop through the neighbors
        for (const auto& neighbor : neighbors)
        {
            // if the neighbor has not been visited yet
            if (!visited[neighbor])
            {
                // mark the neighbor as visited
                visited[neighbor] = true;

                // set the number of moves needed to reach the neighbor
                distance[neighbor] = distance[curr] + 1;

                // push the neighbor onto the queue
                q.push(neighbor);
            }
        }
    }

    // if we reach this point, the destination is not reachable from the source
    return -1;
}

int main()
{
    // fast io
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // read the starting position
    Position src;
    std::cin >> src.x >> src.y;

    // read the destination position
    Position dest;
    std::cin >> dest.x >> dest.y;

    // find the minimum number of moves needed to reach the destination
    int moves = bfs(src, dest);

    // print the result
    std::cout << moves << std::endl;

    return 0;
}