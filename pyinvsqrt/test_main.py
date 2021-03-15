import numpy as np
import pytest

from pyinvsqrt import invsqrt


@pytest.mark.parametrize(
    "number",
    [
        (10),
        (0.001)
    ]
)
def test_invsqrt(number):
    """
    Test that result is within 1% of direct calculation
    """
    result = invsqrt(number)
    expected = np.reciprocal(np.sqrt(number))
    assert np.isclose(result, expected, rtol=0.01)
