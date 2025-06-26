bool isValid(char* s) {
    //获取数组长度
    int len =strlen(s);

    //不可能为奇数，如果是奇数的话就返回false
    if(len % 2 == 1){
        return false;
    }

    //定义栈
    char* stack = (char*)malloc(len * sizeof(char));
    //初始化栈
    int top = -1;
    for(int i = 0; i < len;i++)
    {
        if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')){
            top++;
            stack[top] = s[i];
        }
        //如果数组中读取的是右括号，则栈中必须得有元素
        else{
            if(top == -1){
                free(stack);
                return false;
            }
        if ((s[i] == ')' && stack[top] == '(') ||
            (s[i] == '}' && stack[top] == '{') ||
            (s[i] == ']' && stack[top] == '[')) {
                top--;
            }
            else{
                free(stack);
                return false;
            }
        }
    }
    bool result = (top == -1) ? 1 : 0;
    free(stack);
    return result;
}