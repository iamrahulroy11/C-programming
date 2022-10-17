void findloop(struct node *head) {
    struct node *slow, *fast;
    slow = fast = head;
   
    while(slow && fast && fast->next) {
        /* Slow pointer will move one node per iteration whereas 
        fast node will move two nodes per iteration */
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
           printf("Linked List contains a loop\n");
           return;
        }
    }
    printf("No Loop in Linked List\n");
}
