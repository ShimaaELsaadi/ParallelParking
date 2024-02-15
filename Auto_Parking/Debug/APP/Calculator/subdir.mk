################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Calculator/Calculator.c \
../APP/Calculator/Calculator2.c 

OBJS += \
./APP/Calculator/Calculator.o \
./APP/Calculator/Calculator2.o 

C_DEPS += \
./APP/Calculator/Calculator.d \
./APP/Calculator/Calculator2.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Calculator/%.o: ../APP/Calculator/%.c APP/Calculator/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\APP" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\CFG" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\HAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\MCAL" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking\SERVICES" -I"C:\Users\alsol\eclipse-workspace\Auto_Parking" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


