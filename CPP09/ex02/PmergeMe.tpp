
template <typename iter>
void insertion_sort(iter begin, iter end) {
    // iterate through list starting at second element
    for (iter it = begin; it != end; ++it) {
        iter curr = it;
        iter prev = curr;
        --prev;

        while (curr != begin && *prev > *curr) {
            // Swap the elements pointed to by prev and curr
            std::swap(*prev, *curr);

            // Decrement the iterators
            --curr;
            if (curr != begin) {
                --prev;
            }
        }
    }
}

template <typename source, typename Container>
void copy_container(source &src, Container &dest, typename Container::iterator start)
{
    typename Container::iterator dst = start;
    for (typename Container::iterator it = src.begin(); it != src.end(); ++it) {
        if (dst == dest.end()) {
            dst = dest.insert(dst, *it);
            ++dst;
        } else {
            *dst = *it;
            ++dst;
        }
    }
}

template <typename Container>
void PmergeMe::merge_sort(Container &dest, typename Container::iterator start, typename Container::iterator end) {
    int size = std::distance(start, end);

    if (size <= sublist_size) { // perform insert-sort
        insertion_sort<typename Container::iterator>(start, end);
    }
    else { // recursive call to split function further
        typename Container::iterator middle = start;
        for (int i = 0; i < size / 2; ++i) {
            ++middle; } // increment till middle
        merge_sort(dest, start, middle);
        merge_sort(dest, middle, end);
        merge_step(dest, start, middle, end);
    }
}

template <typename Container>
void PmergeMe::merge_step(Container &dest, typename Container::iterator start, typename Container::iterator middle, typename Container::iterator end) {
    Container temp;
    typename Container::iterator it1 = start;
    typename Container::iterator it2 = middle;

    while (it1 != middle || it2 != end) {
        if (it1 == middle) {
            temp.push_back(*it2);
            it2++;
        } else if (it2 == end || *it1 < *it2) {
            temp.push_back(*it1);
            it1++;
        }
            // sublist 2 item smaller than 1's, add sublist 2 item
        else {
            temp.push_back(*it2);
            it2++;
        }
    }

    copy_container(temp, dest, start);
}
