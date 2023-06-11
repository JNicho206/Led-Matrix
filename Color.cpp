#include "Color.h"
#include <stdio.h>


Color::Color(int r, int g, int b)
{
  red = r; green = g; blue = b;
}

void Color::print()
{
  printf("The color has {R,G,B} of {%d, %d, %d}", red, green, blue);
}