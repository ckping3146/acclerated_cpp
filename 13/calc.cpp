#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>

using namespace std;

double middle(vector<double> h) {
    //typedef vector<double> vd;
    if (!h.size())
        return 0;
    sort(h.begin(), h.end());
    return (h.size() % 2) ? h[h.size()/2] : (h[h.size()/2-1] + h[h.size()/2]) / 2;
}

double grade(double m, double f, double h) {
    return 0.2 * m + 0.4*f + 0.4*h;
}

double grade(const double m, const double f, const vector<double>& h) {
    if(h.empty())
        throw domain_error("Student has done no homeword!");
    return grade(m,f,middle(h));
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear(); // 清除原先的内容
        double x;
        while(in >> x) 
            hw.push_back(x);
        in.clear(); // 清除流以使输入动作对下一学生有效
    }

    return in;
}


