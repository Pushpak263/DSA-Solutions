#include <iostream>
#include <vector>
#include <algorithm> // Required for sort()

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Use a pair to keep track of the original indices after sorting
        vector<pair<int,int>> a(n);

        // Store value + original index
        for (int i = 0; i < n; i++) {
            a[i] = {nums[i], i};
        }

        // Sort the vector based on the values
        sort(a.begin(), a.end());

        int i = 0, j = n - 1;

        // Two-pointer approach
        while (i < j) {
            int sum = a[i].first + a[j].first;

            if (sum == target) {
                return {a[i].second, a[j].second};
            }
            else if (sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {}; // No solution found
    }
};

int main() {
    Solution sol;
    
    // Example Input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Call the function
    vector<int> result = sol.twoSum(nums, target);

    // Print the result
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}