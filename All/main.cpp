
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

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
#if 0 /* 3.3 把一个整数集合分为四部分，每部分的数值比其它各部分都大 */
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
#if 1 /*  */
#endif



    system("pause");
    return 0;
}






