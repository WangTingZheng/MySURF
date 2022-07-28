//
// Created by 14037 on 2022/7/27.
//

#ifndef MYSURF_BITMAP_H
#define MYSURF_BITMAP_H


#include <iostream>
#include <vector>

class Bitmap{
public:
    Bitmap();

    explicit Bitmap(int size);

    void AddBit(bool element);

    int select(bool bit, int index);

    int rank(bool bit, int index);

    int child(int node, int index);

    int parent(int node);

    std::string print();

private:
    std::vector<bool> bitmap_;
    int size_;
    int index_;
};

#endif //MYSURF_BITMAP_H
