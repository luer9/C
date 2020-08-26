#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *getodd( struct ListNode **L );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    struct ListNode *L, *Odd;
    L = readlist();
    Odd = getodd(&L);
    printlist(Odd);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist(){
    struct ListNode *p,*head,*tail;
    head = tail = NULL;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    scanf("%d",&p->data);
    while(p->data != -1) {
        if(head == NULL) {
            head = p;
            head->next = NULL;
        }
        if(tail != NULL) {
            tail->next = p;
        }
        tail = p;
        tail->next = NULL;
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d",&p->data);
    }   
    return head;
}
struct ListNode *getodd(struct ListNode **L){
    struct ListNode *p,*head_odd,*head_even,*tail_odd,*tail_even;
    head_even = head_odd = tail_odd = tail_even = NULL;
    while((*L) != NULL){
        //奇数
        if((*L)->data % 2 != 0){
            p = (struct ListNode *) malloc(sizeof(struct ListNode));
            p->data = (*L)->data;
            if(head_odd == NULL){
                head_odd = p;
                head_odd->next = NULL;
            }
            if(tail_odd != NULL){
                tail_odd->next = p;
            }
            tail_odd = p;
            tail_odd->next = NULL;
        }else{
            p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->data = (*L)->data;
            if(head_even == NULL){
                head_even = p;
                head_even->next = NULL;
            }
            if(tail_even != NULL){
                tail_even->next = p;
            }
            tail_even = p;
            tail_even->next = NULL;
        }
        (*L) = (*L)->next;
    }
    *L=head_even; //偶数 
    return head_odd;//奇数
}