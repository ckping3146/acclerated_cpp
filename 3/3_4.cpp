
#include <iostream>
#include <ios>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	
	// write a program to report input strings's max-long & min-long string
	
	cout << "Enter some strings, followed by end-of-file:";
	
	typedef vector<string>::size_type vec_sz;
	vector<string> words;
	string x;
	while(cin >> x) {
		words.push_back(x);
	}
	vec_sz size = words.size();
	
	if (words.empty()) {
		return -1;
	}
	
	vec_sz max_id = 0, min_id = 0; 
	for (vec_sz i=1; i<size; i++) {
		if (words[max_id].size() < words[i].size()) 
			max_id = i;
		if (words[min_id].size() > words[i].size())
			min_id = i;
	}
	
	cout << "The max long string is : " << words[max_id] << " , length is " << words[max_id].size() << endl;
	cout << "The mix long string is : " << words[min_id] << " , length is " << words[min_id].size() << endl;
	
	return 0;
}



