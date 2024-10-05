def py_add(a: float, b: float)->float:
    return a +b

def py_div(a: float, b: float)->float:
    if b == 0:
        b = 0.0000001
    return a/b