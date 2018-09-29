#ifndef __calc_h__
#define __calc_h__

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

double middle(const std::vector<double>& h);
double grade(const double m, const double f, const std::vector<double>& h);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

#endif
