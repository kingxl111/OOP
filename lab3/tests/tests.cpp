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

TEST(TriangleOperatorsOverloads, equal_oper_overload1) {
    Triangle t1(1, 1, 5, 1, 3, 7);
    Triangle t2(1, 1, 5, 1, 3, 7);

    ASSERT_TRUE(t1 == t2);

}

TEST(TriangleOperatorsOverloads, equal_oper_overload2) {
    Triangle t1(1, 1, 5, 1, 3, 7);
    Triangle t2(0, 0, 5, 1, 3, 7);

    ASSERT_FALSE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, assign_oper_overload1) {
    Triangle t1(0, 0, 5, 1, 8, -5);
    Triangle t2;
    t2 = t1;

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, assign_oper_overload2) {
    Triangle t1(0, 0, 5, 1, 8, -5);
    Triangle t2;
    t1 = t2;

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, assign_oper_overload3) {
    Triangle t1;
    Triangle t2;
    t1 = t2;

    ASSERT_TRUE(t1 == t2);
}

TEST(TriangleOperatorsOverloads, cout_oper_overload1) {
    testing::internal::CaptureStdout(); // Capture the output
    Triangle t1;
    cout << t1;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : 0, y1 : 0 ]" << endl;
    cout << "Point2 [ x2 : 0, y2 : 0 ]" << endl;
    cout << "Point3 [ x3 : 0, y3 : 0 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(TriangleOperatorsOverloads, cout_oper_overload2) {
    testing::internal::CaptureStdout(); 
    Triangle t1(1, 2, 3, 4, 6, -8);
    cout << t1;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : 1, y1 : 2 ]" << endl;
    cout << "Point2 [ x2 : 3, y2 : 4 ]" << endl;
    cout << "Point3 [ x3 : 6, y3 : -8 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(TriangleOperatorsOverloads, cout_oper_overload3) {
    testing::internal::CaptureStdout(); 
    Triangle t1(-7, 8, 3, 4, 6, -2);
    Triangle t2 = t1;
    cout << t2;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : -7, y1 : 8 ]" << endl;
    cout << "Point2 [ x2 : 3, y2 : 4 ]" << endl;
    cout << "Point3 [ x3 : 6, y3 : -2 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(TriangleOperatorsOverloads, cin_oper_overload1) {
    
    Triangle t1;
    std::cin >> t1;
    Triangle t2(-7, 8, 3, 4, 6, -2);
    ASSERT_TRUE(t1 == t2);
}


TEST(RectangleMethods, square1) {
    Rectangle r(1, 1, 3, 1, 3, 5, 1, 5);
    double sq = r.figure_square_calc();
    ASSERT_TRUE(abs(sq - 8) < EPS);
}

TEST(RectangleMethods, square2) {
    Rectangle r(0, 0, 5, 6, 0, 6, 5, 0);
    double sq = r.figure_square_calc();
    ASSERT_TRUE(abs(sq - 30) < EPS);
}

TEST(RectangleCnstructorException, exception1) {
    EXPECT_THROW(Rectangle r(-5, -1, 1, 1, 2, 4, 10, 3), std::logic_error);
}

TEST(RectangleMethods, geo_center1) {
    Rectangle r(0, 0, 3, 0, 0, 3, 3, 3);
    r.geo_center_calc();
    double cent_x = r.get_geo_center_x();
    double cent_y = r.get_geo_center_y();
    ASSERT_TRUE((abs(cent_x - 1.5) < EPS) && (abs(cent_y - 1.5) < EPS));
}

TEST(RectangleMethods, geo_center2) {
    Rectangle r(1, 1, 5, 4, 1, 4, 5, 1);
    r.geo_center_calc();
    double cent_x = r.get_geo_center_x();
    double cent_y = r.get_geo_center_y();
    ASSERT_TRUE((abs(cent_x - 3) < EPS) && (abs(cent_y - 2.5) < EPS));
}

TEST(RectangleOperatorsOverloads, square_op_overload) {
    Rectangle r(1, 1, 5, 4, 1, 4, 5, 1);
    double sq = r;
    ASSERT_TRUE(abs(sq - 12) < EPS);
}

TEST(RectangleOperatorsOverloads, equal_oper_overload1) {
    Rectangle r1;
    Rectangle r2;
    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, equal_oper_overload2) {
    Rectangle r1;
    Rectangle r2(-1, -1, 2, -1, 2, 1, -1, 1);
    ASSERT_FALSE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, assign_oper_overload1) {
    Rectangle r1(5, 5, 10, 12, 10, 5, 5, 12);
    Rectangle r2;
    r2 = r1;
    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, assign_oper_overload2) {
    Rectangle r1(5, 5, 10, 12, 10, 5, 5, 12);
    Rectangle r2(1, 2, 1, 5, 4, 2, 4, 5);
    r1 = r2;
    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, assign_oper_overload3) {
    Rectangle r1;
    Rectangle r2;
    r1 = r2;
    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, cout_oper_overload1) {
    testing::internal::CaptureStdout(); // Capture the output
    Rectangle r1;
    cout << r1;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : 0, y1 : 0 ]" << endl;
    cout << "Point2 [ x2 : 0, y2 : 0 ]" << endl;
    cout << "Point3 [ x3 : 0, y3 : 0 ]" << endl;
    cout << "Point4 [ x4 : 0, y4 : 0 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(RectangleOperatorsOverloads, cout_oper_overload2) {
    testing::internal::CaptureStdout(); 
    Rectangle r1(0, 1, 0, 11, 5, 11, 5, 1);
    cout << r1;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : 0, y1 : 1 ]" << endl;
    cout << "Point2 [ x2 : 0, y2 : 11 ]" << endl;
    cout << "Point3 [ x3 : 5, y3 : 11 ]" << endl;
    cout << "Point4 [ x4 : 5, y4 : 1 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(RectangleOperatorsOverloads, cout_oper_overload3) {
    testing::internal::CaptureStdout(); 
    Rectangle t1(-7, 8, -7, 16, 5, 16, 5, 8);
    Rectangle t2 = t1;
    cout << t2;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : -7, y1 : 8 ]" << endl;
    cout << "Point2 [ x2 : -7, y2 : 16 ]" << endl;
    cout << "Point3 [ x3 : 5, y3 : 16 ]" << endl;
    cout << "Point4 [ x4 : 5, y4 : 8 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(RectangleOperatorsOverloads, cin_oper_overload1) {
    
    Rectangle r1;
    std::cin >> r1;
    Rectangle r2(1, 1, 1, 5, 6, 5, 6, 1);
    ASSERT_TRUE(r1 == r2);
}

TEST(RectangleOperatorsOverloads, cin_oper_overload2) {
    
    Rectangle r1;
    std::cin >> r1;
    Rectangle r2;
    ASSERT_FALSE(r1 == r2);
}

TEST(SquareMethods, square1) {
    Square s(0, 0, 3, 3, 3, 0, 0, 3);
    double sq = s.figure_square_calc();
    ASSERT_TRUE(abs(sq - 9) < EPS);
}

TEST(SquareMethods, square2) {
    Square s;
    double sq = s.figure_square_calc();
    ASSERT_TRUE(abs(sq - 0) < EPS);
}

TEST(SquareCnstructorException, exception1) {
    EXPECT_THROW(Square s(-5, -1, 1, 1, 2, 4, 10, 3), std::logic_error);
}

TEST(SquareCnstructorException, exception2) {
    EXPECT_THROW(Square s(1, 1, 1, 10, 5, 10, 5, 1), std::logic_error);
}

TEST(SquareMethods, geo_center1) {
    Square s(0, 0, 5, 0, 0, 5, 5, 5);
    s.geo_center_calc();
    double cent_x = s.get_geo_center_x();
    double cent_y = s.get_geo_center_y();
    ASSERT_TRUE((abs(cent_x - 2.5) < EPS) && (abs(cent_y - 2.5) < EPS));
}

TEST(SquareMethods, geo_center2) {
    Square s;
    s.geo_center_calc();
    double cent_x = s.get_geo_center_x();
    double cent_y = s.get_geo_center_y();
    ASSERT_TRUE((abs(cent_x - 0) < EPS) && (abs(cent_y - 0) < EPS));
}

TEST(SquareOperatorsOverloads, square_op_overload) {
    Square s(2, 1, 5, 4, 2, 4, 5, 1);
    double sq = s;
    ASSERT_TRUE(abs(sq - 9) < EPS);
}

TEST(SquareOperatorsOverloads, equal_oper_overload1) {
    Square s1;
    Square s2;
    ASSERT_TRUE(s1 == s2);
}

TEST(SquareOperatorsOverloads, equal_oper_overload2) {
    Square s1;
    Square s2(-1, -1, 1, -1, 1, 1, -1, 1);
    ASSERT_FALSE(s1 == s2);
}

TEST(SquareOperatorsOverloads, equal_oper_overload3) {
    Square s;
    Rectangle r;
    ASSERT_TRUE(r == s);
}

TEST(SquareOperatorsOverloads, assign_oper_overload1) {
    Square s1(5, 5, 10, 10, 10, 5, 5, 10);
    Square s2;
    s2 = s1;
    ASSERT_TRUE(s1 == s2);
}

TEST(SquareOperatorsOverloads, assign_oper_overload2) {
    Square s1(5, 5, 10, 10, 10, 5, 5, 10);
    Square s2(5, 11, 6, 12, 5, 12, 6, 11);
    s1 = s2;
    ASSERT_TRUE(s1 == s2);
}

TEST(SquareOperatorsOverloads, assign_oper_overload3) {
    Square s1;
    Square s2;
    s1 = s2;
    ASSERT_TRUE(s1 == s2);
}

TEST(SquareOperatorsOverloads, cout_oper_overload1) {
    testing::internal::CaptureStdout(); // Capture the output
    Square s1;
    cout << s1;
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : 0, y1 : 0 ]" << endl;
    cout << "Point2 [ x2 : 0, y2 : 0 ]" << endl;
    cout << "Point3 [ x3 : 0, y3 : 0 ]" << endl;
    cout << "Point4 [ x4 : 0, y4 : 0 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(SquareOperatorsOverloads, cout_oper_overload2) {
    testing::internal::CaptureStdout(); 
    Square s1(0, 0, 0, 11, 11, 11, 11, 0);
    cout << s1;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    cout <<  "Point1 [ x1 : 0, y1 : 0 ]" << endl;
    cout << "Point2 [ x2 : 0, y2 : 11 ]" << endl;
    cout << "Point3 [ x3 : 11, y3 : 11 ]" << endl;
    cout << "Point4 [ x4 : 11, y4 : 0 ]" << endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(SquareOperatorsOverloads, cin_oper_overload) {
    
    Square s1;
    std::cin >> s1;
    Square s2(1, 1, 1, 5, 5, 1, 5, 5);
    ASSERT_TRUE(s1 == s2);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
