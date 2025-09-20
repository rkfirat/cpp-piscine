#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// Function to print a test header
void printTestHeader(const std::string& title) {
    std::cout << "\n----------------------------------------\n";
    std::cout << title << std::endl;
    std::cout << "----------------------------------------\n";
}

int main() {
    std::srand(std::time(0));

    printTestHeader("Test 1: Basic functionality");
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    printTestHeader("Test 2: Adding to a full Span");
    try {
        Span sp_full(3);
        sp_full.addNumber(1);
        sp_full.addNumber(2);
        sp_full.addNumber(3);
        std::cout << "Span is full. Trying to add one more number..." << std::endl;
        sp_full.addNumber(4);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught as expected: " << e.what() << std::endl;
    }
    printTestHeader("Test 3: Adding a duplicate number");
    try {
        Span sp_dup(4);
        sp_dup.addNumber(5);
        sp_dup.addNumber(10);
        std::cout << "Trying to add a duplicate number (10)..." << std::endl;
        sp_dup.addNumber(10);
    } catch (const std::exception& e) {
        std::cerr << "Exception caught as expected: " << e.what() << std::endl;
    }

    printTestHeader("Test 4: `shortestSpan()` with < 2 numbers");
    try {
        Span sp_short(5);
        sp_short.addNumber(42);
        std::cout << "Span has only one number. Trying to get shortest span..." << std::endl;
        std::cout << "Shortest Span: " << sp_short.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught as expected: " << e.what() << std::endl;
    }

    printTestHeader("Test 5: `longestSpan()` with < 2 numbers");
    try {
        Span sp_long(5);
        std::cout << "Span has no numbers. Trying to get longest span..." << std::endl;
        std::cout << "Longest Span: " << sp_long.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught as expected: " << e.what() << std::endl;
    }

    printTestHeader("Test 6: Copy Constructor and Assignment Operator");
    try {
        Span original(3);
        original.addNumber(100);
        original.addNumber(200);
        
        Span copied(original);
        std::cout << "Original Span shortest: " << original.shortestSpan() << std::endl;
        std::cout << "Copied Span shortest:   " << copied.shortestSpan() << std::endl;
        Span assigned = Span(5);
        assigned.addNumber(5);
        assigned.addNumber(15);
        assigned = original;
        std::cout << "Original Span longest:  " << original.longestSpan() << std::endl;
        std::cout << "Assigned Span longest:  " << assigned.longestSpan() << std::endl;
        copied.addNumber(300);
        std::cout << "After adding to copied, its shortest: " << copied.shortestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    printTestHeader("Test 7: Large-scale test (10,000 numbers)");
    try {
        Span large_span(10000);
        std::cout << "Adding 10,000 random numbers to the span..." << std::endl;
        for (int i = 0; i < 10000; ++i) {
            large_span.addNumber(std::rand());
        }
        std::cout << "Successfully added 10,000 numbers." << std::endl;
        
        long shortest = large_span.shortestSpan();
        long longest = large_span.longestSpan();
        
        std::cout << "Shortest span for 10,000 numbers: " << shortest << std::endl;
        std::cout << "Longest span for 10,000 numbers: " << longest << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught during large-scale test: " << e.what() << std::endl;
    }

    return 0;
}