//
// Created by trist on 2022-12-05.
//

#include <iostream>
#include <vector>

int main()
{
    int M, N, K;
    std::cin >> M >> N >> K; // read the grid dimensions and the number of artist's choices

    // create an M-by-N grid with all cells initially set to black
    std::vector<std::vector<int>> grid(M, std::vector<int>(N, 0));

    // simulate the artist's choices
    int rows[M] = {}, cols[N] = {}; // keep track of the number of flipped rows and columns
    while (K-- > 0)
    {
        char choice;
        int index;
        std::cin >> choice >> index; // read the artist's choice

        if (choice == 'R')
        {
            rows[index - 1] ^= 1; // flip the chosen row
        }
        else if (choice == 'C')
        {
            cols[index - 1] ^= 1; // flip the chosen column
        }
    }

    // count the number of gold cells in the grid
    int goldCells = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // if the row and column of the cell have been flipped an odd number of times, the cell is gold
            if ((rows[i] + cols[j]) % 2 == 1)
            {
                goldCells++;
            }
        }
    }

    std::cout << goldCells << std::endl; // output the number of gold cells

    return 0;
}
