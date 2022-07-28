//
// Created by 14037 on 2022/7/27.
//

#include "bitmap.h"

// 第0个false
// 110
int Bitmap::select(bool bit, int index) {
    if(!bit && index == 0) return -1;
    for (int i = 0; i < index_; ++i) {
        if (bitmap_[i] == bit)
            index--;
        if (index == 0)
            return i;
    }

    return -1;
}

int Bitmap::rank(bool bit, int index) {
    int ret = 0;
    for (int i = 0; i < index + 1; ++i) {
        if (bitmap_[i] == bit)
            ret++;
    }

    return ret;
}

std::string Bitmap::print() {
    std::string ret;
    for (int i = 0; i < index_; ++i) {
        ret.push_back(bitmap_[i] ? '1' : '0');
    }

    return ret;
}

void Bitmap::AddBit(bool element) {
    if(index_ >= size_){
        bitmap_.resize(2 * size_);
        size_ *= 2;
    }

    bitmap_[index_] = element;
    index_ ++;
}

Bitmap::Bitmap(int size):size_(size), index_(0) {
    if(size > 10){
        size_ = size;
    }

    bitmap_.resize(size_);
}

Bitmap::Bitmap():size_(10), index_(0) {
    bitmap_.resize(size_);
}

// 110 110 0 0 0
//    0
//  1   2
// 3 4 0 0
int Bitmap::child(int node, int index) {
    // 第一个孩子节点
    int child_index = rank(true, select(false, node) + 1);

    // 第index个孩子节点的位置是false说明不存在
    if(!bitmap_[select(false, node) + 1 + index]) return -1;
    return child_index + index;
}


int Bitmap::parent(int node) {
    //
    return rank(false, select(true, node));
}
