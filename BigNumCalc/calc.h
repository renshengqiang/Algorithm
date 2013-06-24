#ifndef _CALC_H
#define _CALC_H

char *Plus(const char *lhs, const char *rhs);
char *Substraction(const char *lhs, const char *rhs);
char *Multiply(const char *lhs, const char *rhs);
char *Devide(const char *lhs, const char *rhs, int *remainder);
char *Decimal2N(const char *decimal, int n);

#endif
