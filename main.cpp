#include <iostream>
#include "Deque.h"
#include <deque>

int main()
{

    Deque<int> deque;
    int a = 56;
    deque.pushBack(a);
    deque.pushBack(3);
    deque.pushBack(459);
    deque.pushBack(694);
    deque.pushBack(9349);
    deque.pushBack(13425);
    deque.pushFront(299);
    deque.pushFront(358);

    for (auto num : deque)
    {
        std::cout << num << std::endl;
    }

    {
		Deque<std::string> strings;

		strings.pushBack("Hello");
		strings.pushBack("there");
		strings.pushBack("General");
		strings.pushBack("Kenobi");

		for (auto word : strings) 
		{
			std::cout << word << std::endl;
		}
    }
    std::cout << "Hello there" << std::endl;
    std::cin.get();
    return 0;
}