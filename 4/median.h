#ifndef __MEDIAN_H__
#define __MEDIAN_H__

#include <iostream>	
#include <algorithm>	// ��ȡ sort 
#include <stdexcept>	// ��ȡ domain_error 
#include <vector>

typedef std::vector<double>::size_type dvec_sz ; 

/* ȡ��double�����е���ָ */
double median(std::vector<double>) ;

#endif
