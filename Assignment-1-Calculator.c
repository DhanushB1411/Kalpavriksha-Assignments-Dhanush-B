#include<stdio.h>

#define ADD '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'

/* Function to check the priority of the operator based on DMAS */
int getOperatorPriority(char operator){
    if(operator == MULTIPLY || operator == DIVIDE) return 1;
    if(operator == ADD || operator == SUBTRACT) return 0;
    return -1;
}

/* Function to remove blank spaces from input */
void removeBlankSpaces(char input[]){
    int iteratorI = 0, index = 0;
    while(input[iteratorI] != '\0'){
        if(input[iteratorI] != ' '){
            input[index++] = input[iteratorI];
        }
        iteratorI++;
    }
    input[index] = '\0'; // Terminate cleaned string
}

/* Function to calculate remaining operations */
int evaluateRemainingOperations(int numbers[], char operators[], int *numberIndex, int *operatorIndex, int *errorStatus){
    while((*operatorIndex) != -1){
        int operand1 = numbers[--(*numberIndex)];
        int operand2 = numbers[--(*numberIndex)];
        char operator = operators[(*operatorIndex)--];

        if(operator == MULTIPLY){
            numbers[(*numberIndex)++] = operand2 * operand1;
        }
        else if(operator == SUBTRACT){
            numbers[(*numberIndex)++] = operand2 - operand1;
        }
        else if(operator == ADD){
            numbers[(*numberIndex)++] = operand2 + operand1;
        }
        else if(operator == DIVIDE){
            if(operand1 == 0){
                *errorStatus = 2;
                return 0;
            }
            numbers[(*numberIndex)++] = operand2 / operand1;
        }
    }
    return numbers[0];
}

/* Function to perform the calculation based on the input */
int performCalculation(char input[], int *errorStatus){
    int numbers[1000];      // Array to store numbers or operands
    char operators[1000];   // Array to store operators

    int numberIndex = 0;    
    int operatorIndex = -1;

    int iteratorI = 0;
    while(input[iteratorI] != '\0'){

        if(input[iteratorI] >= '0' && input[iteratorI] <= '9'){  // If the character is a number
            int tempNumber = 0;
            while(input[iteratorI] >= '0' && input[iteratorI] <= '9'){
                tempNumber = tempNumber * 10 + (input[iteratorI] - '0');
                iteratorI++;
            }
            numbers[numberIndex++] = tempNumber;
        }
        else if(input[iteratorI] == MULTIPLY || input[iteratorI] == DIVIDE || 
                input[iteratorI] == ADD || input[iteratorI] == SUBTRACT){

            while(operatorIndex != -1 && getOperatorPriority(operators[operatorIndex]) >= getOperatorPriority(input[iteratorI])){
                int operand1 = numbers[--numberIndex];
                int operand2 = numbers[--numberIndex];
                char operator = operators[operatorIndex--];

                if(operator == MULTIPLY){
                    numbers[numberIndex++] = operand2 * operand1;
                }
                else if(operator == SUBTRACT){
                    numbers[numberIndex++] = operand2 - operand1;
                }
                else if(operator == ADD){
                    numbers[numberIndex++] = operand2 + operand1;
                }
                else if(operator == DIVIDE){
                    if(operand1 == 0){
                        *errorStatus = 2;
                        return 0;
                    }
                    numbers[numberIndex++] = operand2 / operand1;
                }
            }
            operators[++operatorIndex] = input[iteratorI++];
        }
        else{  // Invalid character detected
            *errorStatus = 1;
            return 0;
        }
    }
    return evaluateRemainingOperations(numbers, operators, &numberIndex, &operatorIndex, errorStatus);
}

/* Main Function */
int main(){
    char input[1000];
    printf("Enter the operation: ");
    fgets(input, 1000, stdin);

    int iteratorI;
    for(iteratorI = 0; input[iteratorI] != '\0'; iteratorI++){
        if(input[iteratorI] == '\n'){
            input[iteratorI] = '\0';
            break;
        }
    }

    removeBlankSpaces(input);  // Remove blank spaces from the input

    int errorStatus = 0;
    int result = performCalculation(input, &errorStatus);

    if(errorStatus == 1){
        printf("Error: Invalid expression\n");
    }
    else if(errorStatus == 2){
        printf("'Error: Division by zero.'\n");
    }
    else{
        printf("Answer: %d\n", result);
    }

    return 0;
}
