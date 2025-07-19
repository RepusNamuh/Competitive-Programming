#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

int main() {
    int N;
    std::string original, firstPart, secondPart, smallestString;;
    std::cin >> N;
    std::cin >> original;

    for (int i = 0; i < N; i++) {
        if (original[i] > original[i + 1]) {
            firstPart = original.substr(0, i);
            secondPart = original.substr(i + 1);
            smallestString = firstPart + secondPart;
            break;
        }
    }

    std::cout << smallestString << std::endl;
    return 0;
}