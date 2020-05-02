/*
 * input2.c       -- Un programme avec des chaÃ®nes et des commentaires
 *
 *           Author: Erick Gallesio [eg@unice.fr]
 *    Creation date: 31-Aug-2016 15:00 (eg)
 * Last file update: 24-Apr-2017 17:22 (eg)
 */

#include <stdio.h>

// Un commentaires Ã  la C++
int x = 0;  // Un commentaire C++ sur la fin de la ligne

/* un commentaire 'monoligne"  */


char *str[] = {
  "",                                            // test 0
  "Iâ€™m a string",                                // test 1
  "Another string with embedded \"quotes\"",     // test 2
  "and another one with a \"\\\" !!!",           // test 3
  "Printed text on\n2 lines",                    // test 4
  "The TAB character: '\t' or '\011' or '\x9'.", // test 5
  "Two strings", /* on a */ "line",              // test 6
  "A // comment in a string",                    // test 7
  "A string spanning \
   2 lines",                                     // test 8
   NULL,
};


int main () {
  for (char **p = str; *p; p++) {
    fputs(*p, stdout);
    fputc('\n', stdout);
  }
  x = +/*Un commentaire*/+x;
  if (x == 1) fputs("PERDU\n", stdout);
  return 0;
}
