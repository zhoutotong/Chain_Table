#ifndef _CHAINTABLE_H_
#define _CHAINTABLE_H_

typedef struct _NodeInt{
    int num;
    struct _NodeInt *next;
}NodeInt;

typedef struct _ChainTableInt{
    NodeInt *head;
    NodeInt *tail;
}ChainTableInt;


ChainTableInt* initTableList();
int addNode(ChainTableInt *pCTableInt, int num);
int deleteNodeFromTail(ChainTableInt *pCTableInt);
NodeInt* findNum(ChainTableInt *pCTableInt, int num); 

#endif
 
