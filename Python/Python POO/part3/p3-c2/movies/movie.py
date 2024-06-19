"""Defines the movie class"""

class	Movie():
	"""Movie class"""

	def	__init__(self, title, year) -> None:
		"""Initialize name and year of release for a movie"""
		self.title = title
		self.year = year
		self.where = None

	def __str__(self) -> str:
		return (f"{self.title} ({self.year})")
	
	def __repr__(self) -> str:
		return (f"Movie('{self.title}', {self.year})")
	



