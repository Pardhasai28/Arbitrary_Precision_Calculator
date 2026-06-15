/*
Name : V.PARDHA SAI(25040B_056)
Date : 17/05/2026
Description :    Arbitrary Precision Calculator

This project performs arithmetic operations such as addition, subtraction, multiplication, and division on very large numbers that cannot be handled using normal data types.  
The numbers are stored digit by digit in doubly linked lists to efficiently process large integer calculations.

compare_list : Compares two doubly linked lists digit by digit and determines which number is greater, smaller, or equal.

validate_num : Validates whether the given input string contains only valid numeric characters.

validate_operator : Checks whether the entered operator is a valid arithmetic operator such as +, -, *, or /.

compare_abs : Compares the absolute values of two large numbers represented as strings.

create_list : Creates a doubly linked list for a given large number by storing each digit in separate nodes.

print_list : Displays all digits stored in the doubly linked list in proper number format.

print_resultlist : Prints the resultant doubly linked list after performing arithmetic operations.

Add : Performs addition of two large numbers using doubly linked lists and stores the result in a separate list.

Sub : Performs subtraction between two large numbers and stores the result in the result linked list.

Mul : Performs multiplication of two very large numbers using doubly linked list representation.

Div : Performs division of large numbers and stores the quotient in the result linked list.
*/
#include "dll.h"

int main(int argc, char *argv[])
{
    Dll *head1 = NULL, *head2 = NULL; // Head pointers for input numbers
    Dll *tail1 = NULL, *tail2 = NULL; // Tail pointers for input numbers
    Dll *rhead = NULL, *rtail = NULL; // Head and tail pointers for result

    char sign1 = '+', sign2 = '+'; // Default signs

    if(argc == 4) // Check number of command line arguments
    {
        if((validate_num(argv[1])) && (validate_num(argv[3]))) // Validate numbers
        {
            printf(BMAGENTA "\nSuccessfully Validated Both Numbers\n" RESET); // Validation success
        }
        else
        {
            printf(RED "Only Numbers Are Allowed In 2nd And 4th Argument\n" RESET); // Invalid number error
            printf(YELLOW "\nUSAGE :\n" RESET); // Usage heading

            printf(BCYAN "./result.exe <number1> <operator> <number2>\n" RESET); // Proper syntax

            printf(ORANGE "\nEXAMPLE :\n" RESET); // Example heading

            printf(GREEN "./result.exe 123456789 + 987654321\n\n" RESET); // Example command
            return 0;
        }

        if(argv[1][0] == '+' || argv[1][0] == '-') // Extract sign of first number
        {
            sign1 = argv[1][0];
        }

        if(argv[3][0] == '+' || argv[3][0] == '-') // Extract sign of second number
        {
            sign2 = argv[3][0];
        }

        if(!validate_operator(argv[2])) // Validate arithmetic operator
        {
            printf(RED "Only Arithmetic Operators (+,-,x,/) Are Allowed\n" RESET); // Invalid operator error
            printf(YELLOW "\nUSAGE :\n" RESET); // Usage heading

            printf(BCYAN "./result.exe <number1> <operator> <number2>\n" RESET); // Proper syntax

            printf(ORANGE "\nEXAMPLE :\n" RESET); // Example heading

            printf(GREEN "./result.exe 123456789 + 987654321\n\n" RESET); // Example command
            return 0;
        }
        else
        {
            printf(BMAGENTA "\nOperator Validated Successfully\n" RESET); // Operator validation success
        }

        if(create_list(argv[1], &head1, &tail1) == SUCCESS) // Create DLL for first number
        {
            printf(BBLUE "Operand1 -> " RESET); // First number heading
            if(argv[1][0] == '-')
            printf(YELLOW"-"RESET);
            print_list(head1); // Display first number
        }

        char operator = argv[2][0]; // Store operator

        printf(ORANGE "Operator -> %c\n" RESET, operator); // Display operator

        if(create_list(argv[3], &head2, &tail2) == SUCCESS) // Create DLL for second number
        {
            printf(BBLUE "Operand2 -> " RESET); // Second number heading
            if(argv[3][0] == '-')
            printf(YELLOW"-"RESET);
            print_list(head2); // Display second number
        }

        switch(operator) // Perform arithmetic operation
        {
            case '+':
            {
                int result_sign = '+'; // Default result sign

                int cmp = compare_abs(argv[1], argv[3]); // Compare absolute values

                if(sign1 == '+' && sign2 == '+')
                {
                    Add(head1, head2, tail1, tail2, &rhead, &rtail); // Addition

                    result_sign = '+';
                }
                else if(sign1 == '+' && sign2 == '-')
                {
                    if(cmp >= 0)
                    {
                        Sub(head1, head2, tail1, tail2, &rhead, &rtail); // Subtraction

                        result_sign = '+';
                    }
                    else
                    {
                        Sub(head2, head1, tail2, tail1, &rhead, &rtail);

                        result_sign = '-';
                    }
                }
                else if(sign1 == '-' && sign2 == '+')
                {
                    if(cmp >= 0)
                    {
                        Sub(head1, head2, tail1, tail2, &rhead, &rtail);

                        result_sign = '-';
                    }
                    else
                    {
                        Sub(head2, head1, tail2, tail1, &rhead, &rtail);

                        result_sign = '+';
                    }
                }
                else if(sign1 == '-' && sign2 == '-')
                {
                    Add(head1, head2, tail1, tail2, &rhead, &rtail);

                    result_sign = '-';
                }
                
                printf(GREEN "Result   -> " RESET); // Result heading
                if(result_sign == '-')
                {
                    printf(RED "-" RESET); // Negative sign
                }


                print_resultlist(rhead); // Display result

                break;
            }

            case '-':
            {
                int result_sign = '+'; // Default result sign

                int cmp = compare_abs(argv[1], argv[3]); // Compare absolute values

                if(cmp > 0)
                {
                    if(sign1 == '+' && sign2 == '+')
                    {
                        Sub(head1, head2, tail1, tail2, &rhead, &rtail);

                        result_sign = '+';
                    }
                    else if(sign1 == '-' && sign2 == '-')
                    {
                        Sub(head1, head2, tail1, tail2, &rhead, &rtail);

                        result_sign = '-';
                    }
                    else if(sign1 == '+' && sign2 == '-')
                    {
                        Add(head1, head2, tail1, tail2, &rhead, &rtail);

                        result_sign = '+';
                    }
                    else if(sign1 == '-' && sign2 == '+')
                    {
                        Add(head1, head2, tail1, tail2, &rhead, &rtail);

                        result_sign = '-';
                    }
                }
                else if(cmp < 0)
                {
                    if(sign1 == '+' && sign2 == '+')
                    {
                        Sub(head2, head1, tail2, tail1, &rhead, &rtail);

                        result_sign = '-';
                    }
                    else if(sign1 == '-' && sign2 == '-')
                    {
                        Sub(head2, head1, tail2, tail1, &rhead, &rtail);

                        result_sign = '+';
                    }
                    else if(sign1 == '+' && sign2 == '-')
                    {
                        Add(head2, head1, tail2, tail1, &rhead, &rtail);

                        result_sign = '+';
                    }
                    else if(sign1 == '-' && sign2 == '+')
                    {
                        Add(head2, head1, tail2, tail1, &rhead, &rtail);

                        result_sign = '-';
                    }
                }
                else
                {
                    Dll *new = (Dll *)malloc(sizeof(Dll)); // Create node for zero result

                    if(new == NULL)
                    {
                        return FAILURE;
                    }

                    new->data = 0;
                    new->prev = NULL;
                    new->next = NULL;

                    rhead = new;
                    rtail = new;

                    result_sign = '+';
                }
                
                printf(GREEN "Result   -> " RESET); // Result heading
                if(result_sign == '-')
                {
                    printf(RED "-" RESET); // Negative sign
                }


                print_resultlist(rhead); // Display result

                break;
            }

            case 'x':
            {
                Mul(head1, head2, tail1, tail2, &rhead, &rtail); // Multiplication
                
                printf(GREEN "Result   -> " RESET); // Result heading
                if(sign1 != sign2)
                {
                    printf(RED "-" RESET); // Negative sign
                }


                print_resultlist(rhead); // Display result

                break;
            }

            case '/':
            {
                if(strlen(argv[3]) == 1 && argv[3][0] == '0') // Division by zero check
                {
                    printf(RED "Undefined\n" RESET); // Undefined result

                    return SUCCESS;
                }

                if(strlen(argv[1]) == strlen(argv[3]))
                {
                    if(strcmp(argv[1], argv[3]) < 0)
                    {
                        Dll *new = (Dll *)malloc(sizeof(Dll)); // Quotient = 0

                        new->data = 0;
                        new->prev = NULL;
                        new->next = NULL;

                        rhead = new;
                        rtail = new;
                    }
                    else if(strcmp(argv[1], argv[3]) == 0)
                    {
                        Dll *new = (Dll *)malloc(sizeof(Dll)); // Quotient = 1

                        new->data = 1;
                        new->prev = NULL;
                        new->next = NULL;

                        rhead = new;
                        rtail = new;
                    }
                    else
                    {
                        Div(head1, head2, tail1, tail2, &rhead, &rtail); // Division
                    }
                }
                else if(strlen(argv[1]) > strlen(argv[3]))
                {
                    Div(head1, head2, tail1, tail2, &rhead, &rtail); // Division
                }
                else
                {
                    Dll *new = (Dll *)malloc(sizeof(Dll)); // Quotient = 0

                    new->data = 0;
                    new->prev = NULL;
                    new->next = NULL;

                    rhead = new;
                    rtail = new;
                }
                
                printf(GREEN "Result   -> " RESET); // Result heading
                if(sign1 != sign2)
                {
                    printf(RED "-" RESET); // Negative sign
                }


                print_resultlist(rhead); // Display result

                break;
            }
        }
        printf("\n");
        while(head1 != NULL) // Free first number list
        {
            Dll *temp1 = head1;

            head1 = head1->next;

            free(temp1);
        }

        while(head2 != NULL) // Free second number list
        {
            Dll *temp1 = head2;

            head2 = head2->next;

            free(temp1);
        }

        while(rhead != NULL) // Free result list
        {
            Dll *temp1 = rhead;

            rhead = rhead->next;

            free(temp1);
        }
    }
    else
    {
        printf(RED "\nInvalid Number Of Arguments Provided\n" RESET); // Argument error

        printf(YELLOW "\nUSAGE :\n" RESET); // Usage heading

        printf(BCYAN "./result.exe <number1> <operator> <number2>\n" RESET); // Proper syntax

        printf(ORANGE "\nEXAMPLE :\n" RESET); // Example heading

        printf(GREEN "./result.exe 123456789 + 987654321\n\n" RESET); // Example command

        return 0;
    }
}