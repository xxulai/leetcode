#include "stdafx.h"

class MediumCase{
public:
      vector<vector<int>> pathSumII(TreeNode *root, int sum); //Path Sum II
	  int minimumTotal(vector<vector<int> > &triangle); //Triangle 
	  ListNode *deleteDuplicatesII(ListNode *head); //leaving only distinct numbers from the original list
private: 
	//static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist);
};