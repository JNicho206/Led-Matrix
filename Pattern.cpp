#include "Pattern.h"


Pattern::Pattern(int set_sz, Led_Set* setlist)
: num_sets(set_sz), this->sets(new Led_Set[num_sets])
{
  for (int i = 0; i < num_sets; i++)
  {
    this->sets[i] = setlist[i];
  }
}

Pattern::~Pattern()
{
  delete[] sets;
}

void Pattern::draw_pattern(Adafruit_NeoMatrix matrix, int delay, Color c, bool random_color)
{
  for (int i = 0; i < this->num_sets; i++)
  {
    for (int j = 0; j < this->sets[i].size; j++)
    {
        if !(random_color)
        {
          matrix.drawPixel(this->sets[i].leds[j], c.red, c.blue, c.green);
        }
        else
        {
          matrix.drawPixel(this->sets[i].leds[j], c.red, c.blue, c.green);
        }
    }
  }
}

