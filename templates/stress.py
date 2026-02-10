import subprocess
import random

def generate_test_case():
    """Modify this function to generate appropriate test cases."""
    n = random.randint(1, 100)  # Example: Generate a random number
    return f"{n}\n"

def run_program(program, input_data):
    """Runs a compiled C++ program with input_data and returns output."""
    process = subprocess.run(
        [f"./{program}"], 
        input=input_data, 
        text=True, 
        capture_output=True
    )
    return process.stdout.strip()

def main():
    for test in range(100):  # Run 100 test cases
        test_case = generate_test_case()
        
        brute_output = run_program("brute", test_case)
        optimized_output = run_program("optimized", test_case)

        if brute_output != optimized_output:
            print(f"Test Case {test + 1} Failed!")
            print(f"Input:\n{test_case}")
            print(f"Brute-force Output:\n{brute_output}")
            print(f"Optimized Output:\n{optimized_output}")
            return  # Stop on first failure

    print("All test cases passed!")

if __name__ == "__main__":
    main()
