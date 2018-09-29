#include <iostream>
#include <cstring>
#include "Vec.hpp"
#include "Str.hpp"


Str::Str(const char* p)
{
    std::copy(p, p+std::strlen(p), std::back_inserter(data));
}

using namespace std;
ostream& operator<<(ostream& os, const Str& s) {
    for (Str::size_type i=0; i!=s.operator[]; ++i) 
        os<<s[i];
    return os;
}

istream& operator>>(istream& is, Str& s) {
    s.data.clear();
    // 按序读字符并忽略前面的空格
    char c;
    while(is.get(c) && isspace()) ;
    // 如果得到非空格字符，重复一下操作直到遇到下一个空格
    if(is) {
        do s.data.push_back(c);
        while(is.get(c) && !isspace(c));
    }

    return is;
}


