class Fraction {

public:

    Fraction(int num, int den) {
        numerator = num;
        denominator = den;
    }

    Fraction add(const Fraction & aFractionToSum) const {
        // this => aFraction
        // aFractionToSum => aSecondFraction
        
        // this->numerator OR numerator
        // aFractionToSum.numerator

        int num = ?;
        int den = ?;

        return Fraction(num, den);
    }
    
    int numerator;
    int denominator;

private:
};