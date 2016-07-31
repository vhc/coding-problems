#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, 0);
        return climb(0, n, cache);
    }
    
private:
    int climb(int current_steps, int n, vector<int>& cache) {
        if (current_steps > n) {
            return 0;
        } else if (current_steps == n) {
            return 1;
        }
        
        if (cache[current_steps] > 0) {
            return cache[current_steps];
        }
        
        int one = climb(current_steps + 1, n, cache);
        int two = climb(current_steps + 2, n, cache);
        
        assert(one >= 0);
        assert(two >= 0);

        cache[current_steps] = one + two;

        return cache[current_steps];
    }
};

int main() {
    Solution solution;
    
    cout << solution.climbStairs(0) << endl;
    cout << solution.climbStairs(1) << endl;
    cout << solution.climbStairs(2) << endl;
    cout << solution.climbStairs(3) << endl;
    cout << solution.climbStairs(4) << endl;
    cout << solution.climbStairs(5) << endl;
    
    return 0;
}