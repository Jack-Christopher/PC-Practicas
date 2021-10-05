#include <bits/stdc++.h>

struct PhotoRecord
{
    int mes, dia, hora, minuto, lugar;
    bool es_exit;
    int getTime() { return minuto + hora*60 + dia*24*60; }
};

int main() 
{
    int n;
    std::string input;
    std::cin>> n;

    while(n--)
    {
        int tolls[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        std::map<std::string, std::vector<PhotoRecord>> PhotoRecordMap;
        for(int k = 0; k < 24; k++) 
            std::cin>> tolls[k];
            
        std::cin.ignore();

        while(std::getline(std::cin,input), !input.empty())
        {
            std::istringstream reader(input);
            std::string placa, accion;
            char ignore;
            PhotoRecord record;
            reader >> placa >> record.mes >> ignore >> record.dia >> ignore >> record.hora >> ignore >> record.minuto >> accion >> record.lugar;
            record.es_exit = accion == "exit";
            PhotoRecordMap[placa].push_back(record);
        }

        for(auto& pair : PhotoRecordMap)
        {
            sort(pair.second.begin(), pair.second.end(),[](PhotoRecord a, PhotoRecord b){ return a.getTime() < b.getTime(); });
            int total = 200;

            for(int k = 0; k < pair.second.size(); k++)
            {
                if(!pair.second[k].es_exit && k+1 < pair.second.size() && pair.second[k+1].es_exit)
                {
                    int dist = abs(pair.second[k].lugar - pair.second[k+1].lugar);
                    total += dist*tolls[pair.second[k].hora];
                    total += 100;
                }
            }
            if(total != 200)
                std::cout << pair.first << " $" << std::setprecision(2) << std::fixed << total/100.0 << std::endl;
        }
        if(n) std::cout << std::endl;
    }
}
