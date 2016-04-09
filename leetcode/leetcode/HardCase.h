#include "stdafx.h"
#include "DataStructure.h"

class HardCase{
public:
	int firstMissingPositive(vector<int>& nums); //Given [1,2,0] return 3,  [3,4,-1,1] return 2.
	bool isNumber(string s); //Validate if a given string is numeric.
								/*Some examples:
									"0" => true
									" 0.1 " => true
									"abc" => false
									"1 a" => false
									"2e10" => true
									Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.*/
	string numberToWords(int num); /*123 -> "One Hundred Twenty Three"
									12345 -> "Twelve Thousand Three Hundred Forty Five"
									1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"*/
	string readhundred(int num); //read hundread, int 234->two hundred thirty four
	int calculate(string s); /*"1 + 1" = 2
								" 2-1 + 2 " = 3
								"(1+(4+5+2)-3)+(6+8)" = 23*/
	int cal(string s);
	int stoi(string s);  //from string to integer

	vector<int> d_countone; //dynamic buffer for countone
	int countDigitOne(int n); /*Given n = 13,
								Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.*/
};