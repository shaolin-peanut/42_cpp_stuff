//
// Created by Samuel Bars on 4/20/23.
//

#include "PmergeMe.hpp"

template <typename iter>
void insertion_sort(iter begin, iter end) {
    // iterate through list starting at second element
    for (iter it = begin; it != end; ++it) {
        int curr = *it;
        iter prev = it;
        --prev;
        while (prev != begin && *prev > curr) {
            // Swap the elements pointed to by prev and it
            std::swap(*prev, *it);

            // Decrement the iterators
            --prev;
            --it;
        }
        if (prev == begin && *prev > curr) {
            // Swap the elements pointed to by prev and it
            std::swap(*prev, *it);
        }
    }
}

template <typename source, typename Container>
void copy_container(source &src, Container &dest, typename Container::iterator start)
{
    typename Container::iterator dst = start;
    for (typename Container::iterator it = src.begin(); it != src.end(); ++it) {
        if (dst == dest.end()) {
            dest.insert(dst, *it);
        } else {
            *dst = *it;
        }
        dst++;
    }
}


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

PmergeMe::PmergeMe(std::string const &str)
: sublist_size(0)
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        if (is_numeric(token)) {
            input_data.push_back(std::atoi(token.c_str()));
        }
    }
    // print it
    std::cout << "Before: ";
    print_list(input_data);

    // copy input data to list and deque
    copy_container<std::list<int>, std::list<int> >(input_data, list_data, list_data.begin());
    copy_container<std::list<int>, std::deque<int> >(input_data, deque_data, deque_data.begin());

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

template <typename Container>
void PmergeMe::merge_step(Container &dest, typename Container::iterator start, typename Container::iterator middle, typename Container::iterator end) {
    Container temp;
    typename Container::iterator it1 = start;
    typename Container::iterator it2 = middle;

    while (it1 != middle || it2 != end) {
        if (it1 == middle) {
            temp.push_back(*it2);
            it2++;
        }
        else if (it2 == end || *it1 < *it2) {
            temp.push_back(*it1);
            it1++;
        }
        // sublist 2 item smaller than 1's, add sublist 2 item
        else {
            temp.push_back(*it2);
            it2++;
        }
    }
    // copy temp list into original list
    copy_container(temp, *dest, start);
}

template <typename Container>
void PmergeMe::merge_sort(typename Container &dest, typename Container::iterator start, typename Container::iterator end) {
    int size = std::distance(start, end);

    if (size <= sublist_size) { // perform insert-sort
        insertion_sort<typename Container::iterator>(start, end);
    }
    else { // recursive call to split function further
        typename Container::iterator middle = std::next(start, size / 2);
        list_merge(start, middle);
        list_merge(middle, end);
        merge_step(dest, start, middle, end);
    }

}

void PmergeMe::print_list(std::list<int> &l) {
    for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

