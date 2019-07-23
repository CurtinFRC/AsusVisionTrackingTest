#include "itbroke.h"
#include <stdio.h>
 
const char rocket[] =
"           _\n\
          /^\\\n\
          |-|\n\
          |I|\n\
          |T|\n\
          | |\n\
          |B|\n\
          |R|\n\
         /|O|\\\n\
        / |K| \\\n\
       |  |E|  |\n\
        `-\"\"\"-`\n\
";
 
void itbroke()
{
  while (true)
  {
    for (int i = 0; i < 50; i ++) printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i ++) {
        // usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
  }
}