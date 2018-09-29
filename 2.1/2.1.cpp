
#include <iostream> 
#include <string>

using namespace std;

int main() {

	std::string name;
	std::cout << "Please input a name:";
	
	std::cin >> name;
	
	const std::string greeting = "Hello, " + name + "!";
	
	//  分割输出和输入 
	std::cout << std::endl;
	
	const int pad = 1; // 空白行/列数 
	const int rows = pad * 2 * 3;
	const std::string::size_type cols = greeting.size() + pad*2 + 2; 
	
	int r = 0, c = 0;
	while(r != rows) {
		//  输出每行的数据
		
		// 第一行/最后一行/第一列/最后一列 都是 *
		if (r==0 || r==(rows-1) || c==0 || c==(cols-1)) {
			std::cout << "*";
			c++; 
		} 
		// 输出 欢饮语句 
		else if (c == pad + 1 && r == pad + 1) {
			std::cout << greeting;
			c += greeting.size(); 
		}
		// 输出 空白
		else {
			std::cout << " ";
			c++;
		} 
		
		//  每行 末尾换行
		if (c == cols) {
			std::cout << std::endl;
			c=0;
			r++;
		} 
	} 

	return 0;
}


