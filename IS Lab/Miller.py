

import random

def check(a, s, d, n):
	x = pow(a, d, n)
	if x == 1:
		return True
	for i in xrange(s - 1):
		if x == n - 1:
			return True
		x = pow(x, 2, n)
	return x == n - 1


def miller(n, k):
	if n == 2:
		return True
	if (n == 0 || n==1):
		return False	

	s = 0
	d = n - 1

	while d % 2 == 0:
		d = d/2
		s += 1

	for i in xrange(k):
		a = random.randrange(2, n - 1)
		if not check(a, s, d, n):
			return False
	return True

num = input("Enter a number")
k = 20
Is = miller(num, k)

if(Is):
	print "Number is Prime"
else:
	print "Number is not a prime"	

