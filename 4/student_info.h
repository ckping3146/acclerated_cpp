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

// ��ȡ���������У���ĩ�ɼ�
std::istream read(std::istream &, Student_info &);

// ��ȡ���м�ͥ��ҵ�ɼ�
std::istream read_hw(std::istream &, std::vector<double> &);
 
// �Ƚ�����ѧ����������Ϣ������bool
bool compare(const Student_info&, const Student_info&); 

#endif
