#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, list<int>> indexs = map<int, list<int>>();
        for (int i = 0; i < nums.size(); ++i)
        {
            map<int, list<int>>::iterator iter = indexs.find(nums[i]);
            if (iter == indexs.end())
                indexs[nums[i]] = list<int>{ i };
            else
                iter->second.push_back(i);
        }

        int diff = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            diff = target - nums[i];
            map<int, list<int>>::iterator iter = indexs.find(diff);
            if (iter != indexs.end())
            {
                for (list<int>::iterator j = iter->second.begin(); j != iter->second.end(); ++j)
                {
                    if (i != *j)
                        return vector<int>{i, * j};
                }
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
