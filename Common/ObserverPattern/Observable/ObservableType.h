#ifndef OBSERVABLETYPE_H_
#define OBSERVABLETYPE_H_

#include "Observable.h"
#include <Observer.h>

struct Observable {
    Observer_t* observers[MAX_OBSERVERS];
};

#endif /* OBSERVABLETYPE_H_ */
