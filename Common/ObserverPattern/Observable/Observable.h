#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <CommonTypes.h>
#include <Observer.h>

#define MAX_OBSERVERS 3

typedef struct Observable Observable_t;

void Observable_Initialize(Observable_t* const self);
void Observable_Notify(const Observable_t* const self, void* arg);
bool Observable_RegisterObserver(Observable_t* const self, Observer_t* const observer);
void Observable_UnregisterObserver(Observable_t* const self, const Observer_t* const observer);

#endif /* OBSERVABLE_H_ */
