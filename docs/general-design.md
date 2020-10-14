# 概要设计

## 功能思路

分别初始化两个栈用于存储整数部分和小数部分,将输入的字符串逐字符压栈并检查输入是否合法,在输入合法的情况下,每次从栈中取出3个字符计算八进制值,不足三个时补零(小数部分低位补零,整数部分高位补零),压入到输出栈中,最后从输出栈中打印到窗口

## 数据结构类型定义

```c++
typedef struct Stack
{
    char *bot; //栈底
    int top;   //栈顶
    int size;  //栈大小

} stack;
```

## 主程序流程

```c++
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
```

## 函数调用关系

main()调用work(),work()调用stackInit(),stackPush(),printHex(),stackFree(),printHex()调用stackInit(),stackPush(),stackTop(),stackPop()  
