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
	closeBtn.addEventListener("click", () =>
	{
			hidePopup();
	});

	// Click on the "Envoyer" button
	let	sendBtn = document.getElementById("btnEnvoyerMail");
	sendBtn.addEventListener("click", () =>
	{
		let	nameInput = document.getElementById("nom");
		let	name = nameInput.value;
		let	mailInput = document.getElementById("email");
		let mail = mailInput.value;
		displayMail(name, mail);
		console.log(name, mail);
	})
}
