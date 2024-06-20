"""Defines the movie class"""

class	Movie():
	"""Movie class"""

	def	__init__(self, title, year) -> None:
		"""Initialize title and year of release for a movie"""
		self.title = title
		self.year = year
		self.where = None

	def __str__(self) -> str:
		return (f"{self.title} ({self.year})")
	
	def __repr__(self) -> str:
		return (f"Movie('{self.title}', {self.year})")
	
class	MovieDVD(Movie):
	"""DVD Movie class"""

	type = "dvd"

	def	__init__(self, title, year) -> None:
		super().__init__(title, year)
		self.mega_octet = 4700

class	MovieVHS(Movie):
	"""VHS Movie class"""

	type = "vhs"

	def	__init__(self, title, year) -> None:
		super().__init__(title, year)
		self.magnetic_tape = True

class	MovieExtractor:
	"""Get a movie from data"""

	TITLE_AND_YEAR_INDEX = 0
	TYPE_INDEX = 1

	def	__init__(self, film_data) -> None:
		self.film_data = film_data

	def	generate(self):
		"""generate a Movie"""
		title = self.generate_title()
		year = self.generate_year()
		type = self.generate_type()

		for Movie in (MovieVHS, MovieDVD):
			if (type == Movie.type):
				return (Movie(title, year))

	def	generate_title(self):
		"""generate Movie's title"""
		title_and_year = self.film_data[self.TITLE_AND_YEAR_INDEX]
		return (title_and_year[: title_and_year.index("(")].strip())
	
	def	generate_year(self):
		"""generate Movie's year of release"""
		title_and_year = self.film_data[self.TITLE_AND_YEAR_INDEX]
		year_raw = title_and_year[title_and_year.index("(") :]
		year = year_raw.replace("(", "").replace(")", "")
		return (int(year))
	
	def	generate_type(self):
		"""generate Movie's type"""
		return (self.film_data[self.TYPE_INDEX].lower())
