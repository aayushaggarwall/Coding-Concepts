/**
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

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
 * 
 * @Output head pointer of list.
 */
 listnode *reverse(listnode *A){
     listnode *prev=NULL,*curr=A,*next=curr->next;
     if(A->next==NULL)
        return A;
     while(next!=NULL){
        curr->next=prev;
        prev=curr;
        curr=next;
        next=next->next;
     }
     curr->next=prev;
     return curr;
 }
int length(listnode *A){
    int i=0;
    while(A!=NULL){
        A=A->next;
        i++;
    }
    return i;
}
listnode* reorderList(listnode* A) {
    
    int len=length(A);
    if(len==1){
        return A;
    }
    int j,k,i;
    listnode *temp=A,*temp1,*temp2;
    j=len%2;
    for(i=0;i<len/2+j-1;i++){
        temp=temp->next;
    }
    //return temp;
    temp1=reverse(temp->next);
    temp->next=NULL;
    temp=A;
    for(i=0;i<len/2;i++){
        temp2=temp->next;
        temp->next=temp1;
        temp1=temp1->next;
        temp->next->next=temp2;
        temp=temp2;
        
    }
    return A;
}
