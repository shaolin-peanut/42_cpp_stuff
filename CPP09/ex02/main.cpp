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

        double list_ret = pmergeMe.list_merge();
        double deque_ret = pmergeMe.deque_merge();
        if (list_ret == -1 || deque_ret == -1) {
            std::cout << "List or Deque merge sort failed!" << std::endl;
            return 1;
        }
        else if (!pmergeMe.are_results_equal()) {
            std::cout << "List and Deque results are not equal!" << std::endl;
            return 1;}
        else {
            std::cout << "After: "; PmergeMe::print_list(pmergeMe.list_data);
        }
        std::cout << "List merge sort took: " << list_ret << " seconds" << std::endl;
        std::cout << "Deque merge sort took: " << deque_ret << " seconds" << std::endl;
        return 0;
    }
}
