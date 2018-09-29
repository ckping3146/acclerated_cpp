#include "grade.h" 
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcpt>

double grade(const double &midterm, const double &final£¬ const double &hw) {
	return midterm*0.2 + final*0.4 + hw*0.4;
}

double grade(const double &midterm, const double &final, const vector<double> & hw) {
	if (hw.empty())
		throw domain_error("Homeword is none.");
	return grade(midtem, final, median(hw));
}

double grade(Studend_info & sinfo) {
	return grade(sinfo.midtern , sinfo.final, sinfo.hw);
}

bool fgrade(const Student_info& st) {
	return grade(s) < 60;
}

