#include <iostream>
#include <cstdlib>
#include <memory>
#include "Vec.hpp"

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	// 判断是否进行自我赋值
	if (&rhs != this) {
		// 删除运算符左侧的数组
		uncreate();
		// 从右侧复制元素到左侧
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T> void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type size, const T& t) {
	data = alloc.allocate(size);
	limit = avail = data+size;
	uninitialized_fill(data, limit, t);
}

template <class T> void Vec<T>::create(
	Vec<T>::const_iterator b, Vec<T>::const_iterator e) {
	data = alloc.allocate(e-b);
	limit = avail = uninitialized_copy(b, e, data);
}

template <class T> void Vec<T>::uncreate() {
	if (data) {
		iterator it = avail;
		while(it != data) 
			alloc.destroy(--it);
		
		alloc.deallocate(data, limit-data);
	}

	data = avail = limit = 0;
}

template <class T> void Vec<T>::grow() {
	// 在扩展对象大小的时候，为对象分配实际使用的两倍大小的内存
	size_type new_size = max(2*(limit-data), ptrdiff_t(1));
	//  分配新的内存空间并将已存在的对象元素内容复制到新内存中
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(data, avail, new_data);
	// 返回原来的内存空间
	uncreate();
	// 重置指针，使其指向新分配的内存空间
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// 假设avail 指向一片新分配但未被初始化的内存空间
template <class T> void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}



