#include "stdafx.h"
#include "MediumCase.h"

static void getPath(TreeNode *leaf, vector<int> &list, vector<vector<int>> &retlist){

	if(leaf->left==nullptr && leaf->right==nullptr) {
		list.push_back(leaf->val);
		retlist.push_back(list);
	}

	list.push_back(leaf->val);

	if(leaf->left!=nullptr){
		getPath(leaf->left, list, retlist);
	}

	if(leaf->right!=nullptr){
		getPath(leaf->right, list, retlist);
	}

	list.pop_back();
}

vector<vector<int>> MediumCase::pathSumII(TreeNode *root, int sum){
	vector<vector<int>> ret;
	vector<int> list;

	getPath(root, list, ret);

	return ret;
}

int MediumCase::minimumTotal(vector<vector<int> > &triangle){
	int ret;



	return ret;
}

ListNode *MediumCase::deleteDuplicatesII(ListNode *head) {

	unordered_map<int, int> mp;
    ListNode* p1=head;
	ListNode* p2=head;
        
    if(p1==NULL) return NULL;
	
	p2=p1->next;
	mp.insert(pair<int, int>(p1->val, 1));

    while(p2!=NULL){
        if(mp.count(p2->val)) 
		{
		    mp[p2->val]+=1;
			if(p2->next==NULL) p1->next=NULL;
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
        
    while(head != NULL && mp[head->val]!=1){
        head=head->next;
    }
        
    if(head==NULL) return head;
       
    p1=head;
    p2=p1->next;
        
    while(p2!=NULL){
        if(mp[p2->val]>1){
            p1->next=p2->next;
            p2=p1->next;
        } else {
            p1=p1->next;
            p2=p2->next;
        }
    }
        
    return head;
}

int MediumCase::rangeBitwiseAndSample(int m, int n) {
        while(n>m){
            n=n&(n-1);
        }
        return m&n;
}

int MediumCase::rangeBitwiseAnd(int m, int n){
	int intret=0x7fffffff;

	int step=0;
	int bitwise=4;    //4 bit per step
	int lowbound=-1;
	int highbound=-1;

	vector<int> flagvec;
	

	for(int i=1; i<8; i++){
		int buf=0x7fffffff-0x10000000*(i-1);
		for(int i=1; i<8; i++){
				buf=(buf>>(i*bitwise))*(int)pow(2.0, bitwise*(i));
				flagvec.push_back(buf);
		}
	}
	for(int i=(flagvec.size()-1); i>=0; i--){
		if(m<=flagvec.at(i)){
			lowbound=i; 
			break;
		}
	}
	for(int i=0; i<flagvec.size(); i++){
		if(n>=flagvec.at(i)){
			highbound=i; 
		}
	}

	

	//m<=n
	if(highbound==-1 || lowbound==-1){
		//no high bound find, both right
		//no low bound find, both left
		step=0;
	}else {
		int tvalue=flagvec.at(lowbound);
		int mod=tvalue%16;
		while(mod==0){
			step++;
			tvalue=tvalue/16;
			mod=tvalue%16;
		}
	}

	for(int i=m>>(step*bitwise); i<=n>>(step*bitwise); i++){
		intret&=i;
		if(intret==0 || i==0x7fffffff) break;
	}
	return intret;
}

