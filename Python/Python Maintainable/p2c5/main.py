from card_game.deck import Deck
from card_game.controller import Controller
from card_game.view import View


def main():
	deck = Deck()
	view = View()
	game = Controller(deck, view)
	game.run()


main()