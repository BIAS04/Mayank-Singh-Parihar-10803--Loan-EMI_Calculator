#include <stdio.h>
#include <math.h>

int main()
{

    double principal, rate, emi, totalPayment, totalInterest;
    int timeInYears;

    double balance, interestPart, principalPart;
    int totalMonths;

    printf("\n--- LOAN EMI CALCULATOR ---\n");

    printf("Enter Principal Amount: ");
    scanf("%lf", &principal);

    printf("Enter Annual Interest Rate (%%): ");
    scanf("%lf", &rate);

    printf("Enter Time (in Years): ");
    scanf("%d", &timeInYears);

    double monthlyRate = rate / (12 * 100);

    totalMonths = timeInYears * 12;

    double compoundFactor = pow(1 + monthlyRate, totalMonths);

    emi = (principal * monthlyRate * compoundFactor) / (compoundFactor - 1);

    totalPayment = emi * totalMonths;

    totalInterest = totalPayment - principal;

    printf("\n--- RESULTS ---\n");
    printf("Monthly EMI: %.2lf\n", emi);
    printf("Total Interest: %.2lf\n", totalInterest);
    printf("Total Payment: %.2lf\n", totalPayment);

    printf("\n--- MONTHLY PAYMENT SCHEDULE ---\n");
    printf("Month | EMI      | Interest | Principal | Balance\n");
    printf("--------------------------------------------------\n");

    balance = principal;

    for (int month = 1; month <= totalMonths; month++)
    {
        interestPart = balance * monthlyRate;

        principalPart = emi - interestPart;
        balance = balance - principalPart;

        if (balance < 0)
        {
            balance = 0;
        }
        printf("%-5d | %-8.2lf | %-8.2lf | %-9.2lf | %-8.2lf\n",
               month, emi, interestPart, principalPart, balance);
    }

    printf("--------------------------------------------------\n");

    return 0;
}
