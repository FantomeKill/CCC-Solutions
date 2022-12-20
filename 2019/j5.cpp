//
// Created by trist on 2022-12-18.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

string getNewString(string original, int startIndex, int endIndex, string changeTo) {
    return original.substr(0, startIndex) + changeTo + original.substr(endIndex);
}

vector<string> getMoves(vector<string> ruleOne, vector<string> ruleTwo, vector<string> ruleThree, string current) {
    vector<string> moves;
    for (int i = 0; i < current.length(); i++) {
        try {
            if (current.find(ruleOne[0]) != string::npos) {
                string ruleOneSubString = current.substr(i, ruleOne[0].length());
                if (ruleOneSubString == ruleOne[0]) {
                    moves.push_back("1 " + to_string(i) + " " + to_string(i + ruleOne[0].length()) + " " + getNewString(current, i, i + ruleOne[0].length(), ruleOne[1]));
                }
            }
        } catch (out_of_range& oor) {}
        try {
            if (current.find(ruleTwo[0]) != string::npos) {
                string ruleTwoSubString = current.substr(i, ruleTwo[0].length());
                if (ruleTwoSubString == ruleTwo[0]) {
                    moves.push_back("2 " + to_string(i) + " " + to_string(i + ruleTwo[0].length()) + " " + getNewString(current, i, i + ruleTwo[0].length(), ruleTwo[1]));
                }
            }
        } catch (out_of_range& oor) {}
        try {
            if (current.find(ruleThree[0]) != string::npos) {
                string ruleThreeSubString = current.substr(i, ruleThree[0].length());
                if (ruleThreeSubString == ruleThree[0]) {
                    moves.push_back("3 " + to_string(i) + " " + to_string(i + ruleThree[0].length()) + " " + getNewString(current, i, i + ruleThree[0].length(), ruleThree[1]));
                }
            }
        } catch (out_of_range& oor) {}
    }
    return moves;
}

void findSolution(vector<string> ruleOne, vector<string> ruleTwo, vector<string> ruleThree,
                  string current, string desired, int movesTaken, int movesAllowed, vector<string>& solution, set<string>& visited) {
    if (movesTaken == movesAllowed) {
        if (current == desired) {
            for (string move: solution) {
                cout << move << endl;
            }
            exit(0);
        }
        return;
    }
    visited.insert(current + " " + to_string(movesTaken));
    vector<string> moves = getMoves(ruleOne, ruleTwo, ruleThree, current);
    if (moves.size() > 0) {
        for (string move: moves) {
            string ruleNum, start, end, newString;
            istringstream iss(move);
            iss >> ruleNum >> start >> end >> newString;
            if (visited.find(newString + " " + to_string(movesTaken + 1)) == visited.end()) {
                string addTo = ruleNum + " " + to_string(stoi(start) + 1) + " " + newString;
                solution[movesTaken] = addTo;
                findSolution(ruleOne, ruleTwo, ruleThree, newString, desired, movesTaken + 1, movesAllowed, solution, visited);
                solution[movesTaken] = "";
            }
        }
    }
}

int main() {
    vector<string> ruleOne(2);
    cin >> ruleOne[0] >> ruleOne[1];
    vector<string> ruleTwo(2);
    cin >> ruleTwo[0] >> ruleTwo[1];
    vector<string> ruleThree(2);
    cin >> ruleThree[0] >> ruleThree[1];
    int movesAllowed;
    string current, desired;
    cin >> movesAllowed >> current >> desired;
    vector<string> solution(movesAllowed);
    set<string> visited;
    findSolution(ruleOne, ruleTwo, ruleThree, current, desired, 0, movesAllowed, solution, visited);
    cout << "NO SOLUTION" << endl;
    return 0;
}