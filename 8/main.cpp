#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


bool not_space(char c) {
	return !isspace(c);
}

bool space(char c) {
	return isspace(c);
}

// 泛型的split ： 模版函数
template <class Out>
void split(const string& s, Out os) {
	typedef string::const_iterator iter;
	
	iter i = s.begin();
	while(i != s.end()) {
		// ignore front spaces
		i = find_if(i, s.end(), not_space);
		
		// find next word's end
		iter j = find_if(i, s.end(), space);
		
		// copy chars in [i,j)
		if (i != s.end()) {
			*os++ = string(i, j);
		}
		
		i = j;
	}
}


int main(int argc, char** argv) {

	// 测试 模版函数  split
	string line;
	while (getline(cin, line))
		split(line, ostream_iterator<string>(cout, "\n"));

	return 0;
}
