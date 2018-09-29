#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <cstdlib> // rand [0, RAND_MAX] 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// �������뵥�ʵĸ���
using namespace std;


// �ָ�һ���ַ���
vector<string> split(const string& s) {
	vector<string> ret;
	string::const_iterator i = s.begin();
	string::const_iterator j;
	while(i != s.end()) {
		// ��λ��һ�������ײ� 
		while(isspace(*i) && i!=s.end()) ++i;
		j = i;
		while(!isspace(*j) && j != s.end()) ++j;
		if (j!=i && j!=s.end())
			ret.push_back(string(i, j));

		i = j;
	}
	return ret;
} 

// ����ָ��������ÿ�����ʵ�������
map<string, vector<int> > xref(istream& in, 
	vector<string> find_words(const string&) = split) {
	string line;
	int line_number = 0;
	map<string, vector<int> > ret;
	
	// ����һ�� 
	while(getline(in, line)) {
		++line_number;
		// �зָ�ɵ���
		vector<string> words = find_words(line);
		
		// ��ס��ǰ�е�ÿһ������
		for(vector<string>::const_iterator it = words.begin(); 
			it != words.end(); ++it) {
			ret[*it].push_back(line_number);	
		} 
		
	}
	return ret;
} 



// ��ɾ���
// the <���ʴ���> <����> <λ��>

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammer;

// ��һ���ض����������ж���һ���ķ� 
Grammer read_grammer(istream & in) {
	Grammer ret ;
	
	string line;
	
	// read line 
	while(getline(in, line)) {
		// �ָ�ɵ��� 
		vector<string> entry = split(line);
		
		if (!entry.empty()) {
			ret[entry[0]].push_back( Rule(entry.begin()+1, entry.end()) );
			// ����Ϊ  vector< vector<string> > , ÿ��Ԫ�ض��� vector<string>
			// Rule = vector<string>
			// string(b,e) �൱��һ���Ӵ�
			// ������ĸ�ʽӦ���ǣ� adj beautiful / addr on the ground 
		}
	}
	
	return ret;
} 

// �ж��Ƿ������� 
bool is_type(const string& s) {
	return s.size()>1 && s[0] == '<' && s[s.size()-1] == '>';
} 

// ���� [0,n) �е�һ���������
int nrand(int n) {
	if (n <=0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range.");
	
	const int bucket_size = RAND_MAX / n;
	int r;
	
	do r = rand() / bucket_size;
	while (r >= n);
	
	return r; 
} 

// �����ķ������չ������ɾ���
void gen_aux(const Grammer& g, const string& word, vector<string>& ret) {
	if (!is_type(word)) {
		ret.push_back(word);
	} else {
		// Ϊ��Ӧ��word�Ĺ���λ
		Grammer::const_iterator it = g.find(word);
		if (g.end() == it) 
			throw domain_error("Empty rule.");
		
		// ��ȡ���ܵĹ��򼯺�
		const Rule_collection& c = it->second;
		
		// �ӹ��򼯺������ѡȡһ������
		const Rule& r = c[nrand(c.size())];
		
		// �ݹ�չ����ѡ���Ĺ���
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) 
			gen_aux(g, *i, ret); 
	}
} 

// ���ɾ���
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
	
	// ������
	#if 1
	for (map<string, vector<int> >::const_iterator it = ret.begin();
		it != ret.end(); ++it) {
		
		// ������� 
		cout << it->first << "\t" << "occurs on line:" ;
			
		// ��������к�
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
	
	// �ķ�
	// ���ɾ���
	vector<string> sentence = gen_sentence(read_grammer(cin));
	
	
	
	
	
	return 0;
}
