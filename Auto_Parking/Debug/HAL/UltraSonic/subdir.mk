################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/UltraSonic/UltraSonic.c 

OBJS += \
./HAL/UltraSonic/UltraSonic.o 

C_DEPS += \
./HAL/UltraSonic/UltraSonic.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/UltraSonic/%.o: ../HAL/UltraSonic/%.c HAL/UltraSonic/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\APP" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\CFG" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\HAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\MCAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\SERVICES" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


