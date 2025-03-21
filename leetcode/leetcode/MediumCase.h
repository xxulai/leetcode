﻿#include "stdafx.h"
#include "DataStructure.h"
#include "Util.h"

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
	  int singleNumberII(vector<int>& nums); //Given an array of integers, every element appears three times except for one. Find that single one.
	  bool wordBreak(string s, unordered_set<string>& wordDict); //Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.For example, given s = "leetcode", dict = ["leet", "code"].
	  string removeDuplicateLetters(string s); //Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
	  void reverseWords(string &s); //Given an input string, reverse the string word by word. For example, Given s = "the sky is blue", return "blue is sky the".
	  int divide(int dividend, int divisor); //Divide two integers without using multiplication, division and mod operator. If it is overflow, return MAX_INT. 
	  int searchInsert(vector<int>& nums, int target); //Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. [1,3,5,6], 5 → 2
	  vector<int> countBits(int num); //Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
	  bool hasCycle(ListNode *head); //Given a linked list, determine if it has a cycle in it.
private: 
	Util util;
	//static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist);
};