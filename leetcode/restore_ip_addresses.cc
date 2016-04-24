#include <string>
#include <iostream>
#include <vector>

#include <cstdio>

#include "../common_utils.h"

using namespace std;
using namespace common_utils;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		const int REQUIRED_OCTETS = 4;
		const int OCTET_MAX_LENGTH = 3;
		const int OCTET_MIN_LENGTH = 1;

		vector<string> all_ips;
		if (s.size() >= REQUIRED_OCTETS * OCTET_MIN_LENGTH && s.size() <= REQUIRED_OCTETS * OCTET_MAX_LENGTH) {
			const int start_level = 0;
			const int stop_level = 4;
			helper(s, start_level, stop_level, all_ips, "", 0);
		}
		return all_ips;
	}

private:
	void helper(const string& s,
				const int current_level,
				const int stop_level,
				vector<string>& all_ips,
				const string& ip_so_far,
				const int octet_start_index)
	{
		// Only consider candidates that:
		//	- Have exactly |stop_level| components (4 octets for IPv4)
		//	- Have fully exhausted the original string
		if (current_level == stop_level && octet_start_index == s.size()) {
			all_ips.push_back(ip_so_far);
			return;
		}

		for (int octet_len = 1; octet_len <= 3; octet_len += 1) {
			if (octet_start_index + octet_len > s.size()) {
				break;
			}

			// Handle exceptions when string does not contain valid number
			string octet = s.substr(octet_start_index, octet_len);
			int value = stoi(octet);
			if (is_valid_octet(octet, value)) {
				string ip;
				if (ip_so_far.empty()) {
					ip += octet;
				} else {
					ip += ip_so_far + "." + octet;
				}
				helper(s,
					   current_level + 1,
					   stop_level,
					   all_ips,
					   ip,
					   octet_start_index + octet_len);
			}
		}
	}

	bool is_valid_octet(const string& octet,
						const int value)
	{
        // IPv4-specific range
		if (octet.empty() || octet.size() > 3)
			return false;

        // IPv4-specific range
		if (value < 0 || value > 255)
			return false;

        // Detect leading 0s, e.g. "05", "00"
		if (octet[0] == '0' && octet.size() > 1)
			return false;

        return true;
	}
};

int main() {
	Solution sol;
	string ip_string;
	while (cin) {
		cin >> ip_string;
		print(sol.restoreIpAddresses(ip_string));
	}
	return 0;
}
