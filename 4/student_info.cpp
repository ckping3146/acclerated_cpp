
#include "student_info.h"

using namespace std; 

// ��ȡ���������У���ĩ�ɼ�
istream read(istream& is, Student_info& sinfo) {
	is >> sinfo.name >> sinfo.midterm >> sinfo.final;
	return read_hw(is, sinfo.hw);
}

// ��ȡ���м�ͥ��ҵ�ɼ�
istream read_hw(istream& is, std::vector<double>& hw) {
	if (is) {
		hw.clear(); // �����
		double x;
		while (is>>x) {
			hw.push_back(x);
		} 
		is.clear(); // ��������������Զ�����һѧ����Ϣ 
	}
	
	return is; 
}
 
// �Ƚ�����ѧ����������Ϣ������bool
bool compare(const Student_info& s1, const Student_info& s2) {
	return s1.name < s2.name;
}


