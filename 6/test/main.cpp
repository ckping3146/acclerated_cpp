#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cctype>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

#if 1
// 另一个版本的 spilt
//template <typename T>
bool space(char c) {
	return isspace((char)c);
}
//template <typename T>
bool no_space(char c) {
	return !isspace((char)c);
}
 
vector<string> split(string s) {
	typedef string::const_iterator sciter;
	vector<string> ret;

	sciter i = s.begin();
	while(i != s.end()) {
		// 忽略前面的空白
		i = find_if(s.begin(), s.end(), no_space); 
	}
}
#endif

// 判断回文
bool is_plalindrome(const string& s) {
	return equal(s.begin(), s.end(), s.rbegin());
}

// 查找url
// 判断字符是否是url合法字符
bool not_url_char(char c) {
	static const string url_ch = "~!@#$^&*()_+-=,.;'/[]|}{:?><";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}
// 查找url 的尾部
string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
	return find_if(b,e,not_url_char);
}
// 查找url 的协议头
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
	static const string sep = "://";

	typedef string::const_iterator iter;
	iter i = b;

	// 在[b,e)中查找第一个sep
	while((i=search(b,e,sep.begin(), sep.end())) != e) {
		// 确保sep不在头或尾
		if (i != b && i+sep.size() != e) {
			// beg 标记协议头的开头
			iter beg = i;
			while(beg != b && isalpha(beg[-1])) 
				--beg;
			// 确保sep前后都至少有一个字符
			if (b != i && !not_url_char(i[sep.size()])) {
				cout << *beg << endl;
				return beg;
			}
			if (i != e) {
				i += sep.size();
			}
		}
	}
	return e;
}
// 查找url
vector<string> find_url(const string& s) {
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while(b != e) {
		// 后面紧跟着 :// 的几个字符的开头
		cout << "start find url begind." << endl;
		b = url_beg(b,e);
		//if (i != e) i+=1;
		
		if (b != e) {
			cout << "\t find a url." << endl;
			// 记录 url end
			iter after = url_end(b, e);
			cout << after[0] << after[1] << after[2] << endl;
			ret.push_back(string(b, after));

			b = after;
		} 
	}
	return ret;
}

int main(int argc, char** argv) {
	#if 0
	string hw = "Hello Wordl!";
	string hh = "HAHAHHAAHHAHA!";
	string hw1 = "asdfgfdsa";
	
	cout << hw << (is_plalindrome(hw) ? " is " : " isn\'t ") << "a plalindrome." << endl; 
	cout << hw1 << (is_plalindrome(hw1) ? " is " : " isn\'t ") << "a plalindrome." << endl;   
	#endif
	#if 1
	const string str = "He added that they should step up coordination at the United Nations Security Council and work together to safeguard the legitimate interests of developing countries, including Africannations.https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx 123123adf.";
	vector<string> urls = find_url(str);
	cout << "All urls num:" << urls.size() << endl;
	for (vector<string>::const_iterator i = urls.begin(); i!=urls.end(); ++i) {
		cout << *i << endl;
	}
	#endif

	

	return 0;
}
