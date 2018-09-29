#include "median.h"

using namespace std;
double median(vector<double> &vec) {
	dvec_sz size = vec.size();
	if (vec.size() == 0) {
		throw domain_error("Vector is empty!");
	}
	dvec_sz mid = size / 2;
	return (size % 2 == 0) ? ((vec[mid] + vec[mid-1] ) / 2) : vec[mid]; 
}

