#include "pch.h"
#include "main.cpp"

TEST(XacDinhLoaiTamGiac, TestTamGiacKhongTonTai_1) {
	double Edge_1 = 0;
	double Edge_2 = 3;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1,Edge_2,Edge_3), TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacKhongTonTai_2) {
	double Edge_1 = 5;
	double Edge_2 = 0;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacKhongTonTai_3) {
	double Edge_1 = 6;
	double Edge_2 = 3;
	double Edge_3 = 0;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacKhongTonTai);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacDeu) {
	double Edge_1 = 3;
	double Edge_2 = 3;
	double Edge_3 = 3;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacDeu);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacCan_1) {
	double Edge_1 = 5;
	double Edge_2 = 5;
	double Edge_3 = 6;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacCan_2) {
	double Edge_1 = 5;
	double Edge_2 = 3;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacCan_3) {
	double Edge_1 = 5;
	double Edge_2 = 3;
	double Edge_3 = 3;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacCan);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacVuong) {
	double Edge_1 = 4;
	double Edge_2 = 3;
	double Edge_3 = 5;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacVuong);
}

TEST(XacDinhLoaiTamGiac, TestTamGiacThuong) {
	double Edge_1 = 4;
	double Edge_2 = 3;
	double Edge_3 = 6;
	EXPECT_EQ(XacDinhLoaiTamGiac(Edge_1, Edge_2, Edge_3), TamGiacThuong);
}