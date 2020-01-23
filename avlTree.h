#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include "book.h"
using namespace std;

struct NodeType
{
  Book info;
  int height;
  NodeType *leftLink;
  NodeType *rightLink;

  NodeType(Book info)
  {
    this->info = info;
    height = 1;
    leftLink = nullptr;
    rightLink = nullptr;
  }
};





class AvlTree
{
private:
  NodeType *root;


  void copyTree(NodeType *&copiedTreeRoot, NodeType *otherTreeRoot);
  void destroyTree(NodeType*&p);

  NodeType* rightRotate(NodeType *y);
  NodeType* leftRotate(NodeType *x);
  int getBalanceFactor(NodeType *n);

  int getTreeHeight(NodeType *p) const;
  NodeType* updateHeight(NodeType *p);

  NodeType* getMinimumNode(NodeType *p);
  NodeType* getMaximumNode(NodeType *p);

  int getTreeNodeCount(NodeType *p) const;
  int getTreeLeavesCount(NodeType *p) const;

  void inOrderTraversal(NodeType *p);
  void preOrderTraversal(NodeType *p);
  void postOrderTraversal(NodeType *p);

  int getMax(int x, int y) const;

  NodeType* insert(NodeType *node, const Book& insertItem);
  NodeType* deleteNode(NodeType *&p, const Book& deleteItem);



public:
  AvlTree();
  AvlTree(const AvlTree& otherTree);
  AvlTree(AvlTree&& otherTree);
  ~AvlTree();

  bool isEmpty() const;

  int getTreeHeight() const;
  int getTreeNodeCount() const;
  int getTreeLeavesCount() const;

  bool search(const Book& searchItem);
  void destroyTree();
  void print();

  void inOrderTraversal();
  void preOrderTraversal();
  void postOrderTraversal();

  void insert(const Book& insertItem);
  void deleteNode(const Book& deleteItem);

  const AvlTree& operator = (const AvlTree& otherTree);
  const AvlTree& operator = (AvlTree&& otherTree);
};









#endif
