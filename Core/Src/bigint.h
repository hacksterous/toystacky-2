/* From http://www.hanshq.net/bigint.html */
#ifdef __cplusplus
 extern "C" {
#endif
#ifndef BIGINT_H
#define BIGINT_H
#define __BIGINT_STRUCT__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <ctype.h>
#define BIGINT_STRING_SIZE 101

typedef struct {
        int32_t length: 31;
        uint32_t negative: 1;
        uint32_t data[129];
} bigint_t;

/* Create a bigint from n-character string str, consisting of one or more
   decimal characters, with an optional preceding hyphen. */
bool bigint_from_str(bigint_t *res, const char *str);

/* Get the maximum required string length for x. */
size_t bigint_max_stringlen(const bigint_t *x);

/* Convert bigint to decimal string. */
bool bigint_tostring(const bigint_t *x, char *str, int negate);

/* string is a bigint */
bool isBigIntDecString(const char *str);

/* Print a bigint to stdout in decimal. */
void bigint_print(bigint_t *x);

void bigint_hex(const bigint_t *x, char* res);
void bigint_dec(const bigint_t *x, char* res);
void bigint_bin(const bigint_t *x, char* res);
void bigint_oct(const bigint_t *x, char* res);
void bigint_neg(const bigint_t *x, char* res);
/* Arithmetic. Division does truncation towards zero, and the remainder will
   have the same sign as the divisor. Division by zero is not allowed. */
void bigint_max(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_min(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_add(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_sub(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_mul(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_div(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_rem(const bigint_t *x, const bigint_t *y, bigint_t *res);
void bigint_negative(const bigint_t *x, bigint_t *res);

/* Comparison: returns -1 if x < y, 1 if x > y, and 0 if they are equal. */
int bigint_cmp(const bigint_t *x, const bigint_t *y);
int bigint_gt(const bigint_t *x, const bigint_t *y);
int bigint_lt(const bigint_t *x, const bigint_t *y);
int bigint_gte(const bigint_t *x, const bigint_t *y);
int bigint_lte(const bigint_t *x, const bigint_t *y);
int bigint_eq(const bigint_t *x, const bigint_t *y);
int bigint_neq(const bigint_t *x, const bigint_t *y);

/* Check whether x is zero. */
bool bigint_is_zero(const bigint_t *x);

// Copy a bigint into another
void bigint_copy (bigint_t *dest, const bigint_t *src);

// Useful for initializing bigints 
void bigint_from_int(bigint_t *x, const long int n);
void bigint_from_uint32(bigint_t *x, const uint32_t n);

// Convert to/from hex
void bigint_to_hex(const bigint_t *x, char *hexstr);
bool bigint_from_hex(bigint_t *res, char *hexstr);
bool bigint_from_bin(bigint_t *res, char *binstr);

void bigint_pow(const bigint_t *x, const bigint_t *y, bigint_t *res);
/* Modular arithmetic. */
void bigint_mod_exp(const bigint_t *base, const bigint_t *exp, const bigint_t *mod, bigint_t *res);
void bigint_mod_inv(const bigint_t *base, const bigint_t *mod, bigint_t *res);
void bigint_lcm (const bigint_t *a, const bigint_t *b, bigint_t *lcm);
void bigint_gcd (const bigint_t *a, const bigint_t *b, bigint_t *gcd, bigint_t *x);
#ifdef __cplusplus
}
#endif
#endif
