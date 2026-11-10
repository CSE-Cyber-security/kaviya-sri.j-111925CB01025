#include <stdio.h>

struct Expense {
    char date[20];
    char category[30];
    float amount;
};

int main() {
    struct Expense e[100];
    int choice, count = 0, i;
    float total = 0;

    while (1) {
        printf("\n===== DAILY EXPENSE TRACKER =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count >= 100) {
                    printf("Expense limit reached!\n");
                    break;
                }

                printf("Enter Date (DD/MM/YYYY): ");
                scanf("%19s", e[count].date);

                printf("Enter Category: ");
                scanf("%29s", e[count].category);

                printf("Enter Amount: ");
                scanf("%f", &e[count].amount);

                if (e[count].amount < 0) {
                    printf("Invalid amount!\n");
                    break;
                }

                total += e[count].amount;
                count++;

                printf("Expense Added Successfully!\n");
                break;

            case 2:
                printf("\n--- Expense Details ---\n");
                for (i = 0; i < count; i++) {
                    printf("%s | %s | Rs. %.2f\n",
                           e[i].date,
                           e[i].category,
                           e[i].amount);
                }
                break;

            case 3:
                printf("Total Expenses: Rs. %.2f\n", total);
                break;

            case 4:
                printf("Thank you for using Expense Tracker!\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
