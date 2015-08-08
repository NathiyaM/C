
# coding: utf-8

# In[ ]:

'''
Error checks and other storing methods
1. try-except example of integer divison by zero 
2. Pickle
3. Shelve 
'''


# In[ ]:

'''
An exception is raised when a program has an error. Error handling is used to take care of exceptions 
so that when there is no exception then the program runs smoothly and in case of an error, the error 
handler can fix the problem or handle it so that the program can be continued. 

TRY-EXCEPT is a construct that handles exceptions.

http://www.python-course.eu/exception_handling.php
'''


# In[ ]:

a = 10
b = 0
c = a/b
print c


# In[ ]:

try:
    c = a/b
except ZeroDivisionError:
    c = a

# Instead of quitting after encountering the ZeroDivisionError, in this case we are assigning a new value 
# to c so that the program can continue.
print c
    


# In[ ]:

a = int('92384a')
print a, type(a)
# since the string can't be converted to an int, ValueError exception is raised


# In[ ]:

try:
    a = int('92384g')
    b = 0
    c = a/b
except:
    print 'The error message is - Not a number.'
    print 'The error message is - Cannot divide by zero.'


# In[ ]:

try:
    a = int('92384g')
    b = 12
    c = 0
    d = b/c
except ValueError as v:
    print 'Not a number.  The error message is',v
except ZeroDivisionError as z:
    print 'Cannot divide by zero.  The error message is',z


# In[ ]:

try:
    a = int('92384g')
except ValueError as v:
    print 'Not a number.  The error message is',v
    
try:
    b = 12
    c = 0
    d = b/c
except ZeroDivisionError as z:
    print 'Cannot divide by zero.  The error message is',z


# In[ ]:

'''
try-except-else: the else clause has to placed after all the exceptions and else clause will be 
executed when the try clause doesn't raise any exceptions

syntax

try:
    execute try statements
    
except exception1:
    If there is exception1, then execute this block

except exception2:
    If there is exception2, then execute this block
    
else:
    If there is no exception, then execute this block
'''

try:
    a = int('92a')
except ValueError:
    a = 10
    print 'a is not a number. Gave a new value = ', a
else:
    print 'is a number'


# In[ ]:

''' 
To enforce clean-up or termination clauses there is try-finally or try-except-finally. Finally clause 
will be executed no matter whether an exception occurs or not.

syntax

try:
    execute statements
    
    if an exception occurs, then this may be skipped
    
except e1:
    statement to execute if there is an exception
    
finally:
    this will always be executed

'''


# In[ ]:

try:
    f = open("test1.txt","r")
    f.write("name, age, address")
    
except IOError:
    print "File not found."
    
finally:
    print "There is no file by this name."


# In[ ]:

'''
Note - the major difference between else clause and finally clause is that else clause will get executed 
only when no exceptions are raised. Whereas finally clause gets executed no matter whether an exception 
is raised or not. 
'''


# In[ ]:

a = 10
b = 0
try:
    c = a/b
except ZeroDivisionError:
    c = a
finally:
    print c


# In[ ]:

#  Raising custom exceptions
# Stored in one file
class TooSmallError(Exception):
    pass

class TooLargeError(Exception):
    pass

def checkval(val,limit):
    if val < limit:
        raise TooSmallError
    else:
        raise TooLargeError
        
# Stored in another file
limit = 10
try:
    a = 50
    checkval(a,limit)
except TooSmallError:
    print "Too Small"
except TooLargeError:
    print "Too Large"    


# In[ ]:

# file1.py
a = 10.0
b = 0

def inv(a,b):
    c = 0
    d = 0
    try:
        c = 1.0/a
        d = 1.0/b
    except ZeroDivisionError:
        pass
        # raise ZeroDivisionError("One or more numbers is zero.")
    return (c,d)

def insum(c,d):
    e = c + d
    return e


# file2.py
w = inv(a,b)
insum(w[0],w[1])


# In[ ]:

# file1.py
a = 10.0
b = 0

def inv(a,b):
    c = 0
    d = 0
    try:
        c = 1.0/a
        d = 1.0/b
    except ZeroDivisionError:
        print "Either c or d is zero"
        raise ZeroDivisionError("One or more numbers is zero.")
    return (c,d)

def insum(c,d):
    e = c + d
    return e

## file2.py
try:
    w = inv(a,b)
except ZeroDivisionError:
    print "Could not complete inv()"
insum(w[0],w[1])


# In[ ]:

'''
A pickle converts Python objects to bytes that can be stored or transmitted (not secure). The CPickle 
module implemented using C is faster than pickle that is implemented using Python. Pickle can handle 
unicode objects. A “shelf” is a persistent, dictionary-like object. Check out the followign links to 
learn more https://freepythontips.wordpress.com/2013/08/02/what-is-pickle-in-python/
'''


# In[ ]:

try:
   import cPickle as pickle
except:
   import pickle


# In[ ]:

mydict = [ { 'a':'1', 'b':2, 'c':3 } ]
mydict2 = {'d':4,'e':5}

f = open('pickle.ck','wb')
pickle.dump(mydict,f) #this command dumps mydict into the file pickle.ck
pickle.dump(mydict2,f) # this command dumps mydict2 into the file pickle.ck
f.close()

f = open('pickle.ck','rb')
newdict = pickle.load(f)
newdict2 = pickle.load(f)
f.close()

print 'Read values are:',
print newdict
print(newdict2)


# In[ ]:

f = open('pickle.ck','rb')
newdict = pickle.load(f)
newdict2 = pickle.load(f)
print newdict2
# We have read all the information that needs to be read.  This will give an error
newdict3 = pickle.load(f) 
f.close()


# In[ ]:

'''
Shelve module can be used to store and retrieve Python objects easily.
Shelve uses anydbm to store the data. Check out the following link for more information.
http://pymotw.com/2/shelve/
'''


# In[ ]:

import shelve
mydict = [ { 'a':'1', 'b':2, 'c':3 } ]
mylist = ['apple', 'mango', 'pineapple']
s = shelve.open('fruit.sv') # opens the shelve
try:
    s['first'] = mydict
    s['second'] = mylist
finally:
    print s
    s.close()


# In[ ]:

import shelve
s = shelve.open('fruit.sv','r')
try:
    newdict = s['first']
finally:
    s.close()
print newdict


# In[ ]:

import shelve
mydict = [ { 'a':'1', 'b':2, 'c':3 } ]
# Write back uses in-memory cache. All items in cache are written to the shelve when it is closed.
s = shelve.open('fruit.sv',writeback=True)
try:
    s['firstdict'] = mydict
finally:
    s.close()


# In[ ]:

import shelve
s = shelve.open('fruit.sv')
if 'second' in s: # we are checking if the key second exists
    print s['second']


# In[ ]:

'''
Note - the major difference between pickle and shelve is that pickle stores the objects one at a time 
and objects can only be retrieved in the order they were written. Whereas objects in shelve can be 
accessed in any order. 
'''

