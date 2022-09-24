/**
 * THIS FILE IS PART OF THE chalk.h PROJECT,
 * LICENSED UNDER MIT-LICENSE.
 *
 * THIS HEADER AND THE LICENSE MUST BE INCLUDED IN ALL
 * COPIES OF THIS PRODUCT.
 *
 * Project Owner:    https://github.com/avolgha
 * Project Homepage: https://github.com/avolgha/chalk.h
 * Project License:  https://github.com/avolgha/chalk.h/blob/dev/license
 */

#ifndef CHALK_H_
#define CHALK_H_

#define CHALK_FUNCTION(N) char* N(char* message)
#define CHALK_FLAG(N, I) const int N = ( 1 << I )

CHALK_FLAG(COLOR_BOLD, 1);
CHALK_FLAG(COLOR_DIM, 2);
CHALK_FLAG(COLOR_ITALIC, 3);
CHALK_FLAG(COLOR_UNDERLINE, 4);
CHALK_FLAG(COLOR_INVERSE, 5);
CHALK_FLAG(COLOR_HIDDEN, 6);
CHALK_FLAG(COLOR_STRIKETHROUGH, 7);

CHALK_FLAG(COLOR_BLACK, 10);
CHALK_FLAG(COLOR_RED, 11);
CHALK_FLAG(COLOR_GREEN, 12);
CHALK_FLAG(COLOR_YELLOW, 13);
CHALK_FLAG(COLOR_BLUE, 14);
CHALK_FLAG(COLOR_MAGENTA, 15);
CHALK_FLAG(COLOR_CYAN, 16);
CHALK_FLAG(COLOR_WHITE, 17);
CHALK_FLAG(COLOR_GRAY, 18);

CHALK_FLAG(COLOR_BGBLACK, 20);
CHALK_FLAG(COLOR_BGRED, 21);
CHALK_FLAG(COLOR_BGGREEN, 22);
CHALK_FLAG(COLOR_BGYELLOW, 23);
CHALK_FLAG(COLOR_BGBLUE, 24);
CHALK_FLAG(COLOR_BGMAGENTA, 25);
CHALK_FLAG(COLOR_BGCYAN, 26);
CHALK_FLAG(COLOR_BGWHITE, 27);

char* chalk(char* message, int flags);

CHALK_FUNCTION(chalk_reset);

CHALK_FUNCTION(chalk_bold);
CHALK_FUNCTION(chalk_dim);
CHALK_FUNCTION(chalk_italic);
CHALK_FUNCTION(chalk_underline);
CHALK_FUNCTION(chalk_inverse);
CHALK_FUNCTION(chalk_hidden);
CHALK_FUNCTION(chalk_strikethrough);

CHALK_FUNCTION(chalk_black);
CHALK_FUNCTION(chalk_red);
CHALK_FUNCTION(chalk_green);
CHALK_FUNCTION(chalk_yellow);
CHALK_FUNCTION(chalk_blue);
CHALK_FUNCTION(chalk_magenta);
CHALK_FUNCTION(chalk_cyan);
CHALK_FUNCTION(chalk_white);
CHALK_FUNCTION(chalk_gray);

CHALK_FUNCTION(chalk_bgBlack);
CHALK_FUNCTION(chalk_bgRed);
CHALK_FUNCTION(chalk_bgGreen);
CHALK_FUNCTION(chalk_bgYellow);
CHALK_FUNCTION(chalk_bgBlue);
CHALK_FUNCTION(chalk_bgMagenta);
CHALK_FUNCTION(chalk_bgCyan);
CHALK_FUNCTION(chalk_bgWhite);

#endif // CHALK_H_

#ifndef CHALK_H_IMPLEMENTATION_
#define CHALK_H_IMPLEMENTATION_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHALK_INT_APPLY(FL, FN) \
  if ((flags & FL) > 0) {\
    tmp = FN(tmp);\
  }
char* chalk(char* message, int flags)
{
  char* tmp = message;

  CHALK_INT_APPLY(COLOR_BLACK, chalk_black);
  CHALK_INT_APPLY(COLOR_RED, chalk_red);
  CHALK_INT_APPLY(COLOR_GREEN, chalk_green);
  CHALK_INT_APPLY(COLOR_YELLOW, chalk_yellow);
  CHALK_INT_APPLY(COLOR_BLUE, chalk_blue);
  CHALK_INT_APPLY(COLOR_MAGENTA, chalk_magenta);
  CHALK_INT_APPLY(COLOR_CYAN, chalk_cyan);
  CHALK_INT_APPLY(COLOR_WHITE, chalk_white);
  CHALK_INT_APPLY(COLOR_GRAY, chalk_gray);

  CHALK_INT_APPLY(COLOR_BGBLACK, chalk_bgBlack);
  CHALK_INT_APPLY(COLOR_BGRED, chalk_bgRed);
  CHALK_INT_APPLY(COLOR_BGGREEN, chalk_bgGreen);
  CHALK_INT_APPLY(COLOR_BGYELLOW, chalk_bgYellow);
  CHALK_INT_APPLY(COLOR_BGBLUE, chalk_bgBlue);
  CHALK_INT_APPLY(COLOR_BGMAGENTA, chalk_bgMagenta);
  CHALK_INT_APPLY(COLOR_BGCYAN, chalk_bgCyan);
  CHALK_INT_APPLY(COLOR_BGWHITE, chalk_bgWhite);

  CHALK_INT_APPLY(COLOR_BOLD, chalk_bold);
  CHALK_INT_APPLY(COLOR_DIM, chalk_dim);
  CHALK_INT_APPLY(COLOR_ITALIC, chalk_italic);
  CHALK_INT_APPLY(COLOR_UNDERLINE, chalk_underline);
  CHALK_INT_APPLY(COLOR_INVERSE, chalk_inverse);
  CHALK_INT_APPLY(COLOR_HIDDEN, chalk_hidden);
  CHALK_INT_APPLY(COLOR_STRIKETHROUGH, chalk_strikethrough);

  return tmp;
}

char* chalk_int_concaternate(char *a, char *b, char *c)
{
	size_t alen = strlen(a);
  size_t blen = strlen(b);
  size_t clen = strlen(c);
  char *res = (char*) malloc(alen + blen + clen + 1);
  if (res) {
    memcpy(res, a, alen);
    memcpy(res + alen, b, blen);
    memcpy(res + alen + blen, c, clen + 1);
  }
  return res;
}

char* chalk_int_concaternate2(char* a, int b, char* c)
{
  char num[10];
  sprintf(num, "%d", b);
  return chalk_int_concaternate(a, num, c);
}

char* chalk_int_fmt2(char* message, char* open, char* close, char* replace)
{
	return chalk_int_concaternate(open, message, close);
}

char* chalk_int_fmt1(char* message, char* open, char* close)
{
	return chalk_int_fmt2(message, open, close, open);
}

#define CHALK_IMPL(N,F,S) CHALK_FUNCTION(N) { return chalk_int_fmt1(message, chalk_int_concaternate2("\x1b[", F, "m"), chalk_int_concaternate2("\x1b[", S, "m")); }

CHALK_FUNCTION(chalk_reset) {	return chalk_int_concaternate("\x1b[0m", message, "\x1b[0m"); }

CHALK_FUNCTION(chalk_bold) { return chalk_int_fmt2(message, "\x1b[1m", "\x1b[22m", "\x1b[22m\x1b[1m"); }
CHALK_FUNCTION(chalk_dim) { return chalk_int_fmt2(message, "\x1b[2m", "\x1b[22m", "\x1b[22m\x1b[2m"); }
CHALK_IMPL(chalk_italic, 3, 23);
CHALK_IMPL(chalk_underline, 4, 24);
CHALK_IMPL(chalk_inverse, 7, 27);
CHALK_IMPL(chalk_hidden, 8, 28);
CHALK_IMPL(chalk_strikethrough, 9, 29);

CHALK_IMPL(chalk_black, 30, 39);
CHALK_IMPL(chalk_red, 31, 39);
CHALK_IMPL(chalk_green, 32, 39);
CHALK_IMPL(chalk_yellow, 33, 39);
CHALK_IMPL(chalk_blue, 34, 39);
CHALK_IMPL(chalk_magenta, 35, 39);
CHALK_IMPL(chalk_cyan, 36, 39);
CHALK_IMPL(chalk_white, 37, 39);
CHALK_IMPL(chalk_gray, 90, 39);

CHALK_IMPL(chalk_bgBlack, 40, 49);
CHALK_IMPL(chalk_bgRed, 41, 49);
CHALK_IMPL(chalk_bgGreen, 42, 49);
CHALK_IMPL(chalk_bgYellow, 43, 49);
CHALK_IMPL(chalk_bgBlue, 44, 49);
CHALK_IMPL(chalk_bgMagenta, 45, 49);
CHALK_IMPL(chalk_bgCyan, 46, 49);
CHALK_IMPL(chalk_bgWhite, 47, 49);

#endif // CHALK_H_IMPLEMENTATION_
