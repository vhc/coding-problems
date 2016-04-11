#include "../standard_headers.h"
#include "../common_utils.h"

using namespace common_utils;

static void rotate_left(std::vector<int>& A, int index, const int rotation_range = 3) {
	assert(index + rotation_range <= A.size());

	//printf("Array size = %d, rotating from index = %d to index = %d\n", (int)A.size(), index, index + rotation_range);
	std::rotate(A.begin() + index, A.begin() + index + 1, A.begin() + index + rotation_range);
}

//
// Strategy:
//
// Perform selection sort by moving the smallest element to the correct position until
// all elements are in the correct positions (if possible).
//
static bool is_rotation_sortable(std::vector<int>& A, const int rotation_range = 3) {
	assert(!A.empty() && A.size() >= rotation_range);

	const int max_rotate_start_index_allowed = A.size() - rotation_range;

	for (int i = 0; i < A.size(); i++) {
		int smallest_value_index = std::min_element(A.cbegin() + i, A.cend()) - A.cbegin();
		while (smallest_value_index != i) {
			int rotate_start = 0;
			if (smallest_value_index - i < rotation_range) {
				rotate_start = std::min(max_rotate_start_index_allowed, i);
			} else if (smallest_value_index > max_rotate_start_index_allowed) {
				rotate_start = max_rotate_start_index_allowed;
			} else {
				rotate_start = smallest_value_index - 1;
			}
			rotate_left(A, rotate_start, rotation_range);
			smallest_value_index--;
		}
	}

	return std::is_sorted(A.cbegin(), A.cend());
}

#if 0
static void test_rotations() {
	std::vector<int> A = {1, 2, 3, 4};

	print(A);
	rotate_left(A, 0);
	rotate_left(A, 0);
	rotate_left(A, 1);
	print(A);
}
#endif

int main() {
	int testCases = 0;

	std::cin >> testCases;
	while (testCases-- > 0) {
		int arraySize = 0;
		std::cin >> arraySize;

		std::vector<int> A(arraySize, 0);
		for (int i = 0; i < arraySize; i++) {
			std::cin >> A[i];
		}

		std::cout << (is_rotation_sortable(A) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
