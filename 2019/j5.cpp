//
// Created by trist on 2022-12-18.
//

#include <iostream>
#include <string>

std::string rules[3];

std::string applyRule(const std::string& current, int ruleNumber, int startPos) {
    std::string original, replacement;
    std::sscanf(rules[ruleNumber - 1].c_str(), "%s %s", original.c_str(), replacement.c_str());
    std::string result = current;
    result.replace(startPos - 1, original.size(), replacement);
    return result;
}

void solve(std::string now, int remain, std::string end, int rule, int startPos) {
    if (now == end) {
        std::cout << rule << " " << startPos << " " << now << std::endl;
        return;
    }
    if (remain == 0) {
        return;
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= now.length(); j++) {
            std::string res = applyRule(now, i, j);
            solve(res, remain - 1, end, i, j);
        }
    }
}

int main() {
    for (int i = 0; i < 3; ++i) {
        std::cin >> rules[i];
    }
    std::string initial;
    int steps;
    std::string final;
    std::cin >> steps >> initial >> final;
    solve(initial, steps, final, 0, 0);
    return 0;
}