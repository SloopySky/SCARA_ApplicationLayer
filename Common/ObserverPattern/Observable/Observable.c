#include "ObservableType.h"
#include <assert.h>

void Observable_Initialize(Observable_t* const self)
{
    assert(self);
    for (uint8_t i = 0; i < MAX_OBSERVERS; i++) self->observers[i] = NULL;
}

void Observable_Notify(const Observable_t* const self, void* arg)
{
    assert(self);
    for (uint8_t i = 0; i < MAX_OBSERVERS; i++) Observer_Update(self->observers[i], arg);
}

bool Observable_RegisterObserver(Observable_t* const self, Observer_t* const observer)
{
    assert(self);
    assert(observer);

    for (uint8_t i = 0; i < MAX_OBSERVERS; i++)
    {   
        if (self->observers[i] == NULL)
        {
            self->observers[i] = observer;
            return true;
        }
    }
    return false;
}

void Observable_UnregisterObserver(Observable_t* const self, const Observer_t* const observer)
{
    assert(self);
    assert(observer);

    for (uint8_t i = 0; i < MAX_OBSERVERS; i++)
    {   
        if (self->observers[i] == observer)
        {
            self->observers[i] = NULL;
            return;
        }
    }
}
