#include <gtest/gtest.h>
#include "triangle.h"
#include "rectangle.h"
#include "square.h"

#define EPS  1000 * DBL_EPSILON

TEST(TriangleMethods, square1) {
    Triangle t(1, 2, 3, 3.6, 4.8, 2);
    double sq = t.figure_square_calc();
    ASSERT_TRUE(abs(sq - 3.04) < EPS);
}

TEST(TriangleMethods, square2) {
    Triangle t(0, 0, 5, 5, 5, -5);
    double sq = t.figure_square_calc();
    ASSERT_TRUE(abs(sq - 25) < EPS);
}

TEST(TriangleMethods, square3) {
    Triangle t(0, 0, 0, 0, 0, 0);
    double sq = t.figure_square_calc();
    ASSERT_TRUE(abs(sq - 0) < EPS);
}

TEST(TriangleMethods, square4) {
    Triangle t(0, 0, 1, 1, 3, 3);
    double sq = t.figure_square_calc();
    ASSERT_TRUE(abs(sq - 0) < EPS);
}

TEST(TriangleMethods, geo_center1) {
    Triangle t(0, 0, 1, 1, 2, 0);
    t.geo_center_calc();
    double cent_x = t.get_geo_center_x();
    double cent_y = t.get_geo_center_y();
    ASSERT_TRUE((abs(cent_x - 1) < EPS) && (abs(cent_y - 1.0/3.0) < EPS));
}

TEST(TriangleMethods, geo_center2) {
    Triangle t(0, 0, 0, 0, 0, 0);
    t.geo_center_calc();
    double cent_x = t.get_geo_center_x();
    double cent_y = t.get_geo_center_y();
    ASSERT_TRUE((abs(cent_x - 0) < EPS) && (abs(cent_y - 0) < EPS));
}

TEST(TriangleOperatorsOverloads, square_op_overload) {
    Triangle t(0, 0, 1, 1, 3, 1);
    double sq = t;
    ASSERT_TRUE(abs(sq - 1) < EPS);
}

TEST(TriangleOperatorsOverloads, input_oper_overload) {
    int size = 6;
    double coords[] = {1, 1, 5, 1, 3, 7};
    write(STDIN_FILENO, coords, size);
    Triangle t1;
    std::cin >> t1;
    
    Triangle t2(1, 1, 5, 1, 3, 7);
    ASSERT_TRUE(t1 == t2);

}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

