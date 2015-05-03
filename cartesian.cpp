#include "cartesian.h"

//function finds the minimum value to keep the heap order, and so it'll print inorder the same way it went in, keeping cartesian tree property
template <class T>
int cartesian<T>::minValue(std::vector<std::pair<double, T> > vct, int start, int end)
{
  //will return -1 if there is an error in the variables passed in
  int minLocation = -1;
  double minValue = std::numeric_limits<double>::max();

  for(int i = start; i <= end; i++)
    {
      if(vct[i].first < minValue)
	{
	  minValue = vct[i].first;
	  minLocation = i;
	}
    }
  return minLocation;
}

//base insert function
template <class T>
void cartesian<T>::insert(std::vector<std::pair<double, T> > vct)
{
  if(vct.empty()) return;

  root = insert(vct, 0, vct.size() - 1);  
}

//recursive insert function
template <class T>
node<T>* cartesian<T>::insert(std::vector<std::pair<double, T> > vct, int start, int end)
{
  //base case
  if(end < start) return nullptr;

  //find the location of smallest value remaining
  int minLoc = minValue(vct, start, end);

  //set new node with the smallest remaining value
  node<T> *nn = new node<T>(vct[minLoc]);
  
  //recursive insert calls
  nn->left = insert(vct, start,(minLoc - 1));
  nn->right = insert(vct, (minLoc + 1), end);

  return nn;
}

//public in order call
template <class T>
void cartesian<T>::inorder()
{
  if(root == nullptr)
    return;

  inorder(root);
}

//recursive in order print function
template <class T>
void cartesian<T>::inorder(node<T> *nd)
{
  if(nd == nullptr) return;

  inorder(nd->left);
  std::cout << nd->data.first << " " << nd->data.second << std::endl;
  inorder(nd->right);
}

//search function
template <class T>
node<T>* cartesian<T>::search(double key)
{
  if(root == nullptr) return nullptr;

  return search(root, key);
}

//recursive search function
template <class T>
node<T>* cartesian<T>::search(node<T> *nd, double key)
{
  //base case
  if(nd == nullptr) return nullptr;
   
  //if found return the address
  if(nd->data.first == key)
    {
      return nd;
    }
  else
    {
      node<T> *tmp = nullptr;

      //since in min heap, check to see if key is greater than the data to stop checking in that direction
      if(nd->data.first < key)
	{
	  tmp = search(nd->left, key);

	  //if value not found on left, check right
	  if(tmp == nullptr)
	    {
	      tmp = search(nd->right, key);
	    }
	}
      return tmp;
    }
}
  
