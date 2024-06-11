def month_salary(year_salary):
	return (year_salary / 12)

def week_salary(month_salary):
	return (month_salary / 4)

def hour_salary(week_salary, worked_hours):
	return(week_salary / worked_hours)

def main():
	while True:
		try:
			user_year_salary = int(input("Enter your annual salary?\n"))
			user_worked_hours = int(input("Enter the amount of worked hours in a week\n"))

			user_hour_salary = hour_salary(week_salary(month_salary(user_year_salary)), user_worked_hours)
			print(f"Your salary for one hour is {user_hour_salary}€")
			break
		except ValueError:
			print("Only numbers are allowed.")
		except ZeroDivisionError:
			print("0 hours is forbidden.")

if __name__ == "__main__":
    main()