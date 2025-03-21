#include <stdio.h>
#include <iostream>
#include <numeric>
#include <list>
using namespace std;

int main(){
    int length;
    cin >> length;
    list<int> A;
    for(int i = 1; i <= length; i++){
        int N, Q, even = 0, odd = 0, sum = 0;
        cin >> N >> Q;
        // Getting total number of even and odd numbers
        for(int j = 0; j < N; j++){
            int temp;;
            cin >> temp;
            if(temp % 2 == 0){
                even += 1;
            }else{
                odd += 1;
            }
            sum += temp;
            A.push_back(temp);
        }
        cout << even << endl;
        cout << odd << endl;
        for (int val : A) {
            cout << val << " ";
        }
        cout << endl;
        // Calculating Total Sum
        // for (int j = 0; j < Q; j++){
        //     int x, y;
        //     cin >> x >> y;
        //     if (x == 0){
        //         sum += even * y;
        //     }
        //     else{
        //         sum += odd * y;
        //     }
        //     if (y % 2 != 0){
        //         if (x == 0){
        //             odd += even;
        //             even = 0;
        //         }
        //         else{
        //             even += odd;
        //             odd = 0;
        //         }
        //     }
        //     cout << sum <<endl;
        // }

    }
    return 0;
}