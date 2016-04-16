#include <iostream>
#include <string>
#include <locale>
#include <unordered_set>

static std::unordered_set<char> build_lowercase_alphabet() {
	std::unordered_set<char> alphabet;
	for (char c = 'a'; c <= 'z'; c++) {
		alphabet.insert(c);
	}
	return alphabet;
}

static bool is_pangram(const std::string& sentence) {
	// Strategy
	// - Check using lowercase version
	// - Create a set of must-have letters
	// - For each letter seen, remove it
	// - Is pangram when set is empty
	std::unordered_set<char> lowercase_alphabet = build_lowercase_alphabet();
	
	for (auto letter : sentence) {
		lowercase_alphabet.erase(tolower(letter));
		if (lowercase_alphabet.empty()) {
			break;
		}
	}
	
	return lowercase_alphabet.empty();
}

int main() {
	std::string sentence;
	std::getline(std::cin, sentence);
	std::cout << (is_pangram(sentence) ? "pangram" : "not pangram") << std::endl;
	return 0;
}