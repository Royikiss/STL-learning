/*************************************************************************
        > File Name: vector.cpp
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Sat 08 Jun 2024 09:55:34 PM HKT
      > Describe:
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <list>
#include <system_error>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <cmath>
#include <string>
#include <sstream>
#include <functional>

namespace my {

template <typename T>
class vector {
typedef T * iterator; 
public :
    vector(size_t size = 2) : __size(size) {
        data = (T *)malloc(sizeof(T) * __size);
        _Finish = data + __size;
        _M_pos = data;
    }
    vector(const vector &v) {
        __size = v.__size;
        data = (T *)malloc(sizeof(T) * __size);
        for (size_t i = 0; i < v.size(); ++i) {
            new(data + i) T(v[i]); 
        }
        _Finish = data + __size;
        _M_pos = data + v.size();
    }
    vector(vector &&v) {
        __size  = v.__size;
        data    = v.data;
        _M_pos  = v._M_pos;
        _Finish = v._Finish;
        v.data  = v._M_pos = v._Finish = v._M_pos = nullptr;
    }
    
    ~vector() {
        if (data == nullptr) return ; 
        for (size_t i = 0; i < __size; ++i) {
            data[i].~T();
        }
        free(data);
        return ;
    }

    iterator begin() const { return data; } 
    iterator end() const { return _M_pos; } 
    
    T &operator[](size_t ind) const {
        return data[ind];
    }
    
    size_t size() { return _M_pos - data; }
    
    void push_back(const T &obj) {
        if (_M_pos == _Finish && !__expand()) {
            std::cout << "expand faild!" << std::endl;
            return ;
        }
        new(_M_pos) T(obj);
        _M_pos += 1;
        return ;
    }

private :
    size_t __size;
    T *data;
    T *_M_pos, *_Finish;
    
    bool __expand() {
        T *p = (T *)realloc(data, sizeof(T) * __size * 2);
        if (p == nullptr) { return false; }
        size_t offset = _M_pos - data;
        __size *= 2;
        data = p;
        _M_pos = data + offset;
        _Finish = data + __size;
        return true;
    }
    
};
}

int main() {
    #define MAX_N 10
    srand(time(0));

    my::vector<int> v1;

    for (int i = 1; i <= MAX_N; ++i) {
        v1.push_back(rand() % 100);
    }
    
    for (auto x : v1) {
        std::cout << x << ' ';
    }

    return 0;
}
