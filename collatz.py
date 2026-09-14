import numpy as np
import csv
import matplotlib.pyplot as plt

def collatz_sequence(n):

    if n <= 0:
        raise ValueError("Input must be a positive integer.")
    sequence = [n]
    while n != 1:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
        sequence.append(n)
    return sequence

def collatz_range(n):
    if n <= 0:
        raise ValueError("Input must be a positive integer.")
    sequences = {}
    for i in range(1, n + 1):
        sequences[i] = collatz_sequence(i)
    return sequences

def prime_factorization(n):
    if n < 1:
        raise ValueError("Input must be an integer greater than 0.")
    factors = [1]
    for i in range(2, int(np.sqrt(n)) + 1):
        while n % i == 0:
            factors.append(i)
            n //= i
    if n > 1:
        factors.append(n)
    return factors

def process_sequences(sequences):
    processed = {}
    max_value = 0
    for key, value in sequences.items():
        processed[key] = {
            "sequence": value,
            "length": len(value),
            "max_value": max(value),
            "prime_factors": prime_factorization(key)
        }
        if max(value) > max_value:
            max_value = max(value)
            max_key = key
    print(f"The maximum value encountered in all sequences is: {max_value} at number {max_key}")
    print(f"The expanded prime factorization of {max_key} is:")
    expand_sequence_factors(processed[max_key]["sequence"])
    return processed

def expand_sequence_factors(sequence):
    expanded_factors = []
    for number in sequence:
        factors = prime_factorization(number)
        expanded_factors.append(factors)
        print(f"Number: {number}, Prime Factors: {factors}")
    return expanded_factors

def plot_sequences(processed_sequences):
    plt.figure(figsize=(10, 6))
    starting_numbers = list(processed_sequences.keys())
    sequence_lengths = [processed_sequences[key]["length"] for key in starting_numbers]
    plt.plot(starting_numbers, sequence_lengths, marker="o")
    plt.title("Collatz Sequences")
    plt.xlabel("Starting Number")
    plt.ylabel("Length")
    plt.grid()
    plt.show()
    plt.savefig("collatz_sequences.png")

def log_csv(sequences, filename="collatz_sequences.csv"):
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Number", "Collatz Sequence", "Prime Factorization"])
        for key, value in sequences.items():
            writer.writerow([key, value, prime_factorization(key)])

if __name__ == "__main__":
    n = 1000  # You can change this value to generate sequences for a different range
    try:
        sequences = collatz_range(n)
        log_csv(sequences)
        processed_sequences = process_sequences(sequences)
        if len(processed_sequences) < 10:
            for key, value in processed_sequences.items():
                print(f"Number: {key}, Sequence: {value['sequence']}, Length: {value['length']}, Max Value: {value['max_value']}, Prime Factors: {value['prime_factors']}")
        plot_sequences(processed_sequences)

    except ValueError as e:
        print(e)
