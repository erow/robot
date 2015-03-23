#include "device_data.h"

device_data::device_data()
{
    model_data=0;
    for(int i=0;i<20;i++){
        motor_data[i]=512;
    }
}
void device_data::ModelToMotor(){

}
void device_data::MotorToModel(){

}
