#include <cstdio>
#include <list>
#include <string>

char first_non_repeating_char(const std::string& s) {
	char a = 'n';

	std::list<int> list_of_indexes;
	for (int i = 0; i < s.length(); i++) {
		char ch = s[i];

		list_of_indexes.clear();
		int res = -1;
		while ((res = s.find(ch, res + 1)) != std::string::npos) {
			list_of_indexes.push_back(res);
		}

		// it is about the first one. So if you find just return it
		if (list_of_indexes.size() == 1) {
			return s[i];
		}
	}
	return a;
}

int main() {
	const std::string str = "ssssttttbaa";
	printf("result :%c\n", first_non_repeating_char(str));

	return 0;
}
