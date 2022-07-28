//
// Created by 14037 on 2022/7/27.
//

#include <cassert>
#include "values_test.h"
#include "values.h"


void value_test(){
    Values values;
    values.AddBit('0');
    values.AddBit('1');
    values.AddBit('A');
    values.AddBit('B');
    values.AddBit('D');

    assert(values.ReturnBit(0) == '0');
    assert(values.ReturnBit(1) == '1');
    assert(values.ReturnBit(2) == 'A');
    assert(values.ReturnBit(3) == 'B');
    assert(values.ReturnBit(4) == 'D');
}