#include "BinarySearchTree.h"

int main()
{
   BinarySearchTree<int> numBstTree;
   numBstTree.setRootPtr(numBstTree.insertNode(nullptr, 8));
   numBstTree.insertNode(numBstTree.getRootPtr(), 3);
   numBstTree.insertNode(numBstTree.getRootPtr(), 10);
   numBstTree.insertNode(numBstTree.getRootPtr(), 1);
   numBstTree.insertNode(numBstTree.getRootPtr(), 6);
   numBstTree.insertNode(numBstTree.getRootPtr(), 14);
   numBstTree.insertNode(numBstTree.getRootPtr(), 4);
   numBstTree.insertNode(numBstTree.getRootPtr(), 7);
   numBstTree.insertNode(numBstTree.getRootPtr(), 7);

   numBstTree.traversePreOrder(numBstTree.getRootPtr());
   cout << endl;
   numBstTree.traverseInOrder(numBstTree.getRootPtr());
   cout << endl;
   numBstTree.traversePostOrder(numBstTree.getRootPtr());
   cout << endl;

   BinarySearchTree<int>::Node* node = numBstTree.searchNode(numBstTree.getRootPtr(), 4);
   if (node)
      cout << node->getData() << endl;

   numBstTree.deleteNode(numBstTree.getRootPtr(), 7);
   numBstTree.traversePreOrder(numBstTree.getRootPtr());
   cout << endl;

   numBstTree.deleteTree();
   numBstTree.traversePreOrder(numBstTree.getRootPtr());
   cout << endl;

   BinarySearchTree<float> floatBstTree;
   floatBstTree.setRootPtr(floatBstTree.insertNode(nullptr, 8.1));
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 8.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 3.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 10.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 1.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 6.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 14.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 4.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 7.1);
   floatBstTree.insertNode(floatBstTree.getRootPtr(), 7.1);

   floatBstTree.traversePreOrder(floatBstTree.getRootPtr());
   cout << endl;
   floatBstTree.traverseInOrder(floatBstTree.getRootPtr());
   cout << endl;
   floatBstTree.traversePostOrder(floatBstTree.getRootPtr());
   cout << endl;

   return 0;
}
