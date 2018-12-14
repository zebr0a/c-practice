#include "stack.h"

#define MAX_NUM 100

int calc(char op, int n1, int n2)
{
    switch (op)
    {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            return 0;
    }
}

int priority(char op)
{
    switch (op)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 3;
        default:
            return 0;
    }
}

int calculate(char s[])
{
    int i = 0, tmp = 0, n1, n2;
    Stack op, num;
    char c;
    if (InitStack(&op) && InitStack(&num))
    {
        while ((c = s[i]) != '\0' || IsEmpty(op) == FALSE)
        {
            if (c <= '9' && c >= '0')
            {
                tmp = tmp * 10 + c - '0';
                c = s[++i];
                if (c > '9' || c < '0')
                {
                    Push(&num, tmp);
                    tmp = 0;
                }
            }
            else if (c == ')')
            {
                printf("in\n");
                while ((c = Pop(&op)) != '(')
                {
                    n2 = Pop(&num);
                    n1 = Pop(&num);
                    Push(&num, calc(c, n1, n2));
                }
                i++;
            }
            else if (GetTop(op) == '(' && priority(c) != 0)
            {
                Push(&op, c);
                i++;
            }
            else if (priority(c) <= priority(GetTop(op)))
            {
                    n2 = Pop(&num);
                    n1 = Pop(&num);
                    printf("%d%c%d\n", n1, ' ', n2);
                    Push(&num, calc(Pop(&op), n1, n2));
            }
            else if (c != '\0')
            {
                Push(&op, c);
                i++;
            }
        }
        return Pop(&num);
    }

    return ERROR;
}

int main()
{
    char equation[MAX_NUM], ch;
    int r = 0;

    printf("Please input the equation: ");
    scanf("%s", equation);
    printf("%s\n", equation);
    r = calculate(equation);
    printf("\nThe result is %d", r);

    return 0;
}