//
//		          Programming Assignment #1
//
//					Daljit Singh Dhillon
//
//
/***************************************************************************/
// Calla Corder (C14211064)
/* Include needed files */
#include <iostream>
using namespace std;


/***************************************************************************/
// Forward declarations
void drawPixel(int x, int y);

void drawLineDDA(float xStart, float yStart, float xEnd, float yEnd);
void drawLineBresenham(int xStart, int yStart, int xEnd, int yEnd);
void drawThickLineBresenham(int xStart, int yStart, int xEnd, int yEnd, int lineWidth);
void drawLineSlopeIntercept(float slope, float yIntercept);
void draw2dAxesAndSquare(float orgX, float orgY, float xVecE1, float xVecE2, float yVecE1, float yVecE2, float sqrBaseX, float sqrBaseY, float sqrWidth);
void draw3dAxesAndCube(float orgX, float orgY, float xVecE1, float xVecE2, float yVecE1, float yVecE2, float zVecE1, float zVecE2, float cubeBaseX, float cubeBaseY, float cubeBaseZ, float cubeWidth);
void drawStyleDottedLine(float xStart, float yStart, float xEnd, float yEnd, int lineWidth);
void drawStyleDashedLine(float xStart, float yStart, float xEnd, float yEnd, int lineWidth);
void drawStyleDotAndDashLine(float xStart, float yStart, float xEnd, float yEnd, int lineWidth);

void drawLineDDA(float xStart, float yStart, float xEnd, float yEnd)
{
	drawPixel((int)xStart,(int)yStart);
	drawPixel((int)xEnd, (int)yEnd);

	//replace above two lines with your own inplementation
}

void drawLineBresenham(int xStart, int yStart, int xEnd, int yEnd)
{
  int delta_y = yEnd - yStart;
  int delta_x = xEnd - xStart;
  int y = yStart;
  int x = xStart;

  // if slope is positive and angle is between 0 and 45 degrees, drawn left to right
    if(delta_x > delta_y && delta_x > 0 && delta_y > 0)
    {
      
      int k = 2 * (delta_y - delta_x); 
      int d_1 =  2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while (x <= xEnd)
      {
	drawPixel((int)x, (int)y);
        if (k < 0) {
	  k += d_1;
	}
	else {
	  y += 1;
	  k += d_2;
	} //if
	x += 1;
       } //while
     } //if
    //if slope is positive and angle is between 45 and 90 degrees, drawn from left to right
    else if (delta_y > delta_x && delta_x > 0 && delta_y > 0)
      {
	int k = 2 * (delta_x - delta_y);
	int d_1 = 2 * delta_x;
	int d_2 = 2 * (delta_x - delta_y);
	while (y < yEnd) {
	  drawPixel((int)x, (int)y);
	  if (k < 0) {
	    k += d_1;
	  } else {
	    x +=1;
	    k += d_2;
	  }
	  y +=1;
	} //while
	}  //else if
    //if slope is a positive 45 degree angle, drawn from left to right
   else if (delta_x == delta_y && delta_x > 0 && delta_y > 0) {
      while (x < xEnd) {
	drawPixel((int)x, (int)y);
	x += 1;
	y += 1;
      } //while
    } //else if
    //if drawing a vertical line
    else if (delta_x == 0){
      //drawing left to right
      if (delta_y > 0) {
	while (y < yEnd) {
	  drawPixel((int)x, (int)y);
	  y += 1;
	} //while
	//drawing right to left
      } else {
	while (y >= yEnd) {
	  drawPixel((int)x, (int)y);
	  y -= 1;
	} //while
      } //else
    } //else if
    //horizontal line
    else if (delta_y == 0) {
      //drawing upwards
      if (delta_x > 0) {
	while(x <= xEnd) {
	  drawPixel((int)x, (int)y);
	  x += 1;
	} //while
	// drawing down
      } else {
	while (x >= xEnd) {
	  drawPixel((int)x, (int)y);
	  x -= 1;
	}
      } //if
    } //else if
    //if slope is negative between 0 and -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x > (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x < xEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x += 1;
      } //while
    } //else if
    //if slope is -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x == (delta_y * -1)) {
	delta_y *= -1;
	int k = 0;
	int d_1 = 2 * delta_y;
	int d_2 = 2 * (delta_y - delta_x);
	while(x < xEnd) {
	  drawPixel((int)x, (int)y);
	  if(k < 0) {
	    k += d_1;
	  } else {
	    y -= 1;
	    k += d_2;
	  } //if
	  x += 1;
	} //while
      } //else if
       //if slope is negative between -45 and -90 degrees, drawn from left to right
      else if(delta_y < 0 && delta_x > 0 && delta_x < (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd){
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  x += 1;
	  k += d_2;
	} //if
        y -= 1;
      } //while
    } //else if
    //if slope is positive between 45 and 90 degrees, drawn from right to left
    else if(delta_x < 0 && delta_y > 0 && delta_y > (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y <=yEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y += 1;
      } //while
    } //else if
      //if 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y ==(delta_x * -1)) {
      delta_x *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope is positive between 0 and 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y < (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      // if slope is negative between -45 and -90 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x < delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope = -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x ==delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
    // if slope is negative between 0 and -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x > delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd) {
	drawPixel((int)x, (int)y);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y -= 1;
      } //while
    } //else if
}

void drawThickness(int delta_y, int delta_x, float x, float y, int lineWidth) {
    float xTemp = x;
    float yTemp = y;
    if(delta_y < 0)
      delta_y*= -1;
    if (delta_x <0)
      delta_x *= -1;
    if (delta_y == 0) {
      for( int f = 0; f < lineWidth; f++) {
	yTemp = y + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
    } else if (delta_x == 0) {
      for( int f = 0; f < lineWidth; f++) {
	  xTemp = x + f;
	  drawPixel((int)xTemp, (int) yTemp);
      } //for
    }
    else if( delta_y >= delta_x) {
      for( int f = 0; f < lineWidth; f++) {
	xTemp = x + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
    } else if (delta_y < delta_x) {
	for( int f = 0; f < lineWidth; f++) {
	  yTemp = y + f;
	  drawPixel((int)xTemp, (int) yTemp);
      } //for
    } // if
    
   
}

void drawThickLineBresenham(int xStart, int yStart, int xEnd, int yEnd, int lineWidth)
{
  //draw 3 pixels, have a gap of 4 pixels
  int delta_y = yEnd - yStart;
  int delta_x = xEnd - xStart;
  int y = yStart;
  int x = xStart;

  // if slope is positive and angle is between 0 and 45 degrees, drawn left to right
    if(delta_x > delta_y && delta_x > 0 && delta_y > 0)
    {
      
      int k = 2 * (delta_y - delta_x); 
      int d_1 =  2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while (x <= xEnd)
      {
	drawThickness(delta_y, delta_x, x, y, lineWidth);
        if (k < 0) {
	  k += d_1;
	}
	else {
	  y += 1;
	  k += d_2;
	} //if
	x += 1;
       } //while
     } //if
    //if slope is positive and angle is between 45 and 90 degrees, drawn from left to right
    else if (delta_y > delta_x && delta_x > 0 && delta_y > 0)
      {
	int k = 2 * (delta_x - delta_y);
	int d_1 = 2 * delta_x;
	int d_2 = 2 * (delta_x - delta_y);
	while (y < yEnd) {
	  drawThickness(delta_y, delta_x,x, y, lineWidth);
	  if (k < 0) {
	    k += d_1;
	  } else {
	    x +=1;
	    k += d_2;
	  }
	  y +=1;
	} //while
	}  //else if
    //if slope is a positive 45 degree angle, drawn from left to right
   else if (delta_x == delta_y && delta_x > 0 && delta_y > 0) {
      while (x < xEnd) {
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	x += 1;
	y += 1;
      } //while
    } //else if
    //if drawing a vertical line
    else if (delta_x == 0){
      //drawing left to right
      if (delta_y > 0) {
	while (y < yEnd) {
	  drawThickness(delta_y, delta_x,x, y, lineWidth);
	  y += 1;
	} //while
	//drawing right to left
      } else {
	while (y >= yEnd) {
	  drawThickness(delta_y, delta_x,x, y, lineWidth);
	  y -= 1;
	} //while
      } //else
    } //else if
    //horizontal line
    else if (delta_y == 0) {
      //drawing upwards
      if (delta_x > 0) {
	while(x <= xEnd) {
	  drawThickness(delta_y, delta_x,x, y, lineWidth);
	  x += 1;
	} //while
	// drawing down
      } else {
	while (x >= xEnd) {
	  drawThickness(delta_y, delta_x,x, y, lineWidth);
	  x -= 1;
	}
      } //if
    } //else if
    //if slope is negative between 0 and -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x > (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x < xEnd) {
        drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x += 1;
      } //while
    } //else if
    //if slope is -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x == (delta_y * -1)) {
	delta_y *= -1;
	int k = 0;
	int d_1 = 2 * delta_y;
	int d_2 = 2 * (delta_y - delta_x);
	while(x < xEnd) {
	  drawThickness(delta_y, delta_x,x, y, lineWidth);
	  if(k < 0) {
	    k += d_1;
	  } else {
	    y -= 1;
	    k += d_2;
	  } //if
	  x += 1;
	} //while
      } //else if
       //if slope is negative between -45 and -90 degrees, drawn from left to right
      else if(delta_y < 0 && delta_x > 0 && delta_x < (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd){
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x += 1;
	  k += d_2;
	} //if
        y -= 1;
      } //while
    } //else if
    //if slope is positive between 45 and 90 degrees, drawn from right to left
    else if(delta_x < 0 && delta_y > 0 && delta_y > (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y <=yEnd) {
        drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y += 1;
      } //while
    } //else if
      //if 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y ==(delta_x * -1)) {
      delta_x *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope is positive between 0 and 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y < (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      // if slope is negative between -45 and -90 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x < delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope = -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x ==delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
    // if slope is negative between 0 and -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x > delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd) {
	drawThickness(delta_y, delta_x,x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y -= 1;
      } //while
    } //else if

}

int decideToDrawDot(int count, float x, float y, int lineWidth) {
  if (count < lineWidth) {
    //draw based on lineWidth
    float xTemp = x;
    float yTemp = y;
    for(int d = 0; d < lineWidth; d++) {
      for( int f = 0; f < lineWidth; f++) {
	xTemp = x + d;
	yTemp = y + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
      count++;
    } //for
    
    count++;
  } else {
    if (count < (lineWidth*3)) {
      count++;
    } else {
      count = 0;
    }
  }
  return count;
}

void drawStyleDottedLine(float xStart, float yStart, float xEnd, float yEnd, int lineWidth)
{
  int count = 0;
  //draw 3 pixels, have a gap of 4 pixels
 int delta_y = yEnd - yStart;
  int delta_x = xEnd - xStart;
  int y = yStart;
  int x = xStart;

  // if slope is positive and angle is between 0 and 45 degrees, drawn left to right
    if(delta_x > delta_y && delta_x > 0 && delta_y > 0)
    {
      
      int k = 2 * (delta_y - delta_x); 
      int d_1 =  2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while (x <= xEnd)
      {
	count = decideToDrawDot(count, x, y, lineWidth);
        if (k < 0) {
	  k += d_1;
	}
	else {
	  y += 1;
	  k += d_2;
	} //if
	x += 1;
       } //while
     } //if
    //if slope is positive and angle is between 45 and 90 degrees, drawn from left to right
    else if (delta_y > delta_x && delta_x > 0 && delta_y > 0)
      {
	int k = 2 * (delta_x - delta_y);
	int d_1 = 2 * delta_x;
	int d_2 = 2 * (delta_x - delta_y);
	while (y < yEnd) {
	  count = decideToDrawDot(count, x, y, lineWidth);
	  if (k < 0) {
	    k += d_1;
	  } else {
	    x +=1;
	    k += d_2;
	  }
	  y +=1;
	} //while
	}  //else if
    //if slope is a positive 45 degree angle, drawn from left to right
   else if (delta_x == delta_y && delta_x > 0 && delta_y > 0) {
      while (x < xEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	x += 1;
	y += 1;
      } //while
    } //else if
    //if drawing a vertical line
    else if (delta_x == 0){
      //drawing left to right
      if (delta_y > 0) {
	while (y < yEnd) {
	  count = decideToDrawDot(count, x, y, lineWidth);
	  y += 1;
	} //while
	//drawing right to left
      } else {
	while (y >= yEnd) {
	  count = decideToDrawDot(count, x, y, lineWidth);
	  y -= 1;
	} //while
      } //else
    } //else if
    //horizontal line
    else if (delta_y == 0) {
      //drawing upwards
      if (delta_x > 0) {
	while(x <= xEnd) {
	  count = decideToDrawDot(count, x, y, lineWidth);
	  x += 1;
	} //while
	// drawing down
      } else {
	while (x >= xEnd) {
	  count = decideToDrawDot(count, x, y, lineWidth);
	  x -= 1;
	}
      } //if
    } //else if
    //if slope is negative between 0 and -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x > (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x < xEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x += 1;
      } //while
    } //else if
    //if slope is -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x == (delta_y * -1)) {
	delta_y *= -1;
	int k = 0;
	int d_1 = 2 * delta_y;
	int d_2 = 2 * (delta_y - delta_x);
	while(x < xEnd) {
	  count = decideToDrawDot(count, x, y, lineWidth);
	  if(k < 0) {
	    k += d_1;
	  } else {
	    y -= 1;
	    k += d_2;
	  } //if
	  x += 1;
	} //while
      } //else if
       //if slope is negative between -45 and -90 degrees, drawn from left to right
      else if(delta_y < 0 && delta_x > 0 && delta_x < (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd){
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x += 1;
	  k += d_2;
	} //if
        y -= 1;
      } //while
    } //else if
    //if slope is positive between 45 and 90 degrees, drawn from right to left
    else if(delta_x < 0 && delta_y > 0 && delta_y > (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y <=yEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y += 1;
      } //while
    } //else if
      //if 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y ==(delta_x * -1)) {
      delta_x *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
 	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope is positive between 0 and 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y < (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      // if slope is negative between -45 and -90 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x < delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope = -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x ==delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
    // if slope is negative between 0 and -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x > delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd) {
	count = decideToDrawDot(count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y -= 1;
      } //while
    } //else if

    //make sure start and end points are drawn
    drawPixel((int)xStart,(int)yStart);
    drawPixel((int)xEnd, (int)yEnd);
}

int decideToDrawDash(float delta_y, float delta_x, int count, float x, float y, int lineWidth) {
  if (count < (lineWidth*3)) {
    float xTemp = x;
    float yTemp = y;
    if(delta_y < 0)
      delta_y*= -1;
    if (delta_x <0)
      delta_x *= -1;
    if (delta_y == 0) {
      for( int f = 0; f < lineWidth; f++) {
	yTemp = y + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
    } else if (delta_x == 0) {
      for( int f = 0; f < lineWidth; f++) {
	xTemp = x + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
    }
    else if( delta_y >= delta_x) {
      for( int f = 0; f < lineWidth; f++) {
	xTemp = x + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
    } else if (delta_y < delta_x) {
      for( int f = 0; f < lineWidth; f++) {
	yTemp = y + f;
	drawPixel((int)xTemp, (int) yTemp);
      } //for
    } // if
    count++;
  } else {
    if (count < (lineWidth*4)) {
      count++;
    } else {
      count = 0;
    }
  }
  return count;
}

void drawStyleDashedLine(float xStart, float yStart, float xEnd, float yEnd, int lineWidth)
{
  int count = 0;
  //draw 3 pixels, have a gap of 4 pixels
  int delta_y = yEnd - yStart;
  int delta_x = xEnd - xStart;
  int y = yStart;
  int x = xStart;

  // if slope is positive and angle is between 0 and 45 degrees, drawn left to right
    if(delta_x > delta_y && delta_x > 0 && delta_y > 0)
    {
      
      int k = 2 * (delta_y - delta_x); 
      int d_1 =  2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while (x <= xEnd)
      {
	count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
        if (k < 0) {
	  k += d_1;
	}
	else {
	  y += 1;
	  k += d_2;
	} //if
	x += 1;
       } //while
     } //if
    //if slope is positive and angle is between 45 and 90 degrees, drawn from left to right
    else if (delta_y > delta_x && delta_x > 0 && delta_y > 0)
      {
	int k = 2 * (delta_x - delta_y);
	int d_1 = 2 * delta_x;
	int d_2 = 2 * (delta_x - delta_y);
	while (y < yEnd) {
	  count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
	  if (k < 0) {
	    k += d_1;
	  } else {
	    x +=1;
	    k += d_2;
	  }
	  y +=1;
	} //while
	}  //else if
    //if slope is a positive 45 degree angle, drawn from left to right
   else if (delta_x == delta_y && delta_x > 0 && delta_y > 0) {
      while (x < xEnd) {
	count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
	x += 1;
	y += 1;
      } //while
    } //else if
    //if drawing a vertical line
    else if (delta_x == 0){
      //drawing left to right
      if (delta_y > 0) {
	while (y < yEnd) {
	  count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
	  y += 1;
	} //while
	//drawing right to left
      } else {
	while (y >= yEnd) {
	  count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
	  y -= 1;
	} //while
      } //else
    } //else if
    //horizontal line
    else if (delta_y == 0) {
      //drawing upwards
      if (delta_x > 0) {
	while(x <= xEnd) {
	  count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
	  x += 1;
	} //while
	// drawing down
      } else {
	while (x >= xEnd) {
	  count = decideToDrawDash(delta_y, delta_x, count, x, y, lineWidth);
	  x -= 1;
	}
      } //if
    } //else if
    //if slope is negative between 0 and -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x > (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x < xEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x += 1;
      } //while
    } //else if
    //if slope is -45 degrees, drawn from left to right
    else if(delta_y < 0 && delta_x > 0 && delta_x == (delta_y * -1)) {
	delta_y *= -1;
	int k = 0;
	int d_1 = 2 * delta_y;
	int d_2 = 2 * (delta_y - delta_x);
	while(x < xEnd) {
	  count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	  if(k < 0) {
	    k += d_1;
	  } else {
	    y -= 1;
	    k += d_2;
	  } //if
	  x += 1;
	} //while
      } //else if
       //if slope is negative between -45 and -90 degrees, drawn from left to right
      else if(delta_y < 0 && delta_x > 0 && delta_x < (delta_y * -1)) {
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd){
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x += 1;
	  k += d_2;
	} //if
        y -= 1;
      } //while
    } //else if
    //if slope is positive between 45 and 90 degrees, drawn from right to left
    else if(delta_x < 0 && delta_y > 0 && delta_y > (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y <=yEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y += 1;
      } //while
    } //else if
      //if 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y ==(delta_x * -1)) {
      delta_x *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope is positive between 0 and 45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y > 0 && delta_y < (delta_x * -1)) {
      delta_x *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >=xEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y += 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      // if slope is negative between -45 and -90 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x < delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_y - delta_x);
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
      //if slope = -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x ==delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 0;
      int d_1 = 2 * delta_y;
      int d_2 = 2 * (delta_y - delta_x);
      while(x >= xEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  y -= 1;
	  k += d_2;
	} //if
	x -= 1;
      } //while
    } //else if
    // if slope is negative between 0 and -45 degrees, drawn from right to left
     else if(delta_x < 0 && delta_y < 0 && delta_x > delta_y) {
      delta_x *= -1;
      delta_y *= -1;
      int k = 2 * (delta_x - delta_y);
      int d_1 = 2 * delta_x;
      int d_2 = 2 * (delta_x - delta_y);
      while(y >= yEnd) {
	count = decideToDrawDash(delta_y, delta_x,count, x, y, lineWidth);
	if(k < 0) {
	  k += d_1;
	} else {
	  x -= 1;
	  k += d_2;
	} //if
	y -= 1;
      } //while
    } //else if

    //make sure start and end points are drawn
    drawPixel((int)xStart,(int)yStart);
    drawPixel((int)xEnd, (int)yEnd);
}

void drawStyleDotAndDashLine(float xStart, float yStart, float xEnd, float yEnd, int lineWidth)
{
	drawPixel((int)xStart,(int)yStart);
	drawPixel((int)xEnd, (int)yEnd);

	//replace above two lines with your own inplementation
}


void drawLineSlopeIntercept(float slope, float yIntercept)
{
  int xStart = 0;
  int yStart = yIntercept;
  int x = xStart;
  int y = yStart;
  //box is 800 x 600
  if (slope != 0) {
    while( (x >= 0 &&  x <= 800) || (y >= 0 && y <= 600)) {
      x += 1;
      y = (x * slope) + yIntercept;
    }
  } else {
    x = 800; //no need to calculate x
  }
  
  drawLineBresenham((int)xStart, (int)yStart, (int)x, (int)y);
   
  //drawPixel((int)yIntercept,(int)yIntercept);
  //drawPixel((int)yIntercept, (int)yIntercept);

	//replace above two lines with your own inplementation
}
void draw2dAxesAndSquare(float orgX, float orgY,
						 float xVecE1, float xVecE2,
						 float yVecE1, float yVecE2,
						 float cubeBaseX, float cubeBaseY, float cubeWidth)
{
	drawPixel((int)orgX,(int)orgY);
	drawPixel((int)orgX, (int)orgY);

	//replace above two lines with your own inplementation
}
void draw3dAxesAndCube(float orgX, float orgY,
					   float xVecE1, float xVecE2,
					   float yVecE1, float yVecE2,
					   float zVecE1, float zVecE2,
					   float cubeBaseX, float cubeBaseY, float cubeBaseZ, float cubeWidth)
{
  int xStart = orgX;
  int yStart = orgY;
  
  //draw x axis
  if (xVecE1 == 0 && xVecE2 == 1) { // vertical line
   int xEnd = orgX;
   yStart = 0;
   int yEnd = 800;
   drawLineBresenham((int)xStart, (int)yStart, (int)xEnd, (int)yEnd);
  } else {
     float slopeX = xVecE2 / xVecE1;
     //calculate y intercept (y - mx = c)
     float yIntercept = orgY - (orgX * slopeX);
     drawLineSlopeIntercept(slopeX, yIntercept);
  }

  //draw y axis
  if (yVecE1 == 0 && yVecE2 == 1) { // vertical line
   int xEnd = orgX;
   yStart = 0;
   int yEnd = 800;
   drawLineBresenham((int)xStart, (int)yStart, (int)xEnd, (int)yEnd);
  } else {
     float slopeY = yVecE2 / yVecE1;
     //calculate y intercept (y - mx = c)
     float yIntercept = orgY - (orgX * slopeY);
     drawLineSlopeIntercept(slopeY, yIntercept);
  }

  //draw z axis
  if (zVecE1 == 0 && zVecE2 == 1) { // vertical line
   int xEnd = orgX;
   yStart = 0;
   int yEnd = 800;
   drawLineBresenham((int)xStart, (int)yStart, (int)xEnd, (int)yEnd);
  } else {
     float slopeZ = zVecE2 / zVecE1;
     //calculate y intercept (y - mx = c)
     float yIntercept = orgY - (orgX * slopeZ);
     drawLineSlopeIntercept(slopeZ, yIntercept);
  }

  //draw cube
  float cubeXPoint1 = orgX;
  float cubeYPoint1 = orgY;
  //move point across x axis
  cubeXPoint1 = (cubeXPoint1) + (cubeBaseX * xVecE1);
  cubeYPoint1 = cubeYPoint1 + (cubeBaseX * xVecE2);
  //move across y axis
  cubeXPoint1 = (cubeXPoint1) + (cubeBaseY * yVecE1);
  cubeYPoint1 = cubeYPoint1 + (cubeBaseY * yVecE2);
  //move across z axis
  cubeXPoint1 = (cubeXPoint1) + (cubeBaseZ * zVecE1);
  cubeYPoint1 = cubeYPoint1 + (cubeBaseZ * zVecE2);

 
  //move point across x axis
  float cubeXPoint2 = (cubeXPoint1) + (cubeWidth * xVecE1);
  float cubeYPoint2 = cubeYPoint1 + (cubeWidth * xVecE2);

  //move across y axis
  float cubeXPoint3 = (cubeXPoint1) + (cubeWidth * yVecE1);
  float cubeYPoint3 = cubeYPoint1 + (cubeWidth * yVecE2);

  //move point across x axis
  float cubeXPoint4 = (cubeXPoint3) + (cubeWidth * xVecE1);
  float cubeYPoint4 = cubeYPoint3 + (cubeWidth * xVecE2);

  //move across z axis
  float cubeXPoint5 = (cubeXPoint3) + (cubeWidth * zVecE1);
  float cubeYPoint5 = cubeYPoint3 + (cubeWidth * zVecE2);

  //move point across x axis
  float cubeXPoint6 = (cubeXPoint5) + (cubeWidth * xVecE1);
  float cubeYPoint6 = cubeYPoint5 + (cubeWidth * xVecE2);
  
  //move across y axis
  float cubeXPoint7 = (cubeXPoint5) - (cubeWidth * yVecE1);
  float cubeYPoint7 = cubeYPoint5 - (cubeWidth * yVecE2);

  //move point across x axis
  float cubeXPoint8 = (cubeXPoint7) + (cubeWidth * xVecE1);
  float cubeYPoint8 = cubeYPoint7 + (cubeWidth * xVecE2);

  //draw cube lines
   drawLineBresenham((int)cubeXPoint1, (int)cubeYPoint1, (int)cubeXPoint2, (int)cubeYPoint2);
   drawLineBresenham((int)cubeXPoint1, (int)cubeYPoint1, (int)cubeXPoint3, (int)cubeYPoint3);
   drawLineBresenham((int)cubeXPoint1, (int)cubeYPoint1, (int)cubeXPoint7, (int)cubeYPoint7);
   drawLineBresenham((int)cubeXPoint5, (int)cubeYPoint5, (int)cubeXPoint3, (int)cubeYPoint3);
   drawLineBresenham((int)cubeXPoint5, (int)cubeYPoint5, (int)cubeXPoint6, (int)cubeYPoint6);
   drawLineBresenham((int)cubeXPoint5, (int)cubeYPoint5, (int)cubeXPoint7, (int)cubeYPoint7);
   drawLineBresenham((int)cubeXPoint6, (int)cubeYPoint6, (int)cubeXPoint4, (int)cubeYPoint4);
   drawLineBresenham((int)cubeXPoint6, (int)cubeYPoint6, (int)cubeXPoint8, (int)cubeYPoint8);
   drawLineBresenham((int)cubeXPoint8, (int)cubeYPoint8, (int)cubeXPoint7, (int)cubeYPoint7);
   drawLineBresenham((int)cubeXPoint8, (int)cubeYPoint8, (int)cubeXPoint2, (int)cubeYPoint2);
   drawLineBresenham((int)cubeXPoint3, (int)cubeYPoint3, (int)cubeXPoint4, (int)cubeYPoint4);
   drawLineBresenham((int)cubeXPoint4, (int)cubeYPoint4, (int)cubeXPoint2, (int)cubeYPoint2);
}


