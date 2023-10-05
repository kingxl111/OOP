#include <gtest/gtest.h>
#include "octal.h"

TEST(equals1, basic_test_set) {
    Octal n1("0124");
    Octal n2("124");
    ASSERT_TRUE(n1 == n2);
}

TEST(equals2, basic_test_set) {
    Octal n1("-000000");
    Octal n2(7, '0');
    ASSERT_TRUE(n1 == n2);
}

TEST(equals3, basic_test_set) {
    Octal n1("-000000124");
    Octal n2("-124");
    ASSERT_TRUE(n1 == n2);
}

TEST(equals4, basic_test_set) {
    Octal n1("-00000");
    Octal n2("-0");
    ASSERT_TRUE(n1 == n2);
}

TEST(equals5, basic_test_set) {
    Octal n1("-000");
    Octal n2("00000");
    ASSERT_TRUE(n1 == n2);
}

TEST(equals6, basic_test_set) {
    Octal n1("-0");
    Octal n2(6, '0');
    ASSERT_TRUE(n1 == n2);
}


TEST(greater1, basic_test_set) {
    Octal n1("21641624");
    Octal n2(7, '1');
    ASSERT_TRUE(n1 > n2);
}

TEST(greater2, basic_test_set) {
    Octal n1("-21641624");
    Octal n2(12, '1');
    ASSERT_FALSE(n1 > n2);
}

TEST(greater3, basic_test_set) {
    Octal n1("17273712462463724632641746235234635643756234563452432213452345446");
    Octal n2(50, '7');
    ASSERT_TRUE(n1 > n2);
}

TEST(less1, basic_test_set) {
    Octal n1("45446");
    Octal n2(50, '7');
    ASSERT_TRUE(n1 < n2);
}

TEST(less2, basic_test_set) {
    Octal n1("-124367234");
    Octal n2("-1111111");
    ASSERT_TRUE(n1 < n2);
}

TEST(less3, basic_test_set) {
    Octal n1("-1244124");
    Octal n2("0");
    ASSERT_TRUE(n1 < n2);
}

TEST(less4, basic_test_set) {
    Octal n1("0");
    Octal n2("0");
    ASSERT_FALSE(n1 < n2);
}

TEST(sum1, basic_test_set) {
    Octal n1("-1244124");
    Octal n2("0");
    Octal n3 = n1 + n2;

    Octal answer("-1244124");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum2, basic_test_set) {
    Octal n1("1242141244542342354124");
    Octal n2("25471273444152472316");
    Octal n3 = n1 + n2;

    Octal answer("1267632540206515046442");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum3, basic_test_set) {
    Octal n1("7777124214121244547523532461254632461236423432632662354124");
    Octal n2("1111111111254712734441524723645125354326236465623523472316");
    Octal n3 = n1 + n2;

    Octal answer("11110235325376157504165257405121760035564662120456406046442");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum4, basic_test_set) {
    Octal n1("2445475235324612546324612263257234623647236523753247624623546132642365636423432632662354124");
    Octal n2(90, '5');
    Octal n3 = n1 + n2;

    Octal answer("3223253013102370324102370041035012401425014301531025402401323710420143414201210410440131701");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum5, basic_test_set) {
    Octal n1(100, '5');
    Octal n2(4, '3');
    Octal n3 = n1 + n2;

    Octal answer("5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555561110");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum6, basic_test_set) {
    Octal n1(100, '0');
    Octal n2("0");
    Octal n3 = n1 + n2;

    Octal answer("0");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum7, basic_test_set) {
    Octal n1("176532742356125643271351413543234");
    Octal n2(1023, '0');
    Octal n3 = n1 + n2;

    Octal answer("176532742356125643271351413543234");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum8, basic_test_set) {
    Octal n1("16617231414321143251563423546511325476532742356125643271351413543234");
    Octal n2("0000000000000000127467214326261243152634512356123451616261341253416245162346156456213");
    Octal n3 = n1 + n2;

    Octal answer("146306445742602406424420136124634777315014303631544110453717572221447");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum9, basic_test_set) {
    Octal n1("-7152461245316617231414321143251563423546511325476532742356125643271351413543234");
    Octal n2("-0000000000000000512735467214326261243152634512356123451616261341253416245162346156456213");
    Octal n3 = n1 + n2;

    Octal answer("-7152461760254306445742602406424420136124634777315014303631544110453717572221447");

    ASSERT_TRUE(n3 == answer);
}

TEST(sum10, basic_test_set) {
    Octal n1("-1565132515123123333241237152461245316617231414321143251563423546511325476532742356125643271351413543234");
    Octal n2("54712345400000000423512100000000512735467214326261243152634512356123451616261341253416245162346156456213");
    Octal n3 = n1 + n2;

    Octal answer("53125212662654655070250640625317245416647762711740077701051066607412124117526376675270401670774542712757");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub1, basic_test_set) {
    Octal n1("65765327423561256432734");
    Octal n2(1023, '0');
    Octal n3 = n1 - n2;

    Octal answer("65765327423561256432734");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub2, basic_test_set) {
    Octal n1("65765327423561256432734");
    Octal n2(23, '1');
    Octal n3 = n1 - n2;

    Octal answer("54654216312450145321623");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub3, basic_test_set) {
    Octal n1("-377432373654256326476576532742356125612741263646234432734");
    Octal n2("-71724612547123671345235661461251645312671451267154316124616362717");
    Octal n3 = n1 - n2;

    Octal answer("71724612147471275470757332762453112350313323454213032256361727763");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub4, basic_test_set) {
    Octal n1("-567124421123443774323736542563264765765327423500000000116125612741263646234432734");
    Octal n2("-71724612547123671345235661461251645312671451267154316124616362717");
    Octal n3 = n1 - n2;

    Octal answer("-567124421123443702377123773437373420527445742226132465224454323564745521416050015");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub5, basic_test_set) {
    Octal n1("-567124421123443774323736542563264765765327423500000000116125612741263646234432734");
    Octal n2("325235112454222371724612547123671345235661461251645312671451267154316124616362717");
    Octal n3 = n1 - n2;

    Octal answer("-1114361533577666366250551311707156333223211104751645313007577102115601773053015653");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub6, basic_test_set) {
    Octal n1("125441241567124421123443774323736542563264765765327423500000000116125612741263646234432734");
    Octal n2("-325235112454222371724612547123671345235661461251645312671451267154316124616362717");
    Octal n3 = n1 - n2;

    Octal answer("125441242114361533577666366250551311707156333223211104751645313007577102115601773053015653");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub7, basic_test_set) {
    Octal n1("0");
    Octal n2("7173717462361263325235112454222371724612547123671345235661461251645312671451267154316124616362717");
    Octal n3 = n1 - n2;

    Octal answer("-7173717462361263325235112454222371724612547123671345235661461251645312671451267154316124616362717");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub8, basic_test_set) {
    Octal n1("0");
    Octal n2("-7173717462361263325235112454222371724612547123671345235661461251645312671451267154316124616362717");
    Octal n3 = n1 - n2;

    Octal answer("7173717462361263325235112454222371724612547123671345235661461251645312671451267154316124616362717");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub9, basic_test_set) {
    Octal n1("0");
    Octal n2("-0");
    Octal n3 = n1 - n2;

    Octal answer("0");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub10, basic_test_set) {
    Octal n1("0");
    Octal n2("-0000123");
    Octal n3 = n1 - n2;

    Octal answer("123");

    ASSERT_TRUE(n3 == answer);
}

TEST(sub11, basic_test_set) {
    Octal n1("-123");
    Octal n2("-0000123");
    Octal n3 = n1 - n2;

    Octal answer("0");

    ASSERT_TRUE(n3 == answer);
}

/////////////////////////////////////////////////////////////////
//Constructors and exceptions tests:
TEST(OctalTest, DefaultConstructor) {
    Octal oct;
    ASSERT_EQ(oct.get_size(), 0);
    ASSERT_EQ(oct.get_array(), nullptr);
}

TEST(OctalTest, FillConstructorChar) {
    Octal oct(5, '1');
    ASSERT_EQ(oct.get_size(), 5);
    unsigned char* arr = oct.get_array();
    for(size_t i = 0; i < 5; ++i)
        ASSERT_EQ(arr[i], '1');
}

TEST(OctalTest, FillConstructorCharThrowsException) {
    ASSERT_THROW(Octal oct(5, '8'), std::logic_error);
}

TEST(OctalTest, FillConstructorIntThrowsException) {
    ASSERT_THROW(Octal oct(7, -5), std::logic_error);
}

TEST(OctalTest, CopyStringConstructorThrowsException1) {
    std::string str = "888";
    EXPECT_THROW(Octal oct(str), std::logic_error);
}

TEST(OctalTest, CopyStringConstructorThrowsException2) {
    std::string str = "000*123";
    EXPECT_THROW(Octal oct(str), std::logic_error);
}

TEST(OctalTest, MoveConstructor) {
    Octal oct1;
    Octal oct2(std::move(oct1));
    ASSERT_EQ(oct1.get_size(), 0);
    ASSERT_EQ(oct1.get_array(), nullptr);
    ASSERT_EQ(oct2.get_size(), 0);
    ASSERT_EQ(oct2.get_array(), nullptr);
}

TEST(OctalTest, PrintFunction) {
    testing::internal::CaptureStdout(); // Capture the output
    Octal oct("7214");
    oct.print();
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    ASSERT_EQ(output, "7214\n");
}

TEST(OctalTest, PrintFunctionEmptyArray) {
    testing::internal::CaptureStdout(); // Capture the output
    Octal oct;
    oct.print();
    std::string output = testing::internal::GetCapturedStdout(); // Get the captured output
    ASSERT_EQ(output, "");
}

TEST(OctalTest, DestructorTest) {
    Octal myObject("16");

    // expecting destructor 
    EXPECT_DEATH(delete &myObject, "");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}