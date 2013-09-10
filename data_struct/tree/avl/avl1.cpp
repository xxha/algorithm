/********************************************************************
created:    2007/08/28
filename:     avltree.c
author:        Lichuang

purpose:    AVL树的实现代码, 
            参考资料<<数据结构与算法分析-C语言描述>>, 作者Allen Weiss
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct AVLTree
{
    int nData;
    struct AVLTree* pLeft;
    struct AVLTree* pRight;
    int nHeight;
}AVLTree;

int Max(int a, int b);
int Height(AVLTree* pNode);
AVLTree* Insert(int nData, AVLTree* pNode);
AVLTree* SingleRotateWithLeft(AVLTree* pNode);
AVLTree* SingleRotateWithRight(AVLTree* pNode);
AVLTree* DoubleRotateWithLeft(AVLTree* pNode);
AVLTree* DoubleRotateWithRight(AVLTree* pNode);
void DeleteTree(AVLTree** ppRoot);
void PrintTree(AVLTree* pRoot);

int main()
{
    int i;
    AVLTree* pRoot = NULL;

    srand((unsigned int)::time(NULL));
    
    for (i = 0; i < 100000000; ++i)
    {
        pRoot = Insert(::rand(), pRoot);
    }

    PrintTree(pRoot);

    DeleteTree(&pRoot);

    return 0;
}

int Max(int a, int b)
{
    return (a > b ? a : b);
}

int Height(AVLTree* pNode)
{
    if (NULL == pNode)
        return -1;

    return pNode->nHeight;
}

AVLTree* Insert(int nData, AVLTree* pNode)
{
    if (NULL == pNode)
    {
        pNode = (AVLTree*)malloc(sizeof(AVLTree));
        pNode->nData = nData;
        pNode->nHeight = 0;
        pNode->pLeft = pNode->pRight = NULL;
    }
    else if (nData < pNode->nData)          // 插入到左子树中
    {
        pNode->pLeft = Insert(nData, pNode->pLeft);
        if (Height(pNode->pLeft) - Height(pNode->pRight) == 2)    // AVL树不平衡
        {
            if (nData < pNode->pLeft->nData)
            {
                // 插入到了左子树左边, 做单旋转
                pNode = SingleRotateWithLeft(pNode);
            }
            else 
            {
                // 插入到了左子树右边, 做双旋转
                pNode = DoubleRotateWithLeft(pNode);
            }
        }
    }
    else if (nData > pNode->nData)          // 插入到右子树中
    {
        pNode->pRight = Insert(nData, pNode->pRight);
        if (Height(pNode->pRight) - Height(pNode->pLeft) == 2)    // AVL树不平衡
        {
            if (nData > pNode->pRight->nData)
            {
                // 插入到了右子树右边, 做单旋转
                pNode = SingleRotateWithRight(pNode);
            }
            else 
            {
                // 插入到了右子树左边, 做双旋转
                pNode = DoubleRotateWithRight(pNode);
            }
        }
    }

    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;

    return pNode;
}

/********************************************************************
      pNode                                pNode->pLeft 
      /                                             \
pNode->pLeft                      ==>              pNode
           \                                       /
          pNode->pLeft->pRight                   pNode->pLeft->pRight
*********************************************************************/
AVLTree* SingleRotateWithLeft(AVLTree* pNode)
{
    AVLTree* pNode1;

    pNode1 = pNode->pLeft;
    pNode->pLeft = pNode1->pRight;
    pNode1->pRight = pNode;

    // 结点的位置变了, 要更新结点的高度值
    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    pNode1->nHeight = Max(Height(pNode1->pLeft), pNode->nHeight) + 1;

    return pNode1;
}

/********************************************************************
pNode                                   pNode->pRight
     \                                  /
     pNode->pRight           ==>    pNode 
     /                                   \
pNode->pRight->pLeft                     pNode->pRight->pLeft
*********************************************************************/
AVLTree* SingleRotateWithRight(AVLTree* pNode)
{
    AVLTree* pNode1;

    pNode1 = pNode->pRight;
    pNode->pRight = pNode1->pLeft;
    pNode1->pLeft = pNode;

    // 结点的位置变了, 要更新结点的高度值
    pNode->nHeight = Max(Height(pNode->pLeft), Height(pNode->pRight)) + 1;
    pNode1->nHeight = Max(Height(pNode1->pRight), pNode->nHeight) + 1;

    return pNode1;
}

AVLTree* DoubleRotateWithLeft(AVLTree* pNode)
{
    pNode->pLeft = SingleRotateWithRight(pNode->pLeft);

    return SingleRotateWithLeft(pNode);
}

AVLTree* DoubleRotateWithRight(AVLTree* pNode)
{
    pNode->pRight = SingleRotateWithLeft(pNode->pRight);

    return SingleRotateWithRight(pNode);
}

// 后序遍历树以删除树
void DeleteTree(AVLTree** ppRoot)
{
    if (NULL == ppRoot || NULL == *ppRoot)
        return;

    DeleteTree(&((*ppRoot)->pLeft));
    DeleteTree(&((*ppRoot)->pRight));
    free(*ppRoot);
    *ppRoot = NULL;
}

// 中序遍历打印树的所有结点, 因为左结点 < 父结点 < 右结点, 因此打印出来数据的大小是递增的
void PrintTree(AVLTree* pRoot)
{
    if (NULL == pRoot)
        return;

    static int n = 0;

    PrintTree(pRoot->pLeft);
    printf("[%d]nData = %d\n", ++n, pRoot->nData);
    PrintTree(pRoot->pRight);
}
