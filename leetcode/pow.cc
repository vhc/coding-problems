// Still failing: 34.00515 ^ (-3)

class Solution {
public:
	double myPow(double x, int input_n) {
		if (input_n < 0) {
			return 0;
		} else if (input_n == 0) {
			return 1;
		} else if (input_n == 1) {
			return x;
		}
		
		bool is_num_negative = (x < 0.0);
		if (is_num_negative) {
			x = -x;
		}
		
		bool is_power_negative = (input_n < 0);
		if (is_power_negative) {
			input_n = -input_n;
		}
		
		double result = x;
		uint64_t p = 2;
		uint64_t n = (uint64_t)input_n;
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

		// (-3) ^ 2 = 9
		// (-3) ^ 3 = -27
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
