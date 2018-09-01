#include <stdio.h>
#include <stdlib.h>
#include "chaintable.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i = 0;
	ChainTableInt *ctint = initTableList();
	printf("begin to add nodes to chain table int\n");
	for(i = 0; i < 16; i++)
	{
		printf("add %d node to chain...\n", i);
		addNode(ctint, i);
	}
	printf("completed!\n");
	
	printf("chain table is: \n");
	NodeInt *pnode = ctint->head;
	while(pnode != NULL)
	{
		printf("%02d ", pnode->num);
		pnode = pnode->next;
	}
	printf("\n");
	
	printf("begin to delete 7 nodes...\n");
	for(i = 0; i < 7; i++)
	{
		if(-1 == deleteNodeFromTail(ctint))
		{
			printf("unable to delete tail\n");
		}
	}
	
	printf("chain table is: \n");
	pnode = ctint->head;
    while(pnode != NULL)
	{
		printf("%02d ", pnode->num);
		pnode = pnode->next;
	}
	printf("\n");
	return 0;
}
