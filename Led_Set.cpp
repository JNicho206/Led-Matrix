#include "Led_Set.h"
#include <stdio.h>


Led_Set::Led_Set() {
    leds = nullptr;
    size = 0;
}

Led_Set::Led_Set(int n, int* values)
{
  size = n;
  leds = new int[size];

  for (int i = 0; i < size; i++)
  {
    leds[i] = values[i];
  }
}

Led_Set::Led_Set(const Led_Set& other) {
    this->size = other.size;
    this->leds = new int[size];
    for (int i = 0; i < size; i++) {
        this->leds[i] = other.leds[i];
    }
}


Led_Set::~Led_Set() {
    delete[] leds;
}

// Copy assignment operator
Led_Set& Led_Set::operator=(const Led_Set& other) {
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

void Led_Set::print()
{
  printf("Led numbers in this set: ");
  
  for (int i = 0; i < size; i++)
  {
    printf("%d", leds[i]);
  }
}



int sq2nums[] = {27,28,35,36};
int sq4nums[] = {21,20,19,18,29,34,45,44,43,42,37,26};
int sq6nums[] = {9,10,11,12,13,14,17,30,33,46,54,53,52,51,50,49,41,38,25,22};
int sq8nums[] = {7,6,5,4,3,2,1,0,15,16,31,32,47,48,63,62,61,60,59,58,57,56,55,40,39,24,23,8};

Led_Set squares2  = Led_Set(4, sq2nums);
Led_Set squares4 = Led_Set(12, sq4nums);
Led_Set squares6 = Led_Set(20, sq6nums);
Led_Set squares8 = Led_Set(28, sq8nums);
Led_Set squares_set[] = {squares2, squares4, squares6, squares8};