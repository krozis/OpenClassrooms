


function displayScore(score, maxScore, scoreZone)
{
	scoreZone.innerText = `${score}/${maxScore}`;
}

function choseMode()
{
	let buffer = "";
	while (buffer != "words" && buffer != "sentences")
		buffer = prompt("Choose mode: 'sentences' or 'words'");
	return (buffer);
}

function gameLoop(list, mode)
{
	let	score = 0;
	let	buffer = "";

	for (let i = 0; i < list.length; i++)
	{
		buffer = prompt("Enter the " + mode + ": " + list[i]);
		if (buffer === list[i])
			score++;
	}
	return (score);
}

function launchGame()
{
	let	input = document.getElementById("inputEcriture");
	let	validBtn = document.getElementById("btnValiderMot");
	let toWrite = document.querySelector(".zoneProposition");
	let	scoreZone = document.querySelector(".zoneScore span");
	let mode = document.querySelectorAll(".optionSource input")
	
	let score = 0;
	let maxScore = 0;

	if (choseMode() === "words")
	{
		score = gameLoop(wordList, "word");
		maxScore = wordList.length;
	}
	else
	{
		score = gameLoop(sentList, "sentence");
		maxScore = sentList.length;
	}
	displayScore(score, maxScore, scoreZone);
}
