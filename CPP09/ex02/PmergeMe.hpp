//
// Created by Samuel Bars on 4/20/23.
//

#ifndef INC_42_CPP_STUFF_PMERGEME_H
#define INC_42_CPP_STUFF_PMERGEME_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <list>
#include <deque>
#include <valarray>
#include <ctime>
//#include <chrono>
//#include <algorithm>

template <typename source, typename Container>
void copy_container(source &src, Container &dest, typename Container::iterator start);

class PmergeMe {
public:
    PmergeMe(int argc, char **argv);
    ~PmergeMe();

    // sorts, prints results and returns time of execution
    template <typename Container>
    void merge_sort(Container &dest, typename Container::iterator start, typename Container::iterator end);
    template <typename Container>
    void merge_step(Container &dest, typename Container::iterator start, typename Container::iterator middle, typename Container::iterator end);

    // print time of execution + size of list
    static void print_list(std::list<int> &list);
    //std::ostream &operator<<(std::ostream &os, PmergeMe const &pmergeMe);
    bool are_results_equal();

    std::list<int> &get_list_data();
    std::deque<int> &get_deque_data();
private:
    PmergeMe();
    PmergeMe &operator=(PmergeMe const &copy);
    PmergeMe(PmergeMe const &copy);
    // sorted data

    std::list<int> input_data;

    std::list<int> list_data;
    std::deque<int> deque_data;

    int             sublist_size;
};

#include "PmergeMe.tpp"


#endif //INC_42_CPP_STUFF_PMERGEME_H
