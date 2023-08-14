
var firstTime = true;
var firstTimeCal = true;

var body;
var infoTbl;
var calTbl;
var tblBody;
var INFOTABLENAME = "infoTable";
var CALTABLENAME = "calTable";

function makeInfoTable(descriptorData) {

	infoTbl = document.getElementById(INFOTABLENAME);// ocument.createElement("table");
	var x = infoTbl.rows.length
	for (var r = 0; r < x; r++) {
		infoTbl.deleteRow(-1);
	}
	tblBody = document.createElement("tbody");

	var rows = descriptorData.split("\n");

	for (var i = 0; i < rows.length - 1; i++) {
		var row = document.createElement("tr");
		var colls = rows[i].split(",");

		for (var j = 0; j < colls.length; j++) {
			if (i == 0)
				var cell = document.createElement("th");
			else
				var cell = document.createElement("td");

			var cellText = document.createTextNode(colls[j]);
			cell.appendChild(cellText);
			row.appendChild(cell);
		}
		tblBody.appendChild(row);
	}
	infoTbl.appendChild(tblBody);
}

function makeCalTable(descriptorData) {

	var colls;
	calTbl = document.getElementById(CALTABLENAME);// ocument.createElement("table");
	var x = calTbl.rows.length;
	for (var r = 0; r < x; r++) {
		calTbl.deleteRow(-1);
	}
	tblBody = document.createElement("tbody");

	var rows = descriptorData.split("\n");

	for (var i = 0; i < rows.length - 1; i++) {
		var row = document.createElement("tr");
		if (i == 0) {
			colls = rows[i].split(",");
			for (var j = 0; j < colls.length - 1; j++) {
				var cell = document.createElement("th");
				var cellText = document.createTextNode(colls[j]);
				cell.appendChild(cellText);
				row.appendChild(cell);
			}
		}
		else {
			var cell = document.createElement("td");
			var cellText = document.createTextNode(rows[i]);
			cell.appendChild(cellText);
			row.appendChild(cell);

			cell = document.createElement("td");
			var input = document.createElement("input");
			input.setAttribute("type", "number");
			cell.appendChild(input);
			row.appendChild(cell);

			cell = document.createElement("td");
			cell.setAttribute("calItem", i);

			var button = document.createElement("button");
			button.innerHTML = "Stel in";
			button.className = "button buttonGreen";
			cell.appendChild(button);
			row.appendChild(cell);

			cell = document.createElement("td");
			cell.setAttribute("calItem", i);

			var button = document.createElement("button");
			button.innerHTML = "Herstel";
			button.className = "button buttonGreen";
			button.setAttribute("id", "set" + i);

			cell.appendChild(button);
			row.appendChild(cell);
		}
		tblBody.appendChild(row);
	}
	calTbl.appendChild(tblBody);

	const cells = document.querySelectorAll("td[calItem]");
	cells.forEach(cell => {
		cell.addEventListener('click', function() { setCalFunction(cell.closest('tr').rowIndex, cell.cellIndex) });
	});
}

function readInfo(str) {
	makeInfoTable(str);
}

function readCalInfo(str) {
	if (SIMULATE) {
		if (firstTimeCal) {
			makeCalTable(str);
			firstTimeCal = false;
		}
		return;
	}
	else {	
		str = getItem("getCalValues");
		makeCalTable(str);
	}
}

function save() {
	getItem("saveSettings");
}

function cancel() {
	getItem("cancelSettings");
}


function setCalFunction(row, coll) {
	console.log("Row index:" + row + " Collumn: " + coll);
	var item = calTbl.rows[row].cells[0].innerText;

	if (coll == 3)
		sendItem("revertCal:" + item);
	else {
		//	var x = calTbl.rows[2].cells[3].firstChild.value;
		var value = calTbl.rows[row].cells[1].firstChild.value;
		console.log(item + value);
		if (value != "") {
			sendItem("setCal:" + item + '=' + value);
			//getItem("setcal:" + item + '=' + value);
		}
	}
}

function testInfo() {
	var str = "Meting,xActueel,xOffset,xx,\naap,2,3,4,\nnoot,5,6,7,\n,";
	readInfo(str);
}

function testCal() {
	var str = "Meting,Referentie,Stel in,Herstel,\nTemperatuur\n RH\n CO2\n";
	readCalInfo(str);
}

function initSettings() {
	if (SIMULATE) {
		testInfo();
		testCal();
	}
	else {
		//document.visibilityState

	}
	readCalInfo();
	setInterval(function() { settingsTimer() }, 1000);
}

function tempCal() {
	var str;
	//testInfo();
	testCal();

	// 	document.getElementById("infoTable").rows[2].cells[1].innerHTML = 1234;;
	// 		var rows = document.getElementById("infoTable").rows;
	// 		var targetCells = rows[1].cells;
	// 		targetCells[1].innerHTML = 1000;

	// 	var req = new XMLHttpRequest();
	// 	var data = document.getElementById("temperatureCal").value;
	// 	if ( data != "") 
	// 	{
	// 	str = "cgi_bin/temperatureCal=" + data;
	// 	req.open("POST", "cgi-bin/getLogMeasValues", false);
	// 	req.send();
	// 	if (req.readyState == 4) {
	// 		if (req.status == 200) {
	// 			str = req.responseText.toString();
	// 			return str;
	// 		//	var arr = str.split(",");
	// 		//	return arr;
	// 		}
	// 	}
	// 	}
}
var xcntr = 1;

function getInfo() {
	if (SIMULATE) {
		infoTbl.rows[1].cells[1].innerHTML = xcntr++;
		return;
	}
	var arr;
	var str;
	str = getItem("getInfoValues");
	if (firstTime) {
		makeInfoTable(str);
		firstTime = false;
	}
	else {
		var rows = str.split("\n");
		for (var i = 1; i < rows.length - 1; i++) {
			var colls = rows[i].split(",");
			for (var j = 1; j < colls.length; j++) {
				infoTbl.rows[i].cells[j].innerHTML = colls[j];
			}
		}
	}
}


function settingsTimer() {

	if (document.visibilityState == "hidden")
		return;
	getInfo();
	
}
