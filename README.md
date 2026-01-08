# Loan EMI Calculator

hey! this is my C programming project for calculating loan EMIs. basically it takes your loan details and shows you how much you'll pay each month plus a full breakdown of the payments.

## What it does

- calculates monthly EMI 
- shows total interest you'll end up paying
- prints out the complete payment schedule month by month
- breaks down how much goes to interest vs actual loan amount each month

## What you need

- any C compiler (i used gcc)
- make sure you have math.h library

## How to compile

if you're on linux or mac just do:
```bash
gcc emi_calculator.c -o emi_calculator -lm
```

the -lm flag is important because we're using pow() function from math library

for windows with mingw:
```bash
gcc emi_calculator.c -o emi_calculator.exe -lm
```

## Running it

just run the program and it'll ask you for:
- loan amount (principal)
- interest rate per year (in %)
- how many years you want the loan for

then it prints everything out

## Example run

```
--- LOAN EMI CALCULATOR ---
Enter Principal Amount: 100000
Enter Annual Interest Rate (%): 10
Enter Time (in Years): 2

--- RESULTS ---
Monthly EMI: 4614.49
Total Interest: 10747.71
Total Payment: 110747.71

--- MONTHLY PAYMENT SCHEDULE ---
Month | EMI      | Interest | Principal | Balance
--------------------------------------------------
1     | 4614.49  | 833.33   | 3781.16   | 96218.84
2     | 4614.49  | 801.82   | 3812.67   | 92406.17
...
```

## The formula i used

i found this formula online for calculating EMI:

```
EMI = [P × R × (1+R)^N] / [(1+R)^N - 1]
```

where P is the loan amount, R is monthly interest rate, and N is total months

the tricky part was converting annual rate to monthly (divide by 12 and then by 100)

## Notes

- interest part keeps going down each month while principal part goes up
- by the end balance should be zero or really close to it
- used %.2lf to print values with 2 decimal places

## issues i ran into

honestly the math library thing took me a while to figure out. kept getting undefined reference errors until i added the -lm flag. also had to be careful with the data types (double vs int).

feel free to use this for your own projects or whatever!
