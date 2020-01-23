#include "avlTree.h"
using namespace std;


AvlTree::AvlTree()
{
  root = nullptr;
}


AvlTree::AvlTree(const AvlTree& otherTree)
{
  if (otherTree.root == nullptr)
  {
    root = nullptr;
  }
  else
  {
    copyTree(root, otherTree.root);
  }
}


AvlTree::AvlTree(AvlTree&& otherTree)
{
  if (otherTree.root == nullptr)
  {
    root = nullptr;
  }
  else
  {
    root = otherTree.root;

    delete otherTree.root;
  }
}


AvlTree::~AvlTree()
{
  destroyTree(root);
}


void AvlTree::copyTree(NodeType *&copiedTreeRoot, NodeType *otherTreeRoot)
{
  if (otherTreeRoot == nullptr)
  {
    copiedTreeRoot = nullptr;
  }
  else
  {
    copiedTreeRoot = new NodeType(otherTreeRoot->info);

    copyTree(copiedTreeRoot->leftLink, otherTreeRoot->leftLink);
    copyTree(copiedTreeRoot->rightLink, otherTreeRoot->rightLink);
  }
}


void AvlTree::destroyTree(NodeType*&p)
{
  if (p != nullptr)
  {
    destroyTree(p->leftLink);
    destroyTree(p->rightLink);
    delete p;
    p = nullptr;
  }
}


void AvlTree::destroyTree()
{
  destroyTree(root);
}




NodeType* AvlTree::rightRotate(NodeType *y)
{
  NodeType *x = y->leftLink;
  NodeType *z = x->rightLink;

  // perform rotation
  x->rightLink = y;
  y->leftLink = z;

  // update height
  updateHeight(y);
  updateHeight(x);

  // return new root
  return x;
}


NodeType* AvlTree::leftRotate(NodeType *x)
{
  NodeType *y = x->rightLink;
  NodeType *z = y->leftLink;

  // perform rotation
  y->leftLink = x;
  x->rightLink = z;

  // update height
  updateHeight(x);
  updateHeight(y);

  // return new root
  return y;
}


int AvlTree::getBalanceFactor(NodeType *n)
{
  if (n == nullptr)
  {
    return 0;
  }

  return getTreeHeight(n->leftLink) - getTreeHeight(n->rightLink);
}



int AvlTree::getTreeHeight(NodeType *p) const
{
  if (p == nullptr)
  {
    return 0;
  }
  else
  {
    return p->height;
  }
}


int AvlTree::getTreeHeight() const
{
  return getTreeHeight(root);
}


NodeType* AvlTree::updateHeight(NodeType *p)
{
  p->height = 1 + getMax(getTreeHeight(p->leftLink), getTreeHeight(p->rightLink));

  return p;
}


NodeType* AvlTree::getMinimumNode(NodeType *p)
{
  if (p == nullptr)
  {
    return nullptr;
  }
  else if (p->leftLink == nullptr)
  {
    return p;
  }
  else
  {
    return getMinimumNode(p->leftLink);
  }
}


NodeType* AvlTree::getMaximumNode(NodeType *p)
{
  if (p == nullptr)
  {
    return nullptr;
  }
  else if (p->rightLink == nullptr)
  {
    return p;
  }
  else
  {
    return getMaximumNode(p->rightLink);
  }
}


int AvlTree::getTreeNodeCount(NodeType *p) const
{
  int count = 1;

  if (p->leftLink != nullptr)
  {
    count += getTreeNodeCount(p->leftLink);
  }

  if (p->rightLink != nullptr)
  {
    count += getTreeNodeCount(p->rightLink);
  }

  return count;
}


int AvlTree::getTreeNodeCount() const
{
  int count = 0;

  if (root != nullptr)
  {
    count = getTreeNodeCount(root);
  }

  return count;
}


int AvlTree::getTreeLeavesCount(NodeType *p) const
{
  if (p == nullptr)
  {
    return 0;
  }

  if (p->leftLink == nullptr && p->rightLink == nullptr)
  {
    return 1;
  }
  else
  {
    return getTreeLeavesCount(p->leftLink) + getTreeLeavesCount(p->rightLink);
  }
}


int AvlTree::getTreeLeavesCount() const
{
  return getTreeLeavesCount(root);
}



void AvlTree::inOrderTraversal(NodeType *p)
{
  if (p != nullptr)
  {
    inOrderTraversal(p->leftLink);
    cout << p->info.getBookTitle() << endl;
    inOrderTraversal(p->rightLink);
  }
}

void AvlTree::inOrderTraversal()
{
  cout << "InOrder Traversal" << endl;
  inOrderTraversal(root);
  cout << endl;
}


void AvlTree::preOrderTraversal(NodeType *p)
{
  if (p != nullptr)
  {
    cout << p->info.getBookTitle() << endl;
    preOrderTraversal(p->leftLink);
    preOrderTraversal(p->rightLink);
  }
}

void AvlTree::preOrderTraversal()
{
  cout << "PreOrder Traversal" << endl;
  preOrderTraversal(root);
  cout << endl;
}



void AvlTree::postOrderTraversal(NodeType *p)
{
  if (p != nullptr)
  {
    postOrderTraversal(p->leftLink);
    postOrderTraversal(p->rightLink);
    cout << p->info.getBookTitle() << endl;
  }
}

void AvlTree::postOrderTraversal()
{
  cout << "PostOrder Traversal" << endl;
  postOrderTraversal(root);
  cout << endl;
}


void AvlTree::print()
{
  inOrderTraversal();
  preOrderTraversal();
  postOrderTraversal();
}






int AvlTree::getMax(int x, int y) const
{
  return (x >= y ? x : y);
}






// ***********************************************************************
NodeType* AvlTree::insert(NodeType *node, const Book& insertItem)
{

  // 1. perform the normal BST rotation
  if (node == nullptr)
  {
    return (new NodeType(insertItem));
  }

  if (insertItem < node->info)
  {
    node->leftLink = insert(node->leftLink, insertItem);
  }
  else if (insertItem > node->info)
  {
    node->rightLink = insert(node->rightLink, insertItem);
  }
  else        // equal keys not allowed
  {
    return node;
  }



  // 2. update height of this ancestor node
  updateHeight(node);


  // 3. Get the balance factor of this ancestor node to check whether this node becomes unbalanced
  int balance = getBalanceFactor(node);

  // if this node becomes unbalanced then there are 4 cases

  // left left case
  if (balance > 1 && insertItem < node->leftLink->info)
  {
    return rightRotate(node);
  }

  // right right case
  if (balance < -1 && insertItem > node->rightLink->info)
  {
    return leftRotate(node);
  }

  // left right case
  if (balance > 1 && insertItem > node->leftLink->info)
  {
    return rightRotate(node);
  }

  // right left case
  if (balance < -1 && insertItem < node->rightLink->info)
  {
    return leftRotate(node);
  }


  // return the unchanged node pointer
  return node;
}


void AvlTree::insert(const Book& insertItem)
{
  root = insert(root, insertItem);
}







// ***********************************************************************
NodeType* AvlTree::deleteNode(NodeType *&p, const Book& deleteItem)
{
  // STEP 1: PERFORM STANDARD BST DELETE
  if (root == nullptr)
    return root;

  // If the key to be deleted is smaller than the root's key, then it lies in left subtree
  if ( deleteItem < root->info)
  {
    root->leftLink = deleteNode(root->leftLink, deleteItem);
  }

  // If the key to be deleted is greater than the root's key, then it lies in right subtree
  else if( deleteItem > root->info )
    root->rightLink = deleteNode(root->rightLink, deleteItem);

  // if key is same as root's key, then This is the node to be deleted
  else
  {
    // node with only one child or no child
    if( (root->leftLink == nullptr) || (root->rightLink == nullptr) )
    {
      NodeType *temp = root->leftLink ? root->leftLink : root->rightLink;

      // No child case
      if (temp == nullptr)
      {
        temp = root;
        root = nullptr;
      }
      // one child case
      else
      {
        *root = *temp;    // Copy the contents of the non-empty child
      }

      delete temp;
    }
    else
    {
      // node with two children: Get the inorder successor (smallest in the right subtree)
      NodeType *temp = getMinimumNode(root->rightLink);

      // Copy the inorder successor's data to this node
      root->info = temp->info;

      // Delete the inorder successor
      root->rightLink = deleteNode(root->rightLink, temp->info);
    }
  }

  // If the tree had only one node then return
  if (root == nullptr)
    return root;

  // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  root->height = 1 + getMax(getTreeHeight(root->leftLink), getTreeHeight(root->rightLink));

  // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether this node became unbalanced)
  int balance = getBalanceFactor(root);

  // If this node becomes unbalanced, then there are 4 cases

  // Left Left Case
  if (balance > 1 && getBalanceFactor(root->leftLink) >= 0)
  {
    return rightRotate(root);
  }


  // Left Right Case
  if (balance > 1 && getBalanceFactor(root->leftLink) < 0)
  {
    root->leftLink = leftRotate(root->leftLink);
    return rightRotate(root);
  }

  // Right Right Case
  if (balance < -1 && getBalanceFactor(root->rightLink) <= 0)
    return leftRotate(root);

  // Right Left Case
  if (balance < -1 && getBalanceFactor(root->rightLink) > 0)
  {
    root->rightLink = rightRotate(root->rightLink);
    return leftRotate(root);
  }

  return root;
}


void AvlTree::deleteNode(const Book& deleteItem)
{
  deleteNode(root, deleteItem);
}





bool AvlTree::isEmpty() const
{
  return (root == nullptr);
}








Book AvlTree::search(const Book& searchItem)
{
  NodeType *current;
  bool found = false;

  if (root == nullptr)
  {
    cout << "Cannot search an empty tree" << endl;
  }
  else
  {
    current = root;

    while (current != nullptr && !found)
    {
      if (current->info == searchItem)
      {
        found = true;
        return current->info;
      }
      else if (current->info > searchItem)
      {
        current = current->leftLink;
      }
      else
      {
        current = current->rightLink;
      }
    }
  }



  string ex = "Item Not Found";
  throw (ex);
}





















const AvlTree& AvlTree::operator = (const AvlTree& otherTree)
{
  if (this != &otherTree)
  {
    if (root != nullptr)
    {
      destroyTree(root);
    }

    if (otherTree.root == nullptr)
    {
      root = nullptr;
    }
    else
    {
      copyTree(root, otherTree.root);
    }
  }


  return *this;
}




const AvlTree& AvlTree::operator = (AvlTree&& otherTree)
{
  if (this != &otherTree)
  {
    if (otherTree.root == nullptr)
    {
      root = nullptr;
    }
    else
    {
      root = otherTree.root;

      delete otherTree.root;
    }
  }

  return *this;

}
