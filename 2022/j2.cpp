//
// Created by trist on 2022-12-03.
//

#include <iostream>
#include <vector>

int main() {
    // Read the number of players from the input
    int N;
    std::cin >> N;

    // Initialize a vector of pairs to store the points and fouls of each player
    std::vector<std::pair<int, int>> player(N);

    // Loop over the number of players
    for (int i = 0; i < N; ++i) {
        // Read the number of points scored by the player
        int points;
        std::cin >> points;

        // Read the number of fouls committed by the player
        int fouls;
        std::cin >> fouls;

        // Store the points and fouls of the player in the vector
        player[i].first = points;
        player[i].second = fouls;
    }

    // Initialize a flag that indicates if the team is a gold team
    std::string all = "+";

    // Initialize a counter for the number of players with a star rating greater than 40
    int count = 0;

    // Loop over the vector of players
    for (int i = 0; i < player.size(); ++i) {
        // Calculate the player's star rating
        int rating = (player[i].first * 5) - (player[i].second * 3);

        // Check if the player has a star rating greater than 40
        if (rating > 40) {
            // Increment the counter
            count++;
        } else {
            // Set the gold team flag to false
            all = "";
        }
    }

    // Print the result
    std::cout << count << all << std::endl;

    return 0;
}