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

bool is_safe(const std::vector<int> &reports, int skip_index = -1) {
    bool decreasing = false, increasing = false;

    for (int i = 1; i < reports.size(); i++) {
        if (i == skip_index) {
            continue;
        }

        int current = reports[i];
        int previous;
        if (i - 1 == skip_index) {
            if (i - 2 >= 0) {
                previous = reports[i - 2];
            } else {
                continue;
            }
        } else {
            previous = reports[i - 1];
        }

        int difference = std::abs(previous - current);
        if (difference < 1 || difference > 3) {
            return false;
        }

        if (!decreasing && !increasing) {
            if (previous > current) {
                decreasing = true;
            } else if (previous < current) {
                increasing = true;
            } else {
                return false;
            }
        } else if (decreasing) {
            if (previous <= current) {
                return false;
            }
        } else if (increasing) {
            if (previous >= current) {
                return false;
            }
        }
    }

    return true;
}

void part_two(void) {
    std::ifstream in_file("input");
    if (!in_file.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;

        return;
    }

    std::string line;

    int num_safe = 0;
    while (std::getline(in_file, line)) {
        std::vector<int> reports = split(line, ' ');
        
        if (is_safe(reports)) {
            num_safe++;
        } else {
            bool found_safe = false;
            for (int i = 0; i < reports.size(); i++) {
                if (is_safe(reports, i)) {
                    found_safe = true;
                    break;
                }
            }

            if (found_safe) {
                num_safe++;
            }
        }
    }

    std::cout << "There are " << num_safe << " safe reports with the Problem Dampener in effect." << std::endl;
}

int main(void) {
    part_one();
    part_two();

    return 0;
}