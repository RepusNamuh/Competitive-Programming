#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int no_test;
    cin >> no_test;
    map<int, int> no_num;

    for (int i = 0; i < no_test; i++){
        no_num[0] = 3;
        no_num[1] = 1;
        no_num[2] = 2;
        no_num[3] = 1;
        no_num[5] = 1;
        int list_length;
        int num;
        bool all_zero = true;
        cin >> list_length;
        
        for (int j = 0; j < list_length; j++){
            cin >> num;
            
            if ((no_num.find(num) != no_num.end())){
                if (no_num[num] > 0){
                    no_num[num] -= 1;
                }
            }
            
            all_zero = true;
            for (const auto& pair: no_num){
                if (pair.second != 0){
                    all_zero = false;
                    break;
                }
            }
            if (all_zero){
                cout << j << endl;
            }
        }
        if (!all_zero){
            cout << 0 << endl;
        }
    }
}