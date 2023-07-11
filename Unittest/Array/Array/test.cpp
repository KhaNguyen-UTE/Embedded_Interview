#include "pch.h"
#include "gtest.cpp"


TEST(TestSortArray, Sort_1) {
    int a[5] = { 1,5,3,7,9 };
    ArraySorter * test;
    test = new ArraySorter(a, 5);
    test->BubbleSort();

    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 3);
    EXPECT_EQ(a[2], 5);
    EXPECT_EQ(a[3], 7);
    EXPECT_EQ(a[4], 9);
}