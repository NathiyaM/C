class myqueue:	
	def __init__(self,li):
		self.li=li
	def enqueue(self,item):
		self.item=item
		return self.li.append(item)
	
	def dequeue(self):
		return self.li.pop(0)

a=[1,2,3]
q=myqueue(a)
print a
q.enqueue(7)
print q.li
q.dequeue()
print q.li
