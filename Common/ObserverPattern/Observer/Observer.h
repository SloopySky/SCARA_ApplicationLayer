#ifndef OBSERVER_H_
#define OBSERVER_H_

typedef struct Observer Observer_t;

void Observer_Initialize(Observer_t* const self, void (*observerUpdate)(Observer_t* const, void*));
void Observer_Update(Observer_t* const self, void* arg);

#endif /* OBSERVER_H_ */
