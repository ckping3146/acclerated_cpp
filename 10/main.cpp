#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ios>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	/*
	ifstream infile("in");
	ofstream outfile("out");
	
	string s;
	while(getline(infile, s))
		outfile << s << endl;
	*/
	
	if (argc == 1) {
		cout << "No Input file, plz check!" << endl;
		return -1;
	}

	size_t fail_count = 0;
	for (size_t i=1; i<argc; ++i) {
		ifstream in(argv[i]); 
		if (in) {
			string s;
			while(getline(in, s))
				cout << s << endl;
			cout << endl;
		}
		else  {
			cerr << "Open " << argv[i] << " error." << endl;
			++fail_count;
		}
	}
	
	return fail_count;
}
