#include <iostream>
#include "Thermostat.h"
#include "Motor.h"

Thermostat thermostat;

int main()
{
    /*
    double desiredTemp = thermostat.getDesiredTemp();
    std::cout << desiredTemp << "\n";
    thermostat.raiseTemp();
    std::cout << thermostat.getDesiredTemp() << "\n";
    */

    while (true)
    {
        std::string temp;
        // We are entering the temperature
        printf("enter the temperature: \n");
        
        std::cin >> temp;
        double temp_double;
        
        try
        {
            temp_double = std::stod(temp);
        }
        catch (const std::invalid_argument& ia)
        {
            printf("invalid number \n");
            continue;
        }
        
        thermostat.update(temp_double);
        
        std::string command;
        //we are entering a command
        printf("enter a command: \n");
        
        std::cin >> command;
        
        if (command == "+")
        {
            thermostat.raiseTemp();
        }
        else if (command == "-")
        {
            thermostat.lowerTemp();
        }
        else 
        {
            printf("invalid command \n");
        }
        printf("desired temp: %.1f, cur temp: %.1f \n", thermostat.getDesiredTemp(), temp_double); 
        printf("current state: %d \n\n", thermostat.getState());
    }

    return 0;
}