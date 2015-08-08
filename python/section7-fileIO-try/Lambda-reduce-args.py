
# coding: utf-8

# In[2]:

'''
lambda function is an anonymous function. It is an alternate to a named function. It is generally 
found in places where we need to use a function only once. 
'''

g = lambda x: x**x
g(4)


# In[5]:

a = [2,-4,8]
g2 = lambda x: x+4
b = [g2(x) for x in a]
print b


# In[4]:

# Find the sum of all elements in a list
a = [3,2,5]
reduce(lambda x,y: x+y, a)


# In[3]:

a = [3,2,5]
reduce(lambda x,y: x*y , a)


# In[1]:

# kwargs and args
def sum1(x,y):
    a = x + y
    return a
sum1(10,-2)


# In[11]:

def take1(*args):
    print args
    for i in args:
        print i
     
take1(-10)
take1(1,2,3)


# In[20]:

from operator import mul
def multy(*args):
    return reduce(mul, args)

multy(3, 5, 2, 5)


# In[16]:

def utake(**kwargs):
    print kwargs
    
utake(a = 'abe')
utake(a = 'abe', b ='cab')


# In[25]:

def ptab(**kwargs):
    for key, value in kwargs.items():
        print key, value

ptab(a = 7, b = -5, c = 3, d = -10)


# In[ ]:



