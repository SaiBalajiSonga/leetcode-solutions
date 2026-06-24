class Solution {
public:
    // Defined mod as a constant
    long long MOD = 1e9 + 7;

    long long pow(long long x, long long n) {
        if (n == 0) {
            return 1;
        }
        
        long long a = 1;
        long long p = x % MOD; // Ensure base is within mod bounds
        
        while (n > 0) {
            if (n & 1) {
                a = (a * p) % MOD; // Apply modulo
            }
            p = (p * p) % MOD;     // Apply modulo
            n /= 2;
        }
        return a;
    }

    int countGoodNumbers(long long n) {
        long long even, odd;
        
        if (n & 1) {
            even = (n + 1) / 2;
            odd = (n - 1) / 2;
        } else {
            even = n / 2;
            odd = n / 2;
        }
        
        // Calculate the combinations modulo 10^9 + 7
        long long even_ways = pow(5, even);
        long long odd_ways = pow(4, odd);
        
        // Multiply them together and take modulo one last time
        return (even_ways * odd_ways) % MOD;
    }
};