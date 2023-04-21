//
// Created by Samuel Bars on 4/20/23.
//

#include <valarray>
#include "PmergeMe.hpp"

template <typename iter>
void insertion_sort(iter begin, iter end) {
    // iterate through list starting at second element
    for (iter it = std::next(begin); it != end; it++) {
        int curr = *it;
        iter prev = std::prev(it);
        while (prev != begin && *prev > curr) {
            std::iter_swap(prev, std::next(prev));
            prev--;
        }
        // can be useful, include if insertion sort doesn't work
        //if (prev == begin && *prev > curr) {
        //            std::iter_swap(prev, std::next(prev));
        //        }
        *prev = curr;
    }
}

bool is_numeric(const std::string &str) {
    for (int i = 0; i < (int) str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::string const &str)
: sublist_size(0)
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        if (is_numeric(token)) {
            input_data.push_back(std::stoi(token));
        }
    }
    // print it
    std::cout << "Before: ";
    print_list(input_data);

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

/* PSEUDOCODE STRUCTURE FOR RECURSIVE MERGE
function merge_insert_sort(container, begin, end)
    size = distance between begin and end

    if size <= target_sublist_size
        perform insertion_sort on the portion [begin, end)
    else
        middle = iterator pointing to the middle of the portion [begin, end)
        merge_insert_sort(container, begin, middle)
        merge_insert_sort(container, middle, end)
        merge the sorted halves [begin, middle) and [middle, end)
    end if
end function
*/
void
PmergeMe::list_merge(std::list<int> &list, std::list<int>::iterator start, std::list<int>::iterator end) {
    int size = std::distance(start, end);

    if (size <= sublist_size) { // perform insert-sort
        insertion_sort<std::list<int>::iterator>(start, end);
    }
    else { // recursive call to split function further

    }
    return 1; // update this with real times
}

void PmergeMe::deque_merge(std::deque<int> &deque, std::deque<int>::iterator start, std::deque<int>::iterator end) {
    return 1; // update this with real times
}

void PmergeMe::print_list(std::list<int> &l) {
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

