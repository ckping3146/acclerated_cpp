#include <iostream>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
#include "calc.h"

using namespace std;
vector<string> readwords(istream& in) {
    vector<string> ret;
    string s;
    while(in >> s) {
        if (s.size()) 
            ret.push_back(s);
    }
    return ret;
}

