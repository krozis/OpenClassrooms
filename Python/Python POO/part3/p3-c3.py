class User:
	def __init__(self, username, password) -> None:
		"""Initialize password and name"""
		if (len(username) < 4):
			raise TooShortUsernameException()
		if (len(password) < 4):
			raise TooShortPasswordException()
		self.username = username
		self.password = password




# Exceptions #

class UserException(Exception):
	"""Parent Excepion class"""
	pass

class TooShortUsernameException(UserException):
	"""Exception for an invalid username due to shortness"""

	def	__init__(self, msg="", *args, **kwargs) -> None:
		msg = msg or "Username is too short! (min 4 characters)"
		super().__init__(msg, *args, **kwargs)

class TooShortPasswordException(UserException):
	"""Exception for an invalid password due to shortness"""

	def	__init__(self, msg="", *args: object) -> None:
		msg = msg or "Password is too short! (min 4 characters)"
		super().__init__(msg, *args)


# Main #

if __name__ == "__main__":
	user = User("John", "secretpassword")
	try:
		user = User("t", "secretpassword")
	except TooShortUsernameException as error:
		print(error)

	try:
		user = User("John", "p")
	except TooShortPasswordException as error:
		print(error)