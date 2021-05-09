
function localFilename(url)	// removing path
{
	var x = url.lastIndexOf("/");
	url = url.slice(x + 1);
	return url;		
}


// images are loaded asynchronously with no delay

function preloading(url)
{
	var xhr=createXHR();   
	xhr.onreadystatechange=function()
	{ 
		if(xhr.readyState == 4)
		{
			var content = xhr.responseText;
			var i = new Image();
			i.src = content;
		} 
	}; 

	xhr.open("GET", url , true);
	xhr.send(null); 
} 


function enlarge(element)
{
	var name = element.src;
	
	name = localFilename(name);
	name = name.slice(6);   // remove the "thumb-" part
	name = "images/big-" + name;  // restore path and add the new "big-" prefix
		
	// building a string to display the image
	
	var str = "<img src='" + name + "' >";
	document.getElementById("bigview").innerHTML = str;

}
