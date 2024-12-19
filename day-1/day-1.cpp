#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void) {
    /* Parse file into two lists */
    std::ifstream in_file("input");
    std::string str;

    std::vector<int> left_list, right_list;
    while (std::getline(in_file, str)) {
        int space_index = str.find(' ');
        std::string left_part = str.substr(0, space_index);
        std::string right_part = str.substr(space_index + 1, str.length());

        left_list.push_back(std::stoi(left_part));
        right_list.push_back(std::stoi(right_part));
    }

    /* Sort both lists in ascending order */
    std::sort(left_list.begin(), left_list.end());
    std::sort(right_list.begin(), right_list.end());
    
    /* Compute distances and print to stdout */
    int total_distance = 0;
    for (int i = 0; i < left_list.size(); i++) {
        total_distance += std::abs(left_list[i] - right_list[i]);
    }

    std::cout << "Total distance = " << total_distance << std::endl;

    return 0;
}