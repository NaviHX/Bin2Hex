#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

#define INIT_SIZE 50
#define INCRE_SIZE 10

using namespace std;

typedef struct Stack
{
    char *bot;
    int top;
    int size;

} stack;

stack *stackInit();            // 获取一个栈
char stackTop(stack *);        // 获取栈顶
void stackPop(stack *);        // 去除栈顶
void stackPush(stack *, char); // 新元素入栈
void stackFree(stack *);       // 删除栈
void work();                   // 执行功能
void printHex(stack *);        // 打印

int main()
{
    int arg;
    do
    {
        cout << "请输入功能选项\n1.二进制转八进制\n0.结束程序\n选项:";
        cin >> arg;
        switch (arg)
        {
        case 1:
            work();
            break;
        case 0:
            cout << "感谢使用\n";
            break;
        default:
            cout << "无效的选项\n";
            break;
        }
    } while (arg);
    return 0;
}

stack *stackInit()
{
    stack *ret = (stack *)malloc(sizeof(stack));
    ret->size = INIT_SIZE;
    ret->bot = (char *)malloc(sizeof(char) * INIT_SIZE);
    ret->top = 0;
    return ret;
}

char stackTop(stack *s)
{
    return s->top == 0 ? '\0' : *(s->bot + s->top - 1);
}

void stackPop(stack *s)
{
    if (s->top == 0)
        return;
    *(s->bot + s->top - 1) = '\0';
    s->top--;
}

void stackPush(stack *s, char c)
{
    if (s->top >= s->size)
    {
        s->bot = (char *)realloc(s->bot, s->size + INCRE_SIZE);
        s->size += INCRE_SIZE;
    }
    s->bot[s->top++] = c;
}

void stackFree(stack *s)
{
    free(s->bot);
    free(s);
}

void work()
{
    string bnum;
    stack *inte = stackInit(), *frac = stackInit();
    bool fr;
    cout << "请输入二进制数:";
    cin >> bnum;
    for (string::iterator i = bnum.begin(); i != bnum.end(); i++)
    {
        if (*i == '.')
        {
            fr = true;
            continue;
        }
        if (fr)
            stackPush(frac, *i);
        else
            stackPush(inte, *i);
    }
    printHex(inte);
    if (fr)
    {
        cout << '.';
        switch (frac->top % 3)
        {
        case 1:
            stackPush(frac, '0');
        case 2:
            stackPush(frac, '0');
            break;
        }
        printHex(frac);
    }
    cout<<'\n';
    stackFree(inte);
    stackFree(frac);
}

void printHex(stack *s)
{
    int temp[3];
    stack *ans = stackInit();
    while (stackTop(s) != '\0')
    {
        for (int i = 0; i < 3; i++)
        {
            temp[i] = stackTop(s) == '\0' ? 0 : stackTop(s) - '0';
            stackPop(s);
        }
        stackPush(ans, temp[0] + temp[1] * 2 + temp[2] * 4 + '0');
    }
    while (stackTop(ans) != '\0')
    {
        cout << stackTop(ans);
        stackPop(ans);
    }
}
