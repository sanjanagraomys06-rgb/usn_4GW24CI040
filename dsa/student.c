#include <stdio.h>
#include <string.h>

struct Contact {
    char studentName[50];
    char studentUSN[20];
    char parentName[50];
    char parentPhone[15];
};

int main() {
    struct Contact c[100];
    int choice, count = 0, i, j, found;
    char searchUSN[20];

    while (1) {
        printf("\n-----------------------------------\n");
        printf(" Parents / Students Contact System\n");
        printf("-----------------------------------\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:   // Add Contact
            printf("\nEnter Student Name: ");
            scanf(" %[^\n]", c[count].studentName);

            printf("Enter Student USN: ");
            scanf(" %s", c[count].studentUSN);

            printf("Enter Parent Name: ");
            scanf(" %[^\n]", c[count].parentName);

            printf("Enter Parent Phone Number: ");
            scanf(" %s", c[count].parentPhone);

            count++;
            printf("\nContact added successfully!\n");
            break;

        case 2:   // Display Contacts
            if (count == 0) {
                printf("\nNo contacts to display.\n");
            } else {
                for (i = 0; i < count; i++) {
                    printf("\nStudent Name : %s", c[i].studentName);
                    printf("\nStudent USN  : %s", c[i].studentUSN);
                    printf("\nParent Name  : %s", c[i].parentName);
                    printf("\nParent Phone : %s\n", c[i].parentPhone);
                }
            }
            break;

        case 3:   // Search Contact
            found = 0;
            printf("\nEnter USN to search: ");
            scanf(" %s", searchUSN);

            for (i = 0; i < count; i++) {
                if (strcmp(c[i].studentUSN, searchUSN) == 0) {
                    printf("\nStudent Name : %s", c[i].studentName);
                    printf("\nParent Name  : %s", c[i].parentName);
                    printf("\nParent Phone : %s\n", c[i].parentPhone);
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nContact not found.\n");
            }
            break;

        case 4:   // Delete Contact
            found = 0;
            printf("\nEnter USN to delete: ");
            scanf(" %s", searchUSN);

            for (i = 0; i < count; i++) {
                if (strcmp(c[i].studentUSN, searchUSN) == 0) {
                    for (j = i; j < count - 1; j++) {
                        c[j] = c[j + 1];
                    }
                    count--;
                    printf("\nContact deleted successfully.\n");
                    found = 1;
                    break;
                }
            }

            if (!found) {
                printf("\nContact not found.\n");
            }
            break;

        case 5:   // Exit
            printf("\nThank you!\n");
            printf("Sharanya - 4GW24CIO43\n");
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }
}
