#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    list<int> A;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        A.push_back(value); // Use push_back to insert elements into the list
    }
    A.sort(); // Sort the list
    int mid = (N + K) / 2 - 1;
    auto it = A.begin();

    advance(it, mid); // Move to the 'mid' position
    int x = *it; // Access the value at 'mid'

    advance(it, 1); // Move to the next position

    if (x != *it) {
        cout << *it - 1 << endl;
    } else {
        cout << x - 1 << endl;
    }
}