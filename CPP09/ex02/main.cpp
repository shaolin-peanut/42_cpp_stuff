//
// Created by Samuel Bars on 4/20/23.
//

#include "PmergeMe.hpp"

void	print_time(clock_t start, clock_t end, int size, std::string type)
{
	std::cout << "Time to process a range of " << size << " elements with std::"
	<< type << " : " << static_cast<double>(end - start) / CLOCKS_PER_SEC
	<< " seconds" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe \"10 9 8 7 6 5 4 3 2 1 \"" << std::endl;
        return 1;
    }
    else {
        try {
			//start clocks

			PmergeMe pmergeMe(argc, argv);

			// sort list
			clock_t start_list = clock();
			std::list<int> &list = pmergeMe.get_list_data();
			pmergeMe.merge_sort(list, list.begin(), list.end());
			clock_t end_list = clock();

			// sort deque
			clock_t start_deque = clock();
			std::deque<int> &deque = pmergeMe.get_deque_data();
			pmergeMe.merge_sort(deque, deque.begin(), deque.end());
			clock_t end_deque = clock();

            // check for non-equal results in list vs deque (shouldn't happen)
            if (!pmergeMe.are_results_equal()) {
				throw std::invalid_argument("Results are not equal");
			}

            // print "After: <sorted list>"
            std::cout << "After: "; PmergeMe::print_list(list);


			print_time(start_list, end_list, list.size(), "list");
			print_time(start_deque, end_deque, deque.size(), "deque");
		}
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return 1;
        }
        return 0;
    }
}
