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
private: 
	//static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist);
};