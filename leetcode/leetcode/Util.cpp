#include "stdafx.h"
#include "Util.h"

//if use sizeof(arr)/sizeof(int) here, arr is now only a simple int*, size will be different
//we have to input length here
vector<int> Util::getVecByArray(int arr[], int length)
{
	vector<int> ret;
	for(int i=0; i<length; i++)
	{
		ret.push_back(arr[i]);
	}
	return ret;
}

