/*************************************************************************
        > File Name: 3.my_shared_ptr.cpp
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Tue 18 Jun 2024 05:30:22 PM HKT
      > Describe:
 ************************************************************************/

#include <iostream>
#include <algorithm>
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

#define TEST_BEGINS(x) namespace x {
#define TEST_ENDS(x) } // end of namespace x

TEST_BEGINS(my) 

class A {
public:
    A() {
        std::cout << "default constructer" << std::endl;
    }
    ~A() {
        std::cout << "destructer" << std::endl;
    }
    int x, y;
};

template <typename T>
class _shared_ptr_data {
public:
    _shared_ptr_data(T *ptr, int *cnt = nullptr) : ptr(ptr), cnt(cnt) {
        if (this->cnt == nullptr) {
            this->cnt = new int(1);
        }
    }
    _shared_ptr_data(const _shared_ptr_data &obj) : ptr(obj.ptr), cnt(obj.cnt) {}
    ~_shared_ptr_data() {}
    void increase_one() const {
        *cnt += 1;
        return ;
    }
    void decrease_one() const {
        *cnt -= 1;
        if (*cnt == 0) {
            delete ptr;
        }
        return ;
    }

    bool operator==(const _shared_ptr_data &obj) const {
        return ptr == obj.ptr && cnt == obj.cnt;
    }

    T *ptr;
    int *cnt;
};

template <typename T>
class shared_ptr {
public:
    shared_ptr(T *ptr) : _ptr(ptr) {}
    shared_ptr(const my::shared_ptr<T> &p) : _ptr(p._ptr) {
        this->_ptr.increase_one();
    }

    
    shared_ptr<T> &operator=(const shared_ptr<T> &obj) {
        if (_ptr == obj._ptr)  {
            return *this;
        } 
        this->_ptr.decrease_one();
        _ptr = obj._ptr;
        this->_ptr.increase_one();
        return *this;
    }
    T *operator->() { return _ptr.ptr; }
    A &operator*() { return *(_ptr.ptr); }

    int use_count() { return *_ptr.cnt; }

private:
    _shared_ptr_data<T> _ptr;
};

template <typename T>
my::shared_ptr<T> make_shared() {
    return my::shared_ptr<T> (new T());
}

std::ostream &operator<<(std::ostream &out, A &obj) {
    out << '(' << obj.x << "," << obj.y << ')';
    return out;
}

TEST_ENDS(x)

int main() {
    my::shared_ptr<my::A> p = my::make_shared<my::A>();
    p->x = 3, p->y = 4;
    std::cout << *p << std::endl;
    std::cout << "p.use_count() = " << p.use_count() << std::endl;
    my::shared_ptr<my::A> q = p;
    std::cout << "p.use_count() = " << p.use_count() << std::endl;
    std::cout << "q.use_count() = " << q.use_count() << std::endl;
    p = nullptr;
    std::cout << "q.use_count() = " << q.use_count() << std::endl;
    q = nullptr;
    std::cout << "end main" << std::endl;
    
    return 0;
}
