/*
 * Electricity Bill Generator
 * Team 1
 * Concepts: If-Else, Loops, Functions
 */
#include <stdio.h>

float calculateCharges(float units) {
    float bill = 0.0;
    if (units <= 100) {
        bill = units * 1.50;
    } else if (units <= 200) {
        bill = (100 * 1.50) + ((units - 100) * 2.50);
    } else if (units <= 300) {
        bill = (100 * 1.50) + (100 * 2.50) + ((units - 200) * 4.00);
    } else {
        bill = (100 * 1.50) + (100 * 2.50) + (100 * 4.00) + ((units - 300) * 6.00);
    }
    return bill;
}

int main() {
    int consumerId;
    char name[40];
    float units, baseBill, surcharge = 0.0, totalBill;

    printf("=== ELECTRICITY BILL GENERATOR ===\n");
    printf("Enter Consumer ID: ");
    scanf("%d", &consumerId);
    getchar();
    printf("Enter Consumer Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter Units Consumed: ");
    scanf("%f", &units);

    if (units < 0) {
        printf("Error: Units cannot be negative.\n");
        return 1;
    }

    baseBill = calculateCharges(units);
    if (baseBill > 400.0) {
        surcharge = baseBill * 0.15; // 15% surcharge for bills exceeding 400
    }
    totalBill = baseBill + surcharge + 50.0; // 50 fixed meter rent

    printf("\n=========== ELECTRICITY INVOICE ===========\n");
    printf("Consumer ID      : %d\n", consumerId);
    printf("Consumer Name    : %s", name);
    printf("Units Consumed   : %.1f\n", units);
    printf("Energy Charges   : $%.2f\n", baseBill);
    printf("Meter Rent       : $50.00\n");
    printf("Surcharge        : $%.2f\n", surcharge);
    printf("-------------------------------------------\n");
    printf("TOTAL AMOUNT DUE : $%.2f\n", totalBill);
    printf("===========================================\n");

    return 0;
}
