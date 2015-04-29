#include "stdafx.h"

class MediumCase{
public:
      vector<vector<int>> pathSumII(TreeNode *root, int sum); //Path Sum II
	  int minimumTotal(vector<vector<int> > &triangle); //Triangle 
	  ListNode *deleteDuplicatesII(ListNode *head); //leaving only distinct numbers from the original list
	  /*
	  Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
	  For example, given the range [5, 7], you should return 4. 
	  */
	  int rangeBitwiseAnd(int m, int n);
	  int rangeBitwiseAndSample(int m, int n); //sample program for rangeBitwiseAnd
	  string fractionToDecimal(int numerator, int denominator); //Given two integers representing the numerator and denominator of a fraction, return the fraction in string format. Given numerator = 2, denominator = 3, return "0.(6)".
	  vector<vector<int> > threeSum(vector<int> &num); //Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
private: 
	//static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist);
};