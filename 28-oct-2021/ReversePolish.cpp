#include <iostream>
#include <vector>

int evalRPN(std::vector<std::string>& tokens) 
{
    std::vector<int> stack;
    for (auto& token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            if (token == "+")
                stack.push_back(a + b);
            else if (token == "-")
                stack.push_back(b - a);
            else if (token == "*")
                stack.push_back(a * b);
            else if (token == "/")
                stack.push_back(b / a);
        }
        else
            stack.push_back(std::stoi(token));
    }
    return stack.back();

}

int main()
{
    std::vector<std::string> tokens = { "10","6","9","3","+","-11","*","/","*","17","+","5","+" };
    std::cout << evalRPN(tokens) << std::endl;
    return 0;
}