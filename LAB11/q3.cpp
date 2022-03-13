#include <iostream>

using namespace std;

/* CAN DUYAR - 171044075 */

struct node{
    int data;
    struct node *next;
};

/*to push the nodes*/
void push(struct node **head_ref, int data) {
    struct node *node;
    node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = (*head_ref);
    (*head_ref) = node;
}
 
/*to reverse the nodes */
void reverse(struct node **head_ref) {  
    struct node *temp = NULL;
    struct node *prev = NULL;
    struct node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

/* to print the nodes */
void printnodes(struct node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

/* TEST  */
int main() {
    struct node *head = NULL;
    push(&head, 13);
    push(&head, 17);
    push(&head, 33);
    push(&head, 45);
    push(&head, 58);
    push(&head, 101);
    cout << "\nLinkedlist before the reverse function" << endl;
    printnodes(head);
    reverse(&head);
    cout << endl;
    cout << "\nLinkedlist after the reverse function"<<endl;
    printnodes(head);
    cout << endl << endl;
    return 0;
}