#ifndef __calc_h__
#define __calc_h__

#include <string>
#include <vector>

typedef struct {
    string s;
    int count;
} words_info;

/* 从流读取单词保存在向量中 */
std::vector<std::string> readwords(std::istream& in);


#endif
