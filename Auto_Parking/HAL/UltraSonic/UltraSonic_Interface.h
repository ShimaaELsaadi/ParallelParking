#ifndef ULTRASONIC_INTERFACE_H_
#define ULTRASONIC_INTERFACE_H_

typedef enum{
	US_1=0,
	US_2,
	US_3,
	US_4
}US_t;

void US_init(void);
void US_get_distance(US_t us,u8 *d);

#endif /* ULTRASONIC_INTERFACE_H_ */
