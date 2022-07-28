//
// Created by 14037 on 2022/7/27.
//

#include <cassert>
#include "binarytree_test.h"
#include "bitmap.h"
#include "values.h"
#include "binarytree.h"

void binarytree_test(){
    Bitmap bitmap;
    // 110 10 110 0 0 0
    bitmap.AddBit(true);
    bitmap.AddBit(true);
    bitmap.AddBit(false);

    bitmap.AddBit(true);
    bitmap.AddBit(false);

    bitmap.AddBit(true);
    bitmap.AddBit(true);
    bitmap.AddBit(false);

    bitmap.AddBit(false);

    bitmap.AddBit(false);

    bitmap.AddBit(false);

    Values values;
    values.AddBit('0');
    values.AddBit('1');
    values.AddBit('2');
    values.AddBit('3');
    values.AddBit('4');
    values.AddBit('5');

    /*
     *         ↓-0-↓
     *      ↓-1    ↓-2-↓
     *      3      4   5
     */
    BinaryTree binaryTree(&bitmap, &values);
    // 中序遍历
    assert(binaryTree.ToString(IN) == "310425");
    // 前序遍历
    assert(binaryTree.ToString(PRE) == "013245");
    // 后序遍历
    assert(binaryTree.ToString(POST) == "314520");
}
