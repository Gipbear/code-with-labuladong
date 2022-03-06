import time
from multiprocessing import Pool

def func(x):
    time.sleep(2)
    print(x**2, end=' | ')
    return x**2

if __name__ == '__main__':
    start_time = time.time()
    with Pool(5) as p:
        p.map(func, [i for i in range(10)])
    # list(map(func, [i for i in range(10)]))
    end_time = time.time()
    print(f"\n一共耗时{end_time-start_time}")