#pragma once

class Motor
{
    enum MotorStates
    {
        MOTOR_INIT, MOTOR_OFF, MOTOR_LOW, MOTOR_MID, MOTOR_HIGH
    };

    MotorStates state = MOTOR_INIT;
    int motorSpeed = 0;

    void updateMotorSpeed()
    {
        switch(state)
        {
            case(MOTOR_OFF):
                motorSpeed = 0;
                break;
            case(MOTOR_LOW):
            //60 rpm
                motorSpeed = 60;
                break;
            case(MOTOR_MID):
            //120 rpm
                motorSpeed = 120;
                break;
            case(MOTOR_HIGH):
            //400 rpm
                motorSpeed = 400;
                break;
            case(MOTOR_INIT):
                motorSpeed = 0;
                break;
        }
    }

    public:

        int getMotorSpeed()
        {
            return motorSpeed;
        }

        bool speedUp()
        {
            switch(state)
            {
                case(MOTOR_OFF):
                    state = MOTOR_LOW;
                    return true;
                case(MOTOR_LOW):
                //60 rpm
                    state = MOTOR_MID;
                    return true;
                case(MOTOR_MID):
                //120 rpm
                    state = MOTOR_HIGH;
                    return true;
                case(MOTOR_HIGH):
                //400 rpm
                    return false;
                case(MOTOR_INIT):
                    return false;
            }
            updateMotorSpeed();
        }

        bool speedDown()
        {
            switch(state)
            {
                case(MOTOR_OFF):
                    return false;
                case(MOTOR_LOW):
                //60 rpm
                    return false;
                case(MOTOR_MID):
                //120 rpm
                    state = MOTOR_LOW;
                    return true;
                case(MOTOR_HIGH):
                //400 rpm
                    state = MOTOR_MID;
                    return true;
                case(MOTOR_INIT):
                    return false;
            }
            updateMotorSpeed();
        }

        void stop()
        {
            state = MOTOR_OFF;
            updateMotorSpeed();
        }
};