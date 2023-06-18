#include "ObserverType.h"
#include <assert.h>

void Observer_Initialize(Observer_t* const self, void (*observerUpdate)(Observer_t* const, void*))
{
    assert(self);
    assert(observerUpdate);
    self->observerUpdate = observerUpdate;
}

void Observer_Update(Observer_t* const self, void* arg)
{
    assert(self);
    assert(self->observerUpdate);
    self->observerUpdate(self, arg);
}
