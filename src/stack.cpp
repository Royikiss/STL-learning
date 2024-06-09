/*************************************************************************
        > File Name: stack.cpp
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Sat 08 Jun 2024 01:05:46 PM HKT
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

#define _PrintLine_(str) \
    for (int i = 0; i < 20; ++i) { \
      std::cout << '='; \
    } \
    std::cout << #str; \
    for (int i = 0; i < 20; ++i) { \
      std::cout << '='; \
    } \
    std::cout << std::endl;

namespace my {

template <typename T>
class _deque_node {
  typedef _deque_node _node;
public:
  _deque_node() : _data(new T()), _prev(nullptr), _next(nullptr) {}
  _deque_node(T &data) : _data(new T(data)), _prev(nullptr), _next(nullptr) {}
  _deque_node(T &&data) : _data(new T()), _prev(nullptr), _next(nullptr) {
    *_data = data;
  }
  ~_deque_node() {
    delete _data;
    _prev = nullptr;
    _next = nullptr;
  }

  T *_data;
  _node *_prev;
  _node *_next;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, _deque_node<T> &node) {
  out << *node._data;
  return out;
}

template <typename T>
class _deque_node_iterator {
typedef _deque_node<T> * iterator;
public:
  _deque_node_iterator() : _ptr(nullptr) {}
  _deque_node_iterator(iterator ptr) : _ptr(ptr) {}
  _deque_node_iterator(_deque_node_iterator &ptr) : _ptr(ptr) {}

  bool operator==(const _deque_node_iterator &obj) const {
    return _ptr == obj._ptr;
  }
  
  bool operator!=(const _deque_node_iterator &obj) const {
    return !this->operator==(obj);
  }
  
  iterator &operator++() {
    _ptr = _ptr->_next;
    return _ptr;
  }
  
  iterator operator++(int) {
    new iterator(_ptr);
    _ptr = _ptr->_next;
    return _ptr;
  }
  
  iterator &operator--() {
    _ptr = _ptr->_prev;
    return _ptr;
  }

  iterator operator--(int) {
    new iterator(_ptr);
    _ptr = _ptr->_prev;
    return _ptr;
  }
  
  T &operator*() {
    return *_ptr->_data;
  }
  
  
private:
  iterator _ptr;
};

template <typename T>
class deque {
typedef _deque_node<T> _node;
typedef _deque_node_iterator<T> iterator;
public:
  deque() : _head(new _node()), _tail(_head), _size(0) {}
  

  size_t size() const {
    return _size;
  }

  bool empty() const {
    return _size == 0;
  }

  _node &front() {
    return *_head->_next;
  }

  _node &back() {
    return *_tail;
  }

  void push_front(T &data) {
    _node *new_node = new _node(data);
    new_node->_next = this->_head->_next;
    this->_head->_next->_prev = new_node;
    this->_head->_next = new_node;
    new_node->_prev = this->_head;
    _size += 1;
  }

  void push_back(T &data) {
    _node *new_node = new _node(data);
    this->_tail->_next = new_node;
    new_node->_prev = this->_tail;
    this->_tail = new_node;
    _size += 1;
  }
  
  void pop_front() {
    if (empty()) return ;
    if (this->_size == 1) {
      delete this->_tail;
      this->_tail = this->_head;
    } else {
      _node *old_node = this->_head->_next;
      this->_head->_next = old_node->_next;
      old_node->_next->_prev = this->_head;
      delete old_node;
    }
    _size -= 1;
  }

  void pop_back() {
    if (empty()) return ;
    _node *old_node = this->_tail;
    this->_tail = old_node->_prev;
    this->_tail->_next = nullptr;
    delete old_node;
    _size -= 1;
  }

  iterator begin() const {
    return this->_head->_next;
  }

  iterator end() const {
    return this->_tail->_next;
  }

  void clear() {
    _node *cur = this->_head->_next;
    _node *old = this->_head;
    while(!empty()) {
      pop_back();
    }
  }

private:
  size_t _size;
  _node *_head; // 虚拟头节点 
  _node *_tail;
};

template <typename T>
class stack {
typedef _deque_node<T> _node;
public:
  stack() = default;
  ~stack() = default;

  void push(T &data) {
    deque.push_back(data);
  }

  void pop() {
    deque.pop_back();
  }

  _node &top() {
    return deque.back();
  }

  bool empty() const {
    return deque.empty();
  }

  size_t size() const {
    return deque.size();
  }
  
  void clear() {
    deque.clear();
    return ;
  }

private:
  my::deque<T> deque;
};

}

int main() {
  my::stack<int> st;
  _PrintLine_("init");
  for (int i= 0; i < 10; ++i) {
    st.push(i);
  }
  
  _PrintLine_("pop and top");
  for (int i = 0; i < 10; ++i) {
    std::cout << st.top() << ' ';
    st.pop();
  }
  std::cout << std::endl;

  _PrintLine_("clear");
  st.clear();
  _PrintLine_("empty");
  if (st.empty()) {
    std::cout << "empty" << std::endl;
  } else {
    std::cout << "not empty" << std::endl;
  }
  
  std::cout << "st.size() = " << st.size() << std::endl;
  
  return 0;
}
