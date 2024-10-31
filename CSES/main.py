import sys

# Define the operation keywords
addition = ['plus', 'addition', 'add']
subtraction = ['subtraction', 'subtract', 'minus']
multiplication = ['x', 'multiply', 'multiplied_by', 'into']
division = ['/', 'divide', 'div', 'by']

def main():
    # Check if there are at least 4 arguments (script name, operation, and 2 operands)
    if len(sys.argv) < 4:
        print("Error: Insufficient arguments. Usage: Solution.py <operation> <operand1> <operand2> ...")
        sys.exit(1)

    # Extract the operation and operands from the command-line arguments
    operation = sys.argv[1]
    operands = sys.argv[2:]

    try:
        # Convert all operand arguments to floats
        operands = [float(operand) for operand in operands]
    except ValueError:
        print("Error: Operands must be numbers.")
        sys.exit(1)

    result = None

    # Perform the corresponding operation based on the keyword
    if operation in addition:
        result = sum(operands)
    elif operation in subtraction:
        result = operands[0] - sum(operands[1:])
    elif operation in multiplication:
        result = 1
        for num in operands:
            result *= num
    elif operation in division:
        try:
            result = operands[0]
            for num in operands[1:]:
                result /= num
        except ZeroDivisionError:
            print("Error: Division by zero is not allowed.")
            sys.exit(1)
    else:
        print(f"Error: Unsupported operation '{operation}'")
        sys.exit(1)

    # Print the result rounded to two decimal places
    print(f"{result:.2f}")

# This is the entry point for the script
if __name__ == "_main_":
    main()