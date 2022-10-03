#include <iostream>
#include <vector>
#include <string>

using std::string;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int map[26] = {0};

        for (int i = 0; i < magazine.size(); i++) {
            map[(magazine[i] - 'a')]++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            map[(ransomNote[i] - 'a')]--;
        }


        for (int i  = 0; i < 26; i++) {
            if (map[i] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    std::cout << solution.canConstruct("aa","aab")  << std::endl;

    return 0;
}