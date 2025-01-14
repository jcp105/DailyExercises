//Problem 617: Merge two binary trees
//https://leetcode.com/problems/merge-two-binary-trees/
/**
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL)
            return root2;
        if (root2 == NULL)
            return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};

//Problem 104: Maximum Depth of Binary Tree
//https://leetcode.com/problems/maximum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
#include <iostream>
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return std::max(leftDepth, rightDepth) + 1;
    }
};

//Problem 226: Invert Binary Tree
//https://leetcode.com/problems/invert-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *right = invertTree(root->right);
        TreeNode *left = invertTree(root->left);
        root->right = left;
        root->left = right;
        return root;
    }
};

//Problem 136. Single Number
//https://leetcode.com/problems/single-number/
class Solution
{
public:
//Using hashtable/unordered_map
//Space Complexity -> O(n), number of n in nums
//Time Complexity -> O(n),  O(n*1) for loop n, lookup O(1)
#include <vector>
#include <unordered_map>
    int singleNumberHash(std::vector<int> &nums)
    {

        std::unordered_map<int, int> hash_table;
        for (int i : nums)
        {

            hash_table[i] = hash_table[i] + 1;
            //std::cout << "{" <<i << ", " <<hash_table[i] << "}"<< std::endl;
        }
        for (int i : nums)
        {
            if (hash_table[i] == 1)
                return i;
        }
        return 0;
    }

//Using Maths: 2∗(a+b+c)−(a+a+b+b+c)=c TODO
//Time & Space O(n)
#include <unordered_set>
    int singleNumberMaths(std::vector<int> &nums)
    {
        std::unordered_set<int> set;
        int setSum = 0, numSum = 0;
        for (int i : nums)
        {
            if (set.count(i) == 0)
            {
                set.insert(i);
                setSum += i;
            }
            numSum += i;
        }
        return 2 * setSum - numSum;
    }

    //XOR magic: a ^ a = 0 , a ^ b ^ b = a
    //Time O(n), Space O(1);
    int singleNumberXOR(std::vector<int> &nums)
    {
        int solution = 0;
        for (int i : nums)
        {
            solution ^= i;
        }
        return solution;
    }
};

//94. Binary Tree Inorder Traversal
//https://leetcode.com/problems/binary-tree-inorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result; 
        inorderHelper(root, result); 
        return result; 
    }
    
    void inorderHelper(TreeNode* root, vector<int> &result){
        if(root != NULL) {
            inorderHelper(root->left, result);
            result.push_back(root->val);
            inorderHelper(root->right, result);
        }
    }
};