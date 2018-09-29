
#include "student_info.h"

using namespace std; 

// 读取姓名，期中，期末成绩
istream read(istream& is, Student_info& sinfo) {
	is >> sinfo.name >> sinfo.midterm >> sinfo.final;
	return read_hw(is, sinfo.hw);
}

// 读取所有家庭作业成绩
istream read_hw(istream& is, std::vector<double>& hw) {
	if (is) {
		hw.clear(); // 先清空
		double x;
		while (is>>x) {
			hw.push_back(x);
		} 
		is.clear(); // 清除输入流错误以读入下一学生信息 
	}
	
	return is; 
}
 
// 比较两个学生的姓名信息，返回bool
bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name < s2.name;
}


