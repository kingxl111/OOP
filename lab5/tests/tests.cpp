#include <gtest/gtest.h>
#include <iostream>
#include "allocator.hpp"
#include "stack_container.hpp"

#define BLOCKS 1024

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

TEST(StackIterator, test1) {
    Stack<int, My_Allocator::Allocator<int> > test_stack;
    test_stack.push(3);
    Stack<int, My_Allocator::Allocator<int> >::Iterator it = test_stack.begin();

    testing::internal::CaptureStdout(); 
    std::cout << *it << std::endl;
    std::string output = testing::internal::GetCapturedStdout(); 

    testing::internal::CaptureStdout(); 
    std::cout << 3 << std::endl;
    std::string ans = testing::internal::GetCapturedStdout(); 
    
    ASSERT_TRUE(ans == output);
}

TEST(StackIterator, test2) {
    Stack<int, My_Allocator::Allocator<int> > test_stack1;
    Stack<int, My_Allocator::Allocator<int> >::Iterator it1 = test_stack1.begin();

    Stack<int, My_Allocator::Allocator<int> > test_stack2;
    Stack<int, My_Allocator::Allocator<int> >::Iterator it2 = test_stack2.begin();
        
    ASSERT_TRUE(it1 == it2);
}

TEST(Allocator, test) {
    Stack<int, My_Allocator::Allocator<int>> test_stack;
    for (size_t i = 0; i < BLOCKS; ++i) {
        test_stack.push(i);
    }
    EXPECT_ANY_THROW(test_stack.push(42));    
}

auto main(int argc, char** argv) -> int {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

