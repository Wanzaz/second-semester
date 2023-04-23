# Uloha 2
import operator
from fractions import Fraction


operator_dict = {
    '+': operator.add,
    '-': operator.sub,
    '*': operator.mul,
    '/': operator.truediv,
}

def not_numeric(string):
    """Checking if the input is numeric or not"""
    if not string.replace(".", "").replace("|", "").isnumeric():
        print("=> Chyba ve vstupu")
        exit()

def assign_type(string):
    """Assign type to string which is appropriate for it"""
    if "|" in string:
        numerator, deminator = string.split("|")
        string = Fraction(numerator)/Fraction(deminator)
    else:
        string = float(string) if "." in string else int(string)
    return string

# Operand1 scanning
operand1 = input("Operand 1: ").replace(",", ".")
not_numeric(operand1)

# Oper scanning
oper = input("Operator: ")
if oper not in operator_dict:
    print("=> Chyba ve vstupu")
    exit()

# Operand1 scanning
operand2 = input("Operand 2: ").replace(",", ".")
not_numeric(operand2)


# Assigning appropriate type
operand1 = assign_type(operand1)
operand2 = assign_type(operand2)

# Generic solving function
def solve(x, y, oper):
    return operator_dict[oper](x, y)

# Printing result of the generic solving function
result = str(solve(operand1, operand2, oper)).replace(".", ",")
print("---------\n"
      f"Vysledek: {result}\n")
