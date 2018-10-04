#include"BinarySearchTree.h"

template<class T>
BSTNode<T>* BST<T> ::Find_node(T val)
{

    BSTNode<T>* node_ptr = root;

    while(node_ptr != NULL)
    {
        if(node_ptr->data == val)
        {break;}
        else if(node_ptr->data > val)
        {
           node_ptr = node_ptr->left;

        }
        else
        {
          node_ptr = node_ptr->right;
        }

    }


  return node_ptr;

}



template<class T>

bool Node_exists(T val)
{
  return (Find_node(val) != NULL);
}

template<class T>


void BST<T> :: Insert_node(T val)
{

   BSTNode<T>* node_ptr = Find_node(val);

   if(node_ptr != NULL)
   {
     cout<<"Node already exists. so we insert it as a duplicate";
     node_ptr->num_of_duplicates++;

   }
   else
   {

         BSTNode<T>* new_bstnode = new BSTNode<T>(val);

         if(root == NULL)
           return;


         BSTNode<T>* tmp = root;

         while(true)
         {

             if(tmp->data > val)
             {
                  if(tmp->left == NULL)
                  {
                     tmp->left = new_bstnode;
                     break;
                  }
                  else
                  {
                    tmp = tmp->left;

                  }
             }
             else if(tmp->data < val)
             {
                  if(tmp->right == NULL)
                  {
                     tmp->right = new_bstnode;
                     break;
                  }
                  else
                  {
                    tmp = tmp->right;

                  }
             }
         }

   }

Size_++;
}

template<class T>

BSTNode<T>* BST<T> :: Get_parent(BSTNode<T>* node)
{
      if(node == root)
      {
        return NULL;

      }

      BSTNode<T>* tmp = root;


      while(tmp->left != node && tmp->right != node)
      {

              if(tmp->data > node->data)
              {
                tmp = tmp->left;
              }
              else
              {
                  tmp = tmp->right;

              }

      }


      return tmp;
}


template<class T>

void BST<T> :: Inorder_traversal(BSTNode<T>* Root)
{


   if(Root == NULL)
    return;

   Inorder_traversal(Root->left);

   cout<<Root->data<<" ";

   Inorder_traversal(Root->right);

}


template<class T>

void BST<T> :: Preorder_traversal(BSTNode<T>* Root)
{


   if(Root == NULL)
    return;


   cout<<Root->data<<" ";
   Breorder_traversal(Root->left);
   Breorder_traversal(Root->right);

}

template<class T>

void BST<T> :: Postorder_traversal(BSTNode<T>* Root)
{


   if(Root == NULL)
    return;



   Postorder_traversal(Root->left);
   Postorder_traversal(Root->right);
   cout<<Root->data<<" ";

}


template<class T>
void BST<T> :: BST_traversal_wrapper(string traverse_type)
{
    if(traverse_type == "inorder")
    {
        Inorder_traversal(root);
    }
    else if(traverse_type == "preorder")
    {
      Preorder_traversal(root);

    }
    else if(traverse_type == "postorder")
    {
      Postorder_traversal(root);
    }
    else
    {
     cout<<"not valid traversal type"<<'\n';
    }

}


template<class T>

void BST<T> :: Delete_leaf_node(BSTNode<T>* node)
{

  BSTNode<T>* parent_node = Get_parent(node);

  if(parent_node != NULL)
{

  if(parent_node->left == node)
  {

     parent_node->left = NULL;

  }
  else{
      parent_node->right = NULL;

  }
}
else
{
  root = NULL;
}



delete node;

Size_ --;

}

template<class T>

void BST<T> :: Delete_node_wth_one_child(BSTNode<T>* node)
{
    //get the parent node
    BSTNode<T>* parent_node = Get_parent(node);

    //get a pointer of the child

    BSTNode<T>* child_node  = NULL;

    if(node->left != NULL)
    {

       child_node = node->left;

    }
    else
    {
      child_node = node->right;
    }



    if(parent_node != NULL)
    {

         if(parent_node->left == node) //if node is a left child
         {

               parent_node->left = child_node;


         }
         else if(parent_node->right == node) //if it's a right child
         {
           parent_node->right = child_node;
         }

    }
    else
    {

      if(node->left != NULL)
      {
           root = node->left;

      }
      else
      {
        root = node->right;
      }


    }

delete node;
Size_--;

}

template<class T>
void BST<T> :: Delete_node_wth_two_children(BSTNode<T>* node)
{

       BSTNode<T>* inorder_successor = node->right;

       while(inorder_successor->left != NULL)
       {
           inorder_successor = inorder_successor->left;
       }

      //save the value of the inorder successor

      T inorder_succ_data = inorder_successor->data;


      //delete the inorder successor (we know for sure that the inorder successor  has one child or none)


      if(inorder_successor->left == NULL && inorder_successor->right == NULL)
      {
        Delete_leaf_node(inorder_successor);
      }
      else
      {
        Delete_node_wth_one_child(inorder_successor);
      }

      //assign the value of the inorder successor to the node we want to delete(we are not deleting the node
      //we are only changing its value)

     node->data = inorder_succ_data;
     Size_++; //because  theoritically we didn't delete the inorder successor.
     Size_ --;


}

template<class T>

void BST<T> :: Delete_node_wrappper(T val)
{

      if(!Node_exists(val))
      {
        cout<<"value doesn't exist. can't remove"<<'\n';
        return;
      }

        BSTNode<T>* current_node = Find_node(val);

        //categoriza the node according to the number of children

        // if node has no children

        if(current_node->left == NULL && current_node->right == NULL)
        {
          Delete_leaf_node(node);

        }
        else if( (current_node->left == NULL && current_node->right != NULL) || (current_node->left != NULL && current_node->right ==NULL ) )
        {

          Delete_node_wth_one_child(current_node);

        }
        else
        {
          Delete_node_wth_two_children(current_node);

        }



}











