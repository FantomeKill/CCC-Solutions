//
// Created by trist on 2022-12-03.
//

#include <iostream>

int main() {
    // Read the number of regular boxes from the input
    int regular_boxes;
    std::cin >> regular_boxes;

    // Read the number of small boxes from the input
    int small_boxes;
    std::cin >> small_boxes;

    // Calculate the total number of cupcakes in regular and small boxes
    int total_cupcakes = regular_boxes * 8 + small_boxes * 3;

    // Calculate the number of cupcakes that will be left over
    int leftover_cupcakes = total_cupcakes - 28;

    // Print the result
    std::cout << leftover_cupcakes << std::endl;

    return 0;
}
