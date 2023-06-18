#ifndef OBSERVERTYPE_H_
#define OBSERVERTYPE_H_

#include "Observer.h"

struct Observer {
    void (*observerUpdate)(struct Observer* const observer, void* arg);
};

#endif /* OBSERVERTYPE_H_ */
