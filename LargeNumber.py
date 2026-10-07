import math

class LargeNumber:
    def __init__(self, mantissa: float, exponent: int):
        self.mantissa = mantissa
        self.exponent = exponent
        self.normalize()

    def normalize(self):
        """Ensures the mantissa is always between 1.0 and 10.0."""
        if self.mantissa == 0:
            self.exponent = 0
            return
            
        # Adjust exponent based on the size of the mantissa
        additional_exp = int(math.floor(math.log10(abs(self.mantissa))))
        self.mantissa /= 10 ** additional_exp
        self.exponent += additional_exp

    def __mul__(self, other):
        """Multiplies two LargeNumbers by adding exponents."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)
            
        new_mantissa = self.mantissa * other.mantissa
        new_exponent = self.exponent + other.exponent
        return LargeNumber(new_mantissa, new_exponent)

    def __add__(self, other):
        """Adds two LargeNumbers by aligning their exponents."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)
        
        # Align exponents
        if self.exponent > other.exponent:
            exp_diff = self.exponent - other.exponent
            new_mantissa = self.mantissa + other.mantissa / (10 ** exp_diff)
            new_exponent = self.exponent
        else:
            exp_diff = other.exponent - self.exponent
            new_mantissa = self.mantissa / (10 ** exp_diff) + other.mantissa
            new_exponent = other.exponent
        
        return LargeNumber(new_mantissa, new_exponent)

    def __pow__(self, power):
        """Raises the LargeNumber to a power."""
        if not isinstance(power, (int, float)):
            raise ValueError("Power must be an integer or float.")
        
        new_mantissa = self.mantissa ** power
        new_exponent = int(self.exponent * power)
        return LargeNumber(new_mantissa, new_exponent)
    
    def __sub__(self, other):
        """Subtracts two LargeNumbers by aligning their exponents."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)
        
        # Align exponents
        if self.exponent > other.exponent:
            exp_diff = self.exponent - other.exponent
            new_mantissa = self.mantissa - other.mantissa / (10 ** exp_diff)
            new_exponent = self.exponent
        else:
            exp_diff = other.exponent - self.exponent
            new_mantissa = self.mantissa / (10 ** exp_diff) - other.mantissa
            new_exponent = other.exponent
        
        return LargeNumber(new_mantissa, new_exponent)

    def __ge__(self, other):
        """Checks if the LargeNumber is greater than or equal to another."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)
        return self.mantissa >= other.mantissa and self.exponent >= other.exponent

    def __le__(self, other):
        """Checks if the LargeNumber is less than or equal to another."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)
        return self.mantissa <= other.mantissa and self.exponent <= other.exponent

    def __floordiv__(self, other):
        """Performs floor division between two LargeNumbers."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)

        if other.mantissa == 0:
            raise ZeroDivisionError("floor division by zero")
        if self.mantissa == 0:
            return LargeNumber(0.0, 0)

        exponent_diff = self.exponent - other.exponent
        quotient_mantissa = self.mantissa / other.mantissa

        if exponent_diff > 14:
            return LargeNumber(quotient_mantissa, exponent_diff)
        if exponent_diff < -1:
            return LargeNumber(-1.0 if quotient_mantissa < 0 else 0.0, 0)

        quotient = quotient_mantissa * (10 ** exponent_diff)
        return LargeNumber(math.floor(quotient), 0)
    
    def __truediv__(self, other):
        """Performs true division between two LargeNumbers."""
        if not isinstance(other, LargeNumber):
            other = LargeNumber(float(other), 0)

        if other.mantissa == 0:
            raise ZeroDivisionError("division by zero")
        if self.mantissa == 0:
            return LargeNumber(0.0, 0)

        exponent_diff = self.exponent - other.exponent
        quotient_mantissa = self.mantissa / other.mantissa

        return LargeNumber(quotient_mantissa, exponent_diff)

    def __str__(self):
        """Formats the output into scientific notation."""
        return f"{self.mantissa:.2f}e{self.exponent}"