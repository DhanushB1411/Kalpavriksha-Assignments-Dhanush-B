#include<stdio.h>

int error = 0;

int priority_op(char operator){
    if(operator == '*' || operator == '/')return 1;
    if(operator == '+' || operator == '-')return 0;
    return -1;
}

int calculate(char input[]){

    int numbers[1000]; // to store the number;
    char operators[1000]; //to store operators;

    int num_idx =0;
    int op_idx =-1;

    int i=0;
    while(input[i] !='\0'){

        if(input[i] == ' '){
            i++;
            continue;
        }

    
        if(input[i] >= '0' && input[i]<='9'){
            int temp_num=0;
            while(input[i]>='0' && input[i] <='9'){
                temp_num = temp_num*10 + (input[i]-'0');
                i++;
            }
            numbers[num_idx] = temp_num;
            num_idx++;
        }
        else if( input[i] == '*' || input[i] == '/' || input[i] == '+' || input[i] == '-'){

            while(op_idx !=-1 && priority_op(operators[op_idx])>= priority_op(input[i])) {
                int num1 = numbers[--num_idx];

                int num2 = numbers[--num_idx];
                
                char operator = operators[op_idx--];
                if(operator == '*'){
                    numbers[num_idx++] = num2*num1;
                }else if(operator == '-'){
                    numbers[num_idx++] = num2-num1;
                }else if(operator == '+'){
                    numbers[num_idx++] = num2+num1;
                }else if(operator == '/'){

                    if(num1 == 0 ){
                        error =2;
                        return 0;
                    }else {
                        numbers[num_idx++] = num2/num1;
                    }
                }
            }
            operators[++op_idx]=input[i];
            i++;
        }
        else {
            error =1;
            return 0;
        }
    }
    while(op_idx !=-1){
        int num1 = numbers[--num_idx];
        int num2 = numbers[--num_idx];

        char operator =  operators[op_idx--];
         if(operator == '*'){
                    numbers[num_idx++] = num2*num1;
                }else if(operator == '-'){
                    numbers[num_idx++] = num2-num1;
                }else if(operator == '+'){
                    numbers[num_idx++] = num2+num1;
                }else if(operator == '/'){

                    if(num1 == 0 ){
                        error =2;
                        return 0;
                    }else {
                        numbers[num_idx++] = num2/num1;
                    }
                }
    }
    int ans = numbers[0];
    return ans;
}
void main(){

    char input[1000];
    printf("Enter the operation : ");

    fgets(input,1000,stdin);

    
    int i=0;
     for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    int res = calculate(input);
    
    if(error == 1){
        printf(" Invalid expression. Please check the operator  \n");
    }else if(error == 2){
        printf(" division by zero 0 is not allowed\n");
    }else{
        printf(" answer : %d\n ",res);
    }
}