#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[30];
    char phone[15];
};

void addContact(struct Contact contacts[], int *count) {
    if (*count >= MAX_CONTACTS) {
        printf("Contact book is full!
");
        return;
    }
    printf("Enter contact name: ");
    scanf("%s", contacts[*count].name);
    printf("Enter phone number: ");
    scanf("%s", contacts[*count].phone);
    (*count)++;
    printf("Contact added successfully.
");
}

void displayContacts(struct Contact contacts[], int count) {
    if (count == 0) {
        printf("No contacts to display.
");
        return;
    }
    printf("
----- Contact List -----
");
    for (int i = 0; i < count; i++) {
        printf("%d. Name: %s, Phone: %s
", i + 1, contacts[i].name, contacts[i].phone);
    }
}

void searchContact(struct Contact contacts[], int count) {
    char searchName[30];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Found: Name: %s, Phone: %s
", contacts[i].name, contacts[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.
");
    }
}

int main() {
    struct Contact contacts[MAX_CONTACTS];
    int count = 0;
    int choice;

    while (1) {
        printf("
----- Contact Book Menu -----
");
        printf("1. Add Contact
");
        printf("2. Display All Contacts
");
        printf("3. Search Contact by Name
");
        printf("4. Exit
");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                break;
            case 2:
                displayContacts(contacts, count);
                break;
            case 3:
                searchContact(contacts, count);
                break;
            case 4:
                printf("Exiting Contact Book. Goodbye!
");
                return 0;
            default:
                printf("Invalid choice! Please try again.
");
        }
    }

    return 0;
}