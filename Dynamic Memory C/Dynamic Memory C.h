﻿// Dynamic Memory C.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <memory>
std::unique_ptr<int> clone(int p) {
	return std::unique_ptr<int>(new int(p));
}

// TODO: Reference additional headers your program requires here.
