def sum(a, b):
	try:
		return (a + b)
	except ValueError:
		print("Error: only numbers are allowed")

def mult(a, b):
	try:
		return (a * b)
	except ValueError:
		print("Error: only numbers are allowed")