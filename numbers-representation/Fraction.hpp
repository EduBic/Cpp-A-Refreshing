class Fraction {

public:

    Fraction() {}

    Fraction(int num, int den) 
    {
        numerator = num;
        denominator = den;
    }

    Fraction add(const Fraction& aFractionToSum) const 
    {
        // this => aFraction
        // aFractionToSum => aSecondFraction
        
        // this->numerator OR numerator
        // aFractionToSum.numerator

        int MCD = maxComDiv(denominator, aFractionToSum.denominator);
        int num = (aFractionToSum.numerator * MCD / aFractionToSum.denominator )
                  + (numerator * MCD / denominator);

        return Fraction(num, MCD);
    }

    Fraction multiply(const Fraction& aFractionToMultiply) const
    {

    }

    int maxComDiv(const int v1, const int v2) const
    {
        if (v1 >= v2)
        {
            int MCD = v1;
            while(MCD % v2 != 0)
            {
                MCD = MCD + v1;
            }
            return MCD;
        }
        else
        {
            int MCD = v2;
            while(MCD % v1 != 0)
            {
                MCD = MCD + v2;
            }
            return MCD;
        }
    }

    static Fraction sumFraction(Fraction value1, Fraction value2)
    {
        return Fraction(value1.numerator + value2.numerator, value1.denominator);
    }
    
    int numerator;
    int denominator;

private:
};