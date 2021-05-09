function calc() {
  var p = document.getElementById("principal").value;
  var r = document.getElementById("roi").value;
  var t = document.getElementById("time").value;
  console.log(p);
  var si = (p * r * t) / 100;
  console.log(si);
  document.getElementById("Output").innerHTML = `Simple Interest: ${si}`;
}
