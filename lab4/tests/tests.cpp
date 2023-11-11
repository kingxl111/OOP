#include <gtest/gtest.h>
#include "triangle.h"
#include "rectangle.h"
#include "square.h"

#define EPS  1000*DBL_EPSILON

TEST(TriangleMethods, square1) {
    Triangle<double> t(1, 2, 3, 3.6, 4.8, 2);
    double sq = t.figure_square_calc();
    ASSERT_TRUE(abs(sq - 3.04) < EPS);
}

TEST(TriangleMethods, square2) {
    Triangle<int> t(0, 0, 5, 5, 5, -5);
    double sq = t.figure_square_calc();
    ASSERT_TRUE(sq == 24);
}

TEST(TriangleMethods, square3) {
    Triangle<double> t;
    double sq = t.figure_square_calc();
    ASSERT_TRUE(abs(sq - 0) < EPS);
}

TEST(TriangleMethods, geo_center1) {
    Triangle<double> t(0, 0, 1, 1, 2, 0);
    using vertex_t = std::pair<double, double>;
    vertex_t v = t.geo_center_calc();
    ASSERT_TRUE((abs(v.first - 1) < EPS) && (abs(v.second - 1.0/3.0) < EPS));
}

TEST(TriangleMethods, geo_center2) {
    Triangle<int64_t> t;
    t.geo_center_calc();
    using vertex_t = std::pair<int, int>;
    vertex_t v = t.geo_center_calc();
    ASSERT_TRUE((abs(v.first - 0) < EPS) && (abs(v.second - 0) < EPS));
}

TEST(TriangleOperatorsOverloads, square_op_overload) {
    Triangle<double> t(0, 0, 1, 1, 3, 1);
    double sq = t;
    ASSERT_TRUE(abs(sq - 1) < EPS);
}

TEST(TriangleOperatorsOverloads, equal_oper_overload1) {
    Triangle<int> t1(1, 1, 5, 1, 3, 7);
    Triangle<int> t2(1, 1, 5, 1, 3, 7);

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, equal_oper_overload2) {
    Triangle<long long> t1(1, 1, 5, 1, 3, 7);
    Triangle<long long> t2(0, 0, 5, 1, 3, 7);

    ASSERT_FALSE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, assign_oper_overload1) {
    Triangle<int> t1(0, 0, 5, 1, 8, -5);
    Triangle<int> t2;
    t2 = t1;

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, assign_oper_overload3) {
    Triangle<bool> t1;
    Triangle<bool> t2;
    t1 = t2;

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, CopyConstructor1) {
    Triangle<int64_t> t1(0, 0, 5, 1, 8, -5);
    Triangle<int64_t> t2(t1);

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, cout_oper_overload1) {
    testing::internal::CaptureStdout(); // Capture the output
    Triangle<double> t1;
    t1 << std::cout;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    testing::internal::CaptureStdout();

    std::cout << "Point1 [ x1 : 0, y1 : 0 ]" << std::endl;
    std::cout << "Point2 [ x2 : 0, y2 : 0 ]" << std::endl;
    std::cout << "Point3 [ x3 : 0, y3 : 0 ]" << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(TriangleOperatorsOverloads, cout_oper_overload2) {
    testing::internal::CaptureStdout(); 
    Triangle t1(1, 2, 3, 4, 6, -8);
    t1 << std::cout;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::cout << "Point1 [ x1 : 1, y1 : 2 ]" << std::endl;
    std::cout << "Point2 [ x2 : 3, y2 : 4 ]" << std::endl;
    std::cout << "Point3 [ x3 : 6, y3 : -8 ]" << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(TriangleOperatorsOverloads, cout_oper_overload3) {
    testing::internal::CaptureStdout(); 
    Triangle t1(-7, 8, 3, 4, 6, -2);
    Triangle t2 = t1;
    t2 << std::cout;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::cout << "Point1 [ x1 : -7, y1 : 8 ]" << std::endl;
    std::cout << "Point2 [ x2 : 3, y2 : 4 ]" << std::endl;
    std::cout << "Point3 [ x3 : 6, y3 : -2 ]" << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(TriangleOperatorsOverloads, CinOperator1) {
    Triangle<double> t1;
    //1 1 5 0 4 10
    t1 >> std::cin;
    Triangle<double> t2(1, 1, 5, 0, 4, 10);
    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, CinOperator2) {
    Triangle<double> t1;
    //1 1 5 0 4 11
    t1 >> std::cin;
    Triangle<double> t2(1, 1, 5, 0, 4, 10);
    ASSERT_FALSE(t1 == t2);
}

TEST(RectangleMethods, square1) {
    Rectangle<int> r;
    double sq = r.figure_square_calc();
    ASSERT_TRUE(abs(sq - 0) < EPS);
}

TEST(RectangleMethods, square2) {
    Rectangle<double> r(0, 0, 1, 5, 0, 5, 1, 0);
    double sq = r.figure_square_calc();
    ASSERT_TRUE(abs(sq - 5) < EPS);
}

TEST(RectangleMethods, geo_center1) {
    Rectangle<int> r;
    using vertex_t = std::pair<double, double>;
    vertex_t v = r.geo_center_calc();
    ASSERT_TRUE((abs(v.first - 0) < EPS) && (abs(v.second - 0) < EPS));
}

TEST(RectangleMethods, geo_center2) {
    Rectangle<double> r(0, 0, 5, 5, 5, 0, 0, 5);
    r.geo_center_calc();
    using vertex_t = std::pair<int, int>;
    r.geo_center_calc();
    ASSERT_TRUE((abs(r.geo_center.first - 2.5) < EPS) && (abs(r.geo_center.second - 2.5) < EPS));
}

TEST(RectangleOperatorsOverloads, square_op_overload1) {
    Rectangle<double> r(0, 0, 4, 1, 4, 0, 0, 1);
    double sq = r;
    ASSERT_TRUE(abs(sq - 4) < EPS);
}

TEST(RectangleOperatorsOverloads, square_op_overload2) {
    Rectangle<double> r;
    double sq = r;
    ASSERT_TRUE(abs(sq) < EPS);
}

TEST(RectangleOperatorsOverloads, equal_oper_overload1) {
    Rectangle<int> r1(1, 1, 5, 1, 1, 5, 5, 5);
    Rectangle<int> r2(1, 1, 5, 1, 1, 5, 5, 5);

    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, equal_oper_overload2) {
    Rectangle<long long> r1;
    Rectangle<long long> r2;

    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, assign_oper_overload1) {
    Rectangle<int> r1(0, 0, 4, 3, 4, 0, 0, 3);
    Rectangle<int> r2;
    r2 = r1;

    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, CopyConstructor1) {
    Rectangle<int64_t> r1(0, 0, 1, 1, 1, 0, 0, 1);
    Rectangle<int64_t> r2(r1);

    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, cout_oper_overload1) {
    testing::internal::CaptureStdout(); // Capture the output
    Rectangle<double> r1;
    r1 << std::cout;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    testing::internal::CaptureStdout();

    std::cout << "Point1 [ x1 : 0, y1 : 0 ]" << std::endl;
    std::cout << "Point2 [ x2 : 0, y2 : 0 ]" << std::endl;
    std::cout << "Point3 [ x3 : 0, y3 : 0 ]" << std::endl;
    std::cout << "Point4 [ x4 : 0, y4 : 0 ]" << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(RectangleOperatorsOverloads, cout_oper_overload2) {
    testing::internal::CaptureStdout(); // Capture the output
    Rectangle<double> r1(1, 1, 2, 2, 2, 1, 1, 2);
    r1 << std::cout;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    testing::internal::CaptureStdout();

    std::cout << "Point1 [ x1 : 1, y1 : 1 ]" << std::endl;
    std::cout << "Point2 [ x2 : 1, y2 : 2 ]" << std::endl;
    std::cout << "Point3 [ x3 : 2, y3 : 2 ]" << std::endl;
    std::cout << "Point4 [ x4 : 2, y4 : 1 ]" << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();
    
    ASSERT_EQ(output, ans);
}

TEST(RectangleOperatorsOverloads, CinOperator1) {
    Rectangle<double> r1;
    //0 0 0 0 0 0 0 0
    r1 >> std::cin;
    Rectangle<double> r2;
    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, CinOperator2) {
    Rectangle<double> r1;
    //17 1 0 1 0 5 17 5
    r1 >> std::cin;
    Rectangle<double> r2(17, 1, 0, 1, 0, 5, 17, 5);
    ASSERT_TRUE(r1 == r2);
}



TEST(SquareMethods, square1) {
    Square<int> r;
    double sq = r.figure_square_calc();
    ASSERT_TRUE(abs(sq - 0) < EPS);
}

TEST(SquareMethods, square2) {
    Square<double> r(1, 1, 1, 5, 5, 1, 5, 5);
    double sq = r.figure_square_calc();
    ASSERT_TRUE(abs(sq - 16) < EPS);
}

TEST(SquareMethods, geo_center1) {
    Square<int> r;
    using vertex_t = std::pair<double, double>;
    vertex_t v = r.geo_center_calc();
    ASSERT_TRUE((abs(v.first - 0) < EPS) && (abs(v.second - 0) < EPS));
}

TEST(SquareMethods, geo_center2) {
    Square<double> r(0, 0, 5, 5, 5, 0, 0, 5);
    r.geo_center_calc();
    using vertex_t = std::pair<int, int>;
    r.geo_center_calc();
    ASSERT_TRUE((abs(r.geo_center.first - 2.5) < EPS) && (abs(r.geo_center.second - 2.5) < EPS));
}

TEST(SquareOperatorsOverloads, square_op_overload1) {
    Square<double> r(0, 0, 4, 0, 4, 4, 0, 4);
    double sq = r;
    ASSERT_TRUE(abs(sq - 16) < EPS);
}

TEST(SquareOperatorsOverloads, square_op_overload2) {
    Square<double> r;
    double sq = r;
    ASSERT_TRUE(abs(sq) < EPS);
}

TEST(SquareOperatorsOverloads, CopyConstructor1) {
    Square<int64_t> r1(0, 0, 1, 1, 1, 0, 0, 1);
    Square<int64_t> r2(r1);

    ASSERT_TRUE(r1 == r2);
}

TEST(SquareOperatorsOverloads, CinOperator1) {
    Square<double> r1;
    //0 0 0 0 0 0 0 0
    r1 >> std::cin;
    Square<double> r2;
    ASSERT_TRUE(r1 == r2);
}

TEST(SquareOperatorsOverloads, CinOperator2) {
    Square<double> r1;
    //0 0 8 0 0 8 8 8
    r1 >> std::cin;
    Square<double> r2(0, 0, 8, 0, 0, 8, 8, 8);
    ASSERT_TRUE(r1 == r2);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}