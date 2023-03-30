#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here


bool equalPaths(Node * root)
{
    // Add your code below
    if (root == nullptr) return true;

    Node * l = root->left;
    Node * r = root->right;
    if (l == nullptr && r == nullptr) return true;

    int lh = height(l);
    int rh = height(r);
    int rooth = height(root);

    if (equalPaths(l)&& equalPaths(r) && lh == rh && lh + 1 == rooth) return true;
    return false;

}

int height(Node* a){
    if (a == nullptr) return 0;
    int l = height(a->left)  +1;
    int r = height(a->right) +1;

    if (l>r) return l;
    return r;
}

