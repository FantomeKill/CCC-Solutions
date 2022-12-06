//
// Created by trist on 2022-12-05.
//

#include <iostream>
#include <string>

// Decodes the given instruction and outputs the direction to turn and the number of steps to take.
// If the sum of the first two digits of the instruction is zero, the direction to turn is the same as the previous direction.
void decodeInstruction(const std::string& instruction, std::string& prevDirection)
{
    // compute the direction to turn
    int direction = (instruction[0] - '0') + (instruction[1] - '0');
    if (direction == 0)
    {
        // if the sum of the first two digits is zero, the direction to turn is the same as the previous direction
        std::cout << prevDirection;
    }
    else if (direction % 2 == 0)
    {
        // if the sum is even, the direction to turn is right
        std::cout << "right";
        prevDirection = "right";
    }
    else
    {
        // if the sum is odd, the direction to turn is left
        std::cout << "left";
        prevDirection = "left";
    }

    // compute the number of steps to take
    int steps = std::stoi(instruction.substr(2));
    std::cout << " " << steps << std::endl;
}

int main()
{
    // keep track of the previous direction
    std::string prevDirection = "null";

    // read the instructions
    std::string instruction;
    while (std::cin >> instruction)
    {
        // stop reading when we reach the end-of-input instruction (99999)
        if (instruction == "99999")
        {
            break;
        }

        // decode and output the instruction
        decodeInstruction(instruction, prevDirection);
    }

    return 0;
}
