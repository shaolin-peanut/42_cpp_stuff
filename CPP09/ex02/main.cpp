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
        return 0;
    }
}
