//
// Created by Samuel Bars on 4/20/23.
//

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: ./pmerge \"numbers string\"" << std::endl;
        return 1;
    }
    else {
        try {
            PmergeMe pmergeMe(argv[1]);

            // sort list
            std::list<int>::iterator lbegin = pmergeMe.list_data.begin();
            std::list<int>::iterator lend = pmergeMe.list_data.end();
            pmergeMe.merge_sort(pmergeMe.list_data, lbegin, lend);
            // sort deque
            std::deque<int>::iterator dbegin = pmergeMe.deque_data.begin();
            std::deque<int>::iterator dend = pmergeMe.deque_data.end();
            pmergeMe.merge_sort(pmergeMe.deque_data, dbegin, dend);

            // check for non-equal results in list vs deque (shouldn't happen)
            if (!pmergeMe.are_results_equal()) {
                return 1; }

            // print "After: <sorted list>"
            std::cout << "After: "; PmergeMe::print_list(pmergeMe.list_data);

            // calculate time it took and print
//        std::cout << "List merge sort took: " << list_ret << " seconds" << std::endl;
//        std::cout << "Deque merge sort took: " << deque_ret << " seconds" << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
        return 0;
    }
}
