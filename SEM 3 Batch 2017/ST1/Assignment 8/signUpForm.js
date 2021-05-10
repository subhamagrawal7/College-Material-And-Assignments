function formValidate(e)
{
	let username = document.getElementById('username');
	if(username.value.length > 12 || username.value.length < 7){
		alert("Error: Person name should 7 to 12 characters.");
		username.focus();
		return false;
	}

	let password = document.getElementById('pass');
	let cnfrpassword = document.getElementById('cnfrpass');
	if((password.value !="") && (password.value == cnfrpassword.value)){

		let name = document.getElementById('username').value;
		if(password.value.length <5 || password.value.length >10){
			alert("Error: Password must contain 5 to 10 characters!");
			password.focus();
			return false;
		}
		if(password.value == name){
			alert("Error: Person name cannot be password.");
			password.focus();
			return false;
		}
		var numbers = /[0-9]/g;
		if(!password.value.match(numbers)){
			alert("Error: password must contain at least one number (0-9)!");
	        password.focus();
	        return false;
		}
		var lowerCaseLetters = /[a-z]/g;
		if(!password.value.match(lowerCaseLetters)){
			alert("Error: password must contain at least one lowercase letter (a-z)!");
	        password.focus();
	        return false;
		}
		var upperCaseLetters = /[A-Z]/g;
		if(!password.value.match(upperCaseLetters)){
			alert("Error: password must contain at least one uppercase letter (A-Z)!");
	        password.focus();
	        return false;
		}
	}
	else{
		alert("Error: Your password and confirmation password do not match");
		password.focus();
		return false;
	}

	let phone = document.getElementById('mobile');
	if(isNaN(phone.value)){
		alert("Error: Phone/Mobile number should be 10 digit.");
		phone.focus();
		return false;
	}

	if(phone.value.length != 10){
		alert("Error: Phone/Mobile number should be 10 digit.");
		phone.focus();
		return false;
	}
	
	alert("Welcome "+ username.value +" you have been added as a new user.");
   	return true;
   	
}