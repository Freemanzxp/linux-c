#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"  
  
/* 
 * Create a LinkTable 
 */  
tLinkTable * CreateLinkTable()  
{  
     tLinkTable *pTable = (tLinkTable*)malloc(sizeof(tLinkTable));  
     pTable->pHead = NULL;  
     pTable->pTail = NULL;  
     pTable->SumOfNode = 0;  
  
     return pTable;  
}  
  
/* 
 * Delete a LinkTable 
 */  
int DeleteLinkTable(tLinkTable *pLinkTable)  
{  
     free(pLinkTable);  
     return 0;   
}  
  
/* 
 * Add LinkTableNode to LinkTable 
 */  
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)  
{  
     if (pLinkTable == NULL)   
     {  
          printf("The table is empty and cannot add this node!\n");  
      exit(0);   
     }  
  
     if (pNode == NULL)  
     {  
          printf("The node is empty and cannot add this node!\n");  
      return 0;  
     }  
  
     if (pLinkTable->pHead == NULL)  
     {  
          pLinkTable->pHead = pNode;  
      pLinkTable->pTail = pNode;  
      pLinkTable->SumOfNode = 1;  
     }else  
     {  
          pLinkTable->pTail->pNext = pNode;  
      pLinkTable->pTail = pNode;  
      pLinkTable->SumOfNode++;   
     }  
  
     return 0;  
}  
  
/* 
 * Delete a LinkTableNode from LinkTable 
 */  
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)  
{  
    /* if (pLinkTable == NULL)  
     { 
          printf("The table is empty and cannot delete this node!\n"); 
      exit(0);  
     } 
 
     if (pNode == NULL) 
     { 
          printf("The node is empty and cannot delete this node!\n"); 
      return 0; 
     } 
     
     tLinkTableNode *p = pLinkTable->pHead; 
     while */   
}  
  
/* 
 * Get LinkTableHead 
 */  
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable)  
{  
     if (pLinkTable == NULL)   
     {  
          printf("The table is empty!\n");  
      exit(0);   
     }  
  
     return pLinkTable->pHead;  
}  
  
/* 
 * Get Next LinkTableNode 
 */  
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)  
{  
     if (pLinkTable == NULL)   
     {  
          printf("The table is empty!\n");  
      exit(0);   
     }  
      
     if (pNode == NULL)   
     {  
          printf("The node is empty and cannot get next node!\n");  
      exit(0);  
     }  
     return pNode->pNext;  
}

/* Find cmd */
tDataNode* FindCmd(tLinkTable * head, char* cmd)  
{  
     if (head == NULL || cmd == NULL)  
     {  
          return NULL;  
     }  
     tDataNode *p = (tDataNode*)GetLinkTableHead(head);  
     while (p != NULL)  
     {  
          if (strcmp(p->cmd, cmd) == 0)  
          {  
               return p;  
          }  
          p = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)p);  
      }  
      return NULL;  
}   
  
/* Show all the cmd in Listlist */  
int ShowAllCmd(tLinkTable * head)  
{  
     printf("Menu List:\n");  
     tDataNode *p = (tDataNode*)GetLinkTableHead(head);  
     while (p != NULL)  
     {  
          printf("%s - %s\n", p->cmd, p->desc);  
      p = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)p);  
     }  
  
     return 0;  
  
}    
