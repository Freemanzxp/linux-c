#ifndef _LINK_TABLE_H_  
#define _LINK_TABLE_H_  
  
#define SUCCESS 0  
#define FAILURE (-1)  
  
#include <stdio.h>  
#include <stdlib.h>  
  
/* 
 * LinkTable Node Type 
 */  
typedef struct LinkTableNode  
{  
     struct LinkTableNode *pNext;  
}tLinkTableNode;  
  
/* 
 * LinkTable Type 
 */  
typedef struct LinkTable  
{  
     tLinkTableNode *pHead;  
     tLinkTableNode *pTail;  
     int         SumOfNode;  
}tLinkTable;  

typedef struct DataNode  
{  
    tLinkTableNode *pNext;  
    char*    cmd;  
    char*    desc;  
    void      (*handler)();  
} tDataNode; 
  
/* 
 * Create a LinkTable 
 */  
tLinkTable * CreateLinkTable();  
  
/* 
 * Delete a LinkTalbe 
 */  
int DeleteLinkTable(tLinkTable *pLinkTable);  
  
/* 
 * Add a LinkTableNode to LinkTable 
 */  
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);  
  
/* 
 * Delete a LinkTableNode from LinkTable 
 */  
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);  
  
/* 
 * Get LinkTableHead 
 */  
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);  
  
/* 
 * Get next LinkTableNode 
 */  
tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);  

/* find a cmd in the linklist and return the data node pointer */  
tDataNode * FindCmd(tLinkTable *head, char *cmd);
  
/* show all cmd in linklist */  
int ShowAllCmd(tLinkTable *head);   

#endif /* _LINK_TABLE_H_ */
