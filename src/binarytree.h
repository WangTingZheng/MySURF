//
// Created by 14037 on 2022/7/27.
//

#ifndef MYSURF_BINARYTREE_H
#define MYSURF_BINARYTREE_H

#include "bitmap.h"
#include "values.h"

using namespace std;

enum TravelType{IN, PRE, POST};

class BinaryTree {
    public:
        explicit BinaryTree(Bitmap *has_child, Values *value);

        string ToString(TravelType type);
    private:
        Bitmap *has_child_;
        Values *values_;

        void InTravel(string *ret, int root);
        void PreTravel(string *ret, int root);
        void PostTravel(string *ret, int root);
};


#endif //MYSURF_BINARYTREE_H
