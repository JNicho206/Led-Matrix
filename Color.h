
#define MAX_RED 255
#define MAX_BLUE 255
#define MAX_GREEN 255
#define MIN_RED 0
#define MIN_BLUE 0
#define MIN_GREEN 0


class Color {
    public:
        int red;
        int blue;
        int green;

        /**
         * @brief Construct a new Color object
         * 
         */
        Color();

        /**
         * @brief Construct a new Color object
         * 
         * @param r Red value 0-255
         * @param b Blue value 0-255 
         * @param g Green value 0-255
         */
        Color (int r, int b, int g);


        /**
         * @brief Prints RGB values.
         */
        void print();

};