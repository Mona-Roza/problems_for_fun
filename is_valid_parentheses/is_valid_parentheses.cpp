#include <iostream>
#include <stack>

/*
Input:  "({[]})"
Output:  true

Input:  "({[})"
Output:  false
*/

bool is_valid_parentheses(const std::string& s) {
	std::stack<char> st;

	for (char ch : s) {
		if (ch == '(' || ch == '[' || ch == '{') {
			st.push(ch);
		} else {
			if (st.empty()) return false;

			auto top = st.top();
			st.pop();

			if ((ch == ')' && top != '(') ||
				(ch == ']' && top != '[') ||
				(ch == '}' && top != '{')) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	return 0;
}