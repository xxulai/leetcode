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

string Util::replaceAll(string s, char c)
{
	vector<char> ch;
	string strbuf="";

	for(string::iterator it=s.begin(); it!=s.end(); it++)
	{
		if(*it!=c) ch.push_back(*it);
	}
	for(int i=0; i<ch.size(); i++)
		strbuf+=ch.at(i);
	return strbuf;
}

