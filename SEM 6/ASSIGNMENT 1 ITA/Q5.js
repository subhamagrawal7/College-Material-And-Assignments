var el = document.getElementById("mainCheckbox");
var main = el.getElementsByTagName("input");
if (main[0].type === "checkbox") {
  main[0].onclick = function() {
    showElements(this, "optionsForCheckbox");
  };
}

function showElements(box, id) {
  if (box.checked) {
    document.getElementById(id).style.display = "block";
  } else {
    document.getElementById(id).style.display = "none";
  }
}

function validateForm() {
  var email = document.forms["regForm"]["email"].value;
  if (email == "") {
    alert("Email must be filled out");
    return false;
  } else {
    alert("Thank You!!");
    return true;
  }
}
