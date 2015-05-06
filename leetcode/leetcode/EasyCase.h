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
	ListNode* EasyCase::reverseList(ListNode* head); //reverse single linked list
};