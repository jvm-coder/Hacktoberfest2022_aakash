def add(n1, n2):
    return n1 + n2


def subtract(n1, n2):
    return n1 - n2


def multiply(n1, n2):
    return n1 * n2


def divide(n1, n2):
    return n1 / n2


operations = {"+": add, "-": subtract, "*": multiply, "/": divide}


def calculator():
    num_1 = float(input("What's the first number?: "))
    for symbol in operations:
        print(symbol)
    should_contine = True
    while should_contine:

        oper_sym = input("Pick an operation: ")
        num_2 = float(input("what's the next number?: "))

        calc = operations[oper_sym]
        answer = calc(num_1, num_2)
        print(f"{num_1} {oper_sym} {num_2} = {answer}")

        again = input(
            f"Type 'y' to continue calculating with {answer} ,or type 'n' to start a new calculation: "
        )
        if again == 'y':
            num_1 = answer
        else:
            should_contine = False
            calculator()


calculator()
