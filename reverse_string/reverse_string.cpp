#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverse_string(vector<char>& s) {
	if (s.size() == 0)
		return;

	vector<char> s2(s.size());

	for (int i = s.size() - 1; i >= 0; i--) {
		s2.push_back(s[i]);
	}

	s = s2;
}

void reverse_string(string& s) {
}

int main() {
	vector<char> v = {'b', 'a', 's', 'a', 'k'};

	for (auto i : v) {
		cout << i << " ";
	}

	reverse_string(v);

	for (auto i : v) {
		cout << i << " ";
	}

	return 0;
}