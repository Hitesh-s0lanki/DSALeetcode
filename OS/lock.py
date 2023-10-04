from threading import *
lock = Lock()
counter = 0

def increase():
    lock.acquire()
    global counter
    for i in range(100000):
        counter += 1
        
    lock.release()
    


# create threads
t1 = Thread(target=increase)
t2 = Thread(target=increase)

# start the threads
t1.start()
t2.start()


# wait for the threads to complete
t1.join()
t2.join()


print(f'The final counter is {counter}')