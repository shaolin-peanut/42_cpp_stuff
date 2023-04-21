//
// Created by Samuel Bars on 4/20/23.
//

#ifndef INC_42_CPP_STUFF_PMERGEME_H
#define INC_42_CPP_STUFF_PMERGEME_H

#include <iostream>
#include <sstream>
#include <cctype>
#include <list>
#include <deque>


class PmergeMe {
public:
    PmergeMe(std::string const &str);
    ~PmergeMe();

    // sorts, prints results and returns time of execution
    void list_merge(std::list<int> &list, std::list<int>::iterator start, std::list<int>::iterator end);
    void deque_merge(std::deque<int> &deque, std::deque<int>::iterator start, std::deque<int>::iterator end);
    // print time of execution + size of list
    static void print_list(std::list<int> &list);
    //std::ostream &operator<<(std::ostream &os, PmergeMe const &pmergeMe);
    bool are_results_equal();

    // sorted data
    std::list<int> list_data;
    std::deque<int> deque_data;
private:
    PmergeMe();
    PmergeMe &operator=(PmergeMe const &copy);
    PmergeMe(PmergeMe const &copy);


    std::list<int> input_data;
    int             sublist_size;
};


#endif //INC_42_CPP_STUFF_PMERGEME_H
