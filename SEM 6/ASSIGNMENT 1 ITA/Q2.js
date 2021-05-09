function validateForm() {
  var sname = document.forms["regForm"]["sname"].value;
  var rollNo = document.forms["regForm"]["rollNo"].value;
  var branch = document.forms["regForm"]["branch"].value;
  var phoneNo = document.forms["regForm"]["phoneNo"].value;

  if (sname == "") {
    alert("Name must be filled out");
    return false;
  } else if (rollNo == "") {
    alert("Roll no. must be filled out");
    return false;
  } else if (branch == "") {
    alert("Branch must be filled out");
    return false;
  } else if (phoneNo == "") {
    alert("Phone no. must be filled out");
    return false;
  } else {
    alert("Form submitted successfully");
    return true;
  }
}
