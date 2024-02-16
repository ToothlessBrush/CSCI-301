#ifndef FRACTION_H
#define FRACTION_H

/**
 * @brief Class that represents a fraction
*/
class Fraction {
    private:
        int numerator;
        int denominator;
    public:
        
        /**
         * @brief Construct a new Fraction object
         * 
         * @param numerator Numerator of the fraction
         * @param denominator Denominator of the fraction  
        */
        Fraction(int numerator, int denominator);
        
        /**
         * @brief set the Numerator of the fraction
         * 
         * @param numerator Numerator of the fraction
        */
        void setNumerator(int numerator);

        /**
         * @brief set the Denominator of the fraction
         * 
         * @param denominator Denominator of the fraction
        */
        void setDenominator(int denominator);
        
        /**
         * @brief get the Numerator of the fraction
         * 
         * @return Numerator of the fraction
        */
        int getNumerator();

        /**
         * @brief get the Denominator of the fraction
         * 
         * @return Denominator of the fraction
        */
        int getDenominator();

        /**
         * @brief print the fraction in the form of "numerator/denominator"
        */
        void showFraction();
};

#endif