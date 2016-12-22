################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cursor.c \
../draw.c \
../font.c \
../graphicsManager.c \
../init.c \
../input.c \
../karel.c \
../main.c \
../world.c 

OBJS += \
./cursor.o \
./draw.o \
./font.o \
./graphicsManager.o \
./init.o \
./input.o \
./karel.o \
./main.o \
./world.o 

C_DEPS += \
./cursor.d \
./draw.d \
./font.d \
./graphicsManager.d \
./init.d \
./input.d \
./karel.d \
./main.d \
./world.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/home/christoph/Schreibtisch/dev/uni/bachelorarbeit/Karel -I"/home/christoph/Schreibtisch/dev/uni/bachelorarbeit/Karel" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


