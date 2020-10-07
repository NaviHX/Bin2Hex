# 二进制转八进制

栈实现

小数部分向低位补全至3的倍数,字符串逆转后每三位处理

## 调试报告

访问栈顶时返回值错误

```c++
 char stackTop(stack *s)
 {
-    return s->top == 0 ? *(s->bot + s->top - 1) : '\0';     
+    return s->top == 0 ? '\0' : *(s->bot + s->top - 1);
 }
```
