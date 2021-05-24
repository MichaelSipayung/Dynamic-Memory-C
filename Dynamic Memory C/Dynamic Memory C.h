// Dynamic Memory C.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <new> //raise an exeption
std::unique_ptr<int> clone(int p) {
	return std::unique_ptr<int>(new int(p));
}

class strBlobPtr {
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const  std::string&) const;
	std::weak_ptr<std::vector<std::string>>wptr;
	std::size_t curr;
public:
	strBlobPtr() :curr(0){}
	

};
// TODO: Reference additional headers your program requires here.
