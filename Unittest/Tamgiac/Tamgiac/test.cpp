#include "pch.h"
#include "main.cpp"

TEST(XacDinhLoaiTamGiac, TestTamGiacKhongTonTai_1) {
	double Edge_1 = 0;
	double Edge_2 = 3;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1,Edge_2,Edge_3), TamGiacKhongTonTai);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacKhongTonTai_2) {
	double Edge_1 = 5;
	double Edge_2 = 0;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacKhongTonTai);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacKhongTonTai_3) {
	double Edge_1 = 6;
	double Edge_2 = 3;
	double Edge_3 = 0;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacKhongTonTai);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacDeu) {
	double Edge_1 = 3;
	double Edge_2 = 3;
	double Edge_3 = 3;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacDeu);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacCan_1) {
	double Edge_1 = 5;
	double Edge_2 = 5;
	double Edge_3 = 6;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacCan);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacCan_2) {
	double Edge_1 = 5;
	double Edge_2 = 3;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacCan);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacCan_3) {
	double Edge_1 = 5;
	double Edge_2 = 3;
	double Edge_3 = 3;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacCan);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacVuong) {
	double Edge_1 = 4;
	double Edge_2 = 3;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacVuong);
	EXPECT_TRUE(true);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacThuong) {
	double Edge_1 = 4;
	double Edge_2 = 3;
	double Edge_3 = 6;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacThuong);
	EXPECT_TRUE(true);
}