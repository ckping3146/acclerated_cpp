
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include "calc.h"

using namespace std;


int main(int argc, char ** argv) {

#if 0 /* 2.5 使用 * 输出 三角形，正方形， 长方形 */
    const int rect_w = 10, rect_h = 6, tri_l = 8;

    const string rect_line = string(rect_w, '*');
    cout << "Square : " << endl;
    for (int i = 0; i != rect_w; ++i) 
        cout << rect_line << endl;
    cout << "Rectangle : " << endl;
    for (int i = 0; i != rect_h; ++i) 
        cout << rect_line << endl;
    
#endif   
#if 0 /* 2.7 编写程序依次输出 10 ~ -5 的整数 */
    int x = 10;
    cout << x--;
    while(x >= -5)
        cout << ", " << x--;
    cout << endl;
#endif
#if 0 /* 2.8 编写一个程序输出 区间[1, 10)中数的乘机 */
    int sam = 1;
    for (int i = 1; i != 10; ++i) 
        sam *= i;
    cout << sam << endl;
#endif
#if 0 /* 2.9 让用户输入两个数值，并告诉用户哪个大 */
    int a, b;
    cout << "Plz input 2 interges:" << endl; // , end with end-of-file
    cin >> a >> b;
    cout << endl;
    cout << ((a==b)?"The intergers is same.":"Not the same")<< endl;

#endif
///===============================================================
#if 0 /* 3.2 把一个整数集合分为四部分，每部分的数值比其它各部分都大 */
    cout << "Plz input some integers:" << endl;
    vector<int> collects;
    int rec;
    while (cin >> rec) {
        collects.push_back(rec);
    }
    if (0 == collects.size()) {
        cout << "No inputs!" << endl;
        return -1;
    }
    while(collects.size() % 4 != 0) 
        collects.push_back(0); // 使集合能被4除尽
    
    sort(collects.rbegin(), collects.rend());
    //sort(collects.begin(), collects.end());
    vector<int>::size_type part_size = collects.size() / 4;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<part_size; ++j) {
            cout << collects[i*part_size + j] << "\t";
        }
        cout << endl;
    }
#endif
#if 0 /* 3.3 编写一个程序来计算它的输入中每个不同的单词所出现的次数 */
    cout << "Plz input some words, end with end-of-file:" << endl;
    //cout << endl;
    typedef string::size_type ssize;
    vector<string> words;
    vector<ssize> counts;
    string record;
    string::size_type maxlen = 0;
    while(cin >> record) {
        if(words.end() == find(words.begin(), words.end(), record)) {
            maxlen = max(maxlen, record.size());
            words.push_back(record);
            counts.push_back(1);
        }
        else {
            vector<string>::size_type pos ;
            for (pos=0; pos<words.size(); ++pos) {
                if (words[pos] == record)
                    break;
            }
            if(pos != words.size())
                counts[pos] ++;
        }
    }
    vector<string>::const_iterator it;
    vector<ssize>::const_iterator iit;
    for (it = words.begin(), iit=counts.begin();
            it != words.end(), iit!=counts.end(); ++it, ++iit) {
        // construct output string
        string out = string(maxlen - it->size(), ' ');
        out += *it;
        out += '\t';
        cout << out << *iit << endl;
    }
    // ctrl^Z 结束字符串的输入
#endif
#if 0 /* 3.4 编写程序报告输入中最长及最短字符串及其长度 */
    string maxstr, minstr;
    string::size_type mx=0, mn=0;
    cout << "Strs:";
    string s;
    cin >> s;
    mx = mn = s.size();
    while(cin >> s) {
        if (s.size() > mx) {
            maxstr = s;
            mx = s.size();
        }
        else if (s.size() < mn) {
            minstr = s;
            mn = s.size();
        }
    }
    cout << "Max: " << maxstr << "\t" << mx << endl;
    cout << "Min: " << minstr << "\t" << mn << endl;
#endif


    system("pause");
    return 0;
}






