import random   #used for the rule "get a random movie"

from .data import films
from .movie import MovieExtractor

class	Library():
	"""Movies Library"""

	def	__init__(self) -> None:
		"""initialize movies"""
		self.movies = []
		for movie_raw in films:
			movie = MovieExtractor(movie_raw).generate()
			movie.where = self
			self.movies.append(movie)

		self.sort_by_year_and_title()


	def	sort_by_year_and_title(self):
		"""Sort Library's Movies by year then title"""
		self.movies.sort(key=lambda movie: (movie.year, movie.title))

	def	sort_by_type(self):
		"""Sort with Library's Movies by Movie's type"""
		self.movies.sort(key=lambda movie: movie.type)
	
	def	get_random_movie(self):
		"""Returns a random movie from the Library"""
		return (random.choice(self.movies))
	
	def	get_lent_movies(self):
		"""Returns he ist of lent movies"""

		lent_movies = []
		for movie in self.movies:
			if movie.where is not self:
				lent_movies.append(movie)
		return (lent_movies)
	
	def	find_by_title(self, title):
		"""If title corresponds to a movie, returns it, else return None"""

		for movie in self.movies:
			if (title == movie.title):
				return (movie)
		return (None)