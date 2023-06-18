#ifndef UTIL_H_
#define UTIL_H_

#define SIGN(x) \
    ((x) < 0 ? -1 : 1)

#define LIMIT(x, min, max) \
    ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))

#endif /* UTIL_H_ */
