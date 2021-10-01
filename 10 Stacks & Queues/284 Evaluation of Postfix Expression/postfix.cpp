//Function to evaluate a postfix expression.
int evaluatePostfix(char* exp)
{
    // Your code here
    struct Stack* stack = createStack(strlen(exp));
    if (!stack) return -1; 
    int i = 0;
    for (i = 0; exp[i]; ++i) 
    {
        if (isdigit(exp[i])) 
            push(stack, exp[i] - '0'); 
        else
        { 
            int val1 = pop(stack); 
            int val2 = pop(stack); 
            switch (exp[i]) 
            { 
            case '+': push(stack, val2 + val1); break; 
            case '-': push(stack, val2 - val1); break; 
            case '*': push(stack, val2 * val1); break; 
            case '/': push(stack, val2/val1); break; 
            } 
        } 
    } 
    return pop(stack);
}