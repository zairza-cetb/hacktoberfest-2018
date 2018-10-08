#include<iostream>

using namespace std;
template<class T>


class BSTNode
{
 public:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    int num_of_duplicates;

    BSTNode()
    {
         left= NULL;
         right = NULL;
         num_of_duplicates = 0;
    }
    BSTNode(T val)
    {
          left=right = NULL;
         data = val;
         num_of_duplicates = 0;

    }

};

template<class T>

class BST{

public:
    int Size_;
    BSTNode<T>* root;


   BST()
   {
      root = NULL;
      Size_ = 0;
   }
bool Node_exists(T val);
BSTNode<T>* Find_node(T val);

void Insert_node(T val);
void Delete_node(T val);
void Preorder_traversal(BSTNode<T>* Root);
void Postorder_traversal(BSTNode<T>* Root);
void Inorder_traversal(BSTNode<T>* Root);
void BST_traversal_wrapper(string traverse_type);
BSTNode<T>* Get_parent(BSTNode<T>* node);
void Delete_leaf_node(BSTNode<T>* node);
void Delete_node_wth_one_child(BSTNode<T>* node);
void Delete_node_wth_two_children(BSTNode<T>* node);
void Delete_node_wrapper(T val);


};
