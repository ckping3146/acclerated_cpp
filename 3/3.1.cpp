
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

// ����ѧԱ�����ճɼ�
// ���ճɼ� = ���гɼ�*0.2 + ��ĩ�ɼ�*0.4 + ������ҵƽ���ɼ�*0.4


int main() {

using namespace std;
	
	cout << "Enter midterm & final grades:";
	int midterm, final;
	cin >> midterm >> final;
	
	cout << endl;
	cout << midterm << " - " << final << endl;
	cout << endl;

	cout << "Enter your homework grades  :";
	
	int count = 0; // ��ͥ��ҵ���� 
	double sum = 0; // ��ͥ��ҵ�ܺ� 
	int x = 0; // �洢������ͥ��ҵ
	
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
 




