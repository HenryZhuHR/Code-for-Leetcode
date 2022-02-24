/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
const char EMPTY_CHAR=' ';
        int right=s.length()-1;
        int word_length=0;
        while(right>=0 && s[right]==EMPTY_CHAR){
            right--;
        }
        while(right>=0 && s[right]!=EMPTY_CHAR){
            word_length++;
            right--;
        }
        return word_length;
    }
};
// @lc code=end

