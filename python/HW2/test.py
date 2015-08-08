import string
with open('red-headed-league.txt','r') as fo:
	counts=dict()
	for item in fo.readlines():
		item=item.translate(None,string.punctuation)
		item=item.lower()
		words=item.split()
		for word in words:
		
			counts[word]=counts.get(word,0)+1
		print counts
	lst=counts.keys()
	lst.sort()
	for key in lst:
		print key,counts[key]


