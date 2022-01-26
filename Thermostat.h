#pragma once

#define THERMOSTAT_INIT 0
#define THERMOSTAT_OFF 1
#define THERMOSTAT_HEATING 2
#define THERMOSTAT_HIGH_HEAT 3

#include <thread>

class Thermostat
{
    double curTemp = 20.;
    double desiredTemp = 20.;
    double threshold = 0.25;
    double highHeatThreshold = 5.;
    int state = THERMOSTAT_INIT;
    
    public:
        void raiseTemp()
        {
            //desiredTemp = desiredTemp + 1.;
            desiredTemp += 1.;
        }
        
        void lowerTemp()
        {
            //desiredTemp = desiredTemp - 1.;
            desiredTemp -= 1.;
        }
        
        void update( double temp )
        {
            curTemp = temp;
            switch(state)
            {
                case (THERMOSTAT_OFF):
                    if (desiredTemp - threshold >= curTemp)
                    {
                        //temperature is too cold
                        state = THERMOSTAT_HEATING;
                    }
                    
                    if( desiredTemp - highHeatThreshold >= curTemp)
                    {
                        state = THERMOSTAT_HIGH_HEAT;
                    }
                    else 
                    {
                        //temp fine/too hot
                    }
                    break;
                case (THERMOSTAT_HEATING):
                case (THERMOSTAT_HIGH_HEAT):
                
                if (curTemp + threshold >= desiredTemp )
                {
                    //temperature is too cold
                    state = THERMOSTAT_OFF;
                    break;
                }
                
                    
                if(desiredTemp - highHeatThreshold >= curTemp)
                {
                    state = THERMOSTAT_HIGH_HEAT;
                } 
                else
                {
                    state = THERMOSTAT_HEATING;
                }
                break;
                default:
                    state = THERMOSTAT_OFF;
                    break;
            }
        }
        
        double getDesiredTemp()
        {
            return desiredTemp;
        }
        
        int getState(){
            return state;
        }
};