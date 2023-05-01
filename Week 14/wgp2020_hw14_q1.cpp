#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> findMinMax(const vector<int>& nums, int left, int right) {
    if (left == right) {
        return {nums[left], nums[left]};
    }
    if (left + 1 == right) {
        if (nums[left] < nums[right]) {
            return {nums[left], nums[right]};
        } else {
            return {nums[right], nums[left]};
        }
    }

    int mid = left + (right - left) / 2;
    vector<int> leftMinMax = findMinMax(nums, left, mid);
    vector<int> rightMinMax = findMinMax(nums, mid + 1, right);

    int minVal = min(leftMinMax[0], rightMinMax[0]);
    int maxVal = max(leftMinMax[1], rightMinMax[1]);

    return {minVal, maxVal};
}

vector<int> minMax(const vector<int>& nums) {
    if (nums.empty()) {
        return {};
    }
    vector<int> minMaxVec = findMinMax(nums, 0, nums.size() - 1);
    return {minMaxVec[0], minMaxVec[1]};
}

int main() {
    vector<int> nums = {3, 7, 1, 9, 1, 9, 99, 0, 1, 4, 8, 2};
    vector<int> result = minMax(nums);

    cout << "Minimum: " << result[0] << endl;
    cout << "Maximum: " << result[1] << endl;

    return 0;
}
