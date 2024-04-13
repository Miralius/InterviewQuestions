//
// Created by F-Mir on 4/13/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

template<typename ForwardIt, typename Predicate>
ForwardIt remove_if_(ForwardIt first, ForwardIt last, Predicate pred)
{
    first = std::find_if(first, last, pred);
    ForwardIt result = first;
    while (first++ != last) {
        if (!pred(*first)) {
            std::swap(*result++, *first);
        }
    }
    return result;
}

int main()
{
    std::vector<int> test{1, 3, 7, 0, 2, 4, 6, 0, 0, 1, 2, 3};

    auto last = remove_if_(test.begin(), test.end(), [](const auto& value)
    {
        return value == 0;
    });

    for (const auto& value: test)
    {
        std::cout << value << ' ';
    }
    std::cout << std::endl;

    test.erase(last, test.end());

    for (const auto& value: test)
    {
        std::cout << value << ' ';
    }

    return 0;
}