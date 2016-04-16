#include <iostream>
#include <string>

static int count_min_deletions(const string& s) {
	int deletion_count = 0;
	
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			deletion_count += 1;
		}
	}
	
	return deletion_count;
}

int main() {
	int testCases = 0;
	
	std::cin >> testCases;
	while (testCases-- > 0) {
		std::string s;
		std::cin >> s;
		std::cout << count_min_deletions(s) << std::endl;
	}

	return 0;
}