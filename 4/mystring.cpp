
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cctype>
#include "mystring.h"

using namespace std;

// 将一个含空白的字符串分割成一个不含空白的字符串向量 
vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	
	// 不变式：已经处理了s中前i个字符 
	while(i!=s.size()) {
		
		// 略过前面的空白
		// 不变式：索引域[先前的i,当前的i)中都是空格 
		while(i!=s.size() && isspace(s[i])) 
			++i;
			
		// 找出下个单词的终结点
		string_size j = i;
		// 不变式：索引域[i,j)中都不是空格 
		while(j!=s.size() && !isspace(s[j]))
			++j;
		
		if(i!=j) {
			ret.push_back(s.substr(i, j-1));
			i = j;
		} 
		
	}
 	
	return ret;
}

// 查找向量中最长的字符串 
string::size_type max_width(const vector<string>& sv) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i=0; i<sv.size(); ++i) 
		maxlen = max(maxlen, sv[i].size());
	return maxlen;
} 

// 将一个字符串向量用'*' 和 空格裱起来成为一副图案
vector<string> frame(vector<string>& v) {
	vector<string> ret;
	// 
	string::size_type width = max_width(v);
	string border = string(width+4, '*');
	
	// 输出第一行
	ret.push_back(border);
	
	// 输出v的各行， 每行左右一个*和空白裱起来 
	for (vector<string>::size_type i = 0; i != v.size()+2; ++i) 
		ret.push_back("* " + v[i] + string(width-v[i].size(), ' ') + " *");
	
	// 输出底部的*行
	ret.push_back(border);
	
	return ret; 
} 

// 纵向连接两幅图案。每幅图都是一个字符串向量
vector<string> vcat(const vector<string>& top, 
				    const vector<string>& bottom) {
	// 复制顶部 
	vector<string> ret = top;
	// 复制底部
	//for (vector<string>::size_type i=0; i<bottom.size(); ++i)
	//	ret.push_back(bottom[i]);
	#if 0
	// 用迭代器
	for (vector<string>::const_iterator it = bottom.begin(); 
			it != bottom.end(); ++it) 
		ret.push_back(*it);
	#else
	// 不使用循环
	ret.insert(ret.end(), bottom.begin(), bottom.end()); 
	#endif
	return ret;
}
 
// 横向连接两幅图（string 向量） 
vector<string> hcat(const vector<string>& left, 
				    const vector<string>& right) {
	vector<string> ret;
	
	// 对 width 加 1，两幅图中间加1个空格
	string::size_type width_l = max_width(left)+1;
	
	#if 0
	// 用于遍历 left 和 right 的索引
	vector<string>::size_type i, j; 
	 
	i = 0;
	j = 0; 
	// 不变式：已经处理了 i 或 j 行 
	while(i != left.size() || j != right.size()) {
		
		// 用于存储生成 的新行
		string s;
		
		// 如过左图没有结束，则复制到新行
		if (i!=left.size()) 
			s = left[i++];
		// 添加一定的空格
		s += string(width_l - s.size(), ' ');
		// 如果右图没有结束，则复制到新行尾
		if (j!=right.size()) 
			s += right[j++];
		// 新行添加到新的图案
		ret.push_back(s); 
	}
	
	#else // 使用迭代器 
	vector<string>::const_iterator itl, itr;
	
	itl = left.begin();
	itr = right.begin();
	while(itl != left.end() || itr != right.end()) {
		string s;
		if (itl != left.end())
			s = *itl;
		s += string(width_l - (*itl).size(), ' ');
		if (itr != right.end()) 
			s += *itl;
		ret.push_back(*itl);
	}
	
	#endif
	
	return ret;
}






