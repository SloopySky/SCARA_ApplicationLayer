add_library(Common INTERFACE)
target_include_directories(Common INTERFACE .)

add_library(ObserverPattern STATIC ObserverPattern/Observable/Observable.c ObserverPattern/Observer/Observer.c)
target_include_directories(ObserverPattern PUBLIC ObserverPattern/Observable ObserverPattern/Observer)
target_link_libraries(ObserverPattern Common)
