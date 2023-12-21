
/**
 * @brief Set of led numbers
 * 
 */
class Led_Set{
    public:
        /**
         * @brief Construct a new Led_Set object
         * 
         */
        Led_Set();

        /**
         * @brief Construct a new Led_Set object
         * 
         * @param n Number of leds in the set.
         * @param values Led number values in the set.
         */
        Led_Set(int n, int* values);

        /**
         * @brief Copy constructor a new Led_Set object
         * 
         * @param other Reference to object to be copied.
         */
        Led_Set(const Led_Set& other);

        /**
         * @brief Destroy the Led_Set object
         * 
         */
        ~Led_Set();

        /**
         * @brief 
         * 
         * @param other Reference to other object
         * @return Led_Set& 
         */
        Led_Set& operator=(const Led_Set& other);

        /**
         * @brief Prints the numbers of the leds in the set.
         * 
         */
        void print();

        private:
            int size;
            int* leds;
};

    
extern Led_Set squares2;
extern Led_Set squares4;
extern Led_Set squares6;
extern Led_Set squares8;
extern Led_Set squares_set[];

