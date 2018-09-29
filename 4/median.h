#ifndef __MEDIAN_H__
#define __MEDIAN_H__

#include <iostream>	
#include <algorithm>	// 获取 sort 
#include <stdexcept>	// 获取 domain_error 
#include <vector>

typedef std::vector<double>::size_type dvec_sz ; 

/* 取得double向量中的中指 */
double median(std::vector<double>) ;

#endif
