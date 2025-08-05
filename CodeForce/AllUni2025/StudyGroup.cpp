#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <cfenv>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, i = 0;
    std::cin >> n;
    std::map<std::string, std::vector<std::string>> childs;
    std::map<std::string, std::vector<std::string>> parents;
    std::set<std::string> peoples;
    std::vector<std::string> queue;

    while (n--) {
        std::string person;
        int noFriends;
        std::cin >> person >> noFriends;
        peoples.insert(person);
        if (parents.count(person) == 0) {
          parents[person] = {};
        }

        while(noFriends--) {
            std::string temp;
            std::cin >> temp;
            if (std::find(parents[person].begin(), parents[person].end(), temp) == parents[person].end()) {
              childs[person].push_back(temp);
              parents[temp].push_back(person);
            } 
        }
    }
    int total = 0;
    for (const auto& people: peoples) {
      if (parents[people].empty()) {
        queue.push_back(people);
        total += 1;
      }
    }

    for (i = 2; i <= 7; i++) {
        std::vector<std::string> temp(queue.begin(), queue.end());
        queue.clear();
        
        for (const auto& parent: temp) {
          for (const auto& child: childs[parent]) {
            total += 1;
            queue.push_back(child);
          }
        }

      }   
    std::cout << total << std::endl;
  }