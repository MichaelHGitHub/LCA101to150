#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

#define NULL_NODE_VALUE INT32_MIN-99

template<typename T>
void PrintData(T t);

template<typename T>
bool AreVectorEqual(vector<T> v1, vector<T> v2);

template<typename T>
bool Are2DimensionArrayEqual(vector<vector<T>> array1, vector<vector<T>> array2);

template<typename T>
bool Are2DimensionSetEqual(vector<vector<T>> array1, vector<vector<T>> array2);

void PrintList(ListNode* l);
ListNode* GenerateLinkedList(vector<int> v);
bool IsEqualLinkedList(ListNode* l, ListNode* r);

void PrintTree(TreeNode* root);
TreeNode* GenerateTree(vector<int> v);
bool IsSameTree(TreeNode* p, TreeNode* q);

vector<TreeNode*> GenerateTrees(vector<vector<int>> v);

struct TD_L_L
{
    ListNode* input;
    ListNode* output;
};

struct TD_L_L_L
{
    ListNode* input;
    ListNode* input2;
    ListNode* output;
};

struct TD_L_I_L
{
    ListNode* input;
    int input2;
    ListNode* output;
};

struct TD_L_I_I_L
{
    ListNode* input;
    int input2;
    int input3;
    ListNode* output;
};

struct TD_L_T
{
    ListNode* input;
    TreeNode* output;
};

struct TD_T_I
{
    TreeNode* input;
    int output;
};

struct TD_T_I_B
{
    TreeNode* input;
    int input2;
    bool output;
};


struct TD_VI_T
{
    vector<int> input;
    TreeNode* output;
};

struct TD_VI_VI_T
{
    vector<int> input;
    vector<int> input2;
    TreeNode* output;
};

struct TD_T_VI
{
    TreeNode* input;
    vector<int> output;
};

struct TD_T_VVI
{
    TreeNode* input;
    vector<vector<int>> output;
};

struct TD_T_I_VVI
{
    TreeNode* input;
    int input2;
    vector<vector<int>> output;
};

struct TD_I_VT
{
    int input;
    vector<TreeNode*> output;
};

struct TD_T_B
{
    TreeNode* input;
    bool output;
};


struct TD_T_T_B
{
    TreeNode* input;
    TreeNode* input2;
    bool output;
};

struct TD_S_S
{
    string input;
    string output;
};

struct TD_S_I
{
    string input;
    int output;
};

struct TD_S_S_I
{
    string input;
    string input2;
    int output;
};

struct TD_S_S_S_B
{
    string input;
    string input2;
    string input3;
    bool output;
};

struct TD_S_I_S
{
    string input;
    int input2;
    string output;
};

struct TD_S_B
{
    string input;
    bool output;
};

struct TD_S_S_B
{
    string input;
    string input2;
    bool output;
};

struct TD_S_S_S
{
    string input;
    string input2;
    string output;
};


struct TD_S_VS
{
    string input;
    vector<string> output;
};

struct TD_VS_S
{
    vector<string> input;
    string output;
};

struct TD_VS_VVS
{
    vector<string> input;
    vector<vector<string>> output;
};

struct TD_I_S
{
    int input;
    string output;
};

struct TD_I_B
{
    int input;
    bool output;
};

struct TD_I_VI
{
    int input;
    vector<int> output;
};

struct TD_I_VS
{
    int input;
    vector<string> output;
};

struct TD_I_I
{
    int input;
    int output;
};

struct TD_I_I_I
{
    int input;
    int input2;
    int output;
};

struct TD_I_I_VVI
{
    int input;
    int input2;
    vector<vector<int>> output;
};

struct TD_D_I_D
{
    double input;
    int input2;
    double output;
};

struct TD_VI_I
{
    vector<int> input;
    int output;
};

struct TD_VI_B
{
    vector<int> input;
    bool output;
};

struct TD_VI_I_B
{
    vector<int> input;
    int input2;
    bool output;
};

struct TD_VI_VI
{
    vector<int> input;
    vector<int> output;
};

struct TD_VI_I_VI_I_VI
{
    vector<int> input;
    int input2;
    vector<int> input3;
    int input4;
    vector<int> output;
};

struct TD_VVI_I
{
    vector<vector<int>> input;
    int output;
};

struct TD_VVI_I_B
{
    vector<vector<int>> input;
    int input2;
    bool output;
};

struct TD_VVI_VI
{
    vector<vector<int>> input;
    vector<int> output;
};

struct TD_VVI_VI_VVI
{
    vector<vector<int>> input;
    vector<int> input2;
    vector<vector<int>> output;
};

struct TD_VI_VI_D
{
    vector<int> input;
    vector<int> input2;
    double output;
};

struct TD_VI_VVI
{
    vector<int> input;
    vector<vector<int>> output;
};

struct TD_I_VVI
{
    int input;
    vector<vector<int>> output;
};

struct TD_VVI_VVI
{
    vector<vector<int>> input;
    vector<vector<int>> output;
};

struct TD_VI_I_VI
{
    vector<int> input;
    int input2;
    vector<int> output;
};

struct TD_VI_I_VVI
{
    vector<int> input;
    int input2;
    vector<vector<int>> output;
};

struct TD_VI_I_I
{
    vector<int> input;
    int input2;
    int output;
};


struct TD_VL_L
{
    vector< ListNode*> input;
    ListNode* output;
};

struct TD_VVC_B
{
    vector<vector<char>> input;
    bool output;
};

struct TD_VVC_S_B
{
    vector<vector<char>> input;
    string input2;
    bool output;
};

struct TD_VVC_VVC
{
    vector<vector<char>> input;
    vector<vector<char>> output;
};

void PrintInput(TD_S_S testData);
void CheckResults(TD_S_S testData, string result);

void PrintInput(TD_S_I testData);
void CheckResults(TD_S_I testData, int result);

void PrintInput(TD_S_B testData);
void CheckResults(TD_S_B testData, bool result);

void PrintInput(TD_S_S_I testData);
void CheckResults(TD_S_S_I testData, int result);

void PrintInput(TD_S_I_S testData);
void CheckResults(TD_S_I_S testData, string result);

void PrintInput(TD_S_S_B testData);
void CheckResults(TD_S_S_B testData, bool result);

void PrintInput(TD_S_S_S_B testData);
void CheckResults(TD_S_S_S_B testData, bool result);

void PrintInput(TD_S_S_S testData);
void CheckResults(TD_S_S_S testData, string result);

void PrintInput(TD_S_VS testData);
void CheckResults(TD_S_VS testData, vector<string> result);

void PrintInput(TD_I_S testData);
void CheckResults(TD_I_S testData, string result);

void PrintInput(TD_I_B testData);
void CheckResults(TD_I_B testData, bool result);

void PrintInput(TD_I_I testData);
void CheckResults(TD_I_I testData, int result);

void PrintInput(TD_I_I_I testData);
void CheckResults(TD_I_I_I testData, int result);


void PrintInput(TD_I_I_VVI testData);
void CheckResults(TD_I_I_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_I_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_D_I_D testData);
void CheckResults(TD_D_I_D testData, double result);

void PrintInput(TD_I_VI testData);
void CheckResults(TD_I_VI testData, vector<int> result);

void PrintInput(TD_I_VS testData);
void CheckResults(TD_I_VS testData, vector<string> result);

void PrintInput(TD_VI_I testData);
void CheckResults(TD_VI_I testData, int result);

void PrintInput(TD_VI_B testData);
void CheckResults(TD_VI_B testData, bool result);

void PrintInput(TD_VI_I_B testData);
void CheckResults(TD_VI_I_B testData, bool result);


void PrintInput(TD_VS_S testData);
void CheckResults(TD_VS_S testData, string result);

void PrintInput(TD_VS_VVS testData);
void CheckResults(TD_VS_VVS testData, vector<vector<string>> result);
void CheckResults_Unoder(TD_VS_VVS testData, vector<vector<string>> result);

void PrintInput(TD_VI_I_VI testData);
void CheckResults(TD_VI_I_VI testData, vector<int> result);

void PrintInput(TD_VI_I_I testData);
void CheckResults(TD_VI_I_I testData, int result);

void PrintInput(TD_VI_VVI testData);
void CheckResults(TD_VI_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_VI_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVI_VVI testData);
void CheckResults(TD_VVI_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_VVI_VVI testData, vector<vector<int>> result);


void PrintInput(TD_VI_I_VVI testData);
void CheckResults(TD_VI_I_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_VI_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVC_B testData);
void CheckResults(TD_VVC_B testData, bool result);


void PrintInput(TD_VVC_S_B testData);
void CheckResults(TD_VVC_S_B testData, bool result);

void PrintInput(TD_VI_VI_D testData);
void CheckResults(TD_VI_VI_D testData, double result);

void PrintInput(TD_VI_VI testData);
void CheckResults(TD_VI_VI testData, vector<int> result);

void PrintInput(TD_VI_I_VI_I_VI testData);
void CheckResults(TD_VI_I_VI_I_VI testData, vector<int> result);

void PrintInput(TD_VVI_I testData);
void CheckResults(TD_VVI_I testData, int result);

void PrintInput(TD_VVI_I_B testData);
void CheckResults(TD_VVI_I_B testData, int result);

void PrintInput(TD_VVI_VI testData);
void CheckResults(TD_VVI_VI testData, vector<int> result);

void PrintInput(TD_I_VVI testData);
void CheckResults(TD_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVI_VI_VVI testData);
void CheckResults(TD_VVI_VI_VVI testData, vector<vector<int>> result);

void PrintInput(TD_VVC_VVC testData);
void CheckResults(TD_VVC_VVC testData, vector<vector<char>> result);

void PrintInput(TD_L_L testData);
void CheckResults(TD_L_L testData, ListNode* result);

void PrintInput(TD_L_T testData);
void CheckResults(TD_L_T testData, TreeNode* result);

void PrintInput(TD_T_I testData);
void CheckResults(TD_T_I testData, int result);

void PrintInput(TD_T_I_B testData);
void CheckResults(TD_T_I_B testData, bool result);

void PrintInput(TD_VI_VI_T testData);
void CheckResults(TD_VI_VI_T testData, TreeNode* result);

void PrintInput(TD_VI_T testData);
void CheckResults(TD_VI_T testData, TreeNode* result);

void PrintInput(TD_T_VI testData);
void CheckResults(TD_T_VI testData, vector<int> result);

void PrintInput(TD_T_VVI testData);
void CheckResults(TD_T_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_T_VVI testData, vector<vector<int>> result);

void PrintInput(TD_T_I_VVI testData);
void CheckResults(TD_T_I_VVI testData, vector<vector<int>> result);
void CheckResults_Unorder(TD_T_I_VVI testData, vector<vector<int>> result);

void PrintInput(TD_I_VT testData);
void CheckResults(TD_I_VT testData, vector<TreeNode*> result);

void PrintInput(TD_T_B testData);
void CheckResults(TD_T_B testData, bool result);

void PrintInput(TD_T_T_B testData);
void CheckResults(TD_T_T_B testData, bool result);

void PrintInput(TD_L_L_L testData);
void CheckResults(TD_L_L_L testData, ListNode* result);

void PrintInput(TD_L_I_L testData);
void CheckResults(TD_L_I_L testData, ListNode* result);

void PrintInput(TD_L_I_I_L testData);
void CheckResults(TD_L_I_I_L testData, ListNode* result);

void PrintInput(TD_VL_L testData);
void CheckResults(TD_VL_L testData, ListNode* result);




