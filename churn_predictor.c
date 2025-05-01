#include <stdio.h>
#include <string.h>

// Define customer structure
struct Customer {
    int tenure;               // Months of service
    float monthlyCharges;     // Monthly bill
    char internetService[10]; // "DSL", "Fiber", "None"
    char churn[5];            // "Yes" or "No"
};

// Predict churn based on simple rules
void predictChurn(struct Customer c) {
    printf("\n--- Customer Profile ---\n");
    printf("Tenure: %d months\n", c.tenure);
    printf("Monthly Charges: %.2f\n", c.monthlyCharges);
    printf("Internet Service: %s\n", c.internetService);

    printf("\nPrediction: ");
    if (c.tenure < 6 && c.monthlyCharges > 70 && strcmp(c.internetService, "Fiber") == 0) {
        strcpy(c.churn, "Yes");
        printf("Customer is likely to churn.\n");
    } else {
        strcpy(c.churn, "No");
        printf("Customer is not likely to churn.\n");
    }
}

int main() {
    struct Customer cust1;

    // Input customer details
    printf("Enter customer tenure (in months): ");
    scanf("%d", &cust1.tenure);

    printf("Enter monthly charges: ");
    scanf("%f", &cust1.monthlyCharges);

    printf("Enter internet service type (DSL/Fiber/None): ");
    scanf("%s", cust1.internetService);

    // Predict churn
    predictChurn(cust1);

    return 0;
}
