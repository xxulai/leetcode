#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
	 std::string sval;
	 ListNode(int x) : val(x), next(nullptr) {};
	 ListNode(std::string x) : sval(x), next(nullptr) {}	 
};

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct TreeNodeList{
	TreeNode *node;
	TreeNode *next;
	TreeNodeList(): node(nullptr), next(nullptr){}
};

#endif