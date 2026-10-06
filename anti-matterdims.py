import numpy as np
import time
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

class Dimension:
    def __init__(self, value: LargeNumber, depth: int):
        self.value = value
        self.depth = depth  
        self.purchases = 0
        self.multiplier = LargeNumber(1.0, 0)  # Initial multiplier for production
        self.cost = self.calculate_cost()

    def calculate_cost(self):
        """Calculates the cost of the dimension based on its depth and purchases."""
        # Example cost function: cost increases exponentially with depth and purchases
        base_cost = LargeNumber(1.0, 0)  # Base cost of 1
        depth_multiplier = LargeNumber(10.0, 0)  # Cost x10 with each depth level
        purchase_multiplier = LargeNumber(100, 0)  # Cost increases by x100 with each purchase
        return (base_cost * (depth_multiplier ** self.depth) * (purchase_multiplier ** (self.purchases // 10) + 1))/2

    def purchase(self):
        """Simulates purchasing the dimension, increasing its cost."""
        self.purchases += 1
        self.cost = self.calculate_cost()
        self.value += LargeNumber(1.0, 0)  # Increase the dimension's value by 1 for each purchase

    def produce(self):
        """Each dimension produces the one below it, scaled by its value. D1 produces Matter"""
        if self.depth == 0:
            # D1 produces Matter
            global matter
            matter += self.value
        else:
            # Produce the dimension below
            lower_dimension = dimensions[self.depth - 1]
            lower_dimension.value += self.value

class MatterDims:
    def __init__(self):
        self.matter = LargeNumber(1.0, 0)  # Starting with 1 Matter
        self.dimensions = [Dimension(LargeNumber(0.0, 0), i) for i in range(8)]  # Create 8 dimensions

    def simulate(self, cycles: int):
        """Simulates the production and purchasing of dimensions over a number of cycles."""
        for _ in range(cycles):
            print(f"Matter: {self.matter}, D1: {self.dimensions[0].value}, D2: {self.dimensions[1].value}, D3: {self.dimensions[2].value}, D4: {self.dimensions[3].value}, D5: {self.dimensions[4].value}, D6: {self.dimensions[5].value}, D7: {self.dimensions[6].value}, D8: {self.dimensions[7].value}", end="\r")
            for dim in reversed(self.dimensions):
                if self.matter >= dim.cost:
                    self.matter -= dim.cost
                    dim.purchase()
                dim.produce()
            time.sleep(1)  # Wait for 1 second before the next cycle


if __name__ == "__main__":
    matter_dims = MatterDims()
    matter_dims.simulate(100)  # Simulate for 100 cycles