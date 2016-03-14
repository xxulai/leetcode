#include "stdafx.h"
#include "DataStructure.h"

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
	  void reorderList(ListNode* head); //Given a singly linked list L: L0→L1→…→Ln-1→Ln, reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→… 
	  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t); //Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k. 
	  int singleNumber(vector<int>& nums); //Given an array of integers, every element appears twice except for one. Find that single one.
	  vector<int> singleNumberIII(vector<int>& nums);//Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once
	  vector<int> productExceptSelf(vector<int>& nums); //Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].Solve it without division and in O(n).
	  int bulbSwitch(int n); //There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb.
	  int missingNumber(vector<int>& nums);  //Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array. Given nums = [0, 1, 3] return 2.
private: 
	//static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist);
};