#include <bits/stdc++.h>

struct PhotoRecord
{
    int mes, dia, hora, minuto, lugar;
    bool es_exit;
    int getTime() { return minuto + hora*60 + dia*24*60; }
};

bool compare_PhotoRecords(PhotoRecord a, PhotoRecord b)
{
    return a.getTime() < b.getTime();
}

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
            sort(pair.second.begin(), pair.second.end(), compare_PhotoRecords);
            // pago fijo inicial 2 dolares (200 centavos)
            int total = 200;

            for(int k = 0; k < pair.second.size()-1; k++)
            {
                // Si el primero es de "enter" y el segundo es "exit"
                if(!pair.second[k].es_exit && pair.second[k+1].es_exit)
                {
                    // distancia absoluta
                    int dist = abs(pair.second[k].lugar - pair.second[k+1].lugar);
                    total += dist*tolls[pair.second[k].hora];
                    total += 100; // un dolar (100 centavos) adicional por cada viaje
                }
            }
            // Si se ha realizado al menos un viaje 
            if(total != 200)
                std::cout << pair.first << " $" << std::setprecision(2) << std::fixed << total/100.00 << std::endl;
        }
        if(n) 
            std::cout << "\n";
    }
}
