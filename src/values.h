//
// Created by 14037 on 2022/7/27.
//

#ifndef MYSURF_VALUES_H
#define MYSURF_VALUES_H

#include <vector>

class Values {
    public:
        Values();

        explicit Values(int size);

        void AddBit(char element);

        char ReturnBit(int index);

        int ReturnIndex() const;

private:
        std::vector<char> value_;
        int size_;
        int index_;
};


#endif //MYSURF_VALUES_H
