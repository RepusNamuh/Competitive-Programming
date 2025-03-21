#include <stdio.h>
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    int length;
    ofstream cout("output.txt");
    cout.precision(10);
    cin >> length;
    for(int i = 1; i <= length; i++) {
        long double N, P;
        cin >> N >> P;
        //
        long double Prob;
        Prob = P * (pow((100.0/P), 1.0/N) - 1.0);
        //
        cout << "Case #" << i << ": " << Prob << endl;
    }
}