#include "stdafx.h"

class EasyCase{

public:
	bool isPalindrome(string s);
	vector<vector<int> > generate(int numRows);  //Pascal's Triangle
	vector<int> getRow(int rowIndex); //Pascal's Triangle II
	bool hasPathSum(TreeNode *root, int sum); //Path Sum
	ListNode *deleteDuplicates(ListNode *head); //Remove Duplicates from Sorted List
	int trailingZeroes(int n); //trailingZeros, count prime number of 5 , how many 5s in the given number
};