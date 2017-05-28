################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/NSchiffer_CS140S_PokerGame.cpp \
../src/Poker.cpp \
../src/Scores.cpp 

OBJS += \
./src/NSchiffer_CS140S_PokerGame.o \
./src/Poker.o \
./src/Scores.o 

CPP_DEPS += \
./src/NSchiffer_CS140S_PokerGame.d \
./src/Poker.d \
./src/Scores.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


