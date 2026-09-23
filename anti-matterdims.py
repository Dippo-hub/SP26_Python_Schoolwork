import numpy as np
import time

class Dim:
    def __init__(self, depth:int, value:int):
        self.depth = depth
        self.base = value
        self.exponent = 1
        self.purchases = 0
        self.cost = (10 ** self.depth) * (10 ** (self.purchases // 10))
        self.value = self.base * (10 ** self.exponent)

    def __repr__(self):
        return f"Dim(depth={self.depth}, number={self.base}e{self.exponent}, cost={self.cost}, purchases={self.purchases}, value={self.value})"

matter = 1
dims = [Dim(i, 0) for i in range(8)]
timeout = 2 # Seconds
start_time = time.time()

while time.time() - start_time < timeout and matter >= 0:
    time.sleep(0.1)  # Simulate time passing
    for dim in reversed(dims):
        if matter >= dim.cost:
            matter -= dim.cost
            dim.purchases += 1
            dim.exponent += 1
            dim.cost = (10 ** dim.depth) * (10 ** (dim.purchases // 10))
            dim.value = dim.base * (10 ** dim.exponent)
            print(f"Purchased {dim}. Remaining matter: {matter}", end="\r")
        else:
            print(f"Not enough matter to purchase {dim}. Required: {dim.cost}, Available: {matter}", end="\r")