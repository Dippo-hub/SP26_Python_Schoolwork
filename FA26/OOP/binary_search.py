
b = [1,2,3,4,5,6,7,8,9]

def binary_search(target, low=-1, high=-1, list=[]) -> int:
    if low == -1:
        low = int(0)
    if high == -1:
        high = int(len(list)) -1
    low = int(low)
    high = int(high)
    number = low + (high-low//2)
    if target == list[number]:
        return number
    elif target < list[number] and not target<list[0]:
        return binary_search(target, low=low, high=number, list=list)
    elif target > list[number] and not target>list[-1]:
        return binary_search(target, low=number, high=high, list=list)
    else:
        return -1

if __name__ == "__main__":
    print(binary_search(1, b))
    print(binary_search(6, b))
    print(binary_search(-1, b))
    print(binary_search(12, b))