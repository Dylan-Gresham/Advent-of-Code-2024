#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>

void part_one(void) {
    std::ifstream in_file("input");
    std::string line;
    std::regex mul_regex(R"(mul\((\d{1,3}),(\d{1,3})\))");
    std::smatch match;

    int total = 0;
    while (std::getline(in_file, line)) {
        std::string::const_iterator search_start(line.cbegin());

        while (std::regex_search(search_start, line.cend(), match, mul_regex)) {
            int num_one = std::stoi(match[1].str());
            int num_two = std::stoi(match[2].str());

            total += num_one * num_two;

            search_start = match.suffix().first;
        }
    }

    std::cout << "Total = " << total << std::endl;
}

void part_two(void) {

}

int main(void) {
    part_one();
    // part_two();

    return 0;
}