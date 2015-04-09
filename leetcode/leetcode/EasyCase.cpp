#include "stdafx.h"
#include "EasyCase.h"

bool EasyCase::isPalindrome(string s){
	bool ret=true;
	string strvalue="";

	std::unordered_map<char, int> mp;
	std::unordered_map<char, char> mp1;

	if(s=="") return true;

	//insert alphanumerics
	char tvalue='0';
	for(int i=0; i<10; i++){
		mp.insert(std::pair<char, int>(tvalue, 0));
		tvalue++;
	}

	tvalue='a';
	char tvalue1='A';
	for(int i=0; i<26; i++){
		mp1.insert(std::pair<char, int>(tvalue, tvalue1));
		mp1.insert(std::pair<char, int>(tvalue1, tvalue));
		tvalue++;
		tvalue1++;
	}

	for(string::iterator sit=s.begin(); sit!=s.end(); sit++){
		if(mp.count(*sit) || mp1.count(*sit)){
			strvalue+=*sit;
		}
	}
	
	string::iterator sit1=strvalue.begin();
	string::reverse_iterator sit2=strvalue.rbegin();
	int steps=strvalue.length()/2;

	for(; sit1<=strvalue.begin()+steps; sit1++){
			if(*sit1!=*sit2 && mp1[*sit1]!=*sit2){
				ret=false;
				break;
			} else{
				sit2++;
			}
	}
	return ret;
}

vector<vector<int>> EasyCase::generate(int numRows) {
    vector<vector<int>> ret;
	vector<int> lastRow;
	vector<int> currentRow;

	lastRow.push_back(1);
	currentRow.push_back(1);
	currentRow.push_back(1);

	if(numRows==0) return ret;
	else if(numRows==1){
		ret.push_back(lastRow);
		return ret;
	} else if(numRows==2){
		ret.push_back(lastRow);
		ret.push_back(currentRow);
		return ret;
	}
	
	ret.push_back(lastRow);
	ret.push_back(currentRow);


	lastRow.clear();
	lastRow.insert(lastRow.begin(), currentRow.begin(), currentRow.end());
	for(int i=2; i<numRows; i++){
		currentRow.clear();
		currentRow.push_back(1);
    	for(vector<int>::iterator iit=lastRow.begin(); (iit+1)!=lastRow.end(); iit++){
			currentRow.push_back(*iit+*(iit+1));
		}
		
		currentRow.push_back(1);
		ret.push_back(currentRow);
		lastRow.clear();
		lastRow.insert(lastRow.begin(), currentRow.begin(), currentRow.end());
	}
	
	return ret;
}

vector<int> EasyCase::getRow(int rowIndex) {
	vector<int> lastRow;
	vector<int> currentRow;

	lastRow.push_back(1);
	currentRow.push_back(1);
	currentRow.push_back(1);

	if(rowIndex==0) return lastRow;
	else if(rowIndex==1){
		return currentRow;
	} 

	lastRow.clear();
	lastRow.insert(lastRow.begin(), currentRow.begin(), currentRow.end());
	for(int i=1; i<rowIndex; i++){
		currentRow.clear();
		currentRow.push_back(1);
    	for(vector<int>::iterator iit=lastRow.begin(); (iit+1)!=lastRow.end(); iit++){
			currentRow.push_back(*iit+*(iit+1));
		}
		currentRow.push_back(1);
		lastRow.clear();
		lastRow.insert(lastRow.begin(), currentRow.begin(), currentRow.end());
	}
	
	return currentRow;
}

bool EasyCase::hasPathSum(TreeNode *root, int sum){
	if(root == NULL)return false;
    if(root->left == NULL && root->right == NULL && root->val == sum)
        return true;
	//detect sub left tree to find the sum
    if(root->left && hasPathSum(root->left, sum - root->val))
        return true;
	//detect sub right tree to find the sum
    if(root->right && hasPathSum(root->right, sum - root->val))
        return true;
    return false;
}

ListNode *EasyCase::deleteDuplicates(ListNode *head) {
        unordered_map<int, int> mp;
        ListNode* p1=head;
		ListNode* p2=head;
        
        if(p1==nullptr) return nullptr;
		
		p2=p1->next;
		mp.insert(pair<int, int>(p1->val, 1));

        while(p2!=nullptr){
            if(mp.count(p2->val)) 
			{
				if(p2->next==nullptr) p1->next=nullptr;
				else {
				   p1->next=p2->next;
				   p2=p1->next;
				   continue;
				}
			}
            else mp.insert(pair<int, int>(p2->val, 1));
            
            p1=p1->next;
			p2=p2->next;
        }
        
        return head;
        
    }

int EasyCase::trailingZeroes(int n) {
	if ( n<0 ) return -1;
    int count = 0;
    for (long i=5; n/i>=1; i*=5) {
        count += n / i;
    }        
    return count;
}

vector<int> EasyCase::plusOne(vector<int> &digits) {
        int carry=0;
        
        for(vector<int>::reverse_iterator rit=digits.rbegin(); rit!=digits.rend(); rit++){
			if(rit==digits.rbegin()){
				if(*rit+1==10){
					carry=1;
					*rit=0;
				} else *rit=*rit+1;
			} else if(*rit+carry==10){
				*rit=0;
				carry=1;
			} else{
				*rit+=carry;
				carry=0;
			}
        }
        
        if(carry==1) digits.insert(digits.begin(), 1);
        
        return digits;
    }


string EasyCase::addBinary(string a, string b) {
        int carry=0;
        string ret="";
        vector<int> alist;
        vector<int> blist;
        vector<int> sumlist;
        
        for(string::reverse_iterator sit=a.rbegin(); sit!=a.rend(); sit++)
			if(*sit=='1') alist.push_back(1);
			else alist.push_back(0);
            
        for(string::reverse_iterator sit=b.rbegin(); sit!=b.rend(); sit++)
            if(*sit=='1') blist.push_back(1);
			else blist.push_back(0);
        
        int length=alist.size()<blist.size()?alist.size():blist.size();
        
        for(int i=0; i<length; i++){
            if(alist.at(i)+blist.at(i)+carry>=2){
                sumlist.push_back(alist.at(i)+blist.at(i)+carry-2);
				carry=1;
            } else {
                sumlist.push_back(alist.at(i)+blist.at(i)+carry);
                carry=0;
            }
        }
        
        int difflength=abs((int)blist.size()-(int)alist.size());
        
        if(alist.size()<blist.size()){
            for(int i=length; i<length+difflength; i++)
            {
                if(carry+blist.at(i)==2){
                    sumlist.push_back(0);
                    carry=1;
                }
                else{
                    sumlist.push_back(carry+blist.at(i));
                    carry=0;
                }
            }
        }
        
        if(alist.size()>blist.size()){
            for(int i=length; i<length+difflength; i++)
            {
                if(carry+alist.at(i)==2){
                    sumlist.push_back(0);
                    carry=1;
                }
                else{
                    sumlist.push_back(carry+alist.at(i));
                    carry=0;
                }
            }
        }
        
        if(carry==1) sumlist.push_back(1);
        
        for(vector<int>::reverse_iterator rit=sumlist.rbegin(); rit!=sumlist.rend(); rit++)
		{
			ret+=std::to_string((_ULonglong)*rit);
		}
            
        
        return ret;
    }

int EasyCase::lengthOfLastWord(const char *s)
{
	string str=s;
	vector<char> strvec;

	if(str=="") return 0;

	for(string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); rit++){

		if(*rit==' ' && strvec.size()==0) continue; //skip ending space

		if(*rit!=' ') strvec.push_back(*rit);
		else break;
	}

	return strvec.size();
}


string EasyCase::translate(string s){
        unordered_map<int, char> mp;
        vector<vector<char>> arr;
        vector<char> tarr;
        string ret="";
        int count=0;
        
        for(int i=0; i<10; i++)
        {
            mp.insert(pair<int, char>(i, '0'+i));
        }

		tarr.push_back(*s.begin());
        for(string::iterator sit=s.begin()+1; sit!=s.end(); sit++){
			if(*sit == tarr.at(0)) {
				tarr.push_back(*sit);
				continue;
			}
            else{
                arr.push_back(tarr);
                tarr.clear();
				tarr.push_back(*(sit));
            }
        }

		if(tarr.size()!=0) arr.push_back(tarr);
        
		
        for(int i=0; i<arr.size(); i++){
            for(int j=0; j<arr.at(i).size(); j++){
                count++;
            }
			stringstream ss1, ss2;
			ss1<<mp[count];
			ss2<<arr.at(i).at(0);
			string str1, str2;
			ss1>>str1;
			ss2>>str2;
			
			ret+=str1+str2;		

            count=0;
        }
        
        return ret;
    }

string EasyCase::countAndSay(int n) {
        
        if(n==0) return "";
        
        string ret="";
        vector<char> charray;

		ret="1";

		for(int i=1; i<n ;i++){
			ret=translate(ret);
		}
        
        return ret;
}

int EasyCase::strStr(char *haystack, char *needle) {
        
        if(haystack==NULL || needle==NULL) return -1;
        
        string hstack(haystack);
        string ndle(needle);
		bool match=true;

		if(hstack==ndle || ndle=="") return 0;

		for(string::iterator sit=hstack.begin(); sit!=hstack.end(); sit++){
			if(*sit==*ndle.begin()){
				match=true;
				//find match sub string
				for(int i=0; i<ndle.size(); i++){
					if((sit+i)!=hstack.end()){
						if(*(sit+i)!=*(ndle.begin()+i)){
							match=false;
							break;
						}
					}
					else return -1;
				}

				if(match) return sit-hstack.begin();
			}
		}
        
        return -1;
}

int EasyCase::removeElement(int A[], int n, int elem) {
        int num=0,i;  
        for(i=0;i<n;++i)  
            if(A[i]!=elem)A[num++]=A[i];  
        return num; 
}

int EasyCase::removeDuplicates(int A[], int n) {
      int pre, cur;  
      pre = 1; cur = 1;  
      if(n <=1) return n;  
      while(cur<n)  
      {  
        if(A[cur] == A[cur-1])  
        {  
          cur++;  
          continue;  
        }  
        A[pre] = A[cur];  
        pre++;  
        cur++;  
      }  
     return pre;  
}

string EasyCase::convert(string s, int nRows) {
        vector<vector<char>> vec;
		vector<char> tvec;
        string ret="";
		int step=0;

		for(int i=0; i<nRows; i++)
		{
			for(string::iterator sit=s.begin()+i; sit!=s.end();){
				tvec.push_back(*sit);

				if(i==0 || i==nRows-1){
					if((s.end()-sit)>=nRows)
						step=nRows+1;
					else
						break;
				} else{
					if((s.end()-sit)>=nRows)
						step=nRows-1;
					else
						break;
					
				}
				sit+=step;
			}
			vec.push_back(tvec);
			tvec.clear();
		}

		for(int i=0; i<vec.size(); i++)
			for(vector<char>::iterator it=vec.at(i).begin(); it<vec.at(i).end(); it++)
			{
				ret+=*it;
			}
		   
        return ret;
    }

//when input is large enough, reverse it will still cause overflow problem
int EasyCase::reverse(int x) {
        int ret=0;
        int buf=x;

        while(x!=0){
            ret=ret*10+x%10;
            x=x/10;
			if((x>0 && ret>(INT_MAX/10)) || (x<0 && abs(ret)>abs(INT_MIN/10))) return 0;
        }
        
        return ret;
    }

int EasyCase::atoi(string str) {
		int ret=0;
		string hasflag="";
		string::iterator start=str.begin();
		string::iterator endpos=str.begin();

		if(str=="") return 0;

		//remove heading space
		for(string::iterator it=str.begin(); it!=str.end(); it++){
			if(*it==' ') continue;
			else {
			  start=it;
			  break;
			}
		}
		//start with flag
		if((*start=='+' || *start=='-') && *(start+1)>='0' && *(start+1)<='9')
		{
			hasflag=*start;
			start++;
		}
		else if(*start=='+' || *start=='-')  //illeagal char after + -
			return 0;

		//find as many numeric value as possible
		string strbuf="";
		for(string::iterator it=start; it!=str.end(); it++){
			if(*(it)>='0' && *(it)<='9'){
				strbuf+=*it;
				continue;
			}
			else break;
		}
		/*
		*  number   1       2          3456789  /
		*         begin() begin()+1            end()
		*
		*   every iterator only 1 char, 
		*   it=begin()--> it->123456789
		*   it+1 -> 23456789
		*   it=end() --> it->/
		*/
		for(string::iterator it=strbuf.begin(); it!=strbuf.end(); it++){
			if(hasflag=="-" && ret>abs(INT_MIN+1)/10) return INT_MIN;
			else if(hasflag!="-" && ret>(INT_MAX)/10) return INT_MAX;

			if(hasflag=="-" && ret==abs(INT_MIN+1)/10) 
			{  //remove { } excution change!!!!!
				if((it+1)!=strbuf.end() || (*it-48)>=abs(INT_MIN+1)%10+1) 
					return INT_MIN;  //left more than 2 digits or number is bigger than 8
			} else if(hasflag!="-" && ret==(INT_MAX)/10){
				if((it+1)!=strbuf.end() || (*it-48)>=abs(INT_MAX)%10) 
					return INT_MAX;
			}
			ret=ret*10+(*it-48);
		}

		if(hasflag=="-") ret=ret*-1;

		return ret;
    }

bool EasyCase::isPalindrome(int x) {

	if(x<0) return false;

    string strbuf="";
    unordered_map<int, char> mp;
        
    for(int i=0; i<=9; i++){
       mp.insert(pair<int, char>(i, i+48));
    }
        
    while(x!=0){
        strbuf+=mp[x%10];
        x=x/10;
    }
        
    string rstrbuf="";
	for(string::reverse_iterator rit=strbuf.rbegin(); rit!=strbuf.rend(); rit++){
		rstrbuf+=*rit;
	}

	return strbuf==rstrbuf?true:false;
}

string EasyCase::longestCommonPrefix(vector<string> &strs) {
        
        if(strs.size()==0) return "";
        
        int len=strs[0].length();
        
		for(int i=1; i<strs.size(); i++)
        {
            for(int j=0; j<len; j++)
			{
				//Important!!!  for a string strs[i], strs[i][j] is corresponding to the jth char in the string!!!
                if(strs[0][j]==strs[i][j]) {
                    continue;
                }
                else {
                    len=j;
                    break;
                }
            }
        }

		//int count=0;
        //string::iterator tit=strs[0].begin();
		/*for(int i=1; i<strs.size(); i++)
        {
            for(string::iterator sit=strs.at(i).begin(); sit!=strs.at(i).begin()+len; sit++)
            {
                if(*sit==*(tit+count)) {
                    count++;
                    continue;
                }
                else {
                    len=sit-strs.at(i).begin();-
                    break;
                }
            }
			count=0;
        }*/
        
        
        return strs[0].substr(0, len);
}

    ListNode *EasyCase::removeNthFromEnd(ListNode *head, int n) {
        int len=0;
		ListNode *thead=head;
        
		while(thead!=NULL){
            len++;
            thead=thead->next;
        }

		if(head==NULL || len<n) return NULL;

        if(len==n){
			head=head->next;
			return head;
		}

		if(n==0) return head;

        thead=head;
        for(int i=0; i<len-n-1; i++){
			//Move to previous pos of the node to be deleted
            thead=thead->next;
        }
		thead->next=thead->next->next;

        return head;
    }