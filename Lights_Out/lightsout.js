
function Flips(num) {
	// create a counter
	var counting = 0;

	// if block is clicked, then the color will change
	var block = num.toString();
	block = 'box' + block;
	newColor(block);

	// checks if the top half is in range
      // if it is, block will flip
	if ((num - 5) >= 1) {
		var upper = num - 5;
		upper = upper.toString();
		upper = 'box' + upper;
		newColor(upper);
	}

	// checks if lower half is in range
      // if it is, block will flip
	if ((num + 5) <= 25) {
		var lower = num + 5;
		lower = lower.toString();
		lower = 'box' + lower;
		newColor(lower);
	}

	// checks if righthand part of the grid is in range
      // if so, the block will flip
	if (((num - 1) % 5) == 0) {
		var rightHand = num + 1;
		rightHand = rightHand.toString();
		rightHand = 'box' + rightHand;
		newColor(rightHand);
	} 

	// checks if lefthand part of the grid is in range
      // if so, the block will flip
	else if ((num % 5) == 0) {
		var leftHand = num - 1;
		leftHand = leftHand.toString();
		leftHand = 'box' + leftHand;
		newColor(leftHand);
	}
    // if none of the if statements are true, then the right and left 
     // blocks are reset and then made true, the block will then flip
	else {
		var rightHand = num + 1;
		rightHand = rightHand.toString();
		rightHand = 'box' + rightHand;
		newColor(rightHand);

		var leftHand = num - 1;
		leftHand = leftHand.toString();
		leftHand = 'box' + leftHand;
		newColor(leftHand);
	}

	// checks the grid to see if player has won yet as they're playing
	// loop through the blocks to see what's clicked on
      // increment the counter
	for (var travelling = 1; travelling < 26; travelling++) {
		// turn current cell number into string
		travelling = travelling.toString();

		// concatenate to get ID
		var travellingID = 'box' + travelling;

		// get current element using ID
		var newElement = document.getElementById(travellingID);

		// get background color
		var background = newElement.style.backgroundColor;

		// check if background color is white
		if (background == 'blue') {
			// increment counter
			counting++;
		}
	}

	// if the grid is completely filled by blue blocks the player wins
       // display a win message
	if (counting == 25) {
		alert("You win!");
	}	
}
function  newColor(ID){

// sees what the buttons' colors are at present
  // initialize set color variable
    var button = document.getElementById(ID).style.backgroundColor;  
    var color = '';
   // if the block is not blue, then it will turn blue
    if (button !== 'blue') {
        color = 'blue';
        document.getElementById(ID).style.backgroundColor = color;       
    }
    // if the block is already blue, then the block will turn white
    else if (button === 'blue') {
        color = 'white';
        document.getElementById(ID).style.backgroundColor = color; 
    }
}

function  newTable() {
    // loop through the blocks and increment counter
	for (var temp = 1; temp < 26; temp++) {
		// the block that the player clicks on will convert to string
		temp = temp.toString();

		// get the new ID
		var tempID = 'box' + temp;

		// search for current element
		var tempElement = document.getElementById(tempID);

		// randomly generate 1 or 0 to create new table
		var randnums = Math.round(Math.random() % 2);

		// if the random number is 1, the block will be white
		if (randnums == 1) {
			tempElement.style.backgroundColor = 'white';
        // otherwise the block will be blue
		} else {
			tempElement.style.backgroundColor = 'blue';
		}

	}
}