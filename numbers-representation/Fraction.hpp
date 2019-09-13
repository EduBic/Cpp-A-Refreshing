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
        int MCD = maxComDiv(denominator, aFractionToSum.denominator);
        int num = (aFractionToSum.numerator * MCD / aFractionToSum.denominator )
                  + (numerator * MCD / denominator);

        return Fraction(num, MCD);
    }

    Fraction subtract(const Fraction& aFractionToSubtract)
    {
        int MCD = maxComDiv(denominator, aFractionToSubtract.denominator);
        int num = (numerator * MCD / denominator) 
                  - (aFractionToSubtract.numerator * MCD / aFractionToSubtract.denominator);
        
        return Fraction(num, MCD);
    }

    Fraction multiply(const Fraction& aFractionToMultiply) const
    {
        int resNumerator = numerator * aFractionToMultiply.numerator;
        int resDenominator = denominator * aFractionToMultiply.denominator;
        
        return simplify(resNumerator, resDenominator);
    }

    Fraction divide(const Fraction& aFractionThatDivide) const
    {
        int resNumerator = numerator * aFractionThatDivide.denominator;
        int resDenominator = denominator * aFractionThatDivide.numerator;
        
        return simplify(resNumerator, resDenominator);
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

    static int minComMul(const int v1, const int v2)
    {
        int mcm = 2;
        while (mcm <= v1 && mcm <= v2 )
        {
            if (v1 % mcm == 0 && v2 % mcm == 0)
            {
                return mcm;
            }
            else
            {
                mcm++;
            }
        }
        return 1;
    }
    
    bool compare(Fraction res)
    {
        return numerator == res.numerator && denominator == res.denominator;
    }
    
    static Fraction simplify(int resNumerator, int resDenominator)
    {
        int mcm = minComMul(resNumerator, resDenominator);
        while (mcm != 1)
        {
            resNumerator = resNumerator / mcm;
            resDenominator = resDenominator / mcm;
            mcm = minComMul(resNumerator, resDenominator);
        }
        return Fraction(resNumerator, resDenominator);
    }

    static Fraction sumFraction(Fraction value1, Fraction value2)
    {
        return Fraction(value1.numerator + value2.numerator, value1.denominator);
    }
    
    int numerator;
    int denominator;

};
