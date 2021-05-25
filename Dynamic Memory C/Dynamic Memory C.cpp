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
	std::cout << "Test weak_ptr" << std::endl;
	std::shared_ptr<int> dec = std::make_shared<int>(42);
	std::weak_ptr<int> wp(dec);//point to the same object
	std::cout << "Test object to to where \t: [" << dec << "]" << std::endl;
	std::cout << "Test if it still exist \t: [" << wp.lock() << "]" << std::endl;
	std::cout<<"Test  use_count \t:[ "<<dec.use_count() <<"]"<<std::endl;
	std::weak_ptr<int> dc(dec);//point to the same object //weak share 
	std::cout << "Test  use_count \t:[ " << dec.use_count() << "]" << std::endl;
	auto point = dec;
	std::cout << "Test  use_count \t:[ " << dec.use_count() << "]" << std::endl;
	if (std::shared_ptr<int> np = wp.lock()) {
		std::cout << "True if np is not null , inside this condition , np shares its object with p" << std::endl;
	}
	else {
		std::cout << "null" << std::endl;
	}

	std::cout << "Dynamic Array" << std::endl;
	int* pia = new int[42];
	std::cout << "Initializing an array " << std::endl;
	int* init = new int[10](); //value initialized to 0
	std::string* tenStr = new std::string[10](); //block of ten empty string
	std::cout << "New standart c++0x , braced initalized" << std::endl;
	int* brac = new int[10]{ 0,1,2,3,4,5,6,7 };
	std::string* bracSt = new std::string[10]{ "mic","and","you" };//remaining elements are value initalized
	//int* bad = new int[3]{ 1,2,3,4 }; //raise and exception bad_array_new_length
	size_t n = sizeof(int);
	int* pAllocate = new int[n];
	std::cout << "freeing dynamic array " << std::endl;
	delete[] brac;
	std::cout << "Smart pointer and dynamics array" << std::endl;
	std::unique_ptr<int[]>up(new int[10]);
	std::cout << "Access the elements in the array" << std::endl;
	for (size_t i = 0; i != 10; ++i) {
		up[i] = i;
	}
	std::cout << "Show value after use unique ptr to array\t:[ ";
	for (size_t i = 0; i != 10; ++i) {
		std::cout << up[i] << "|";
	}
	std::cout << "]" << std::endl;
	up.release(); //automatically uses delete[] to destroys its pointer

	std::cout << "Manage dynamic array by shared_ptr" << std::endl;
	std::shared_ptr<int>sp(new int[10], [](int* p) {delete[]p; });
	std::cout << "shared_ptr doesn't support pointer arithmetic and subscript operator" << std::endl;
	for (size_t i = 0; i != 10; ++i) {
		*(sp.get() + i) = i;
	}
	sp.reset();//frees the memory 
	std::cout << "allocator class" << std::endl;
	std::allocator<std::string> alloc; //object that can allocate string 
	auto const p = alloc.allocate(50); //allocate 5 unconstructed strings
	auto q = p;
	alloc.construct(q++);//q is the empty string
	alloc.construct(q++, 10, 'c');  // q is ten 'c'
	alloc.construct(q++, "hi");
	
	std::cout << "Destroy each constructed element" << std::endl;
	while (q!=p)
	{
		alloc.destroy(--q);// free the string we actually allocated 
		std::cout << "Destroy" << std::endl;
	}
	std::cout << "Dealocate , free the memory " << std::endl;
	alloc.deallocate(p, 3);
	std::allocator<int> allocThem;
	std::cout << "Allocator Algorithm" << std::endl;
	std::vector<int> all{ 1,2,3,4,5,6 };
	auto pOri = allocThem.allocate(all.size() * 2);
	auto qOri = std::uninitialized_copy(all.begin(), all.end(), pOri);
	std::uninitialized_fill_n(qOri, all.size(), 42);
	



}



