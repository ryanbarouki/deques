#include <iostream>
#include "Deque.h"

int main()
{
    Deque<int> deque;
    int a = 56;
    deque.pushBack(a);
    deque.pushBack(3);
    std::cout << "Hello there" << std::endl;
    return 0;
}