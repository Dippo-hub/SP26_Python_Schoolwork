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

    def purchase(self):
        print(f"Purchasing Dim(depth={self.depth}) with cost {self.cost}.")
        self.purchases += 1
        self.value += 1
        self.base += 1
        self.cost = (10 ** self.depth) * (10 ** (self.purchases // 10))
        if self.purchases % 10 == 0:
            self.exponent += 1

    def display(self):
        print(f'Dim{self.depth}: {self.base}e{self.exponent}, Cost: {self.cost}\n')

def produce(): ## Each dimension produces the next dimension, and the last dimension produces matter
    global dim1, dim2, dim3, dim4, dim5, dim6, dim7, dim8
    dim1.value += dim2.value
    dim2.value += dim3.value
    dim3.value += dim4.value
    dim4.value += dim5.value
    dim5.value += dim6.value
    dim6.value += dim7.value
    dim7.value += dim8.value
    matter.value += dim1.value


matter = Dim(0, 1)
dim1 = Dim(1, 0)
dim2 = Dim(2, 0)
dim3 = Dim(3, 0)
dim4 = Dim(4, 0)
dim5 = Dim(5, 0)
dim6 = Dim(6, 0)
dim7 = Dim(7, 0)
dim8 = Dim(8, 0)
dims = [dim1, dim2, dim3, dim4, dim5, dim6, dim7, dim8]
dim1.purchase()
start_time = time.time()
while dim8.value < 10 or (time.time() - start_time) < 5: #timeout after 5 seconds
    time.sleep(1)
    #print(f"Current state: {matter} Matter, {dim1} Dimension1, {dim2} Dimension2, {dim3} Dimension3, {dim4} Dimension4, {dim5} Dimension5, {dim6} Dimension6, {dim7} Dimension7, {dim8} Dimension8", end="\r")
    for dim in reversed(dims):
        if matter.value >= dim.cost:
            matter.value -= dim.cost
            dim.purchase()
            break
    print("Matter: ", matter.value)
    for dim in dims:
        dim.display()
    produce()
    