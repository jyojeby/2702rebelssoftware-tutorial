#pragma once


#include "Motor.h"
#include <thread>

class Thermostat {

  enum ThermostatState { 
      THERMOSTAT_INIT, 
      THERMOSTAT_HEATING, 
      THERMOSTAT_IDLE, 
      THERMOSTAT_COOLING};

  double curTemp = 20.;
  double desiredTemp = 20.;
  double threshold = 0.25;
  double highHeatThreshold = 5.;
  Motor *fan;
  ThermostatState state = THERMOSTAT_INIT;

public:
  Thermostat(Motor *fan) { this->fan = fan; }

  void raiseTemp() {
    // desiredTemp = desiredTemp + 1.;
    desiredTemp += 1.;
  }

  void lowerTemp() {
    // desiredTemp = desiredTemp - 1.;
    desiredTemp -= 1.;
  }

  void update(double temp) {
    curTemp = temp;
    if (desiredTemp - threshold >= curTemp) {
        // temperature is too cold
        state = THERMOSTAT_HEATING;
    } else if (desiredTemp + threshold <= curTemp) {
        // themerature is too hot
        state = THERMOSTAT_COOLING;
    } else {
        state = THERMOSTAT_IDLE;
    }
    updateMotor();
  }

  void updateMotor() {
    switch (state) {
    case THERMOSTAT_IDLE:
    case THERMOSTAT_INIT:
    case THERMOSTAT_HEATING: 
      fan->stop();
      break;
    case THERMOSTAT_COOLING:
      fan->speedUp();
    }
  }

  double getDesiredTemp() { return desiredTemp; }

  int getState() { return state; }
};