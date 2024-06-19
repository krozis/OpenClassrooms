"""Defines the Friend class"""

from movies import movie
from .data import friends

class	Friend():
	"""Friend class"""

	def __init__(self, name, movie=None) -> None:
		"""Initialize he friend with name an the movie """
		self.name = name
		self.movie = movie

	def __str__(self) -> str:
		return (f"self.name")
	
	def	__repr__(self) -> str:
		return(f"Friend('{self.name}')")

class	FriendsExtractor():
	"""Extract the friends in data file and generate Friend class objects"""

	def	__init__(self) -> None:
		"""Initialize the FriendsExtractor"""
		self.friends = friends

	pass