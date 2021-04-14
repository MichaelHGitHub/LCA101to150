#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include "common.h"

using namespace std;

template<typename T>
void PrintData(T t)
{
    std::cout << t;
}

template<>
void PrintData(ListNode* l)
{
    PrintList(l);
}

template<>
void PrintData(TreeNode* t)
{
    PrintTree(t);
}

template<typename T>
void PrintData(vector<T> v)
{
    std::cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i];
        if (i != v.size() - 1)
        {
            std::cout << " ,";
        }
    }
    std::cout << "}";
}

template<>
void PrintData(vector<ListNode*> vl)
{
    for (int i = 0; i < vl.size(); i++)
    {
        PrintList(vl[i]);
        std::cout << endl;
    }
}

template<>
void PrintData(vector<TreeNode*> v)
{
    std::cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        PrintData(v[i]);
        cout << endl;
    }
    std::cout << "}";
}

template<typename T>
void PrintData(vector<vector<T>> vv)
{
    std::cout << "{" << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        std::cout << "{";
        for (int j = 0; j < vv[i].size(); j++)
        {
            std::cout << vv[i][j];
            if (j != vv[i].size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "}";

        if (i != vv.size() - 1)
        {
            std::cout << ", ";
        }

        std::cout << endl;
    }
    std::cout << "} ";
}

template<typename T>
bool AreVectorEqual(vector<T> v1, vector<T> v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        int j = 0;
        for (; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                break;
            }
        }

        if (j >= v2.size())
        {
            return false;
        }
    }

    for (int j = 0; j < v2.size(); j++)
    {
        int i = 0;
        for (; i < v1.size(); i++)
        {
            if (v1[i] == v2[j])
            {
                break;
            }
        }

        if (i >= v1.size())
        {
            return false;
        }
    }
}

template<>
bool AreVectorEqual(std::vector<TreeNode*> v1, std::vector<TreeNode*> v2)
{
    for (int i = 0; i < v1.size(); i++)
    {
        int j = 0;
        for (; j < v2.size(); j++)
        {
            if (IsSameTree(v1[i], v2[j]))
            {
                break;
            }
        }

        if (j >= v2.size())
        {
            return false;
        }
    }

    for (int j = 0; j < v2.size(); j++)
    {
        int i = 0;
        for (; i < v1.size(); i++)
        {
            if (IsSameTree(v1[i], v2[j]))
            {
                break;
            }
        }

        if (i >= v1.size())
        {
            return false;
        }
    }
}

template<typename T>
bool Are2DimensionArrayEqual(vector<vector<T>> array1, vector<vector<T>> array2)
{
    if (array1.size() != array2.size())
    {
        return false;
    }

    for (int i = 0; i < array1.size(); i++)
    {
        if (array1[i].size() != array2[i].size())
        {
            return false;
        }

        for (int j = 0; j < array1[i].size(); j++)
        {
            if (array1[i][j] != array2[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

template<typename T>
bool Are2DimensionSetEqual(vector<vector<T>> array1, vector<vector<T>> array2)
{
    if (array1.size() != array2.size())
    {
        return false;
    }

    {
        int i = 0;
        for (; i < array1.size(); i++)
        {
            int j = 0;
            for (; j < array2.size(); j++)
            {
                if (array1[i].size() == array2[j].size())
                {
                    if (AreVectorEqual(array1[i], array2[j]))
                    {
                        break;
                    }
                }
            }

            if (j >= array2.size())
            {
                return false;
            }

        }
    }

    {
        int i = 0;
        for (; i < array2.size(); i++)
        {
            int j = 0;
            for (; j < array1.size(); j++)
            {
                if (array2[i].size() == array1[j].size())
                {
                    if (AreVectorEqual(array2[i], array1[j]))
                    {
                        break;
                    }
                }
            }

            if (j >= array1.size())
            {
                return false;
            }
        }
    }

    return true;
}


void PrintInput(TD_I_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout<< endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_I_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_I_I_I testData, int result)
{

    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_I_VVI testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_I_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_I_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_D_I_D testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_D_I_D testData, double result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout<< endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_S testData, string result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout<< endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

}

void CheckResults(TD_S_S_I testData, int result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout<< endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_I_S testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_S_I_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_B testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_S_S_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << testData.output << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_S_B testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;

}
void CheckResults(TD_S_S_S_B testData, bool result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << testData.output << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_S_S testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_S_S_S testData, string result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << testData.output << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_S_VS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_S_VS testData, vector<string> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_I_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_I_VS testData, vector<string> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

}

void CheckResults(TD_VI_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VI_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VI_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_I_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VS_S testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VS_S testData, string result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VS_VVS testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VS_VVS testData, vector<vector<string>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unoder(TD_VS_VVS testData, vector<vector<string>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output,result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_I testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

}

void CheckResults(TD_VI_I_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_VI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVI_VVI testData) 
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VVI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
    }

    std::cout << endl;
}
void CheckResults_Unorder(TD_VVI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
    }

    std::cout << endl;
}


void PrintInput(TD_VI_I_VVI testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result); 
    cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_VI_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;

        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVC_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::wcout << endl;
}

void CheckResults(TD_VVC_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVC_S_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::wcout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::wcout << endl;
}
void CheckResults(TD_VVC_S_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI_D testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_VI_D testData, double result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VI_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_VI_I_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;

    std::cout << "Input4 :";
    PrintData(testData.input4);
    std::cout << endl;
}
void CheckResults(TD_VI_I_VI_I_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VVI_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VVI_I testData, int result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVI_I_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VVI_I_B testData, int result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VVI_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VVI_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_I_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VVI_VI_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VVI_VI_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}


void PrintInput(TD_VVC_VVC testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}

void CheckResults(TD_VVC_VVC testData, vector<vector<char>> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;

        std::cout << "Expect :";
        PrintData(testData.output);
        std::cout << endl;

        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_I_VI testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_VI_I_VI testData, vector<int> result)
{
    std::cout << "Output :";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect :";
        PrintData(result);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VL_L testData)
{
    std::cout << "Input :" << endl;
    PrintData(testData.input);
    std::cout << endl;

}

void CheckResults(TD_VL_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
    }

    std::cout << endl;
}

ListNode* GenerateLinkedList(vector<int> v)
{
    if (v.size() < 1)
    {
        return nullptr;
    }

    ListNode* h = new ListNode(v[0]);
    ListNode* p = h;

    for (int i = 1; i < v.size(); i++)
    {
        p->next = new ListNode(v[i]);
        p = p->next;
    }

    return h;
}

void PrintList(ListNode* l)
{
    if (nullptr == l)
    {
        std::cout << "null";
        return;
    }

    ListNode* p = l;
    while (p)
    {
        std::cout << "[" << p->val << "]";
        if (p->next)
        {
            std::cout << "-";
        }

        p = p->next;
    }
}

bool IsEqualLinkedList(ListNode* l, ListNode* r)
{
    if (nullptr == l && nullptr == r)
    {
        return true;
    }

    bool result = false;

    ListNode* pl = l;
    ListNode* pr = r;
    while (pl && pr)
    {
        if (pl->val != pr->val)
        {
            break;
        }

        pl = pl ->next;
        pr = pr->next;
    }

    if (nullptr == pl && nullptr == pr)
    {
        result = true;
    }

    return result;
}

TreeNode* GenerateTree(vector<int> v)
{
    if (v.size() == 0)
    {
        return nullptr;
    }
    queue< TreeNode*> nodes;
    TreeNode* root = new TreeNode(v[0]);
    nodes.push(root);


    int count = 1;
    while (!nodes.empty())
    {
        TreeNode* cur = nodes.front();
        nodes.pop();

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            TreeNode* node = new TreeNode(v[count]);
            cur->left = node;
            nodes.push(node);
        }
        else
        {
            cur->left = nullptr;
        }
        ++count;

        if (count < v.size() && v[count] != NULL_NODE_VALUE)
        {
            TreeNode* node = new TreeNode(v[count]);
            cur->right = node;
            nodes.push(node);
        }
        else
        {
            cur->right = nullptr;
        }
        ++count;
    }

    return root;
}

vector<TreeNode*> GenerateTrees(vector<vector<int>> v)
{
    vector<TreeNode*> result;
    for (int i = 0; i < v.size(); i++)
    {
        result.push_back(GenerateTree(v[i]));
    }

    return result;
}

void PrintInput(TD_L_L testData)
{
    std::cout << "Input :";
    PrintList(testData.input);
    std::cout << endl;
}
void CheckResults(TD_L_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintList(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_VI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_VI testData, vector<int> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_L_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_L_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output,result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_I testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_I testData, int result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_VI_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_VI_VI_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output,result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_VI_T testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_VI_T testData, TreeNode* result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (IsSameTree(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_VVI testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionArrayEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void CheckResults_Unorder(TD_T_VVI testData, vector<vector<int>> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (Are2DimensionSetEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_I_VT testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_I_VT testData, vector<TreeNode*> result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (AreVectorEqual(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;
}
void CheckResults(TD_T_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_T_T_B testData)
{
    std::cout << "Input :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}
void CheckResults(TD_T_T_B testData, bool result)
{
    std::cout << "Output: ";
    PrintData(result);
    std::cout << endl;

    if (testData.output == result)
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: " << endl;
        PrintData(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_L_L_L testData)
{
    std::cout << "Input1 :";
    PrintList(testData.input);
    std::cout << endl;
    std::cout << "Input2 :";
    PrintList(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_L_L_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
    }

    std::cout << endl;
}

void PrintInput(TD_L_I_L testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;
}

void CheckResults(TD_L_I_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

void PrintInput(TD_L_I_I_L testData)
{
    std::cout << "Input1 :";
    PrintData(testData.input);
    std::cout << endl;

    std::cout << "Input2 :";
    PrintData(testData.input2);
    std::cout << endl;

    std::cout << "Input3 :";
    PrintData(testData.input3);
    std::cout << endl;
}
void CheckResults(TD_L_I_I_L testData, ListNode* result)
{
    std::cout << "Output: ";
    PrintList(result);
    std::cout << endl;

    if (IsEqualLinkedList(testData.output, result))
    {
        std::cout << "Succeeded!" << endl;
    }
    else
    {
        std::cout << "***Failed!***" << endl;
        std::cout << "Expect: ";
        PrintList(testData.output);
        std::cout << endl;
    }

    std::cout << endl;
}

// Print out tree node in width traversal order
void PrintTree(TreeNode* root)
{
    queue<TreeNode*> nodes;
    nodes.push(root);
    cout << "{ ";

    while (!nodes.empty())
    {
        root = nodes.front();
        nodes.pop();

        if (root == nullptr)
        {
            cout << "null" << " ";
        }
        else
        {
            cout << root->val << " ";
            nodes.push(root->left);
            nodes.push(root->right);
        }
    }

    cout << "} ";

}

// Use pre-order traversal, compare each of the node. 
// Note: unlike regual traversal, the null node can't be
// left out without comparing.
bool IsSameTree(TreeNode* p, TreeNode* q)
{
    if (p == nullptr && q == nullptr)
    {
        return true;
    }

    if ((p != nullptr && q == nullptr) ||
        (p == nullptr && q != nullptr))
    {
        return false;
    }

    bool result = true;

    stack<TreeNode*> nodes_p, nodes_q;
    nodes_p.push(p);
    nodes_q.push(q);

    while (!nodes_p.empty() && !nodes_q.empty())
    {
        p = nodes_p.top();
        nodes_p.pop();

        q = nodes_q.top();
        nodes_q.pop();

        if (p == nullptr && q == nullptr)
        {
            continue;
        }

        if ((p != nullptr && q == nullptr) ||
            (p == nullptr && q != nullptr))
        {
            result = false;
            break;
        }

        if (p->val != q->val)
        {
            result = false;
            break;
        }

        // Push right first so that visit it last
        nodes_p.push(p->right);
        nodes_p.push(p->left);

        nodes_q.push(q->right);
        nodes_q.push(q->left);

    }

    if (!nodes_p.empty() || !nodes_q.empty())
    {
        result = false;
    }

    return result;
}