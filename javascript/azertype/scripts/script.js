
function	displayScore(score, maxScore)
{
	let	scoreZone = document.querySelector(".zoneScore span");
	scoreZone.innerText = `${score}/${maxScore}`;
}

function	writeInZone(zone, toWrite)
{
	zone.innerText = `${toWrite}`;
}

function	launchGame()
{
	let	input = document.getElementById("inputEcriture");
	let toWrite = document.querySelector(".zoneProposition");
	let	validBtn = document.getElementById("btnValiderMot");
	let mode = document.querySelectorAll(".optionSource input")
	
	let i = 0;
	let score = 0;

	let	chosenList = wordList;

	writeInZone(toWrite, chosenList[i]);
	displayScore(score, i);
	mode.forEach(btn => 
	{
		btn.addEventListener("change", () =>
		{
			if (mode[0].checked)
				chosenList = wordList;
			else
				chosenList = sentList;
			i = 0;
			score = 0;
			validBtn.disabled = false;
			writeInZone(toWrite, chosenList[i]);
			displayScore(score, i);
			console.log("mode changed to :" + (mode[0].checked ? "words" : "sentences"));
		});
	});

	validBtn.addEventListener("click", () =>
	{
		console.log("input value: " + input.value);
		if (input.value === chosenList[i])
			score++;
		input.value = "";
		i++;
		if (i < chosenList.length)
			writeInZone(toWrite, chosenList[i]);
		else
		{
			writeInZone(toWrite, "Game is now over.");
			validBtn.disabled = true;
		}
		displayScore(score, i);
	});	

	//displayScore(score, i, scoreZone);
}
