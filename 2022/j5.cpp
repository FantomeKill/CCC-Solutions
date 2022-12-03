//
// Created by trist on 2022-10-26.
//

#include <iostream>
#include <algorithm>

using namespace std;

// check if the square pool of size 'size' at position (r,c) does not overlap with any trees
bool check(int N, bool** yard, int size, int r, int c)
{
    // check if the square pool of size 'size' at position (r,c) is entirely contained within the yard
    if (r+size-1 > N || c+size-1 > N)
    {
        // the square pool of size 'size' at position (r,c) is not entirely contained within the yard
        return false;
    }

    // check if the square pool of size 'size' at position (r,c) does not overlap with any trees
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // use the '[]' operator to access the element at index '(r+i-1)*N+c+j-1' of the array
            if (yard[r+i-1][c+j-1])
            {
                // the square pool of size 'size' at position (r,c) overlaps with a tree
                return false;
            }
        }
    }

    // the square pool of size 'size' at position (r,c) does not overlap with any trees
    return true;

}

int main(){
    // enable the standard input/output streams to be synchronized with the C++ streams
    ios::sync_with_stdio(false);

    // disable the synchronization of the C++ streams with the standard streams
    cin.tie(nullptr);
    cout.tie(nullptr);

    // read the input values for N and T
    int N, T;
    cin >> N >> T;

    // create a two-dimensional array of bits to represent the yard base on the input value for N
    bool **yard = new bool*[N];
    for (int i = 0; i < N; i++)
    {
        yard[i] = new bool[N];
    }

    // initialize the two-dimensional array of bits to represent the yard
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            yard[i][j] = false;
        }
    }

    // read the input values for the positions of the trees
    for (int i = 0; i < T; i++)
    {
        int r, c;
        cin >> r >> c;
        yard[r-1][c-1] = true;
    }

    // find the largest possible size M of the square pool using a binary search algorithm
    int M = 0;
    int lo = 1;
    int hi = N;
    while (lo <= hi)
    {
        int mid = (lo+hi) >> 1;

// check if there is a square pool of size 'mid' that does not contain any trees
        bool found = false;
        for (int r = 1; r <= N-mid+1 && !found; r++)
        {
            for (int c = 1; c <= N-mid+1 && !found; c++)
            {
                if (check(N, yard, mid, r, c))
                {
                    // we found a square pool of size 'mid' that does not contain any trees
                    M = mid;
                    found = true;
                }
            }
        }

        if (found)
        {
            // the square pool of size 'mid' does not contain any trees, so we can increase the size
            lo = mid+1;
        }
        else
        {
            // the square pool of size 'mid' contains at least one tree, so we must decrease the size
            hi = mid-1;
        }

    }

// output the size of the largest possible square pool
    cout << M << endl;

    return 0;
}