#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>
#include <vector>

static bool load_data(const char* filename, std::vector<std::vector<int>> & data_table) {
    if (!data_table.empty()) {
        data_table.clear();
    }

    data_table.resize(1);

    std::ifstream file(filename, std::ios::in);

    if (!file) {
        std::cout << "Cannot open data file." << std::endl;
        return false;
    }

    int input;

    for ( ;; ) {
        if (file.peek() == '\n') {
            data_table.resize(data_table.size()+1);
        }
        else if (!std::isspace(file.peek())) {
            if (!(file >> input)) {
                break;
            }

            data_table.back().push_back(input);
            continue;
        }
        file.get();
    }

    file.close();
    return true;
}

static constexpr int divround(int const & n, int const & d) {
    return ((n < 0) ^ (d < 0)) ? ((n - d / 2) / d) : ((n + d / 2) / d);
}

static int accumulate_average(std::vector<int> elements) {
    return divround(std::accumulate(std::begin(elements), std::end(elements), 0), elements.size());
}

int main(void) {
    std::vector<std::vector<int>> data;

    if (load_data("data.dat", data)) {
        for (auto temp : data) {
            //for (auto n : temp ) { std::cout << n << " "; }
            //std::cout << std::endl;
            std::cout << accumulate_average(temp) << " ";
        }

        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}
