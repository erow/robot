#ifndef DEVICE_DATA_H
#define DEVICE_DATA_H
#include "pendulum.h"
class device_data
{
public:
    Pendulum* model_data;
    int motor_data[20];

    void ModelToMotor();
    void MotorToModel();
    device_data();
};

#endif // DEVICE_DATA_H
