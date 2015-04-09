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
};