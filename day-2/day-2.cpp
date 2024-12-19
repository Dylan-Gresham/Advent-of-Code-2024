#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> split(const std::string &in, char delimiter) {
    std::vector<int> tokens;
    std::string token;
    std::istringstream token_stream(in);

    while (std::getline(token_stream, token, delimiter)) {
        tokens.push_back(std::stoi(token));
    }

    return tokens;
}

void part_one(void) {
    std::ifstream in_file("input");
    std::string line;
    const char *delimiter = " ";

    int num_safe = 0;
    while (std::getline(in_file, line)) {
        std::vector<int> reports = split(line, ' ');
        bool decreasing = false, increasing = false;
        bool safe = true;
        for (int i = 1; i < reports.size(); i++) {
            if (!safe) {
                break;
            }

            int difference = std::abs(reports[i - 1] - reports[i]);

            if (!decreasing && !increasing) {
                if (reports[i - 1] > reports[i]) {
                    if (difference >= 1 && difference <= 3) {
                        decreasing = true;
                    } else {
                        safe = false;
                        break;
                    }
                } else if (reports[i - 1] < reports[i]) {
                    if (difference >= 1 && difference <= 3) {
                        increasing = true;
                    } else {
                        safe = false;
                        break;
                    }
                } else {
                    safe = false;
                    break;
                }
            } else if (decreasing) {
                if (reports[i - 1] <= reports[i] || difference < 1 || difference > 3) {
                    safe = false;
                    break;
                }
            } else {
                if (reports[i - 1] >= reports[i] || difference < 1 || difference > 3) {
                    safe = false;
                    break;
                }
            }
        }

        if (safe) {
            num_safe++;
        }
    }

    std::cout << "There are " << num_safe << " safe reports." << std::endl;
}

void part_two(void) {

}

int main(void) {
    part_one();
    // part_two();

    return 0;
}