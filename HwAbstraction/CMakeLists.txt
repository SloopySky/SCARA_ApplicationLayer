add_library(StepMotor StepMotor/StepMotor.c)
target_include_directories(StepMotor PUBLIC StepMotor)
target_link_libraries(StepMotor Common ObserverPattern IGpio IOneShotTimer)
