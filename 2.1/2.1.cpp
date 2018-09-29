
#include <iostream> 
#include <string>

using namespace std;

int main() {

	std::string name;
	std::cout << "Please input a name:";
	
	std::cin >> name;
	
	const std::string greeting = "Hello, " + name + "!";
	
	//  �ָ���������� 
	std::cout << std::endl;
	
	const int pad = 1; // �հ���/���� 
	const int rows = pad * 2 * 3;
	const std::string::size_type cols = greeting.size() + pad*2 + 2; 
	
	int r = 0, c = 0;
	while(r != rows) {
		//  ���ÿ�е�����
		
		// ��һ��/���һ��/��һ��/���һ�� ���� *
		if (r==0 || r==(rows-1) || c==0 || c==(cols-1)) {
			std::cout << "*";
			c++; 
		} 
		// ��� ������� 
		else if (c == pad + 1 && r == pad + 1) {
			std::cout << greeting;
			c += greeting.size(); 
		}
		// ��� �հ�
		else {
			std::cout << " ";
			c++;
		} 
		
		//  ÿ�� ĩβ����
		if (c == cols) {
			std::cout << std::endl;
			c=0;
			r++;
		} 
	} 

	return 0;
}


