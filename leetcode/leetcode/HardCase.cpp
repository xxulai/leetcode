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

string HardCase::numberToWords(int num)
{
	string number[]={"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	string bit[]={"null", "Thousand", "Million", "Billion", "Trillion"};
	
	if(num==0) return "Zero";

	int count=0;
	int buf=num;

	string ret="";
	string buf_num="";
	string s_num="";

	while(num!=0)
	{
		num=num/10;
		count++;
	}
	while(buf!=0)
	{
		buf_num+=number[buf%10];
		buf=buf/10;
	}
	for(string::reverse_iterator rit=buf_num.rbegin(); rit!=buf_num.rend(); rit++)
	{
		s_num+=*rit;
	}

	int highestbit=0;
	if(count%3==0)
		highestbit=count/3-1;
	else 
		highestbit=count/3;
	for(int i=0; i<count; )
	{
		string input="";
		if(i==0)
		{
			if(count%3==0)
			{
				input=s_num.substr(0, 3); //read highest bit
				i+=3;
			}
			else
			{
				input=s_num.substr(0, count%3); //read highest bit
				i+=count%3;
			}
		}
		else
		{
			input=s_num.substr(i, 3);
			i+=3;
		}
		if(highestbit>=1)
		{
			if(atoi(input.c_str())!=0)
				ret+=readhundred(atoi(input.c_str()))+" "+bit[highestbit]+" ";
		}
		else 
			ret+=readhundred(atoi(input.c_str()));
		highestbit--;
	}

	return ret;
}

string HardCase::readhundred(int num)
{
		string word[]={"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
					"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
					"Twenty", "","","","","","","","","", 
					"Thirty", "","","","","","","","","",
					"Forty" , "","","","","","","","","",
					"Fifty" , "","","","","","","","","",
					"Sixty" , "","","","","","","","","",
				  "Seventy" , "","","","","","","","","",
				   "Eighty" , "","","","","","","","","",
				   "Ninety"  , "","","","","","","","",""
				  };
	string ret="";
	
	if(num==0) return ret;

	if(num>=100)	ret+=word[num/100-1]+" Hundred ";
	num=num-num/100*100;

	if(num!=0) //remove num=100, 200, 300 etc. case
	{
		if(word[num-1]!="") ret+=word[num-1]+" ";
		else 
		{
			ret+=word[num/10*10-1]+" ";
			num=num-num/10*10;
			ret+=word[num-1];
		}
	}
	
	if(ret[ret.length()-1]==' ') ret=ret.substr(0,ret.length()-1);
	return ret;
}

int HardCase::calculate(string s)
{
		int ret=0;

		string buf="";
		string tmp="";
        stack<char> st;
		stack<char> rst;
        
        //remove all spaces
        for(string::iterator it=s.begin(); it!=s.end(); it++)
        {
            if(*it!=' ') buf+=*it;
        }
        
        for(string::iterator it=buf.begin(); it!=buf.end(); it++)
        {
			//equation is always legal
			if(*it==')')
			{
				while(st.top()!='(')
				{
					tmp+=st.top();
					st.pop();
				}
				st.pop(); //pop '('

				//revert tmp
				string rtmp="";
				for(string::reverse_iterator rit=tmp.rbegin(); rit!=tmp.rend(); rit++)
				{
					rtmp+=*rit;
				}
				//calculate the tmp
				stringstream ss;
				int tt=cal(rtmp);
				if(tt<0 && st.size())
				{
					//when eq result is <0, change the op accordingly
					if(st.top()=='+')
					{
						st.pop();
						st.push('-');
					}
					else if(st.top()=='-')
					{
						st.pop();
						st.push('+');
					}
					tt=abs(tt);
				}
				ss<<tt;
				tmp=ss.str();
				for(string::iterator sit=tmp.begin(); sit!=tmp.end(); sit++)
				{
					st.push(*sit);
				}
				tmp="";
			}
            else 
            {
				st.push(*it);
            }
        }
      
		buf="";
		while(st.size())
		{
			rst.push(st.top());
			st.pop();
		}

		buf="";
		while(rst.size())
		{
			buf+=rst.top();
			rst.pop();
		}

		ret=cal(buf);

		return ret;
}

int HardCase::stoi(string s)
{
	int ret=0;
	int carry=0;
	for(string::reverse_iterator it=s.rbegin(); it!=s.rend(); it++)
	{
		ret+=(*it-48)*(int)pow(10.0, carry);
		carry++;
	}
	return ret;
}

int HardCase::cal(string s)
{
	int step=0;
	int ret=0;
	string buf="";
	vector<string> v;
	

	for(string::iterator it=s.begin(); it!=s.end();it++)
	{
		if(*it=='+' || *it=='-')
		{
			stringstream ss;
			v.push_back(buf);
			ss<<*it;
			v.push_back(ss.str());
			buf="";
		}
		else buf+=*it;
	}
	v.push_back(buf);

	ret=stoi(v.at(0));
	for(int index=1; index<v.size();index+=2)
	{
		if(v.at(index)=="+") ret+=stoi(v.at(index+1));
		if(v.at(index)=="-") ret-=stoi(v.at(index+1));
	}

	return ret;
}


int HardCase::countDigitOne(int n) {

        if(d_countone.size()==0)
			d_countone.push_back(0);
        
		if(d_countone.size()>n)
			return d_countone.at(n);
		else
		{
			for(int i=d_countone.size(); i<=n; i++)
			{
				int count=0;
				stringstream ss;
				ss<<i;
				string str=ss.str();
				for(string::iterator it=str.begin(); it!=str.end(); it++)
				{
					if(*it=='1')
						count++;
				}
				d_countone.push_back(count+d_countone.at(d_countone.size()-1));
			}
		}
		return d_countone.back();	
}