from abc import ABC

class	File(ABC):
	"""File class"""

	def __init__(self, name, size):
		"""initialize name and size"""

		self.name = name
		self.size = size

	def display(self):
		"""display the file"""

		print(f"File '{self.name}'")

class	ImageFile(File):
	"""Image file class"""

	def display(self):
		"""display the image"""
		print(f"Image file '{self.name}'")

class	ImageJPG(ImageFile):
	"""JPG image file class"""

	def	display(self):
		"""display the JPG image"""
		super().display()
		print("File is of type 'JPG'.")

class	ImageGIF(ImageFile):
	"""JPG image file class"""
	
	def	display(self):
		"""display the GIF image"""
		super().display()
		print("File is of type 'GIF'.")

class User:
	"""User class"""

	def	__init__(self, username, password):
		"""Initialize username and password"""

		self.username = username
		self.password = password

	def	login(self):
		"""log the user"""

		print(f"User {self.username} just logged in")

	def	post(self, thread, content, file=None):
		"""Post a message in a thread"""

		if (file):
			post = FilePost(self, "today", content, file)
		else:
			post = Post(user=self, time_posted="today", content=content)
		thread.add_post(post)
		return (post)

	def	make_thread(self, title, content):
		"""Create a new discussion thread"""

		post = Post(self, "today", content)
		return (Thread(title, "today", post))
	
	def	__str__(self):
		"""User representation"""
		return (self.username)
	
class Moderator(User):
	""" Moderator User class"""

	def	edit(self, post, content):
		"""Modify a message"""

		post.content = content

	def delete(self, thread, post):
		"""Delete a message"""

		index = thread.posts.index(post)
		del thread.posts[index]

class Post:
	"""Message class"""

	def __init__(self, user, time_posted, content):
		"""Initialize with the user, the date and the content"""

		self.user = user
		self.time_posted = time_posted
		self.content = content

	def display(self):
		"""Display a message"""

		print(f"Message posted by {self.user}, {self.time_posted} :")
		print(self.content)

class FilePost(Post):
	"""Message with a file class"""

	def	__init__(self, user, time_posted, content, file):
		"""Initialize the message with a file"""

		super().__init__(user, time_posted, content)
		self.file = file

	def	display(self):
		"""Display the message and the file"""
		super().display()
		print("attached file:")
		self.file.display()

class Thread:
	"""Discussion thread class"""

	def __init__(self, title, time_posted, post):
		"""Initalize the title, date and posts. beinning with only one post"""
		
		self.title = title
		self.time_posted = time_posted
		self.posts = [post]

	def display(self):
		"""Display the thread"""

		print("**** Thread ****")
		print(f"title: {self.title}, date: {self.time_posted}\n")
		for post in self.posts:
			post.display()
			print()
			print("****************")

	def add_post(self, post):
		"""Add a message to the thread"""

		self.posts.append(post)

def main():

	user = User("Toto", "1234")
	modo = Moderator("Big Boss", "Qwertyuiop1234")

	thread = user.make_thread("Am i dumb?", "I passed an IQ test an got 64. Am i dumb or can i still be a famous spider trainer?")
	oos_post = user.post(thread, "I love cats!")
	sentence = modo.post(thread, "You mesage is totally out of subject and will be deleted.")
	thread.display()

	modo.delete(thread, oos_post)
	modo.delete(thread, sentence)

	img = ImageJPG("My IQ test", 1024)
	answerWithImage = user.post(thread, "I forgot, here is my IQ test image", img)

	print()
	thread.display()

main()