from pprint import pprint
from movies.friend import FriendsExtractor
from movies.library import Library

def	main():
	library = Library()

	movies = library.movies
	friends = FriendsExtractor().list_from_data(library)

	print("My movies:")
	pprint(movies)

	print("\nMy friends:")
	pprint(friends)

	library.sort_by_type()
	print('\nMy Movies sorted by type:')
	pprint(movies)

	print("\nRandom movie:")
	print(library.get_random_movie())

	print("\nI lent these movies:")
	lent_movies = library.get_lent_movies()
	pprint(lent_movies)
	for movie in lent_movies:
		print(f"The movie '{movie}' is at {movie.where}'s home")

if __name__ == "__main__":
	main()