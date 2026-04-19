# tool.py
# -------------------------------------------------------
# Tool Name  : Compounded Interest Calculator
# Domain     : Financial/Investment
# Author     : Nathan Silvey
# Description: Calculates compounded interest for investment scenarios.
#              This tool is essential for evaluating the potential returns on investments.
# Usage      : See README.md for a sample call.
# -------------------------------------------------------
import math
def compounded_interest_calculator(principal: float, rate: float, time: float, frequency: int) -> dict:
    """
    Calculates the compounded interest for a given principal amount, interest rate, and time period.

    Args:
        principal (float): The initial amount of money invested.
        rate (float): The annual interest rate (as a decimal).
        time (float): The time period for which the interest is calculated (in years).
        frequency (int): The number of times interest is compounded per year.

    Returns:
        dict: {
            "total_payment": <primary computed value>,
            "unit":   <string label, e.g. "USD" or "liters">,
            "detail": <string providing additional information about the result, such as
            a formal sentence describing the interest over time>
        }

    Raises:
        ValueError: if any input is out of expected range or type.
    """
    # --- Input Validation ---
    if principal < 0:
        raise ValueError("Principal amount cannot be negative.")
    if not (0 <= rate <= 1):
        raise ValueError("Interest rate must be between 0 and 1.")
    if time < 0:
        raise ValueError("Time period cannot be negative.")

    # --- Core Logic ---
    total = principal * (1 + rate / frequency) ** (frequency * time)
    interest = total - principal    

    return {"total_payment": total, "unit": "USD", "detail": 
            f"Calculated for {principal} at {rate*100}% over {time} years, compounded {frequency} times per year. Total interest will be {interest:.2f} USD."}

