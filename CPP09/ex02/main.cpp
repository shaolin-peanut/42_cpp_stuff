//
// Created by Samuel Bars on 4/20/23.
//

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./PmergeMe \"numbers string\"" << std::endl;
        return 1;
    }
    else {
        PmergeMe pmergeMe(argv[1]);

        // sort list
        std::list<int>::iterator lbegin = pmergeMe.list_data.begin();
        std::list<int>::iterator lend = pmergeMe.list_data.end();
        double list_ret = pmergeMe.list_merge(pmergeMe.list_data, lbegin, lend);
        // sort deque
        std::deque<int>::iterator dbegin = pmergeMe.deque_data.begin();
        std::deque<int>::iterator dend = pmergeMe.deque_data.end();
        double deque_ret = pmergeMe.deque_merge(pmergeMe.deque_data, dbegin, dend);

        // check for sorting func. errors or non-equal results
        if (list_ret == -1 || deque_ret == -1 || !pmergeMe.are_results_equal()) {
            return 1; }

        // print "After: <sorted list>"
        std::cout << "After: "; PmergeMe::print_list(pmergeMe.list_data);

        std::cout << "List merge sort took: " << list_ret << " seconds" << std::endl;
        std::cout << "Deque merge sort took: " << deque_ret << " seconds" << std::endl;
        return 0;
    }
}
