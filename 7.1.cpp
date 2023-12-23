#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position to insert.\n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void deleteFirst(struct Node** head) {
  struct Node* temp;
    if (*head == NULL)
        return;
    temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void deleteEnd(struct Node* head) {
  struct Node *temp = NULL;
  struct Node *cur = head;
    if (head == NULL)
        return;
    while(cur->next) {
      temp = cur;
      cur = cur->next;
    }
    temp->next = NULL;
    free(cur);
    return;
}

struct Node* deletePosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;
    if (temp->next == NULL) {
        printf("Invalid position to delete.\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    return head;
}

struct Node* reverseLL(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

void displayList(struct Node* head) {
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Insert at Position\n");
        printf("3. Delete First\n");
        printf("4. Delete End\n");
        printf("5. Delete at Position\n");
        printf("6. Reverse List\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 3:
                deleteFirst(&head);
                break;
            case 4:
                deleteEnd(head);
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deletePosition(head, position);
                break;
            case 6:
                head = reverseLL(head);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                exit(1);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}