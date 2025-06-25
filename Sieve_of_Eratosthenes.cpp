// Sieve of Eratosthenes
// Difficulty: MediumAccuracy: 47.43%Submissions: 65K+Points: 4
// Given a positive integer n, calculate and return all prime numbers less than or equal to n using the Sieve of Eratosthenes algorithm.
// A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

// Examples:

// Input: n = 10
// Output: [2, 3, 5, 7]
// Explanation: Prime numbers less than equal to 10 are 2, 3, 5 and 7.
// Input: n = 35

// Approach:
//  1. Create a boolean array to store prime status of numbers.
//  2. Initialize all numbers as prime except 0 and 1.
//  3. Iterate from 2 to the square root of n.
//  4. For each prime number, mark its multiples as non-prime.
//  5. Collect all numbers that remain marked as prime.
//  6. Return the list of prime numbers.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sieve(int n)
    {
        // code here
        vector<int> ans;
        vector<bool> prime(n + 1, true);
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {

                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
                ans.push_back(i);
        }

        return ans;
    }
};