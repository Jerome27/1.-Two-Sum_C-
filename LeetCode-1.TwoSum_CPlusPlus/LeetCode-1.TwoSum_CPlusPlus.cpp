#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        multimap<int, int> indexs = multimap<int, int>();
        for (int i = 0; i < nums.size(); ++i)
        {
            indexs.insert(pair<int, int>(nums[i], i));
        }

        int diff = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            diff = target - nums[i];
            multimap<int, int>::iterator iter = indexs.find(diff);
            for (; iter != indexs.end() && diff == iter->first; ++iter)
            {
                if (i != iter->second)
                    return vector<int>{i, iter->second};
            }
        }

        return vector<int>();
    }
};

string ArrayToString(const vector<int>& input)
{
    string output = "";
    char buffer[16] = "";

    for (int i = 0; i < input.size(); ++i)
    {
        if (i != 0)
            output += ", ";

        _itoa_s(input[i], buffer, 10);
        output += buffer;
    }

    return output;
}

int main()
{
    Solution s;
    vector<int> nums = { 2, 7, 11, 15 };
    vector<int> results = s.twoSum(nums, 9);

    printf("input: [%s]\n", ArrayToString(nums).c_str());
    printf("output: [%s]\n", ArrayToString(results).c_str());
}
