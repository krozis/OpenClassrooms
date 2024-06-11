nb_at_left = 42
nb_at_right = 25
symbol = '*'
result = 0

if not isinstance(nb_at_left, int) or not isinstance(nb_at_right, int):
	exit()

match symbol:
	case "+":
		result = nb_at_left + nb_at_right
	case "-":
		result = nb_at_left - nb_at_right
	case "*":
		result = nb_at_left * nb_at_right
	case "/":
		if nb_at_right == 0:
			print("Error: cannot divide by 0")
			exit()
		else:
			result = nb_at_left / nb_at_right
	case _:
		exit()

print(result)