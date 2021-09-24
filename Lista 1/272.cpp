#include <iostream>

int main()
{
    std::string text = "";
    std::string line;
    std::string temp;
    bool start = true;
    std::string val = "\"";


    while (std::getline(std::cin, line))
    {
        temp = ""; 
        for (int k = 0; k < line.size(); k++)
        {
            //std::cout<< int(line[k])<< " `` ";
            if (int(line[k]) == 34)
            {
                if (start)
                {
                    temp += "``";
                                      
                    start = false;
                }
                else
                {
                    temp += "''";
                    start = true;
                }
            }
            else
                temp += line[k];
            // std::cout<< temp;  
        }


        text += temp;
        text += "\n";
    }

    std::cout<< text;


    return 0;
}