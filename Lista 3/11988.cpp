#include <iostream>

int main()
{
    std::string line, result, temp = "";
    int mode = 0;
    bool changed = false;
    while (std::cin>> line)
    {
        if (std::cin.eof())
            break;
        result = "";
        temp = "";
        for (int k = 0; k < line.size(); k++)
        {
            if (line[k] == '[')
            {
                if (mode == 0 || mode == 1)
                    result = temp + result;
                else if (mode == 2)
                    result += temp;

                temp = "";
                mode = 1;                
            }
            else if (line[k] == ']')
            {
                if (mode == 0 || mode == 1)
                    result = temp + result;
                else if (mode == 2)
                    result += temp;
                temp = "";
                mode = 2;                
            }
            else
            {
                temp += line[k];                
            }
                        
        }

        if (mode == 0 || mode == 1)
            result = temp + result;
        else if (mode == 2)
            result += temp;

        std::cout << result << std::endl;
        result = "";
    }

    return 0;
}