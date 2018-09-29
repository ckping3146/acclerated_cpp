#ifndef __Str_hpp__
#define __Str_hpp__

#include <iostream>
#include <memory>
#include "Vec.hpp"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



// 简单的string 类
class Str{
public:
    typedef Vec<char>::size_type size_type;
    // 默认的构造函数，生成空Str
    Str() {  }
    // 构造函数： 生成一个Str对象，包含c的n个复件
    Str(size_type n, char c):data(n,c) {  }
    //  构造函数： 生成一个Str对象，并用一个空字符结尾的字符串初始化
    Str(const char * p) ;
    // 构造函数: 生成一个对象并用迭代器b和e之间的内容对它进行初始化
    template <class In> Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    //  索引运算符
    char& operator[](size_type i) {return data[i];}
    const char& operator[](size_type i) const {return data[i];}

    size_type size() const { return data.size(); }

private:
	Vec<char> data;
};

std::istream operator>>(std::istream&, Str&);
std::ostream operator<<(std::ostream&, const Str&);

#endif
