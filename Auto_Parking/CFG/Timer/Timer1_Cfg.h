#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

#define _1_prescalar 1
#define _8_prescalar 2
#define _64_prescalar 3
#define _256_prescalar 4
#define _1024_prescalar 5

#define Timer1_Prescaler _8_prescalar

#define Normal_mode 1
#define PWM_mode 2
#define CTC_mode 4
#define Fast_PWM_mode 14

#define Timer1_mode Normal_mode

#define Non_Inverting 2
#define Inverting 3

#define Timer1_modeofcmp Non_Inverting


#endif /* TIMER1_CFG_H_ */
