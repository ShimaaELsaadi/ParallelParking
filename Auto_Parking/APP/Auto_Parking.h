#ifndef AUTO_PARKING_H_
#define AUTO_PARKING_H_

#define BUTTON_PIN PINA0
#define BUZZER_PIN PINB0
#define LED_PIN PINB1

#define SPOT_NOTFOUND 0
#define SPOT_FOUND 1
#define Car_Parked 2

#define STATE_0 0
#define STATE_1 1
#define STATE_2 2

#define MIN_DISTANCE 15
#define Adjust_Distance 7
#define Front_Distance 12
#define Front_Min 7
#define Park_Distance 7

void Auto_Parking_init(void);
void Auto_Parking_Runnable(void);

void Car_Adjust(void);
void Find_Slot_init(void);
void Find_Slot_Runnable(void);

void Park_Finish(void);
void Parking_Runnable(void);

#endif /* AUTO_PARKING_H_ */
