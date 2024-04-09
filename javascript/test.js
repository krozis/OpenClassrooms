const wordToType = "toto";
let userWord = prompt("Enter the word:");

let	isMatching = (wordToType === userWord) ? true : false;


if (isMatching)
	console.log("Congratulations");
else
	console.log("Word is incorrect");