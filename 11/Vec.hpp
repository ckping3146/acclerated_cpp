#ifndef __Vec_hpp__
#define __Vec_hpp__

#include <iostream>
#include <memory>

template <class T> 
class Vec{
public:
	//接口
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	// 构造函数
	Vec() { create(); }
	explicit Vec(size_type n, const T& val=T()) { create(n, val); }
	// 大小与索引
	size_type size() const { return limit-data; }
	T& operator[](size_type i) { return data[i]; }
	const T& operator[](size_type i) const { return data[i]; }
	// 迭代器函数
	iterator begin() {return data;}
	const_iterator begin() const {return data;}
	iterator end() {return limit;}
	const_iterator end() const {return limit;}
	// 复制构造函数
	Vec (const Vec& v) { create(v.begin(), v.end()); } 
	// 赋值运算符
	Vec& operator=(const Vec&);
	// 析构函数
	//~Vev() { uncreate(); }
	// 
	void push_back(const T& val) {
		if (avail == limit) 
			grow();
		unchecked_append(val);
	}
private:
	//实现
	iterator data;	// vec 中的首元素
	iterator avail;	// 指向构造元素末元素后面的一个元素
	iterator limit;	// 指向最后一个可获得元素后面的一个元素

	// 内存分配工具
	std::allocator<T> alloc;	// 控制内存分配的对象

	// 为底层的数组分配内存并对它们初始化
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// 删除数组中的元素并释放其占用的内存
	void uncreate();

	// 支持Push_back 的函数
	void grow();
	void unchecked_append(const T&);
};

#endif
