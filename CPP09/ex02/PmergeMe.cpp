//
// Created by Samuel Bars on 4/20/23.
//

#include "PmergeMe.hpp"

// can be useful, include if insertion sort doesn't work
//if (prev == begin && *prev > curr) {
//            std::iter_swap(prev, std::next(prev));
//        }

bool is_numeric(const std::string &str) {
    for (int i = 0; i < (int) str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv)
: sublist_size(0)
{
	for (int i = 1; i < argc; ++i) {
		std::string token(argv[i]);
		if (is_numeric(token) && token > "0") {
			input_data.push_back(std::atoi(token.c_str()));
		}
		else {
			std::cout << "Please enter only positive integers" << std::endl;
			throw std::invalid_argument("Usage: ./PmergeMe 10 9 8 7 6 5 4 3 2 1");
		}
	}
	if (input_data.size() == 0) {
		std::cout << "Please enter at least one number" << std::endl;
		throw std::invalid_argument("Usage: ./PmergeMe 10 9 8 7 6 5 4 3 2 1");
	}
	// print it
	std::cout << "Before: ";
	print_list(input_data);

	// copy input data to list and deque
	for (std::list<int>::iterator it = input_data.begin(); it != input_data.end(); ++it) {
		list_data.push_back(*it);
		deque_data.push_back(*it);
	}

	// init sublist size, first number is max, second is min
	sublist_size = std::max(std::min(static_cast<int>(std::sqrt(input_data.size())), 60), 5);

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

void PmergeMe::print_list(std::list<int> &l) {
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::list<int> &PmergeMe::get_list_data() {
    return list_data;
}

std::deque<int> &PmergeMe::get_deque_data() {
    return deque_data;
}

