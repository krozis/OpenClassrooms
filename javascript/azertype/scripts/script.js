
/**
 * @brief set to mode "words" by default
 */
function	initMode()
{
	let mode = document.querySelectorAll(".optionSource input");
	mode[1].checked = false;
	mode[0].checked = true;
	return (wordList)
}

/**
 * @brief Fill the "zoneScore" span of the HTML page
 * @param {number} score 
 * @param {number} maxScore 
 */
function	displayScore(score, maxScore)
{
	let	scoreZone = document.querySelector(".zoneScore span");
	scoreZone.innerText = `${score}/${maxScore}`;
}

/**
 * @brief Fill the "zoneProposition" div of the HTML page
 * @param {string} toWrite 
 */
function	displayProposition(toWrite)
{
	let zone = document.querySelector(".zoneProposition");
	zone.innerText = `${toWrite}`;
}

/**
 * @brief launch the Azertype game
 */
function	launchGame()
{
	let	score = 0;
	let	total = 0;

	chosenList = initMode();
	initPopup();
	displayProposition(wordList[total]);

	// Handle player input
	let	playerInput = document.getElementById("inputEcriture");

	// handle validation with the button
	let	validationBtn = document.getElementById("btnValiderMot");
	validationBtn.addEventListener("click", () =>
	{
		console.log("submitted: " + playerInput.value);
		if (playerInput.value === chosenList[total])
			score++;
		total++;
		displayScore(score, total);
		playerInput.value = "";
		if (chosenList[total] === undefined)
		{
			displayProposition("Game is now over.");
			validationBtn.disabled = true;
		}
		else
			displayProposition(chosenList[total]);
	});

	// Handle validation with "Enter"
	playerInput.addEventListener("keypress", (event) =>
	{
		if (event.key === "Enter")
		{
			const clickEvent = new Event("click");
			validationBtn.dispatchEvent(clickEvent);
		}
	});

	// Handle mode change
	let mode = document.querySelectorAll(".optionSource input");
	for (i = 0; i < mode.length; i++)
	{
		mode[i].addEventListener("change", (event) => 
		{
			if (event.target.value === "1")
				chosenList = wordList;
			else
				chosenList = sentList;
			displayProposition(chosenList[total]);
		});
	}
	displayScore(score, total);
}
