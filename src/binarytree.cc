//
// Created by 14037 on 2022/7/27.
//

#include "binarytree.h"

BinaryTree::BinaryTree(Bitmap *has_child, Values *value)
    :has_child_(has_child),
    values_(value){
}


/*
 * bitmap: 110 10 110 0 0 0
 *
 * binary tree
 *       ↓- 0 -↓
 *     ↓-1   ↓-2-↓
 *     3     4   5
 *
 */
string BinaryTree::ToString(TravelType type) {
    string ret;
    switch (type) {
        case IN:
        {
            InTravel(&ret, 0);
            break;
        }
        case PRE:
        {
            PreTravel(&ret, 0);
            break;
        }
        case POST:
        {
            PostTravel(&ret, 0);
            break;
        }
    }

    return ret;
}

void BinaryTree::PreTravel(string *ret, int root) {
    if(root == -1) return;
    int left ,right;

    left = has_child_->child(root, 0);
    right = has_child_->child(root, 1);

    ret->push_back(values_->ReturnBit(root));

    PreTravel(ret, left);
    PreTravel(ret, right);
}

void BinaryTree::InTravel(string *ret, int root) {
    if(root == -1) return;
    int left ,right;

    left = has_child_->child(root, 0);
    right = has_child_->child(root, 1);

    InTravel(ret, left);

    ret->push_back(values_->ReturnBit(root));

    InTravel(ret, right);
}

void BinaryTree::PostTravel(string *ret, int root) {
    if(root == -1) return;
    int left ,right;

    left = has_child_->child(root, 0);
    right = has_child_->child(root, 1);

    PostTravel(ret, left);
    PostTravel(ret, right);
    ret->push_back(values_->ReturnBit(root));
}
