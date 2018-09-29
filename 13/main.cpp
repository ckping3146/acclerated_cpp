#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

#include "calc.h"
#include "core.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

/* 读出 Core 类型，即不需要写论文的学生的成绩 */
#if 0
int main(int argc, char** argv) {
	vector<Core> students; // 读取并处理文件中的Core 记录
	Core record;
	string::size_type maxlen = 0;

	// 读入并存储数据
	cout << "Please enter student\'s info." << endl;
	while(record.read(cin)) {
		cout << "Read " << record.name() << " info over." << endl;
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	// 对学生记录按字母排序
	sort(students.begin(), students.end(), compare);
	// 输出学生姓名与成绩
	//cout << "test" << endl;
	for (vector<Core>::size_type i =0; i != students.size(); ++i ) {
		cout << setw(maxlen+1) << students[i].name() << "\t";
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		} catch(domain_error e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
#endif

#if 1
int main(int argc, char** argv) {
	vector<Grad> students; // 读取并处理文件中的Grad 记录
	Grad record;
	string::size_type maxlen = 0;

	// 读入并存储数据
	cout << "Please enter student\'s info." << endl;
	while(record.read(cin)) {
		cout << "Read " << record.name() << " info over." << endl;
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}
	// 对学生记录按字母排序
	sort(students.begin(), students.end(), compare);
	// 输出学生姓名与成绩
	//cout << "test" << endl;
	for (vector<Grad>::size_type i =0; i != students.size(); ++i ) {
		cout << setw(maxlen+1) << students[i].name() << "\t";
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		} catch(domain_error e) {
			cout << e.what() << endl;
		}
	}
	
	return 0;
}
#endif