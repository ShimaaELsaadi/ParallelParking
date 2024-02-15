#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

void Timer2_init(void);
void Timer2_start(void);
void Timer2_stop(void);

void Timer2_set_int_value(u8 value);
void Timer2_set_cmp_value(u8 value);

void Timer2_PWM_set_cmp(u8 duty);
void Timer2_PWM_set_cmp_PC(u8 duty);

void Timer2_OV_InterruptEnable(void);
void Timer2_OV_InterruptDisable(void);
void Timer2_OC_InterruptEnable(void);
void Timer2_OC_InterruptDisable(void);

void Timer2_OV_set_callbck(void (*p2f_var)(void));
void Timer2_OC_set_callbck(void (*p2f_var)(void));


#endif /* TIMER2_INTERFACE_H_ */
