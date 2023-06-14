char counter(char a)
{
    if(a==')') return '(';
    if(a=='}') return '{';
    else return '[';
}
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> s;
    for(char i:expression)
    {
        if(i=='(' or i=='[' or i=='{') s.push(i);
        else
        {
            if(s.empty()) return false;
            if(s.top()==counter(i)) s.pop();
            else return false;
        }
    }
    if(s.empty())return true;
    return false;
}
