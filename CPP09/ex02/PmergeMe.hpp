//
// Created by Samuel Bars on 4/20/23.
//

#ifndef INC_42_CPP_STUFF_PMERGEME_H
#define INC_42_CPP_STUFF_PMERGEME_H

#include <iostream>
#include <sstream>
#include <ctype.h>
#include <list>
#include <deque>


class PmergeMe {
public:
    PmergeMe(std::string const &str);
    ~PmergeMe();

    // sorts, prints results and returns time of execution
    double list_merge();
    double deque_merge();
    // print time of execution + size of list
    void print_list();
    //std::ostream &operator<<(std::ostream &os, PmergeMe const &pmergeMe);
private:
    PmergeMe();
    PmergeMe &operator=(PmergeMe const &copy);
    PmergeMe(PmergeMe const &copy);


    std::list<int> input_data;
    std::list<int> list_data;
    std::deque<int> deque_data;
};


#endif //INC_42_CPP_STUFF_PMERGEME_H
