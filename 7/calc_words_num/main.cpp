#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cstdlib> // rand [0, RAND_MAX] 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// 计算输入单词的个数
using namespace std;


// 分割一行字符串
vector<string> split(const string& s) {
	vector<string> ret;
	string::const_iterator i = s.begin();
	string::const_iterator j;
	while(i != s.end()) {
		// 定位第一个单词首部 
		while(isspace(*i) && i!=s.end()) ++i;
		j = i;
		while(!isspace(*j) && j != s.end()) ++j;
		if (j!=i && j!=s.end())
			ret.push_back(string(i, j));

		i = j;
	}
	return ret;
} 

// 查找指向输入中每个单词的所在行
map<string, vector<int> > xref(istream& in, 
	vector<string> find_words(const string&) = split) {
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;
	
	// 读入一行 
	while(getline(in, line)) {
		++line_number;
		// 行分割成单词
		vector<string> words = find_words(line);
		
		// 记住当前行的每一个单词
		for(vector<string>::const_iterator it = words.begin(); 
			it != words.end(); ++it) {
			ret[*it].push_back(line_number);	
		} 
		
	}
	return ret;
} 



// 组成句子
// the <名词词组> <动词> <位置>

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammer;

// 从一个特定的输入流中读入一个文法 
Grammer read_grammer(istream & in) {
	Grammer ret ;
	
	string line;
	
	// read line 
	while(getline(in, line)) {
		// 分割成单词 
		vector<string> entry = split(line);
		
		if (!entry.empty()) {
			ret[entry[0]].push_back( Rule(entry.begin()+1, entry.end()) );
			// 类型为  vector< vector<string> > , 每个元素都是 vector<string>
			// Rule = vector<string>
			// string(b,e) 相当于一个子串
			// 故输入的格式应该是： adj beautiful / addr on the ground 
		}
	}
	
	return ret;
} 

// 判断是否是种类 
bool is_type(const string& s) {
	return s.size()>1 && s[0] == '<' && s[s.size()-1] == '>';
} 

// 返回 [0,n) 中的一个随机整数
int nrand(int n) {
	if (n <=0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range.");
	
	const int bucket_size = RAND_MAX / n;
	int r;
	
	do r = rand() / bucket_size;
	while (r >= n);
	
	return r; 
} 

// 根据文法，按照规则生成句子
void gen_aux(const Grammer& g, const string& word, vector<string>& ret) {
	if (!is_type(word)) {
		ret.push_back(word);
	} else {
		// 为对应于word的规则定位
		Grammer::const_iterator it = g.find(word);
		if (g.end() == it) 
			throw domain_error("Empty rule.");
		
		// 获取可能的规则集合
		const Rule_collection& c = it->second;
		
		// 从规则集合中随机选取一条规则
		const Rule& r = c[nrand(c.size())];
		
		// 递归展开所选定的规则
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) 
			gen_aux(g, *i, ret); 
	}
} 

// 生成句子
vector<string> gen_sentence(const Grammer& g) {
	vector<string> ret;
	gen_aux(g, "<sentence>", ret);
	return ret;
} 

int main(int argc, char** argv) {
/*
	map<string, int> counters;
	string s;
	
	while(cin >> s) 
		++counters[s];
	
	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
*/

	/*
	cout << "test" << endl;
	map<string, vector<int> > ret = xref(cin);
	
	// 输出结果
	#if 1
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it) {
		
		// 输出单词 
		cout << it->first << "\t" << "occurs on line:" ;
			
		// 后面跟着行号
		vector<int>::const_iterator line_it = it->second.begin(); 
		cout << *line_it;
		
		++line_it;
		while(line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
		cout << endl;
	} 
	#endif
	 
	*/
	
	// 文法
	// 生成句子
	vector<string> sentence = gen_sentence(read_grammer(cin));
	
	
	
	
	
	return 0;
}
