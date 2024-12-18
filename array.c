import random
import math

# Class to represent a geometric shape
class Shape:
    def __init__(self, name):
        self.name = name

    def area(self):
        raise NotImplementedError("This method should be overridden in subclasses")

    def perimeter(self):
        raise NotImplementedError("This method should be overridden in subclasses")

    def __str__(self):
        return f"{self.name} Shape"

# Class for Circle, subclass of Shape
class Circle(Shape):
    def __init__(self, radius):
        super().__init__("Circle")
        self.radius = radius

    def area(self):
        return math.pi * (self.radius ** 2)

    def perimeter(self):
        return 2 * math.pi * self.radius

    def __str__(self):
        return f"Circle with radius {self.radius}"

# Class for Rectangle, subclass of Shape
class Rectangle(Shape):
    def __init__(self, length, width):
        super().__init__("Rectangle")
        self.length = length
        self.width = width

    def area(self):
        return self.length * self.width

    def perimeter(self):
        return 2 * (self.length + self.width)

    def __str__(self):
        return f"Rectangle with length {self.length} and width {self.width}"

# Class for Square, subclass of Rectangle
class Square(Rectangle):
    def __init__(self, side_length):
        super().__init__(side_length, side_length)

    def __str__(self):
        return f"Square with side length {self.length}"

# Function to generate a random number within a range
def generate_random_number(min_value, max_value):
    return random.randint(min_value, max_value)

# Function to generate a random list of integers
def generate_random_list(length, min_value, max_value):
    return [generate_random_number(min_value, max_value) for _ in range(length)]

# Function to find the mean of a list of numbers
def calculate_mean(numbers):
    return sum(numbers) / len(numbers) if numbers else 0

# Function to find the median of a list of numbers
def calculate_median(numbers):
    sorted_numbers = sorted(numbers)
    length = len(sorted_numbers)
    if length % 2 == 1:
        return sorted_numbers[length // 2]
    else:
        mid = length // 2
        return (sorted_numbers[mid - 1] + sorted_numbers[mid]) / 2

# Function to find the mode of a list of numbers
def calculate_mode(numbers):
    frequency = {}
    for number in numbers:
        frequency[number] = frequency.get(number, 0) + 1
    max_frequency = max(frequency.values())
    modes = [key for key, value in frequency.items() if value == max_frequency]
    return modes

# Function to calculate the standard deviation of a list of numbers
def calculate_standard_deviation(numbers):
    mean = calculate_mean(numbers)
    variance = sum((x - mean) ** 2 for x in numbers) / len(numbers)
    return math.sqrt(variance)

# Function to calculate the range of a list of numbers
def calculate_range(numbers):
    return max(numbers) - min(numbers)

# Function to test the Shape classes
def test_shapes():
    # Create instances of shapes
    circle = Circle(5)
    rectangle = Rectangle(10, 20)
    square = Square(15)

    # Print area and perimeter of each shape
    print(f"{circle}: Area = {circle.area():.2f}, Perimeter = {circle.perimeter():.2f}")
    print(f"{rectangle}: Area = {rectangle.area():.2f}, Perimeter = {rectangle.perimeter():.2f}")
    print(f"{square}: Area = {square.area():.2f}, Perimeter = {square.perimeter():.2f}")

# Function to demonstrate statistical functions
def test_statistics():
    # Generate a random list of numbers
    numbers = generate_random_list(100, 1, 100)
    print(f"Numbers: {numbers}")
    
    # Calculate and display various statistics
    print(f"Mean: {calculate_mean(numbers)}")
    print(f"Median: {calculate_median(numbers)}")
    print(f"Mode: {calculate_mode(numbers)}")
    print(f"Standard Deviation: {calculate_standard_deviation(numbers)}")
    print(f"Range: {calculate_range(numbers)}")

# Function to calculate the Fibonacci sequence up to a certain number
def fibonacci(n):
    sequence = [0, 1]
    for i in range(2, n):
        sequence.append(sequence[-1] + sequence[-2])
    return sequence

# Function to find the factorial of a number
def factorial(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)

# Function to generate a random password of specified length
def generate_password(length):
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"
    return ''.join(random.choice(characters) for _ in range(length))

# Function to calculate the greatest common divisor of two numbers
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

# Function to calculate the least common multiple of two numbers
def lcm(a, b):
    return abs(a * b) // gcd(a, b)

# Class to represent a simple bank account
class BankAccount:
    def __init__(self, account_number, balance=0.0):
        self.account_number = account_number
        self.balance = balance

    def deposit(self, amount):
        if amount > 0:
            self.balance += amount
            print(f"Deposited {amount:.2f}. New balance: {self.balance:.2f}")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amount):
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"Withdrew {amount:.2f}. New balance: {self.balance:.2f}")
        else:
            print("Insufficient funds or invalid amount.")

    def get_balance(self):
        return self.balance

    def __str__(self):
        return f"Bank Account {self.account_number} with balance {self.balance:.2f}"

# Function to demonstrate the BankAccount class
def test_bank_account():
    account = BankAccount("123456789")
    account.deposit(500)
    account.withdraw(200)
    print(f"Final balance: {account.get_balance():.2f}")

# Function to test Fibonacci, factorial, and password generation
def test_utilities():
    # Fibonacci sequence
    fib_seq = fibonacci(10)
    print(f"Fibonacci Sequence (first 10 numbers): {fib_seq}")

    # Factorial calculation
    fact_5 = factorial(5)
    print(f"Factorial of 5: {fact_5}")

    # Password generation
    password = generate_password(12)
    print(f"Generated password: {password}")

# Main function to execute all tests
def main():
    print("Testing Shape Classes:")
    test_shapes()
    print("\nTesting Statistical Functions:")
    test_statistics()
    print("\nTesting Bank Account Class:")
    test_bank_account()
    print("\nTesting Utility Functions:")
    test_utilities()

# Entry point of the script
if __name__ == "__main__":
    main()
