#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "core.h"
#include "calc.h"

using namespace std;

// Core
istream& Core::read(istream& in){
    read_common(in);
    read_hw(in, hw);
    return in;
}

istream& Core::read_common(istream& in){
    // 读出学生姓名与考试成绩
    in >> n >> midterm >> final ;
    return in; 
}
   
double Core::grade() const {
    return ::grade(midterm, final, hw);
}

// ===================================================

istream& Grad::read(istream& in) {
    read_common(in);
    in >> thesis;
    read_hw(in, hw);
    return in;
}

double Grad::grade() const {
    return min(Core::grade(), thesis);
}


//====================================================
bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}





