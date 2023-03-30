#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO //should be good
    virtual void remove(const Key& key); //TODO //should be good
    void clear(); //TODO //should be good
    bool isBalanced() const; //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for trversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

    //DELETE THIS
    //virtual void pubswap(Key k1, Key k2);

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;

    // Add helper functions here
    virtual void del(Node<Key, Value>* cur);
    virtual bool balance(const Node<Key, Value>* cur) const ;
    virtual void removeNode(Node<Key, Value>* n);
    virtual int height(const Node<Key,Value>* a) const ;

protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    // TODO
    current_ = ptr;
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
    // TODO
    current_ = nullptr;
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator ->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return this->current_ == rhs.current_;
}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return this->current_ != rhs.current_;
}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO
    if (current_ == nullptr) return *this;
    if (current_->getRight()!= nullptr){
        current_=current_->getRight();
        while(current_->getLeft()!=nullptr){
            current_ = current_->getLeft();
        }
        return *this;
    }
    else{
        Node<Key,Value> *par = current_->getParent();
        while (par!=nullptr && current_==par->getRight()){
            current_=par;
            par = par->getParent();
        }
        current_ = par;
        return *this;
    }
}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    root_ = nullptr;
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
    clear();
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::del(Node<Key, Value> *cur) {
    if (cur == nullptr){
        return;
    }
    if(cur->getLeft()!= nullptr){
        del(cur->getLeft());
    }
    if(cur->getRight()!= nullptr){
        del(cur->getRight());
    }


    delete cur;
}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    // TODO
    //std::cout << "inserting " << keyValuePair.first << std::endl;

    if (root_ == nullptr){
        root_ = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);
        //std::cout << "set root" << std::endl;
        return;
    }
    Node<Key, Value>* find = internalFind(keyValuePair.first);
    if (find!= nullptr){
        find->setValue(keyValuePair.second);
        return;
    }

    Node<Key, Value>* leaf = root_;
    Node<Key, Value>* parent = nullptr;
    Node<Key, Value>* newnode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr);
    bool right;

    while (leaf!=nullptr){
        if (newnode->getKey() < leaf->getKey()){
            parent = leaf;
            leaf = leaf->getLeft();
            right = false;
        }
        else if (newnode->getKey() > leaf->getKey()){
            parent = leaf;
            leaf = leaf->getRight();
            right = true;
        }
    }

    if (right){
        parent->setRight(newnode);
    }
    else if(!right){
        parent->setLeft(newnode);
    }
    newnode->setParent(parent);
    /*
    Node<Key, Value>* temp = root_;
    Node<Key, Value>* parent;
    while (temp->getRight()!= nullptr && temp->getLeft()!=nullptr){
        if (temp->getKey() == keyValuePair.first){
            temp->setValue(keyValuePair.second);
            //std::cout << "Updated value of " << temp->getKey() << std::endl;
            return;
        }
        else if (temp->getKey() > keyValuePair.first){
            temp = temp->getLeft();
            //std::cout << "Going left from " << temp->getKey() << std::endl;
        }
        else {
            temp = temp->getRight();
           // std::cout << "Going right from " << temp ->getKey() << std::endl;
        }
    }

    //std::cout << "Found leaf at " << temp->getKey() << std::endl;
    Node<Key, Value>* newnode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, temp);
    if (temp->getKey() > keyValuePair.first){
        temp->setLeft(newnode);
    }
    else{
        temp->setRight(newnode);
    }
    newnode->setParent(temp);
     */
}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key) {
    // TODO
    Node<Key, Value>* find = internalFind(key);
    //Case 1: Not found
    if(find == nullptr){
        std::cout << "Not Found " << std::endl;
        return;
    }

    //Parent:
    Node<Key, Value>* parent = find->getParent();
    Node<Key, Value>* pred = predecessor(find);
    std::cout << "Parent: " << parent << " Predecessor: " << pred << std:: endl;//Good to here

    //Swaps
    if (find->getRight()!=nullptr && find->getLeft()!=nullptr){
        std::cout << "pred swap" << std::endl;
        nodeSwap(find, predecessor(find));
    }
    while(find->getRight()!=nullptr || find->getLeft()!=nullptr) {
        if (find->getRight() != nullptr) {
            std::cout << "Right swap" << std::endl;
            nodeSwap(find, find->getRight());
        } else if (find->getLeft() != nullptr) {
            std::cout << "Left swap" << std::endl;
            nodeSwap(find, find->getLeft());
        }
    }
    //print();
    std::cout << root_->getKey() << std::endl;

    //Update Root
    Node<Key, Value>* temp = find;
    while(temp->getParent() != nullptr){
        temp = temp->getParent();
    }
    root_ = temp;
    std::cout << "Root: " << root_ << " value: " << root_->getKey() << std::endl;

    //Delete
    Node<Key, Value>* next = nullptr;
    if (find->getLeft()!=nullptr){
        next = find->getLeft();
    } else if (find->getRight()!=nullptr){
        next = find->getRight();
    }

    parent = find->getParent();
    if (parent != nullptr){
        if (parent->getLeft() == find){
            parent->setLeft(next);
        }
        else if (parent->getRight() == find){
            parent->setRight(next);
        }
    }

    /*
    std::cout << "at the end: " <<std::endl;
    std::cout <<"Parent: " << parent;
    std::cout <<"parent L: " << parent->getLeft()<< "Parent R" << parent->getRight() << std:: endl;
    std::cout <<"Next: " << next << "Next L: " << next->getLeft()<< "Next R" << next->getRight() << std:: endl;
    std::cout <<"Find: " << find << "Find L: " << find->getLeft()<< "find R" << find->getRight() << std:: endl;
    */
    if (root_ == find){
        root_ = nullptr;
    }
     delete find;

    print();
}

template<class Key, class Value>
void BinarySearchTree<Key, Value>::removeNode(Node<Key,Value>* n){
    //Function for removal of a Node with a single child

    Node<Key,Value>* par = n->getParent();
    if(par==nullptr){

    }
}


template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{
    // TODO
    //TEST
    if (current == nullptr){
        return nullptr;
        std::cout << "No predecessor"<< std::endl;
    }


    Node<Key, Value>* cur = current;

    if (cur->getLeft() != nullptr){
        cur = cur->getLeft();
        while (cur->getRight() != nullptr){
            cur = cur->getRight();
        }
        std::cout << "Predecessor" << cur->getKey() << std::endl;
        return cur;
    }

    else {

        Node<Key, Value>* parent = cur->getParent();
        Node<Key, Value> * ancestor = nullptr;
        if (parent != nullptr) {
            ancestor = parent->getParent();
        }
        while (parent != nullptr && cur==parent->getLeft()){
            cur = parent;
            parent = ancestor;
            if (parent!=nullptr && parent->getParent()!= nullptr) {
                ancestor = parent->getParent();
            }
        }
        std::cout << "Predecessor 2" << std::endl;
        return parent;
    }
}


/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
    // TODO
    Node<Key, Value>* cur = root_;
    if (cur == nullptr){
        return;
    }

    del(cur);

    /*
    del(cur->getLeft());
    del(cur->getRight());
     */
    //delete cur;

    root_ = nullptr;
}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    // TODO
    Node<Key, Value>* temp = root_;
    if(temp == nullptr){
        return temp;
    }
    while (temp->getLeft() != nullptr){
        temp = temp->getLeft();
    }
    return temp;
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    // TODO

    Node<Key, Value>* temp = root_;
    if (temp == nullptr){
        return nullptr;
    }
    if (temp->getKey() == key){
        return temp;
    }
    while (temp!=nullptr){
        if (temp->getKey() == key){
            break;
        }
        else if (key < temp->getKey()){
            temp = temp->getLeft();
        }
        else if (key > temp->getKey()){
            temp = temp->getRight();
        }
    }
    return temp;

    /*
    Node<Key, Value>* temp = root_;
    std::cout << "Current root: " << temp->getKey() << std::endl;

    while (temp!= nullptr && temp->getKey()!= key){
        std::cout << "test a" << std:: endl;
        if(temp->getKey() > key){
            temp = temp->getRight();
        }
        else if (temp->getKey() < key){
            temp = temp->getLeft();
        }
        else{
            break;
        }
    }

    return temp;
     */
}

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
    // TODO
    return balance(root_);
}

template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::balance(const Node<Key, Value> *cur) const {

    if (cur == nullptr) return true;

    int l = height(cur->getLeft());
    int r = height(cur->getRight());
    int hbal = l - r;

    if (hbal >= -1 && hbal <= 1 && balance(cur->getLeft()) && balance(cur->getRight())){
        return true;
    }
    return false;
}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::height(const Node<Key, Value> *a) const {
    if (a == nullptr) return 0;
    int l = height(a->getLeft());
    int r = height(a->getRight());

    if (l > r){
        return 1 + l;
    }
    else {
        return 1 + r;
    }
}

/*
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::pubswap(Key k1, Key k2) {
    Node<Key,Value>* a = internalFind(k1);
    Node<Key,Value>* b = internalFind(k2);
    nodeSwap(a, b);
}
 */

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
   Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
