import pytest 
from tool import compounded_interest_calculator

def test_happy_path():
    result = compounded_interest_calculator(1000, 0.05, 10, 4)
    assert result["total_payment"] == pytest.approx(1643.619463487, rel=1e-5)
    assert result["unit"] == "USD"
    assert "Calculated for 1000 at 5.0% over 10 years, compounded 4 times per year. Total interest will be" in result["detail"]

def test_edge_cases():
    # Test with zero principal
    result = compounded_interest_calculator(0, 0.05, 10, 4)
    assert result["total_payment"] == 0
    assert result["unit"] == "USD"
    assert "Calculated for 0 at 5.0% over 10 years, compounded 4 times per year. Total interest will be 0.00 USD." in result["detail"]

    # Test with zero interest rate
    result = compounded_interest_calculator(1000, 0, 10, 4)
    assert result["total_payment"] == 1000
    assert result["unit"] == "USD"
    assert "Calculated for 1000 at 0% over 10 years, compounded 4 times per year. Total interest will be 0.00 USD." in result["detail"]

def test_invalid_inputs():
    with pytest.raises(ValueError):
        compounded_interest_calculator(-1000, 0.05, 10, 4)  # Negative principal

    with pytest.raises(ValueError):
        compounded_interest_calculator(1000, -0.05, 10, 4)  # Negative interest rate

    with pytest.raises(ValueError):
        compounded_interest_calculator(1000, 1.5, 10, 4)   # Interest rate greater than 1

    with pytest.raises(ValueError):
        compounded_interest_calculator(1000, 0.05, -10, 4) # Negative time period

if __name__ == "__main__":
    pytest.main()