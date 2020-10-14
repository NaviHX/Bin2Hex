# 详细设计

stack *stackInit()  
初始化一个栈并获取它的结构指针

```c++
stack *stackInit()
{
    stack *ret = (stack *)malloc(sizeof(stack));
    ret->size = INIT_SIZE;
    ret->bot = (char *)malloc(sizeof(char) * INIT_SIZE);
    ret->top = 0;
    return ret;
}
```

char stackTop(stack *)  
获取栈顶

```c++
char stackTop(stack *s)
{
    return s->top == 0 ? '\0' : *(s->bot + s->top - 1);
}
```

void stackPop(stack *)  
去除栈顶

```c++
void stackPop(stack *s)
{
    if(...)//栈空直接退出
        //...
    //清除栈顶数据
    s->top--;
}
```

void stackPush(stack *, char)  
新元素入栈

```c++
void stackPush(stack *s, char c)
{
    //空间不足,重新申请空间
    {
        s->bot = (char *)realloc(s->bot, s->size + INCRE_SIZE);
        s->size += INCRE_SIZE;
    }
    //添加新元素
}
```

void stackFree(stack *)  
释放栈空间

```c++
void stackFree(stack *s)
{
    free(s->bot);
    free(s);
}
```

void printHex(stack *s)  
将栈中的二进制数据翻译为八进制数后输出

```c++
void printHex(stack *s)
{
    int temp[3];
    stack *ans = stackInit();

    while (stackTop(s) != '\0')
    {
        //连续取三位,不足补0
        //转换后压入ans
    }
    while (stackTop(ans) != '\0')
    {
        cout << stackTop(ans);
        stackPop(ans);
    }
}
```

void work()  
主要工作函数,处理输入

```c++
void work()
{
    string bnum;
    stack *inte = stackInit(), *frac = stackInit();
    bool fr;           //是否有小数部分
    bool legal = true; //合法输入标志
    cout << "请输入二进制数:";
    cin >> bnum;
    for (string::iterator i = bnum.begin(); i != bnum.end() && legal; i++)
    {
        //当遇见'#'时直接退出输入
        if (*i == '#')
            break;
        //当遇见'.'时切换输入栈至小数部分
        else if (*i == '.')
        {
            fr = true;
            continue;
        }
        //判断是否合法
        else if (*i != '1' && *i != '0')
            legal = false;
        //输入压入栈
    }
    if (legal)
    {
        printHex(inte);
        if (fr)
        {
            cout << '.';
            //小数部分补0在最低位,让小数部分长度控制为3的倍数
            printHex(frac);
        }
        cout << '\n';
    }
    else
        printf("输入非法,请检查二进制序列是否合法\n");
    //释放内存
}
```
