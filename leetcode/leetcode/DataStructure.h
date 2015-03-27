struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
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