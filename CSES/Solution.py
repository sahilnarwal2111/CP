# Function to perform the calculation
def calculate(operation, operands):
    if operation in ['+', 'plus', 'addition', 'add']:
        return sum(operands)
    elif operation in ['-', 'subtraction', 'subtract', 'minus']:
        result = operands[0]
        for num in operands[1:]:
            result -= num
        return result
    elif operation in ['x', 'multiply', 'multiplied_by', 'into']:
        result = operands[0]
        for num in operands[1:]:
            result *= num
        return result
    elif operation in ['/', 'divide', 'div', 'by']:
        result = operands[0]
        try:
            for num in operands[1:]:
                result /= num
            return result
        except ZeroDivisionError:
            return "Error: Division by zero"
    else:
        return "Invalid operation"

# Main function
if __name__ == "__main__":
    user_input = input()
    
    input_parts = user_input.split()
    
    operation = input_parts[0]
    operands = list(map(float, input_parts[1:]))

    result = calculate(operation, operands)

    if isinstance(result, float):
        print(f"{result:.2f}")
    else:
        print(result)
