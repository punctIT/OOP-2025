#include "pch.h"
#include "Sort.h"
#include <gtest/gtest.h>
#include <iostream>



TEST(SortCORECT, Array) {
    Array <int>a1 = { 1,2,4,5,2,5 };
    a1.sortGOOD();
    EXPECT_STREQ("1 2 2 4 5 5 ", a1.print().c_str());
}

TEST(SortGRESIT, Array) {
   
    Array <int>a1 = { 1,2,4,5,2,5 };
    a1.sort();
    EXPECT_STREQ("1 2 2 3 5 5 ",a1.print().c_str());
}


