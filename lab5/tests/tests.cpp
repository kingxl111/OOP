#include <gtest/gtest.h>
#include <iostream>
#include "allocator.hpp"
#include "stack.hpp"


TEST(MapWithMyAllocatorTests, test1) {

    std::map<double, double, std::less<int>, My_Allocator::Allocator<std::pair<const double, double> > > test_map;
    test_map[1] = 2;
    test_map[2] = 3;
    test_map[3] = 5;

    testing::internal::CaptureStdout(); 
    for(const auto& [k,v]: test_map) {
            std::cout << k << " -> " << v << std::endl;
    } 
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::cout << 1 << " -> " << 2 << std::endl;
    std::cout << 2 << " -> " << 3 << std::endl;
    std::cout << 3 << " -> " << 5 << std::endl;
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(MapWithMyAllocatorTests, test2) {

    std::map<double, double, std::less<int>, My_Allocator::Allocator<std::pair<const double, double> > > test_map;

    testing::internal::CaptureStdout(); 
    for(const auto& [k,v]: test_map) {
            std::cout << k << " -> " << v << std::endl;
    } 
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout();
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_EQ(output, ans);
}

TEST(StackWithMyAllocator, test1) {

    Stack<long, My_Allocator::Allocator<long> > test_stack;
    
    for (int i = 0; i < 4; i++) {    
        test_stack.push(i + 1);
    }

    testing::internal::CaptureStdout(); 
    for (Stack<long, My_Allocator::Allocator<long> >::Iterator i = test_stack.begin(); i != test_stack.end(); ++i) {
        std::cout << *i << std::endl; // 
    }     
    std::string output = testing::internal::GetCapturedStdout(); 
    
    testing::internal::CaptureStdout();
    for (int i = 3; i >= 0; --i) { 
        std::cout << i + 1 << std::endl; 
    }
    std::string ans = testing::internal::GetCapturedStdout();

    ASSERT_TRUE(ans == output);
}

TEST(StackWithMyAllocator, test2) {

    Stack<double, My_Allocator::Allocator<double> > test_stack;
    EXPECT_ANY_THROW(test_stack.pop());
}

TEST(StackWithMyAllocator, test3) {

    Stack<double, My_Allocator::Allocator<double> > test_stack;
    EXPECT_ANY_THROW(test_stack.top());
}

TEST(StackWithMyAllocator, test4) {

    Stack<float, My_Allocator::Allocator<float> > test_stack;
    test_stack.push(4.5);
    ASSERT_TRUE(test_stack.top() == 4.5);
}

TEST(StackWithMyAllocator, test5) {

    Stack<int, My_Allocator::Allocator<int> > test_stack;
    test_stack.push(-1000);
    test_stack.pop();
    test_stack.push(512);

    ASSERT_TRUE(test_stack.top() == 512);
}

TEST(StackWithMyAllocator, test6) {

    Stack<int, My_Allocator::Allocator<int> > test_stack;
    ASSERT_TRUE(test_stack.begin() == test_stack.end());
}



auto main(int argc, char** argv) -> int {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

