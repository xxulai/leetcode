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
		map<char, int> mp;
		map<string, int> s_mp;
		string sa[]={"lg", "e", "tan", "ctg"};

		for(char c='0'; c<='9'; c++)
		{
			mp.insert(pair<char, int>(c, 0));
		}
		mp.insert(pair<char, int>('.', 0));
		mp.insert(pair<char, int>('-', 0));
		mp.insert(pair<char, int>('+', 0));
		
	    for(int index=0; index<sizeof(sa)/sizeof(string); index++)
		{
			s_mp.insert(pair<string, int>(sa[index], 0));
		}
		
        string::iterator it=s.begin();
        //remove space, -, + head 
        for(; it!=s.end(); it++)
        {
			if(*it=='-' || *it=='+')
			{
				it++;
				break; //only remove first - or +
			}
            if(*it!=' ')
			{
				break; 
			}
        }
        buf=s.substr(it-s.begin());
        
        //remove space tail, if there is + - at tail, return false
        for(int index=buf.length()-1; index>=0; index--)
        {
            if(buf[index]=='-' || buf[index]=='+')
            {
                return false;
            }
            if(buf[index]!=' ')
			{
				buf=buf.substr(0, index+1);
				break;
			}
        }
        
		//if there is still multi . + - in the string, return false
		for(string::iterator iit=buf.begin(); iit!=buf.end(); iit++)
		{
			if(mp.count(*iit)) 
			{
				mp[*iit]++;
			}
			else if(*iit==' ')
			{
				return false;
			}
		}

		if(mp['+'] && buf[buf.find("+")-1]!='e')
		{
			return false; //only e+6 is legal
		}

		if(mp['-'] && buf[buf.find("-")-1]!='e') 
			return false; //only e-6 is legal

		bool withNum=false;
		for(char cc='0'; cc<='9'; cc++)
		{
			if(mp[cc]!=0) withNum=true;
		}
		if(!withNum) return false;  //there is no number in string

		for(map<char, int>::iterator mit=mp.begin(); mit!=mp.end(); mit++)
		{
			mit->second=0;
		}

        //if there is invalid space and multiple . inside?
        it=buf.begin();
        for(; it!=buf.end(); it++)
        {
			if(mp.count(*it))
			{
				if(*it=='.'&& mp[*it]==1) return false; //there is more that 1 '.' in the string
				mp[*it]++;
			}
			else
			{
				//consider 2e0 lg etc. case 3. can be ignored here
				for(map<string, int>::iterator sit=s_mp.begin(); sit!=s_mp.end(); sit++)
				{
					int index=buf.find(sit->first);
					if(sit->first=="e")
					{
						if(buf.substr(index+1).find(".")!=-1) return false;
						if(buf.substr(index+1).find("e")!=-1) return false;
					}

					if(index>=0 && isNumber(buf.substr(0,index)) && isNumber(buf.substr(index+1)))
					{
						return true;
					}
				}
				return false;
			}
        }
        if(buf=="" || buf==".") return false;

		

        return true;
}