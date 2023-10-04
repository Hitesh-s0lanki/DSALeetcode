import threading

def taskA():
    for i in range(10):
        print(f"Task A: {i}")

def taskB():
    for i in range(10):
        print(f"Task B: {i}")
        
        
if __name__ =='__main__':
    
    t1 = threading.Thread(target=taskA)
    t2 = threading.Thread(target=taskB)
    
    # starting thread 1
    t1.start()
    # starting thread 2
    t2.start()
    
    t1.join()
    t2.join()