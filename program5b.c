#include <stdio.h>
#include <stdlib.h>

// Define a structure for a circular singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the circular list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to delete a node with a given value from the circular list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
printf("The circular list is empty.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    do {
        if (current->data == key) {
            if (prev == NULL) {
                struct Node* last = *head;
                while (last->next != *head) {
                    last = last->next;
                }
                last->next = current->next;
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
printf("Node with data %d deleted from the circular list.\n", key);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

printf("Node with data %d not found in the circular list.\n", key);
}

// Function to display the elements of the circular list
void display(struct Node* head) {
    if (head == NULL) {
printf("The circular list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
printf("...\n"); // Indicates the circular structure
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;

    while (1) {
printf("1. Insert at the beginning\n");
printf("2. Delete a node\n");
printf("3. Display\n");
printf("4. Quit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

        switch (choice) {
            case 1:
printf("Enter data to insert at the beginning: ");
scanf("%d", &data);
insertAtBeginning(&head, data);
                break;
            case 2:
printf("Enter data to delete: ");
scanf("%d", &key);
deleteNode(&head, key);
                break;
            case 3:
printf("Circular Linked List:\n");
                display(head);
                break;
            case 4:
exit(0);
            default:
printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
