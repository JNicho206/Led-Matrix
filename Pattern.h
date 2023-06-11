#include "Led_Set.h"
#include <Adafruit_NeoMatrix.h>
#include "Color.h"

class Pattern
{
    public:
        /**
         * @brief Construct a new Pattern object
         * 
         * @param set_sz Number of led sets in the pattern.
         * @param setlist List of led sets.
         */
        Pattern(int set_sz, Led_Set* setlist);

        /**
         * @brief Destroy the Pattern object
         */
        ~Pattern();

        /**
         * @brief Draws pattern on the led matrix.
         * 
         * @param delay Delay in milliseconds between led set switching.
         * @param matrix Matrix object to be drawn on.
         * @param c Color object which will be the pattern's color.
         * @param random_color If true, overrides color and has a random color for each.
         */
        void draw_pattern(Adafruit_NeoMatrix matrix, int delay, Color c, bool random_color);

        private:
            int num_sets;
            Led_Set* sets;
};

extern Pattern squares = Pattern(4, squares_set);


