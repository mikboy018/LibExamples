def py_add(a: float, b: float)->float:
    """
    py_add
    
    :param a: First value
    :type a: float
    :param b: Second value
    :type b: float
    :return: A + B
    :rtype: float
    """
    return a +b

def py_div(a: float, b: float)->float:
    """
    Docstring for py_div
    
    :param a: Numerator
    :type a: float
    :param b: Denominator
    :type b: float
    :return: Quotient
    :rtype: float
    """
    if b == 0:
        b = 0.0000001
    return a/b