import threading
import time

lock_a = threading.Lock()
lock_b = threading.Lock()

print("Starting the deadlock example...")
print("!!! The program will freeze. You'll need to manually stop it !!!")

def worker_one():
    print("Worker 1: Trying to acquire Lock A...")
    lock_a.acquire()
    print("Worker 1: Acquired Lock A.")
    
    time.sleep(1)
    
    print("Worker 1: Trying to acquire Lock B...")
    lock_b.acquire()
    print("Worker 1: Acquired Lock B.")
    
    # This part will never be reached
    print("Worker 1: Releasing both locks.")
    lock_a.release()
    lock_b.release()

def worker_two():
    print("Worker 2: Trying to acquire Lock B...")
    lock_b.acquire()
    print("Worker 2: Acquired Lock B.")
    
    time.sleep(1)
    
    print("Worker 2: Trying to acquire Lock A...")
     # This will block forever
    lock_a.acquire() 
    print("Worker 2: Acquired Lock A.")
    
    # This part will never be reached
    print("Worker 2: Releasing both locks.")
    lock_b.release()
    lock_a.release()


t1 = threading.Thread(target=worker_one)
t2 = threading.Thread(target=worker_two)

t1.start()
t2.start()

# Wait for both threads to finish (which they never will)
t1.join()
t2.join()

# This line will never be printed
print("Finished.") 