#ifndef Tires_CONTROL_INTERFACE_H_
#define Tires_CONTROL_INTERFACE_H_

#define Time_Angle 10

typedef enum{
	BW,
	FW
}move_state_t;

void CarCon_Vinit(void);
void CarCon_VMoveForward(u8 duty);
void CarCon_VMoveBackward(u8 duty);
void CarCon_VTurnRight(void);
void CarCon_VTurnRight_withAngle(u8 angle);
void CarCon_VTurnLeft(void);
void CarCon_VTurnLeft_withAngle(u8 angle);
void CarCon_VStop_Move(void);
void CarCon_VStop_Move_duty(void);
void CarCon_VStop_Rotate(void);

#endif /* Tires_CONTROL_INTERFACE_H_ */
