/* data struct and its operations */

typedef struct DatNode
{
    char*  cmd;
    char*  desc;
    void    (*handler)();
    struct DataNode *next;
} tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode * head, char * cmd);

/* shoe all cmd in linklist */
int ShowAllCmd(tDataNode * head);
