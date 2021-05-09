var a = prompt("Enter the first no.");
var b = prompt("Enter the second no.");
var c = prompt("Enter the third no.");
var maxx = Math.max(a, Math.max(b, c));
document.getElementById("Output").innerHTML = `The maximum element is ${maxx}`;
