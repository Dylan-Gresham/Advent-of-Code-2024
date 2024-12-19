#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

std::vector<int> left_list, right_list;
std::map<int, int> counts;

void parse_input(void) {
     /* Parse file into two lists */
    std::ifstream in_file("input");
    std::string str;
    
    while (std::getline(in_file, str)) {
        int space_index = str.find(' ');
        int left_part = std::stoi(str.substr(0, space_index));
        int right_part = std::stoi(str.substr(space_index + 1, str.length()));

        left_list.push_back(left_part);
        right_list.push_back(right_part);

        counts[right_part] += 1; 
    }
}

void part_one(void) {
     /* Sort both lists in ascending order */
    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());
    
    /* Compute distances and print to stdout */
    int total_distance = 0;
    for (int i = 0; i < left_list.size(); i++) {
        total_distance += std::abs(left_list[i] - right_list[i]);
    }

    std::cout << "Total distance = " << total_distance << std::endl;
}

void part_two(void) {
    int similarity_score = 0;

    for (int i = 0; i < left_list.size(); i++) {
        similarity_score += left_list[i] * counts[left_list[i]];
    }

    std::cout << "Similarity score = " << similarity_score << std::endl;
}

int main(void) {
    parse_input();

    part_one();
    part_two();

    return 0;
}