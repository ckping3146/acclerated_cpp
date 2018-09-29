
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

// 计算学员的最终成绩
// 最终成绩 = 期中成绩*0.2 + 期末成绩*0.4 + 家做作业平均成绩*0.4


int main() {

using namespace std;
	
	cout << "Enter midterm & final grades:";
	int midterm, final;
	cin >> midterm >> final;
	
	cout << endl;
	cout << midterm << " - " << final << endl;
	cout << endl;

	cout << "Enter your homework grades  :";
	
	int count = 0; // 家庭作业个数 
	double sum = 0; // 家庭作业总和 
	int x = 0; // 存储单个家庭作业
	
	while(cin >> x) {
		++count;
		sum += x;
	} 

	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) <<
		midterm * 0.2 + final * 0.4 + sum * 0.4 / count << 
		setprecision(prec) << "!" << endl;


	return 0;
}
 




