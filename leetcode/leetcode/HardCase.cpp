#include "stdafx.h"
#include "HardCase.h"

//swap number to the position which is equal to its value
//find first unmatch
int HardCase::firstMissingPositive(vector<int>& nums)
{
	if (nums.size()==0) return 1;
	
	int length=nums.size();

	for(int i=0; i<length; i++)
	{
		if(nums.at(i)!=(i+1))
		{
			int buf=0;
			//swap
			if(nums.size()>=nums.at(i) && nums.at(i)>0)
			{
				int buf1=nums.at(i)-1;
				buf=nums.at(nums.at(i)-1);
				nums.at(nums.at(i)-1)=nums.at(i);
				nums.at(i)=buf;
				i=buf1;
			}
			else
			{
				nums.push_back(nums.at(i));
				nums.at(i)=0;
			}
		}
	}

	for(int i=0; i<length; i++)
	{
		if(nums.at(i)!=(i+1))
		{
			return i+1;
		}
	}

	return nums.at(length-1)+1;
}

bool HardCase::isNumber(string s) {
        string buf=s;
        
        string::iterator it=s.begin();
        //remove space head and tail
        for(; it!=s.end(); it++)
        {
            if(*it!=' ') break; 
        }
        buf=s.substr(it-s.begin());
        
        for(int index=buf.length()-1; index>=0; index--)
        {
            if(buf[index]!=' ')
			{
				buf=buf.substr(0, index+1);
				break;
			}
        }
        
        //if there is invalid space and multiple . inside?
        it=buf.begin();
        for(; it!=buf.end(); it++)
        {
            if(*it==' ') return false;
            if(*it<'0' || *it>'9')
            {
                if(*it=='.' && (*(it+1)>=0 || *(it+1)<=9)) continue;
                else return false;
            }
        }
        if(buf=="") return false;
        return true;
    }