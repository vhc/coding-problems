#include <iostream>
#include <cstdio>

class Solution {
public:
	double myPow(double x, int input_n) {
		if (input_n == 0) {
			return 1;
		} else if (input_n == 1) {
			return x;
		}

		bool is_num_negative = (x < 0.0);
		if (is_num_negative) {
			x = -x;
		}

		// Convert to 64-bit early to avoid overflow on the negation
		int64_t n = (int64_t)input_n;
		bool is_power_negative = (n < 0);
		if (is_power_negative) {
			n = -n;
		}

		double result = x;
		uint64_t p = 2;
		while (p <= n) {
			result = result * result;
			if (p * 2 > n) {
				break;
			}
			p = p * 2;
		}

		uint64_t n_remainder = (n > p) ? n - p : 0;
		if (n_remainder > 0) {
			result = result * myPow(x, n_remainder);
		}

		// (-3) ^ 2 = 9, (-3) ^ 3 = -27
		if (is_num_negative) {
			if (n % 2 != 0) {
				result = -result;
			}
		}

		if (is_power_negative) {
			result = (long double)1 / result;
		}

		return result;
	}
};

int main() {
	Solution solver;
	while (!std::cin.eof()) {
		double x;
		int n;

		std::cin >> x;
		std::cin >> n;

		std::cout << solver.myPow(x, n) << std::endl;
	}
	return 0;
}
