#include "stdafx.h"
#include "DataStructure.h"

class EasyCase{

public:
	bool isPalindrome(string s);
	bool EasyCase::isPalindrome_lessspace(ListNode* head); //Given a singly linked list, determine if it is a palindrome. Could you do it in O(n) time and O(1) space?
	vector<vector<int> > generate(int numRows);  //Pascal's Triangle
	vector<int> getRow(int rowIndex); //Pascal's Triangle II
	bool hasPathSum(TreeNode *root, int sum); //Path Sum
	ListNode *deleteDuplicates(ListNode *head); //Remove Duplicates from Sorted List
	int trailingZeroes(int n); //trailingZeros, count prime number of 5 , how many 5s in the given number
	vector<int> plusOne(vector<int> &digits); //Given a non-negative number represented as an array of digits, plus one to the number.  {1, 0} -> {1, 1}
	string addBinary(string a, string b); //Given two binary strings, return their sum (also a binary string).  11+1=100
	int lengthOfLastWord(const char *s); //Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

    string translate(string s);
	string countAndSay(int n); //1, 11, 21, 1211, 111221, ..  21 is read off as "one 2, then one 1" or 1211.

	int strStr(char *haystack, char *needle); //Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

	int removeElement(int A[], int n, int elem); //Given an array and a value, remove all instances of that value in place and return the new length. 
	int removeDuplicates(int A[], int n); //Given a sorted array, remove the duplicates in place such that each element appear only once, A = [1,1,2], length = 2, and A is now [1,2]. 
	string convert(string s, int nRows); //convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
	int reverse(int x); //321->123
	/*
	The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. 
	Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, 
	and interprets them as a numerical value.
	*/
	int atoi(string str); 

	bool isPalindrome(int x); //int is Palindrome or not
	string longestCommonPrefix(vector<string> &strs); //input {abc, ab, a} output {a}
	ListNode *removeNthFromEnd(ListNode *head, int n); //Given linked list: 1->2->3->4->5, and n = 2.  output 1->2->3->5
	/*
		Write an algorithm to determine if a number is "happy".

		A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

		Example: 19 is a happy number

		12 + 92 = 82
		82 + 22 = 68
		62 + 82 = 100
		12 + 02 + 02 = 1
	*/
	bool isHappy(int n); //happy number
	ListNode* removeElements(ListNode* head, int val);//Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6   Return: 1 --> 2 --> 3 --> 4 --> 5 
	int countPrimes(int n); //Count the number of prime numbers less than a non-negative number, n
	bool isIsomorphic(string s, string t); //Two strings are isomorphic if the characters in s can be replaced to get t.Given "egg", "add", return true. Given "foo", "bar", return false.
	bool containsDuplicate(vector<int>& nums); //Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
	bool containsNearbyDuplicate(vector<int>& nums, int k); //Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
	int addDigits(int num); //Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
	bool isUgly(int num); //Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
	void deleteNode(ListNode* node); //Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4
	void moveZeroes(vector<int>& nums); //For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
	bool isAnagram(string s, string t); //Given two strings s and t, write a function to determine if t is an anagram of s.  s = "anagram", t = "nagaram", return true.
	int NremoveDuplicates(vector<int>& nums); //Given input array nums = [1,1,2], Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
	bool isPowerOfTwo(int n); //Given an integer, write a function to determine if it is a power of two.
	int titleToNumber(string s); //Given a column title as appear in an Excel sheet, return its corresponding column number. A -> 1  AB -> 28
	int majorityElement(vector<int> &num); //Given an array of size n, find the majority element. The majority element is the element that appears more than [n/2] times.
	int hammingWeight(uint32_t n); //For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
	ListNode* reverseList(ListNode* head); ////reverse single linked list
	ListNode* reverseList2(ListNode* head);
	bool isPowerOfThree(int n); //Given an integer, write a function to determine if it is a power of three. 
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2); //Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
	int firstBadVersion(int n); //Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad. 
	vector<string> summaryRanges(vector<int>& nums); //Given a sorted integer array without duplicates, return the summary of its ranges. 
	int sumRange(int i, int j); //Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive. DP problem!!
	bool wordPattern(string pattern, string str); //pattern = "abba", str = "dog cat cat dog" should return true.   pattern = "aaaa", str = "dog cat cat cat" should return false
	string getHint(string secret, string guess); //Secret number:  "1807" Friend's guess: "7810"  return 1A3B    Secret number:  "1123"   Friend's guess: "0111"  return 1A1B
	bool isValid(string s); //Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H); //Find the total area covered by two rectilinear rectangles in a 2D plane. Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
	ListNode* oddEvenList(ListNode* head); //Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
	string reverseString(string s);
};