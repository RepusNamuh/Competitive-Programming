#include <iostream>
#include <bits/stdc++.h>
#include <math.h>   
#define vecPair std::vector<std::pair<int, int>>

// The merger sort algorithm work very slow compare to the built in one.
// Still good to know that I can still write my own sort function.
// Albeit way worse than stock.
vecPair merger(vecPair left, vecPair right) {
    vecPair merged;
    size_t total_size = left.size() + right.size();
    
    auto it_left = left.begin();
    auto it_right = right.begin();

    for (size_t i = 0; i < total_size; i++) {
        // Check if left iterator is valid
        if (it_left != left.end() && (it_right == right.end() ||
                                (it_left->first <= it_right->first))) {
            merged.push_back(*it_left);
            ++it_left;
        } else {
            merged.push_back(*it_right);
            ++it_right;
        }
    }
    return merged;
}


vecPair mergesort(vecPair unsorted) {
    size_t size = unsorted.size();

    if (size <= 1) {
        return unsorted;
    } else {
        int mid = size / 2;
        vecPair left, right;
        
        int i = 0;
        for (const auto& pair: unsorted){ 
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
    // Fast I/O optimization
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T, N;
    std::cin >> T;
    int x, y;
    for (int i = 0; i < T; i++) {
        vecPair xsorted, ysorted;
        std::cin >> N;
        for (int j = 0; j < N; j++) {
            std::cin >> x >> y;
            xsorted.push_back({x, j});
            ysorted.push_back({y, j});
        }
        sort(xsorted.begin(), xsorted.end());
        sort(ysorted.begin(), ysorted.end());

        std::vector<int> xSortedOrder(N), ySortedOrder(N);
        for (int j = 0; j < N; j++) {
            xSortedOrder[xsorted[j].second] = j;
            ySortedOrder[ysorted[j].second] = j;
        }

        std::vector<int> first, second, third, fourth;
        for (int j = 0; j < N; j++) {
            if (xSortedOrder[j] < (N / 2) && ySortedOrder[j] < (N / 2)) {
                first.push_back(j + 1);
            } else if (xSortedOrder[j] >= (N / 2) && ySortedOrder[j] < (N / 2)) {
                second.push_back(j + 1);
            } else if (xSortedOrder[j] >= (N / 2) && ySortedOrder[j] >= (N / 2)) {
                third.push_back(j + 1);
            } else {
                fourth.push_back(j + 1);
            }
        }

        for (int j = 0; j < first.size(); j++) {
            std::cout << first[j] << " " << third[j] << "\n";
        }
        for (int j = 0; j < second.size(); j++) {
            std::cout << second[j] << " " << fourth[j] << "\n";
        }
    }
}