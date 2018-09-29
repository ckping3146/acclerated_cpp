#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <stdexcept>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Student_info {
public:
	// 类型提供的接口
	double grade() const;
	std::istream& read(std::istream&);
	std::string name() const { return n; };
	bool valid() const { return !homework.empty(); }

	// 构造函数
	Student_info() : midterm(0), final(0) { }	// 构造一个空的Student_info 对象 【缺省构造函数】, n和homework被隐式初始化
	Student_info(istream& in) { read(in); } 	// 读一个流从而构造一个对象

private:
	// 类型的实现
	std::string n;
	double midterm, final;
	std::vector<double> homework;
};

double middle(const vector<double>& hw) {
	if (hw.empty()) return 0;
	vector<double>::size_type mid = hw.size() / 2;
	return (0==hw.size()%2) ? (hw[mid]+hw[mid+1])/2 : hw[mid];
}

double grade(double mid, double fin, vector<double> hw) {
	return 0.2 * mid + 0.4*fin + 0.4*middle(hw);
}
double Student_info::grade() const {
	return ::grade(midterm, final, homework);
}

istream& read_hw(istream& in, vector<double>& ret) {
	double hw;
	while(in >> hw) {
		ret.push_back(hw);
	}
	
	return in;
}
std::istream& Student_info::read(std::istream& in) {
	in >> n >> midterm >> final;
	cout << "Read student [" << n << "]'s mid & final." << endl;
	read_hw(in, homework);
	return in;
}

bool compare(const Student_info& x, const Student_info& y) {
	return x.name() < y.name();
}


int main(int argc, char** argv) {
	// 读取一系列学生成绩，格式化后输出
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	cout << "Read " << students.size() << " students info." << endl;


	return 0;
}
