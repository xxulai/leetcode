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
                sumlist.push_back(alist.at(i)+blist.at(i));
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