#include "forwardlist.hpp"

#include <iostream>

using namespace a08;

int main()
{
    ForwardList<int> list;

    // Test 1: Push elements to the front
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    // Test 2: Iterate and print elements
    std::cout << "Elements in the list:\n";
    for (auto i : list) {
        std::cout << i << "\n";
    }

    // Test 3: Check front and size
    std::cout << "Front element: " << list.front() << "\n";
    std::cout << "Size of the list: " << list.size() << "\n";

    // Test 4: Pop front and check size
    list.pop_front();
    std::cout << "After popping front element:\n";
    std::cout << "Front element: " << list.front() << "\n";
    std::cout << "Size of the list: " << list.size() << "\n";

    // Test 5: Insert after iterator
    auto it = list.begin();
    it = list.insert_after(it, 10);
    std::cout << "After inserting 10 after the first element:\n";
    for (auto i : list) {
        std::cout << i << "\n";
    }

    // Test 6: Swap two lists
    ForwardList<int> anotherList;
    anotherList.push_front(20);
    anotherList.push_front(30);
    std::cout << "List before swap:\n";
    for (auto i : list) {
        std::cout << i << "\n";
    }
    std::cout << "Another list before swap:\n";
    for (auto i : anotherList) {
        std::cout << i << "\n";
    }
    swap(list, anotherList);
    std::cout << "List after swap:\n";
    for (auto i : list) {
        std::cout << i << "\n";
    }
    std::cout << "Another list after swap:\n";
    for (auto i : anotherList) {
        std::cout << i << "\n";
    }

    return 0;
}