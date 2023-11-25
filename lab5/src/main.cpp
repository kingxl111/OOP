#include <iostream>
#include <map>
#include "allocator.hpp"
#include "stack_container.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::less;
using std::map;

using namespace My_Allocator;

int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {

    try {
        std::map<int, int, std::less<int>, Allocator<std::pair<const int,int>>> my_map;
        
        cout << "Allocator checking for std::map " << endl;
        
        for (size_t i = 0; i < 10; ++i) {
            my_map[i] = fact(i);
        }

        for(const auto& [k,v]: my_map) {
            cout << k << " -> " << v << endl;
        } cout << "=======================================================" << endl << endl;

        cout << "Allocator checking for my Stack " << endl; 

        Stack<int, Allocator<int> > stack;
        size_t elem_count;
        cout << "Enter elements count: ";
        cin >> elem_count;
        for (size_t i = 0; i < elem_count; ++i) {    
            cout << "Enter the integer number: ";
            int n;
            cin >> n;
            stack.push(n);
        }

        for (Stack<int, Allocator<int> >::Iterator i = stack.begin(); i != stack.end(); ++i) {
            cout << *i << endl; // 
        }        
        stack.pop();
        stack.push(42);
        for (Stack<int, Allocator<int> >::Iterator i = stack.begin(); i != stack.end(); ++i) {
            cout << *i << endl; // 
        } 
        cout << "Checking is done=======================================" << endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << endl;
    }

    return 0;
}
