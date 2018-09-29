#ifndef __STUDENT_INFO_H__
#define __STUDENT_INFO_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

typedef struct {
	std::string name;
	double midterm;
	double final;
	std::vector<double> hw;
}Student_info;

// 读取姓名，期中，期末成绩
std::istream read(std::istream &, Student_info &);

// 读取所有家庭作业成绩
std::istream read_hw(std::istream &, std::vector<double> &);
 
// 比较两个学生的姓名信息，返回bool
bool compare(const Student_info&, const Student_info&); 

#endif
