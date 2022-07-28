//
// Created by 14037 on 2022/7/27.
//

#include "values.h"

Values::Values():size_(10), index_(0) {
    value_.resize(size_);
}

Values::Values(int size) {
    if(size > 10){
        size_ = size;
    }

    value_.resize(size_);
}

void Values::AddBit(char element) {
    if(index_ >= size_){
        value_.resize(2 * size_);
        size_ *= 2;
    }

    value_[index_] = element;
    index_ ++;
}

char Values::ReturnBit(int index) {
    return value_[index];
}

int Values::ReturnIndex() const {
    return index_;
}
