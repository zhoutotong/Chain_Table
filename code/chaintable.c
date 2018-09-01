#include <stdlib.h>
#include <stdio.h>

#include "chaintable.h"


ChainTableInt* initTableList()
{
    ChainTableInt *pCTableInt = (ChainTableInt*)malloc(sizeof(ChainTableInt));
    pCTableInt->head = pCTableInt->tail = NULL;
    return pCTableInt;
}

int addNode(ChainTableInt *pCTableInt, int num)
{
    // 首先申请内存空间
    NodeInt *pnode = (NodeInt*)malloc(sizeof(NodeInt));
    pnode->num = num;
    pnode->next = NULL;
    // 判断以下情况
    if(pCTableInt->head == NULL)
    {
        // 此时链表是一个空链表，链表的首尾均为新加入的节点
        pCTableInt->head = pCTableInt->tail = pnode;
    }
    else
    {
        // 此时链表不为空链表，首先将尾部节点指针指向新加入的节点，然后将尾节点改为新加入的节点
        pCTableInt->tail = pCTableInt->tail->next = pnode;
    }
    return 0;
}

int deleteNodeFromTail(ChainTableInt *pCTableInt)
{
    NodeInt *pnode = pCTableInt->head;
    if(pCTableInt == NULL)
    {
        // 链表未经初始化
        return -1;
    }
    else if(pCTableInt->head == NULL)
    {
        // 链表为空链表
        return -1;
    }
    else if(pCTableInt->head->next == NULL)
    {
        // 链表中仅有一个元素
        free(pCTableInt->head);
        pCTableInt->head = NULL;
    }
    else{
        // 链表中有多个元素
        while(pnode->next != pCTableInt->tail)
        {
            pnode = pnode->next;
        }
        free(pCTableInt->tail);
        pCTableInt->tail = pnode;
        pnode->next = NULL;
    }
    return 0;
}

NodeInt* findNum(ChainTableInt *pCTableInt, int num)
{
    NodeInt* pnode = pCTableInt->head;
    while(pnode != NULL && pnode->num != num)
    {
        pnode = pnode->next;
    }
    return pnode;
}

