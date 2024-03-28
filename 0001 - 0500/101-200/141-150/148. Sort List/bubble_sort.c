/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//bubbleSort
struct ListNode* bubbleSort(struct ListNode* head){
    struct ListNode* node_i=head;
    struct ListNode* tail =NULL;
    int temp;
    
    while(node_i){
        struct ListNode* node_j=head;
        while(node_j && node_j->next!=tail){            
            if(node_j->val>node_j->next->val) {
                temp=node_j->val;
                node_j->val=node_j->next->val;
                node_j->next->val=temp;       
            }
            node_j=node_j->next;
        }
        tail=node_j;
        node_i=node_i->next;
    }
    return head;
}

//countSort
struct ListNode* countSort(struct ListNode* head){
    if(!head||!head->next) return head;
    int max=head->val;
    int min=head->val;
    struct ListNode* cur=head;
    int temp;
    while(cur){
        temp=cur->val;
        if(temp>max){
            max=temp;
        }else if(temp<min){
            min=temp;
        }
        cur=cur->next;
    }
    int size=max-min+1;
    int counts[size];
    for (int i = 0; i < size; i++) {
        counts[i] = 0;
    }
    cur=head;

    while(cur){
        counts[cur->val-min]+=1;
        cur=cur->next;
    }
    cur=head;
    for(int i=0;i<size;i++){
        while(counts[i]&&counts[i]>0){
            cur->val=i+min;
            counts[i]--;
            cur=cur->next;
        }
    }
    return head;
}
struct ListNode* sortList(struct ListNode* head){
    return countSort(head);
}