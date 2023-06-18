add_library(IGpio IGpio/IGpioStubs.c)
target_include_directories(IGpio PUBLIC IGpio)
target_link_libraries(IGpio Common)

add_library(IOneShotTimer IOneShotTimer/IOneShotTimerStubs.c)
target_include_directories(IOneShotTimer PUBLIC IOneShotTimer)
target_link_libraries(IOneShotTimer Common)
