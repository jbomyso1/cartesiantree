#ifndef CARTESIAN_H_
#define CARTESIAN_H_

#include "node.h"
#include <iostream>
#include <vector>
#include <utility>
#include <limits>

template <class T>
class cartesian
{
 public:
  int minValue(std::vector<std::pair<double, T> > vct, int start, int end);
  void insert(std::vector<std::pair<double, T> > vct);
  void inorder();
  //search
  bool search(double key);
  //delete key
  //return sorted vector
 private:
  node<T> *root;
  node<T>* insert(std::vector<std::pair<double, T> > vct, int start, int end);
  void inorder(node<T> *nd);
  bool search(node<T> *nd, double key);
};

#include "cartesian.cpp"
#endif			
