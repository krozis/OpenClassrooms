"""Defines the Friend class"""

from movies import movie
from .data import friends

class	Friend():
	"""Friend class"""

	def __init__(self, name, movie=None) -> None:
		"""Initialize he friend with name an the movie """
		self.name = name
		self.movie = movie
		if movie:
			movie.where = self

	def __str__(self) -> str:
		return (f"{self.name}")
	
	def	__repr__(self) -> str:
		return(f"Friend('{self.name}')")

class	FriendsExtractor():
	"""Extract the friends in data file and generate Friend class objects"""

	NAME_INDEX = 0
	MOVIE_INDEX = 1

	def	__init__(self) -> None:
		"""Initialize the FriendsExtractor"""
		self.friends = friends

	def	generate(self, data, library):
		"""Returns a friend from raw data"""

		name = data[self.NAME_INDEX]
		if (len(data) > 1):
			movie_title = data[self.MOVIE_INDEX]
			movie = library.find_by_title(movie_title)
		else:
			movie = None
		return (Friend(name, movie))
	
	def	list_from_data(self, library):
		"""Returns a list of Friends from raw data"""

		friends_list = []
		for friend_raw in self.friends:
			friend = self.generate(friend_raw, library)
			friends_list.append(friend)
		return (friends_list)