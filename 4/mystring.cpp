
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cctype>
#include "mystring.h"

using namespace std;

// ��һ�����հ׵��ַ����ָ��һ�������հ׵��ַ������� 
vector<string> split(const string& s) {
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;
	
	// ����ʽ���Ѿ�������s��ǰi���ַ� 
	while(i!=s.size()) {
		
		// �Թ�ǰ��Ŀհ�
		// ����ʽ��������[��ǰ��i,��ǰ��i)�ж��ǿո� 
		while(i!=s.size() && isspace(s[i])) 
			++i;
			
		// �ҳ��¸����ʵ��ս��
		string_size j = i;
		// ����ʽ��������[i,j)�ж����ǿո� 
		while(j!=s.size() && !isspace(s[j]))
			++j;
		
		if(i!=j) {
			ret.push_back(s.substr(i, j-1));
			i = j;
		} 
		
	}
 	
	return ret;
}

// ��������������ַ��� 
string::size_type max_width(const vector<string>& sv) {
	string::size_type maxlen = 0;
	for (vector<string>::size_type i=0; i<sv.size(); ++i) 
		maxlen = max(maxlen, sv[i].size());
	return maxlen;
} 

// ��һ���ַ���������'*' �� �ո���������Ϊһ��ͼ��
vector<string> frame(vector<string>& v) {
	vector<string> ret;
	// 
	string::size_type width = max_width(v);
	string border = string(width+4, '*');
	
	// �����һ��
	ret.push_back(border);
	
	// ���v�ĸ��У� ÿ������һ��*�Ϳհ������� 
	for (vector<string>::size_type i = 0; i != v.size()+2; ++i) 
		ret.push_back("* " + v[i] + string(width-v[i].size(), ' ') + " *");
	
	// ����ײ���*��
	ret.push_back(border);
	
	return ret; 
} 

// ������������ͼ����ÿ��ͼ����һ���ַ�������
vector<string> vcat(const vector<string>& top, 
				    const vector<string>& bottom) {
	// ���ƶ��� 
	vector<string> ret = top;
	// ���Ƶײ�
	//for (vector<string>::size_type i=0; i<bottom.size(); ++i)
	//	ret.push_back(bottom[i]);
	#if 0
	// �õ�����
	for (vector<string>::const_iterator it = bottom.begin(); 
			it != bottom.end(); ++it) 
		ret.push_back(*it);
	#else
	// ��ʹ��ѭ��
	ret.insert(ret.end(), bottom.begin(), bottom.end()); 
	#endif
	return ret;
}
 
// ������������ͼ��string ������ 
vector<string> hcat(const vector<string>& left, 
				    const vector<string>& right) {
	vector<string> ret;
	
	// �� width �� 1������ͼ�м��1���ո�
	string::size_type width_l = max_width(left)+1;
	
	#if 0
	// ���ڱ��� left �� right ������
	vector<string>::size_type i, j; 
	 
	i = 0;
	j = 0; 
	// ����ʽ���Ѿ������� i �� j �� 
	while(i != left.size() || j != right.size()) {
		
		// ���ڴ洢���� ������
		string s;
		
		// �����ͼû�н��������Ƶ�����
		if (i!=left.size()) 
			s = left[i++];
		// ���һ���Ŀո�
		s += string(width_l - s.size(), ' ');
		// �����ͼû�н��������Ƶ�����β
		if (j!=right.size()) 
			s += right[j++];
		// ������ӵ��µ�ͼ��
		ret.push_back(s); 
	}
	
	#else // ʹ�õ����� 
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






