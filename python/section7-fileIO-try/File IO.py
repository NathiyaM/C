
# coding: utf-8

# In[ ]:

'''
File IO
1. using module os
2. using module csv
3. using module xlrd
4. using context manager (with keyword)
5. walking a directory and all its sub-directories
'''


# In[ ]:

# syntax for file open is open(file_name,mode)
# http://www.tutorialspoint.com/python/python_files_io.htm
fo = open('python_list.txt', 'r')
# the above statement opens python_list.txt file in the read mode and is assigned a file object fo
# readlines() function reads one line at a time from the file
# syntax is file_object.readlines()
for items in fo.readlines():
    print items
fo.close() # remember to close the file


# In[ ]:

fo = open('python_list.txt', 'r')  
for items in fo.readlines():
    print items.strip() # strip removes newline, space, carriage return and tab from either 
    # end of the line. 
fo.close()


# In[ ]:

fo = open('python_list.txt', 'r')
print fo.readlines()
# Why does the for-loop not produce any output ???
for items in fo.readlines():
    print 'inside for-loop',items
fo.close()


# In[ ]:

# Writing a file
fo = open('python_list1.txt', 'w+') # here the text file is opened in write and read mode. 
fo.writelines('1,2,3\n')
print fo
fo.close()


# In[ ]:

fo = open('python_list1.txt', 'r')
for items in fo.readlines():
    print items.strip()
fo.close()


# In[ ]:

# The with keyword is called the context manager
# It will close the file whether or not there is an exception
with open('python_list1.txt', 'r') as fo:
    for items in fo.readlines():
        print items.strip()
# close does not have to be called exclusively 


# In[ ]:

with open('test.csv', 'r') as fo:
    for items in fo.readlines():
        print items.strip() # This is a string


# In[ ]:

import csv
with open('test.csv', 'r') as fo:
    alllines = csv.reader(fo,delimiter=',')
    for lines in alllines:
        print lines


                XLRD 
http://www.python-excel.org/
http://www.youlikeprogramming.com/2012/03/examples-reading-excel-xls-documents-using-pythons-xlrd/
                
# In[ ]:

import xlrd
# this module will help to read and write Excel files


# In[ ]:

# Open an excel file and get all the sheet names
wb = xlrd.open_workbook('Book1.xlsx')
print wb.sheet_names()


# In[ ]:

# In sheet 1, get the number of rows
ws = wb.sheet_by_name('Sheet1')
print ws.nrows


# In[ ]:

print ws.row(0) # Get the content of first row as a list


# In[ ]:

print ws.row(0)[1] # Get the second element of the first row list 


# In[ ]:

'''
The common cell types are 0=Empty, 1=Text, 2=Number, 3=Date, 4=Boolean, 5=Error, 6=Blank
'''


# In[ ]:

celltype = ws.cell_type(0,1)
cellval = ws.cell_value(0,1)
print celltype, cellval


# In[ ]:

celltypevaldict = {0:"Empty", 1:"Text", 2:"Number", 3:"Date", 4:"Boolean", 5:"Error", 6:"Blank"}

celltype = ws.cell_type(0,1)
cellval = ws.cell_value(0,1)
print celltypevaldict[celltype], cellval


# In[ ]:

import xlwt
workbook = xlwt.Workbook() 
sheet = workbook.add_sheet("Sheet 1") 

#sheet.write(0, 0, 'Adam') # row, column, value

g = [['Adam', ' 10034'],
['Nitin', ' 10043'],
['Rob', ' 10134'],
['Sheela', ' 10045']]

for i,v in enumerate(g):
    if len(v) > 2:
        sheet.write(i,0,v[0])
        sheet.write(i,1,v[1])
        
workbook.save('Xcel1.xls')


                '''
DIRECTORY LISTING
'''
                
# In[ ]:

import os
os.listdir(".")


# In[ ]:

import glob
print glob.glob("*.*")
# glob.glob(_directory_name) will return all the files in a particular directory or folder


# In[ ]:

print glob.glob("*.ipynb")
# in this example it will return all the ipython notebook files in the current directory


# In[ ]:

import os
# os.walk returns three values - root, directories and files and they are passed to the variables
# root, dirs and files respectively.
for root, dirs, files in os.walk("/Users/chityala/Desktop/"):
    # root, dirs, files
    for file in files:
        if file.endswith(".py"):
             print os.path.join(root, file)


# In[ ]:

import os
os.getcwd()


# In[ ]:



