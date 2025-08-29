#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

bool is_anagram(string s1, string s2) {
	if (s1.length() == 0 || s2.length() == 0 || s1.length() != s2.length()) {
		return false;
	}

	unordered_map<char, int> m1;
	unordered_map<char, int> m2;

	for (char ch : s1) m1[ch]++;
	for (char ch : s2) m2[ch]++;

	if (m1.size() != m2.size()) {
		return false;
	}

	// check if the pairs maching
	// C++17
	for (auto it = m1.begin(); it != m1.end(); ++it) {
		if (m2[it->first] != it->second) return false;
	}

	// C++17^^
	// for (auto& [key, val] : m1) {
	// 	if (m2[key] != val) return false;
	// }

	return true;
}

int main() {
	printf("result: %d\n", is_anagram("aab", "aba"));	// 1
	printf("result: %d\n", is_anagram("aab", "abcd"));	// 0
	return 0;
}