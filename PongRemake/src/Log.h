#pragma once

#ifdef _DEBUG
#include <iostream>

	// Check if a task is succesfully completed
	#define ASSERT(condition, message) \
			if ((condition)){ \
				std::cerr << message " -> Success!" << std::endl; \
			} \
			else { \
				std::cerr << message << " -> Failed!" << std::endl; \
			}
	#define LOG(message) \
				std::cout << message << std::endl;
#else
	#define ASSERT(condition, message) ((void)0)
	#define LOG(message) ((void)0)
#endif
