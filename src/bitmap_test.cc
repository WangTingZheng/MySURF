//
// Created by 14037 on 2022/7/27.
//

#include <cassert>
#include "bitmap.h"

void bloom_test(){
    // test construction and resize
    Bitmap bitmap(2);

    // test add bit
    // 110 110 0 0 0
    /*    0
     *  1  2
     * 3 4
    */
    bitmap.AddBit(true);
    bitmap.AddBit(true);
    bitmap.AddBit(false);

    bitmap.AddBit(true);
    bitmap.AddBit(true);
    bitmap.AddBit(false);

    bitmap.AddBit(false);

    bitmap.AddBit(false);

    bitmap.AddBit(false);

    // test print
    assert(bitmap.print() == "110110000");

    // test select
    assert(bitmap.select(true, 1) == 0);
    assert(bitmap.select(true, 2) == 1);
    assert(bitmap.select(false, 1) == 2);
    assert(bitmap.select(true, 3) == 3);
    assert(bitmap.select(true, 4) == 4);

    // test rank
    assert(bitmap.rank(true, 0) == 1); //[0, 0] true的个数
    assert(bitmap.rank(true, 1) == 2); //[0, 1] true的个数
    assert(bitmap.rank(true, 2) == 2); //[0, 2] true的个数
    assert(bitmap.rank(true, 3) == 3); //[0, 3] true的个数
    assert(bitmap.rank(true, 4) == 4); //[0, 4] true的个数

    assert(bitmap.rank(false, 0) == 0); //[0, 0] false的个数
    assert(bitmap.rank(false, 1) == 0); //[0, 1] false的个数
    assert(bitmap.rank(false, 2) == 1); //[0, 2] false的个数
    assert(bitmap.rank(false, 3) == 1); //[0, 3] false的个数
    assert(bitmap.rank(false, 4) == 1); //[0, 4] false的个数

    /*
     * 110 110 0 0 0
     *       ↓-0-----↓
     *     ↓-1-↓     2-↓
     *    ↓-3  4-↓     0
     *    0      0
     */
    // test get child node
    assert(bitmap.child(0, 0) == 1);
    assert(bitmap.child(0, 1) == 2);
    assert(bitmap.child(1, 0) == 3);
    assert(bitmap.child(1, 1) == 4);

    assert(bitmap.child(2, 0) == -1);
    assert(bitmap.child(2, 1) == -1);

    assert(bitmap.child(3, 0) == -1);
    assert(bitmap.child(3, 1) == -1);

    // test get parent node
    assert(bitmap.parent(3) == 1);
    assert(bitmap.parent(4) == 1);
    assert(bitmap.parent(1) == 0);
    assert(bitmap.parent(2) == 0);
}