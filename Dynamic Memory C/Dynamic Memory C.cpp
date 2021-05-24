// Dynamic Memory C.cpp : Defines the entry point for the application.
//

#include "Dynamic Memory C.h"


int main()
{
	std::cout << "Hello CMake.... Dynamic Memory" << std::endl;
	std::cout << "Unique_ptr" << std::endl;
	std::unique_ptr<int> p1(new int(12));
	std::cout << "p1 point to int with value \t: [" << *p1 << "]" << std::endl;
	std::cout << "noted : unique_ptr doesn't support copy or assignment" << std::endl;
	std::cout << "Delete the memory which p1 point , call reset " << std::endl;
	std::unique_ptr<int> p2(new int(98));
	std::cout << "Before deletes the memory to which p1 had point\t: [ " << *p1 << "]" << std::endl;
	p1.reset(p2.release());
	std::cout << "After deletes the memory to which p1 had point\t: [ " << *p1 << "]" << std::endl;
	

}
