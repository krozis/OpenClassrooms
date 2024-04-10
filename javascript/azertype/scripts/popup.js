function	displayErrorMessage(message)
{
	let	spanErrMsg = document.getElementById("errorMessage");
	if (!spanErrMsg)  // Reuse if exists, to avoid multiple creation
	{
		let	popup = document.querySelector(".popup");
		spanErrMsg = document.createElement("span");
		spanErrMsg.id = "errorMessage";
		popup.append(spanErrMsg);
	}
	spanErrMsg.innerText = message;
}

function	displayPopup()
{
	let	popup = document.querySelector(".popupBackground")

	popup.classList.add("active");
}

function	hidePopup()
{
	// disable popup
	let	popup = document.querySelector(".popupBackground");
	popup.classList.remove("active");

	// delete previous error message
	let	spanErrMsg = document.getElementById("errorMessage");
	if (spanErrMsg)
		spanErrMsg.remove();

	// flush name and mail
	let	nameInput = document.getElementById("nom");
	let	mailInput = document.getElementById("email");

	nameInput.value = "";
	mailInput.value = "";
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
		if (!regex.test(name.value))
		{
			console.log("Error, invalid name");
			name.classList.add("error");
			throw new Error("name is not valid");
		}
		else
		{
			name.classList.remove("error");
		}
}

function	checkMail(mail)
{
	let	regex = new RegExp("[a-z0-9._-]+@[a-z0-9._-]+\\.[a-z0-9._-]+");
	if (!regex.test(mail.value))
	{
		console.log("Error, invalid mail");
		mail.classList.add("error");
		throw new Error("eMail is not valid");
	}
	else
	{
		mail.classList.remove("error");
	}

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
		event.preventDefault();
		try
		{
			let	nameInput = document.getElementById("nom");
			let	mailInput = document.getElementById("email");
			checkName(nameInput);
			checkMail(mailInput);
			displayMail(nameInput.value, mailInput.value);
			console.log("sent mail with values :", nameInput.value, mailInput.value);
		}
		catch(error)
		{
			displayErrorMessage(error.message);
			console.log(error);
		}
	})
}
