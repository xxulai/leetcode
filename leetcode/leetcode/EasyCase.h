#include "stdafx.h"

class EasyCase{

public:
	bool isPalindrome(string s);
	vector<vector<int> > generate(int numRows);  //Pascal's Triangle
	vector<int> getRow(int rowIndex); //Pascal's Triangle II
	bool hasPathSum(TreeNode *root, int sum); //Path Sum
	ListNode *deleteDuplicates(ListNode *head); //Remove Duplicates from Sorted List
	int trailingZeroes(int n); //trailingZeros, count prime number of 5 , how many 5s in the given number
	vector<int> plusOne(vector<int> &digits); //Given a non-negative number represented as an array of digits, plus one to the number.  {1, 0} -> {1, 1}
	string addBinary(string a, string b); //Given two binary strings, return their sum (also a binary string).  11+1=100
};