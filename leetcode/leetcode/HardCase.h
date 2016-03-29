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
};