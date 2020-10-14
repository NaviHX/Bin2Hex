# 调试分析报告

访问栈顶时返回值错误

```c++
 char stackTop(stack *s)
 {
-    return s->top == 0 ? *(s->bot + s->top - 1) : '\0';     
+    return s->top == 0 ? '\0' : *(s->bot + s->top - 1);
 }
```
