/**
 *Given a linked list, remove the nth node from the end of list and return its head.
 *For example,
 *Given linked list: 1->2->3->4->5, and n = 2.
 *After removing the second node from the end, the linked list becomes 1->2->3->5


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * typedef struct ListNode listnode;
 * 
 * listnode* listnode_new(int val) {
 *     listnode* node = (listnode *) malloc(sizeof(listnode));
 *     node->val = val;
 *     node->next = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Head pointer of linked list 
 * @input B : Integer
 * 
 * @Output head pointer of list.
 */
 int length(listnode *A){
     int len=0;
     while(A!=NULL){
         A=A->next;
         len++;
     }
     
     return len;
 }
listnode* removeNthFromEnd(listnode* A, int B) {
    int len,i,j;
    listnode *temp=A,*temp1;
    len=length(A);
    i=len-B-1;
    if(i<=-1){
        A=A->next;
        free(temp);
        return A;
    }
    //i--;
    while(i--){
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
    return A;
}
