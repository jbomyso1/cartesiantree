#ifndef CARTESIAN_H_
#define CARTESIAN_H_

#include "node.h"
#include <iostream>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

template <class T>
class cartesian
{
 public:
  int minValue(std::vector<std::pair<double, T> > vct, int start, int end);
  void insert(std::vector<std::pair<double, T> > vct);
  void inorder();
  node<T>* search(double key);
  //delete key
  void sortVector(std::vector<std::pair<double, T> > &vct);
 private:
  node<T> *root;
  node<T>* insert(std::vector<std::pair<double, T> > vct, int start, int end);
  void inorder(node<T> *nd);
  node<T>* search(node<T> *nd, double key);
  void fillVector(node <T> *nd, std::vector<std::pair<double, T> > &vct);
};

template <class T>
struct pair_comp{
  bool operator()(std::pair<double, T> const &lhs, std::pair<double, T> const &rhs)
  {
    return lhs.first < rhs.first;
  }
};

#include "cartesian.cpp"
#endif			
