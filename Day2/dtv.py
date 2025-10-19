import os

def read_file(filename):
    base_path = './documents/'
    full_path = os.path.join(base_path, filename)

    if os.path.exists(full_path):
        with open(full_path, 'r') as f:
            print(f.read())
    else:
        print("File not found.")

# Simulate user input
user_input = input("Enter the filename to read: ")
read_file(user_input)