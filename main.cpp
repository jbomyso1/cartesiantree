#include "cartesian.h"

int main()
{
  cartesian<int> cart;
  std::vector<std::pair<double, int> > pairs;

  pairs.push_back(std::make_pair(9,9));
  pairs.push_back(std::make_pair(3,3));
  pairs.push_back(std::make_pair(7,7));
  pairs.push_back(std::make_pair(1,1));
  pairs.push_back(std::make_pair(8,8));
  pairs.push_back(std::make_pair(12,12));
  pairs.push_back(std::make_pair(10,10));
  pairs.push_back(std::make_pair(20,20));
  pairs.push_back(std::make_pair(15,15));
  pairs.push_back(std::make_pair(18,18));
  pairs.push_back(std::make_pair(5,5));

std::cout << "calling insert" << std::endl;
  
  cart.insert(pairs);

  cart.inorder();

  return 0;
}
