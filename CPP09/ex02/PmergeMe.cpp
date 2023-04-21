//
// Created by Samuel Bars on 4/20/23.
//

#include "PmergeMe.hpp"

bool is_numeric(const std::string &str) {
    for (int i = 0; i < (int) str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string const &str) {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        if (is_numeric(token)) {
            input_data.push_back(std::stoi(token));
        }
    }
    std::cout << "Before: ";
    print_list(input_data);
}

PmergeMe::~PmergeMe() {
    input_data.clear();
    list_data.clear();
    deque_data.clear();
}

bool PmergeMe::are_results_equal() {
    if (list_data.size() != deque_data.size())
        return false;
    else {
        std::list<int>::iterator list_it = list_data.begin();
        std::deque<int>::iterator deque_it = deque_data.begin();
        while (list_it != list_data.end()) {
            if (*list_it != *deque_it)
                return false;
            list_it++;
            deque_it++;
        }
        return true;
    }
}

double PmergeMe::list_merge() {
    // do a merge-insertion sort on the list data structure
    return 0;
}

double PmergeMe::deque_merge() {
    return 0;
}

void PmergeMe::print_list(std::list<int> &l) {
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

