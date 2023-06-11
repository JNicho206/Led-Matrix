#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#include <stdlib.h>
#include <time.h>


 


//MODE TYPES FOR fill_rainbow
#define FILL_IO 0//Fill matrix from inside to out
#define FILL_OI 1//Fill matrix from outside to inside
#define FILL_LEFT_TOP 2 //Fill matrix from left side to right, top to bottom
#define FILL_LEFT_BOTTOM 3 //Fill matrix from left side to right, bottom to top
#define FILL_RIGHT_TOP 4 //Fill matrix right side to left, top to bottom
#define FILL_RIGHT_BOTTOM 5 //Fill matrix right side to left, bottom to top
#define FILL_TOP_LEFT 6 //Fill top to bottom, left to right
#define FILL_TOP_RIGHT 7 //Fill top to bottom, right to left
#define FILL_BOTTOM_LEFT 8 //Fill bottom to top, left to right
#define FILL_BOTTOM_RIGHT 9 //Fill bottom to top, right to left

//Corner led numbers 0-63
#define TOP_LEFT 0 //Top left LED is led 0
#define TOP_RIGHT 7 //Top right is led 7
#define BOTTOM_LEFT 56 //Bottom left is led 56
#define BOTTOM_RIGHT 63 //Bottom right is led 63



//Squares (outlines) from inner 2x2 to full 8x8
int square2[] = {27,28,35,36};
int square4[] = {21,20,19,18,29,34,45,44,43,42,37,26};
int square6[] = {9,10,11,12,13,14,17,30,33,46,54,53,52,51,50,49,41,38,25,22};
int square8[] = {7,6,5,4,3,2,1,0,15,16,31,32,47,48,63,62,61,60,59,58,57,56,55,40,39,24,23,8};

class Led_Set
{
  private:
    int size;
    int* leds;
  
  public:

    Led_Set() {
        leds = nullptr;
        size = 0;
    }

    Led_Set(int n, int* values)
    {
      size = n;
      leds = new int[size];

      for (int i = 0; i < size; i++)
      {
        leds[i] = values[i];
      }
    }
  // Copy constructor
    Led_Set(const Led_Set& other) {
        this->size = other.size;
        this->leds = new int[size];
        for (int i = 0; i < size; i++) {
            this->leds[i] = other.leds[i];
        }
    }
    
    // Destructor to free the dynamically allocated memory
    ~Led_Set() {
        delete[] leds;
    }
    
    // Copy assignment operator
    Led_Set& operator=(const Led_Set& other) {
        if (this != &other) {
            // Free the old memory
            delete[] leds;
            
            // Copy the new memory
            this->size = other.size;
            this->leds = new int[size];
            for (int i = 0; i < size; i++) {
                this->leds[i] = other.leds[i];
            }
        }
        return *this;
    }

    void print()
    {
      printf("Led numbers in this set: ");
      
      for (int i = 0; i < size; i++)
      {
        printf("%d", leds[i]);
      }
    }
};

Led_Set square2x2(4, square2);
Led_Set square4x4(12, square4);
Led_Set square6x6(20, square6);
Led_Set square8x8(28, square8);
Led_Set square_set[4] = {square2x2, square4x4, square6x6, square8x8};

class Color 
{
  public:
    int red;
    int blue;
    int green;

    Color(int r, int g, int b)
    {
      red = r; green = g; blue = b;
    }

    void print()
    {
      printf("The color has {R,G,B} of {%d, %d, %d}", red, green, blue);
    }
};



class Pattern
{
  private:
    int num_sets;
    Led_Set* sets;

  public:
    Pattern(int set_sz, Led_Set* setlist)
    {
      num_sets = set_sz;
      this->sets = new Led_Set[num_sets];

      for (int i = 0; i < num_sets; i++)
      {
        this->sets[i] = setlist[i];
      }
    }

    ~Pattern()
    {
      delete[] sets;
    }
};


Pattern squares(4, square_set)


void display_Pattern(Adafruit_NeoMatrix matrix, Pattern p, int d = 100, int r = 100, int b = 75, int g = 150)
{

  for (int i = 0; i < p.num_sets; i++)
  {
    for (int j = 0; j < p.sets[i].size; j++)
    {
      matrix.setPixelColor(p.sets[i][j], r, g, b);
    }
    delay(d);
  }


}





void light_leds(Adafruit_NeoMatrix matrix, int* leds, Color* colors, int d = 100)
{
  /*  --- Docstring ---
    Description:
      This function lights leds from a vector of led numbers with colors according a vector of RGB values.

    Arguments:
      matrix: The matrix object to act upon.

      leds: An array of led numbers.

      colors: An array of colors, one RGB for each led number in leds.

      d: Delay in ms to wait in between lighting each led, default is 100ms
  */

  int size = sizeof(leds) / sizeof(leds[0]);

  for (int i = 0; i < size; i++)
  {
    matrix.setPixelColor(leds[i], colors[i].red, colors[i].green, colors[i].blue);
    delay(d);
  }
}

void off_leds(Adafruit_NeoMatrix matrix, int* leds, int d = 100)
{
  int size = sizeof(leds) / sizeof(leds[0]);

  for (int i = 0; i < size; i++)
  {
    matrix.setPixelColor(leds[i], 0, 0, 0);
    delay(d);
  }

}


void full_rainbow(Adafruit_NeoMatrix matrix, uint8_t max_red = 256, uint8_t max_green = 256, uint8_t max_blue = 256, int d = 0)
{
  //Set the seed for random
  srand(time(NULL)); 

  //Loop through each LED
  for (int i = 0; i < 64; i++)
  {
    //Set color for each led using the provided maximums to scale each color value
    matrix.setPixelColor(i, rand() % max_red, rand() % max_green, rand() % max_blue);
  }
  //Delay based on 'delay' argument
  delay(d);
}

void fill_rainbow(Adafruit_NeoMatrix matrix, uint8_t mode, uint8_t max_red = 256, uint8_t max_green = 256, uint8_t max_blue = 256, int delay = 0)
{
  if (mode == FILL_IO)
  {

  }
  /* Starts at top left */
  else if (mode == FILL_LEFT_TOP)
  {
    //Outer loop goes top to bottom
    for (int i = TOP_LEFT; i <= BOTTOM_LEFT; i += 8)
    {
      //Inner loop goes left to right
      for (int j = i; j <=  i + 7; j++)
      {
        matrix.setPixelColor(j, rand() % max_red, rand() % max_green, rand() % max_blue);
      }
    }
  }
  
  else if (mode == FILL_TOP_LEFT)
  {
    //Outer loop goes left to right
    for (int i = TOP_LEFT; i <= TOP_RIGHT; i++)
    {
      //Inner loop goes top to bottom
      for (int j = i; j <=  i + 7; j += 8)
      {
        matrix.setPixelColor(j, rand() % max_red, rand() % max_green, rand() % max_blue);
      }
    }
  }

  /* Starts at top right */
  else if (mode == FILL_RIGHT_TOP)
  {
    //Outer loop goes left to right
    for (int i = TOP_RIGHT; i <= BOTTOM_RIGHT; i += 8)
    {
      //Inner loop goes top to bottom
      for (int j = i; j >=  i - 7; j--)
      {
        matrix.setPixelColor(j, rand() % max_red, rand() % max_green, rand() % max_blue);
      }
    }
  }

  else if (mode == FILL_TOP_RIGHT)
  {
    //Outer loop goes left to right
    for (int i = TOP_RIGHT; i >= 0; i--)
    {
      //Inner loop goes top to bottom
      for (int j = i; j <=  BOTTOM_RIGHT; j += 8)
      {
        matrix.setPixelColor(j, rand() % max_red, rand() % max_green, rand() % max_blue);
      }
    }
  }

  /* Starts at bottom right */
  else if (mode == FILL_RIGHT_BOTTOM)
  {
    //Outer loop goes left to right
    for (int i = BOTTOM_RIGHT; i >= TOP_RIGHT; i -= 8)
    {
      //Inner loop goes top to bottom
      for (int j = i; j >=  i - 7; j--)
      {
        matrix.setPixelColor(j, rand() % max_red, rand() % max_green, rand() % max_blue);
      }
    }
  }

  else if (mode == FILL_BOTTOM_RIGHT)
  {
    //Outer loop goes left to right
    for (int i = BOTTOM_RIGHT; i >= BOTTOM_LEFT; i--)
    {
      //Inner loop goes top to bottom
      for (int j = i; j >=  TOP_RIGHT ; j -= 8)
      {
        matrix.setPixelColor(j, rand() % max_red, rand() % max_green, rand() % max_blue);
      }
    }
  }
}



ß