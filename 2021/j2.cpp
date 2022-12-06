//
// Created by trist on 2022-12-05.
//

#include <iostream>
#include <string>

int main()
{
    int N;
    std::cin >> N; // read the number of bids

    // keep track of the highest bid seen so far and the name of the person who placed it
    int highestBid = 0;
    std::string winner;

    for (int i = 0; i < N; ++i)
    {
        std::string name;
        int bid;
        std::cin >> name >> bid; // read the name and the bid

        // update the highest bid and the name of the person who placed it if necessary
        if (bid > highestBid)
        {
            highestBid = bid;
            winner = name;
        }
    }

    std::cout << winner << std::endl; // output the name of the winner

    return 0;
}
