const fs = require('fs');

function traverse_case(s)
{
	let i1 = s.indexOf("case(") + "case(".length;
	let i2 = s.indexOf(")", s.indexOf("case("));
	let condition = s.substring(i1, i2);
	
	let i3 = s.indexOf("return(") + "return(".length;
	let i4 = s.indexOf(")", s.indexOf("return("));
	let statement = s.substring(i3, i4);

	return(`case(${statement}): { return(${condition}); break; }`);
}


var switch_body = fs.readFileSync("switch_to_traverse.cpp", "utf-8");

var cases = switch_body.split('\r\n');
var result = "";
for (let i = 0; i < cases.length; i++)
{
	if (cases[i].length != 0)
	{
		result += traverse_case(cases[i]);
	}
	result += "\n";
}

fs.writeFileSync("switch_traversed.cpp", result, "utf-8");