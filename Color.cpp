#include "Color.h"

uint8_t RGBTriple::getR() const {return r;}
uint8_t RGBTriple::getG() const {return g;}
uint8_t RGBTriple::getB() const {return b;}


ColorSetNode* rainbowColors()
{
    ColorSetNode* head = new ColorSetNode;
    ColorSetNode* iter = head;
    iter->c = RGBTriple(255,0,0);
    iter->next = nullptr;

    uint8_t nvals = 11;
    uint8_t cvals[11] = {
        0, 25, 50, 75, 100, 125, 150,
        175, 200, 225, 255
    };

    //Red to yellow
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(255, cvals[i], 0);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Yellow to green
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(cvals[nvals - i - 1], 255, 0);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Green to cyan 
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(0, 255, cvals[i]);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Cyan to blue
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(0, cvals[nvals - i - 1], 255);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Blue to violet
    for (uint8_t i = 0; i < nvals; i++) 
    {
        iter->c = RGBTriple(cvals[i], 0, 255);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }

    //Violet to right before red
    for (uint8_t i = 0; i < nvals - 1; i++) 
    {
        iter->c = RGBTriple(255, 0, cvals[nvals - i - 1]);

        ColorSetNode* n = new ColorSetNode;
        iter->next = n;
        iter = n;
        iter->next = nullptr;
    }
    return head;
}
