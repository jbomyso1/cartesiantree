#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <utility>

template <class T>
struct node
{
  node *left;
  node *right;
  std::pair<double, T> data;
  node():left(nullptr), right(nullptr){}
  node(std::pair<double, T> dta):left(nullptr),right(nullptr),data(dta){}

};

#endif
