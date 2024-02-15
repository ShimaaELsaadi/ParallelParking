#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

#define resoultion 256

#define no_prescalar 1
#define _8_prescalar 2
#define _64_prescalar 3
#define _256_prescalar 4
#define _1024_prescalar 5

#define Timer0_Prescaler _8_prescalar

#define Normal_mode 1
#define PWM_mode 2
#define CTC_mode 3
#define Fast_PWM_mode 4

#define Timer0_mode CTC_mode

#define Non_Inverting 2
#define Inverting 3

#define Timer0_modeofcmp Non_Inverting


#endif /* TIMER0_CFG_H_ */
