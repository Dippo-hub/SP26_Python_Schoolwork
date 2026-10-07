import numpy as np
import time
from LargeNumber import LargeNumber

class Dimension:
    def __init__(self, value: LargeNumber, depth: int):
        self.value = value
        self.depth = depth  
        self.purchases = 0
        self.multiplier = LargeNumber(1.0, 0)  # Initial multiplier for production
        self.locked = True
        self.cost = self.calculate_cost()

    def unlock(self):
        if self.depth <= 3:
            self.locked = False
        elif self.depth == 4 and matter_dims.dimboosts >= 1:
            self.locked = False
        elif self.depth == 5 and matter_dims.dimboosts >= 2:
            self.locked = False
        elif self.depth == 6 and matter_dims.dimboosts >= 3:
            self.locked = False
        elif self.depth == 7 and matter_dims.dimboosts >= 4:
            self.locked = False

    def calculate_cost(self):
        """Calculates the cost of the dimension based on its depth and purchases."""
        # Example cost function: cost increases exponentially with depth and purchases
        base_cost = LargeNumber(1.0, 0)  # Base cost of 1
        depth_multiplier = LargeNumber(10.0, 0)  # Cost x10 with each depth level
        purchase_multiplier = LargeNumber(100, 0)  # Cost increases by x100 with each purchase
        return (base_cost * (depth_multiplier ** self.depth) * (purchase_multiplier ** (self.purchases // 10) + 1))/2

    def purchasable(self):
        return not self.locked

    def purchase(self):
        """Simulates purchasing the dimension, increasing its cost."""
        self.purchases += 1
        self.cost = self.calculate_cost()
        self.value += LargeNumber(1.0, 0)  # Increase the dimension's value by 1 for each purchase


    def produce(self):
        """Each dimension produces the one below it, scaled by its value. D1 produces Matter"""
        if self.depth == 0:
            # D1 produces Matter
            matter_dims.matter += self.value
        else:
            # Produce the dimension below
            lower_dimension = matter_dims.dimensions[self.depth - 1]
            lower_dimension.value += self.value

class MatterDims:
    def __init__(self):
        self.matter = LargeNumber(1.0, 0)  # Starting with 1 Matter
        self.dimensions = [Dimension(LargeNumber(0.0, 0), i) for i in range(8)]  # Create 8 dimensions
        self.dimboosts = 0
        self.galaxies = 0

    def simulate(self, cycles: int):
        """Simulates the production and purchasing of dimensions over a number of cycles."""
        for _ in range(cycles):
            print(f"Matter: {self.matter}, D1: {self.dimensions[0].value}, D2: {self.dimensions[1].value}, D3: {self.dimensions[2].value}, D4: {self.dimensions[3].value}, D5: {self.dimensions[4].value}, D6: {self.dimensions[5].value}, D7: {self.dimensions[6].value}, D8: {self.dimensions[7].value}")
            for dim in reversed(self.dimensions):
                dim.unlock()
                if not dim.locked:
                    if self.matter >= dim.cost:
                        if dim.purchasable():
                            self.matter -= dim.cost
                            dim.purchase()
                    dim.produce()
            if self.canDimboost():
                self.DimBoost()
        print(self.dimboosts)
            #time.sleep(1)  # Wait for 1 second before the next cycle

    def DimBoost(self):
        """Resets all dimensions but grants a stacking 1.5x multiplier to all dimensions."""
        self.matter = LargeNumber(1.0, 0)  # Reset matter to 1
        self.dimboosts += 1  # Increment the number of dimension boosts
        for dim in self.dimensions:
            dim.value = LargeNumber(0.0, 0)  # Reset dimension value
            dim.purchases = 0  # Reset purchases
            dim.multiplier *= LargeNumber(1.5, 0)  # Apply the multiplier
            dim.cost = dim.calculate_cost()  # Recalculate cost after reset
        print("Dimboosted!")

    def canDimboost(self) -> bool:
        """Dimboosts scale differently before the 8th dimension. The first requires 20 4th dimensions, the second requires 20 5th dimensions, and so on. Upon reaching dimboost 4, the requirement is 20 8th dimensions. After that, the requirement is 20 8th dimensions for each dimboost."""
        if self.dimboosts == 0 and self.dimensions[3].value >= LargeNumber(2, 1):
            return True
        elif self.dimboosts == 1 and self.dimensions[4].value >= LargeNumber(2, 1):
            return True
        elif self.dimboosts == 2 and self.dimensions[5].value >= LargeNumber(2, 1):
            return True
        elif self.dimboosts == 3 and self.dimensions[6].value >= LargeNumber(2, 1):
            return True
        elif self.dimboosts >= 4 and self.dimensions[7].value >= LargeNumber(21*(self.dimboosts-3), 1):
            return True
        return False


if __name__ == "__main__":
    matter_dims = MatterDims()
    matter_dims.simulate(1001)  # Simulate for int cycles