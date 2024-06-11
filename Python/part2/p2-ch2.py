userlist = input("Enter numbers separated with comas\n")
userlist = userlist.split(",")
print(userlist)

sum = 0

for n in userlist:
	sum += int(n)

print(f"Sum: {sum}")

average = sum / len(userlist)
print(f"Average: {average}")

print ("--- Average ----")
better_than_average = 0
for n in userlist:
	if int(n) > average:
		print(n)
		better_than_average += 1

print(f"Total of numbers higher than average: {better_than_average}")

print ("--- Even Numbers ----")
even = 0
for n in userlist:
	if int(n) % 2 == 0:
		print(f"{n} is even")
		even += 1
print(f"Total of even numbers: {even}")