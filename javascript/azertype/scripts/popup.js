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

function	displayMail(name, mail, score)
{
	let mailto = `mailto:${mail}?subject=Partage du score Azertype&body=Salut, je suis ${name} et je viens de réaliser le score ${score} sur le site d'Azertype !`
    location.href = mailto
}

function	initPopup(score)
{
	// Click on the "Partager" button
	let shareBtn = document.getElementById("sendBtn");
	shareBtn.addEventListener("click", () =>
	{
		console.log("Form popup asked");
		displayPopup();
	});
	
	// Click on the background
	let	popupBackground = document.querySelector(".popupBackground");
	popupBackground.addEventListener("click", (event) =>
	{
		if (event.target == popupBackground)
			hidePopup();
	});

	// Event on the form
 	let form = document.querySelector("form");
	form.addEventListener("submit", (event) => 
	{
		event.preventDefault();		// prevent from refreshing the page (default behavior)
		let	nameInput = document.getElementById("nom");
		let	name = nameInput.value;
		let	mailInput = document.getElementById("email");
		let mail = mailInput.value;
		console.log(name, mail);
		displayMail(name, mail, score);
	});

}