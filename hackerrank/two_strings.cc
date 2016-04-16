#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

static bool strings_have_common_substring(const string& A, const string& B) {
	set<char> setA(A.begin(), A.end());
	set<char> setB(B.begin(), B.end());
	vector<char> common(min(A.size(), B.size()));
	
	auto it = set_intersection(setA.begin(), setA.end(),
							   setB.begin(), setB.end(),
							   common.begin());
	
	common.resize(it - common.begin());
	
	return !common.empty();
}

int main() {
	int testCases = 0;
	
	cin >> testCases;
	while (testCases-- > 0) {
		string s1;
		string s2;
		
		cin >> s1;
		cin >> s2;
		
		cout << (strings_have_common_substring(s1, s2) ? "YES" : "NO")
			 << endl;
	}
}