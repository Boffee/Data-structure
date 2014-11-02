/**
 * @file fib.cpp
 * Contains Fibonacci-number generating functions both utilizing and not
 * utilizing memoization.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "fib.h"

#include <map>

using std::map;

/** 
 * Calculates the nth Fibonacci number where the zeroth is defined to be 
 * 0.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long fib(unsigned long n)
{
    /* Your code goes here! */
    if (n < 1) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

/** 
 * Calculates the nth Fibonacci number where the zeroth is defined to be 
 * 0. This version utilizes memoization.
 * @param n Which number to generate.
 * @return The nth Fibonacci number.
 */
unsigned long memoized_fib(unsigned long n)
{
    static map<unsigned long, unsigned long> memo = { {0, 0}, {1, 1} };
    static map<unsigned long, unsigned long>::iterator lookup;
    lookup = memo.find(n);
    if (lookup != memo.end()){
        return lookup->second;
    }
    memo.insert( std::pair<unsigned long, unsigned long> (n, memoized_fib(n-2) + memoized_fib(n-1)));
    /* Your code goes here! */
    return memo[n];
}
