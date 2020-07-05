# Number of bit strings recursive
def recursive_bit_strings(n):
    if n < 3:
        return 0
    return 2**(n - 3) + recursive_bit_strings(n - 1) + recursive_bit_strings(n - 2) + recursive_bit_strings(n - 3)
recursive_bit_strings(5)


# Number of bit strings problem
def get_sum(array, i):
    return array[i - 1] + array[i - 2] + array[i - 3]

def num_bit_strings(n):
    array = [0 for i in range(n + 1)]
    
    for i in range(3, n + 1):
        array[i] = get_sum(array, i) + 2**(i - 3)
    return array[n]

num_bit_strings(4)


# In[22]:


# Number of bit strings of x consecutive 1s problem
def get_sum(array, index, x):
    total = 0
    for i in range(x):
        total += array[index - i]
    return total

def num_bit_strings(n, x):
    array = [0 for i in range(n + 1)]
    
    for i in range(x, n + 1):
        array[i] = get_sum(array, i, x + 1) + 2**(i - x)
    return array[n]

num_bit_strings(4, 3)


# In[41]:


# Number of bit strings of x consecutive 1s problem
def get_sum(array, index, x):
    total = 0
    for i in range(x):
        total += array[index - i]
    return total

def num_bit_strings(n, x):
    array = [0 for i in range(n + 1)]
    array_test = [0 for i in range(n + 1)]
    
    for i in range(x, n + 1):
        array[i] = get_sum(array, i, x + 1) + 2**(i - x)
    return array[n]
    
num_bit_strings(5, 3)


# Coin change problem
MAX = 10000000
def min_change(coins_array, total_cost):
    array = [[MAX for i in range(total_cost + 1)] for j in range (3) ]
    
    for i in range(3):
        array[i][0]
    
    for i in range(3):
        for j in range(total_cost + 1):
            array[i][j] = min(array[i][j - coins_array[i]] + 1, array[i - 1][j])
    return array[2][total_cost]
min_change([1, 5, 6], 11)





