#pragma once

class Motor {
  enum MotorState { MOTOR_INIT, MOTOR_OFF, MOTOR_LOW, MOTOR_MID, MOTOR_HIGH };

  MotorState state = MOTOR_OFF;
  int motorSpeed = 0;

  void setMotorSpeed() {
    switch (state) {
    case MOTOR_LOW:
      motorSpeed = 60;
      break;
    case MOTOR_MID:
      motorSpeed = 120;
      break;
    case MOTOR_HIGH:
      motorSpeed = 400;
      break;
    default:
      motorSpeed = 0;
    };
  }

public:
  bool speedUp() {
    switch (state) {
    case MOTOR_INIT:
    case MOTOR_OFF:
      state = MOTOR_LOW;
      return true;
    case MOTOR_LOW:
      state = MOTOR_MID;
      return true;
      break;
    case MOTOR_MID:
      state = MOTOR_HIGH;
      return true;
      break;
    case MOTOR_HIGH:
      state = MOTOR_HIGH;
      return false;
    };
  }

  bool speedDown() {
    switch (state) {
    case MOTOR_INIT:
    case MOTOR_OFF:
      return true;
    case MOTOR_LOW:
      state = MOTOR_OFF;
      return true;
      break;
    case MOTOR_MID:
      state = MOTOR_LOW;
      return true;
      break;
    case MOTOR_HIGH:
      state = MOTOR_MID;
      return true;
    };
  }
};