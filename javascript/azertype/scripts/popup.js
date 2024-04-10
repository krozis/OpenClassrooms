function	displayPopup()
{
	let	popup = document.querySelector(".popupBackground")

	popup.classList.add("active");
}

function	hidePopup()
{
	let	popup = document.querySelector(".popupBackground")

	popup.classList.remove("active");
}

function	displayMail(name, mail)
{
	let	scoreElement = document.querySelector(".zoneScore span");
	score = scoreElement.innerText;
	let mailto = `mailto:${mail}?subject=Partage du score Azertype&body=Salut, je suis ${name} et je viens de réaliser le score ${score} sur le site d'Azertype !`
    location.href = mailto
}

function	checkName(name)
{
	let	regex = new RegExp("[a-zA-Z]{2,}"); //minimum 2 letters (upper/lower accepted);
	return (regex.test(name));
}

function	checkMail(mail)
{
	let	regex = new RegExp("[a-z0-9._-]+@[a-z0-9._-]+\.[a-z0-9._-]+");
	return (regex.test(mail));
}

function	initPopup()
{
	// prevent default event on the form
	let form = document.querySelector("form");
	form.addEventListener("submit", (event) => 
	{
		event.preventDefault();		// prevent from refreshing the page (default behavior)
	});

	// Click on the "Partager" button
	let shareBtn = document.getElementById("sendBtn");
	shareBtn.addEventListener("click", () =>
	{
		console.log("Form popup asked");
		displayPopup();
	});
	
	// Click on close button
	let	closeBtn = document.getElementById("close");
	closeBtn.addEventListener("click", (event) =>
	{
			event.preventDefault();
			hidePopup();
	});

	// Click on the "Envoyer" button
	let	sendBtn = document.getElementById("sendMailForm");
	sendBtn.addEventListener("submit", (event) =>
	{
		let	nameInput = document.getElementById("nom");
		let	name = nameInput.value;
		let	mailInput = document.getElementById("email");
		let mail = mailInput.value;
	
		if (!checkName(name))
		{
			console.log("Error, invalid name");
			nameInput.classList.add("error");
			nameInput.classList.remove("correct");
		}
		else if (!checkMail(mail))
		{
			console.log("Error, invalid mail");
			mailInput.classList.add("error");
			mailInput.classList.remove("correct");
		}
		else
		{
			nameInput.classList.remove("error");
			nameInput.classList.add("correct");
			mailInput.classList.remove("error");
			mailInput.classList.add("correct");
			displayMail(name, mail);
			console.log(name, mail);
		}
	})
}
