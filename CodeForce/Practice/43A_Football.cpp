#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>

#define dict std::map<std::string, int>
#define vecPair std::vector<std::pair<std::string, int>>


// I learned how to write mergesor in C++ by myself.
// Obviously, I still need to search for the syntax of vecPair 
// and dict creation, but the code is fully me.
// Not clean, but it definitely works.
vecPair merger(vecPair left, vecPair right) {
    vecPair merged;
    size_t total_size = left.size() + right.size();
    
    auto it_left = left.begin();
    auto it_right = right.begin();

    for (size_t i = 0; i < total_size; i++) {
        // I don't exactly know how it_left->"number" works, 
        // under the hood. But the syntax make sense in a way.
        if (it_left != left.end() && (it_right == right.end() || it_left->second >= it_right->second)) {
            merged.push_back(*it_left);
            ++it_left;
        } else {
            merged.push_back(*it_right);
            ++it_right;
        }
    }
    return merged;
}


vecPair mergesort(vecPair input_map) {
    size_t size = input_map.size();

    if (size <= 1) {
        return input_map;
    } else {
        int mid = size / 2;
        vecPair left, right;
        
        int i = 0;
        for (const auto& pair: input_map){ 
            if (i < mid) {
                left.push_back(pair);
            } else {
                right.push_back(pair);
            }
            i++;
        }
        left = mergesort(left);
        right = mergesort(right);

        return merger(left, right);

    }
}

int main() {
    int N;
    std::cin >> N;
    dict A;

    for (int i = 0; i < N; i++) {
        std::string value;
        std::cin >> value;
        if (A.find(value) == A.end()) {
            A[value] = 1; // Initialize count to 1 if not found
        } else {
            A[value]++; // Increment count if found
        }
    }
    vecPair sort;

    for (const auto& pair: A){
        sort.push_back(pair);
    }

    sort = mergesort(sort);
    std::cout << sort[0].first << std::endl;
    return 0;
}