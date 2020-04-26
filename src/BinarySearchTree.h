#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
using namespace std;

template <typename DataType>
class BinarySearchTree
{
public:
   class Node
   {
   private:
      DataType data;
      Node* pLeft;
      Node* pRight;

   public:
      Node(DataType value) : data(value), pLeft(nullptr), pRight(nullptr) {};
      ~Node() {};

      void setData(DataType value) { data = value; }
      DataType getData() { return data; }

      void setLeftPtr(Node* ptr) { pLeft = ptr; }
      Node* getLeftPtr() { return pLeft; }

      void setRightPtr(Node* ptr) { pRight = ptr; }
      Node* getRightPtr() { return pRight; }
   };

private:
   Node* m_pRoot;

public:
   BinarySearchTree();
   ~BinarySearchTree();

   BinarySearchTree(const BinarySearchTree<DataType>&) = delete;
   BinarySearchTree& operator=(const BinarySearchTree<DataType>&) = delete;

   Node* getRootPtr() { return m_pRoot; };
   void setRootPtr(Node* ptr) { m_pRoot = ptr; };

   Node* insertNode(Node* root, DataType data);
   Node* searchNode(Node* root, DataType data);
   Node* deleteNode(Node* root, DataType data);
   Node* findMinNode(Node* root);

   void traverseInOrder(Node* root);
   void traversePreOrder(Node* root);
   void traversePostOrder(Node* root);

   void deleteTree();

private:
   void deleteTree(Node* root);

};

template <typename DataType>
BinarySearchTree<DataType>::BinarySearchTree() : m_pRoot(nullptr)
{
}

template <typename DataType>
BinarySearchTree<DataType>::~BinarySearchTree()
{
   deleteTree();
}

template <typename DataType>
typename BinarySearchTree<DataType>::Node* BinarySearchTree<DataType>::insertNode(Node* root, DataType data)
{
   if (root == nullptr)
   {
      root = new Node(data);
      return root;
   }

   if (data < root->getData())
   {
      root->setLeftPtr(insertNode(root->getLeftPtr(), data));
   }
   else if (data > root->getData())
   {
      root->setRightPtr(insertNode(root->getRightPtr(), data));
   }

   return root;
}

template <typename DataType>
typename BinarySearchTree<DataType>::Node* BinarySearchTree<DataType>::searchNode(Node* root, DataType data)
{
   // if root is null or key is present at root
   if ((root == nullptr) || (root->getData() == data))
      return root;

   if (data < root->getData())
      return searchNode(root->getLeftPtr(), data);
   else
      return searchNode(root->getRightPtr(), data);
}

template <typename DataType>
typename BinarySearchTree<DataType>::Node* BinarySearchTree<DataType>::deleteNode(Node* root, DataType data)
{
   if (root == nullptr)
      return nullptr;

   if (data < root->getData())
   {
      root->setLeftPtr(deleteNode(root->getLeftPtr(), data));
   }
   else if (data > root->getData())
   {
      root->setRightPtr(deleteNode(root->getRightPtr(), data));
   }
   else
   {
      if ((root->getLeftPtr() == nullptr) && (root->getRightPtr() == nullptr)) // no children
      {
         delete root;
         root = nullptr;
      }
      else if (root->getLeftPtr() == nullptr) // one right child
      {
         Node* temp = root;
         root = root->getRightPtr();
         delete temp;
      }
      else if (root->getRightPtr() == nullptr) // one left child
      {
         Node* temp = root;
         root = root->getLeftPtr();
         delete temp;
      }
      else // two children
      {
         Node* temp = findMinNode(root->getRightPtr()); // find minimal value of the right sub tree
         root->setData(temp->getData());
         root->setRightPtr(deleteNode(root->getRightPtr(), temp->getData()));
      }
   }

   return root;
}

template <typename DataType>
typename BinarySearchTree<DataType>::Node* BinarySearchTree<DataType>::findMinNode(Node* root)
{
   if (root == NULL)
   {
      return nullptr;
   }

   if (root->getLeftPtr() != NULL)
   {
      return findMinNode(root->getLeftPtr()); // left tree is smaller
   }

   return root;
}

//  InOrder (Left, Root, Right)
template <typename DataType>
void BinarySearchTree<DataType>::traverseInOrder(Node* root)
{
   if (root == nullptr)
      return;

   traverseInOrder(root->getLeftPtr());
   cout << root->getData() << " ";
   traverseInOrder(root->getRightPtr());
}

// PreOrder (Root, Left, Right)
template <typename DataType>
void BinarySearchTree<DataType>::traversePreOrder(Node* root)
{
   if (root == nullptr)
      return;

   cout << root->getData() << " ";
   traversePreOrder(root->getLeftPtr());
   traversePreOrder(root->getRightPtr());
}

// PostOrder (Left, Right, Root)
template <typename DataType>
void BinarySearchTree<DataType>::traversePostOrder(Node* root)
{
   if (root == nullptr)
      return;

   traversePostOrder(root->getLeftPtr());
   traversePostOrder(root->getRightPtr());
   cout << root->getData() << " ";
}

template <typename DataType>
void BinarySearchTree<DataType>::deleteTree(Node* root)
{
   if (root == nullptr) return;

   deleteTree(root->getLeftPtr());
   deleteTree(root->getRightPtr());

    delete root;
}

template <typename DataType>
void BinarySearchTree<DataType>::deleteTree()
{
   deleteTree(m_pRoot);
   m_pRoot = nullptr;
}

#endif /* BINARYSEARCHTREE_H_ */
