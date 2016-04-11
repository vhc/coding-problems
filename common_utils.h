#pragma once

#include <iostream>
#include <vector>

namespace common_utils {

template <typename T>
void print(const std::vector<T> A) {
	for (const auto& elem : A) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

}
