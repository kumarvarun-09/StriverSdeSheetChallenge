void insert(stack<int> &stack, int num)
{
    if(stack.empty() || stack.top() <= num)
    { 
        stack.push(num);
        return;
    }
    int var = stack.top();
    stack.pop();
    insert(stack, num);
    stack.push(var);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty())
        return;
    int var = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, var);    
}
