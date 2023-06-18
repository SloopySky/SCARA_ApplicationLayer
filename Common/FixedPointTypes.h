#ifndef FIXEDPOINTTYPES_H_
#define FIXEDPOINTTYPES_H_

#include <stdint.h>

typedef int16_t fp16x1000_t;
typedef uint16_t ufp16x1000_t;

typedef int16_t fp16x100_t;
typedef uint16_t ufp16x100_t;

typedef int16_t fp16x10_t;
typedef uint16_t ufp16x10_t;

typedef int32_t fp32x10_t;
typedef uint32_t ufp32x10_t;

typedef int32_t fp32x100_t;
typedef uint32_t ufp32x100_t;

typedef int32_t fp32x1000_t;
typedef uint32_t ufp32x1000_t;

typedef int64_t fp64x1000_t;

#define FPx1_TO_FPx10     10
#define FPx1_TO_FPx100    100
#define FPx1_TO_FPx1000   1000

#endif /* FIXEDPOINTTYPES_H_ */
