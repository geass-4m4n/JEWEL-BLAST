#include <SFML/Graphics.hpp>
#include <time.h>
#include <bits/stdc++.h>
using namespace sf;
using namespace std;
;

int ts = 54; //tile size
Vector2i offset(48,24);  /////ALWAYS MOE4VE THIS MUCH TO ADJUST FRMAE;

struct piece
{ int x,y,col,row,kind,match,alpha,yscore,cancount;
piece(){match=0; alpha=255;yscore=0;cancount=1;}
} grid[10][10];

void swap(piece p1,piece p2)
{
  std::swap(p1.col,p2.col);   //////SWAP THE COLOMN VALUE WHICH SHOULD BE
  std::swap(p1.row,p2.row);

  grid[p1.row][p1.col]=p1;   ///////SWAP COORDINATES ACCORDINGLY 
  grid[p2.row][p2.col]=p2;
}

 int color_ava =7;
 int totscore =0;
 int highscore =0;
 
int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(740,480), "Match-3 Game!");
    app.setFramerateLimit(60);            //////////FRMAELIMIT
    
    Font font;
   if(!font.loadFromFile("AllerDisplay.ttf"))
   { 
      cout<<"error in font"<<endl;  /////////////font for score display
   }

    Texture t1,t2;
    t1.loadFromFile("images/background.png");
    t2.loadFromFile("images/gems.png");

    Sprite background(t1), gems(t2);

	for (int i=1;i<=8;i++)
     for (int j=1;j<=8;j++)
      {
          grid[i][j].kind=rand()%color_ava;          ///////////////STORING AN INTIAL DATA;
          grid[i][j].col=j;
          grid[i][j].row=i;
          grid[i][j].x = j*ts;
          grid[i][j].y = i*ts;
      }


    int x0,y0,x,y; int click=0; Vector2i pos;
    bool isSwap=false, isMoving=false;

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
			   	
			if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
				{
				   if (!isSwap && !isMoving) click++;     //////////IF NOT SWAPING AND NOT MOVING
				   pos = Mouse::getPosition(app)-offset;
                }
            if (e.type == Event::KeyPressed)
             if (e.key.code==Keyboard::R)
             {

	         	for (int i=1;i<=8;i++)
             	for (int j=1;j<=8;j++)
              	{
          			grid[i][j].kind=rand()%color_ava;          ///////////////STORING AN INTIAL DATA; 
                                grid[i][j].cancount=1;
          			grid[i][j].col=j;
          			grid[i][j].row=i;
          			grid[i][j].x = j*ts;
          			grid[i][j].y = i*ts;
     			 }
     			 totscore=0;

             }



         }
	
   // mouse click
   if (click==1)
    {
      x0=pos.x/ts+1;      ////////////FIRST CLICK TO SET 
      y0=pos.y/ts+1;
    }
   if (click==2)
    {
      x=pos.x/ts+1;
      y=pos.y/ts+1;
      if (abs(x-x0)+abs(y-y0)==1)
        {swap(grid[y0][x0],grid[y][x]); isSwap=1; click=0;}    ///SECOND CLICK TO MOVE
      else click=1;
    }

   //Match finding
   for(int i=1;i<=8;i++)
   for(int j=1;j<=8;j++)
   {
    if (grid[i][j].kind==grid[i+1][j].kind)
    if (grid[i][j].kind==grid[i-1][j].kind)
     for(int n=-1;n<=1;n++) 
     {
     grid[i+n][j].match++; 
     if(grid[i+n][j].cancount)
     {
        totscore++;
        grid[i+n][j].cancount=0;
        if(totscore>highscore)
          highscore=totscore;
     }
     
     }    /////STORE MATCH IN ALL THE CONSECUTIVE WAY

    if (grid[i][j].kind==grid[i][j+1].kind)
    if (grid[i][j].kind==grid[i][j-1].kind)               ///////SAME JUST AXIS IS DIFFERENT
     for(int n=-1;n<=1;n++) 
       {     	
       	grid[i][j+n].match++;
       	if(grid[i][j+n].cancount)
        {
        totscore++;
        grid[i][j+n].cancount=0;
        if(totscore>highscore)
          highscore=totscore;
         }
       }   
   }

   //Moving animation
   isMoving=false;                /////////////SETING THAT NOW ANYTHING IS NOT MOVING
   for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
     {
       piece &p = grid[i][j];
       int dx,dy;
       for(int n=0;n<6;n++)   // 4 - speed
       {dx = p.x-p.col*ts;
        dy = p.y-p.row*ts;
        if (dx) p.x-=dx/abs(dx);
	    if (dy) p.y-=dy/abs(dy);}
       if (dx||dy) isMoving=1;      ///////////IF DIFFERNCE THAN MOVING IS = 1
     }

   //Deleting amimation
   if (!isMoving)                 ///////////IF NOT MOVING THAN GO ON
    for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
      if (grid[i][j].match) 
    	if (grid[i][j].alpha>10) {grid[i][j].alpha-=10; isMoving=true;} /////ALPHA TO REDUCE OPACITY

   //Get score
   int score=0;
   for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++)
     { score+=grid[i][j].match;
      /////////JUST SIMPLE SCORE 
       }


   //Second swap if no match
   if (isSwap && !isMoving)
      {if (!score) swap(grid[y0][x0],grid[y][x]); 
      isSwap=0;}  ///AFTER EACH MOVE IF  
         /// SCORE DOESNT GROW THAN BACK TO POSITION


   //Update grid
   if (!isMoving)   //////////UPDATE ONLY IF NO ANIMATION IS GOING ON I.E. NOT MOVING ANYTHING
    {
      for(int i=8;i>0;i--)
       for(int j=1;j<=8;j++)
         if (grid[i][j].match)
         for(int n=i;n>0;n--)
            if (!grid[n][j].match) {swap(grid[n][j],grid[i][j]);grid[n][j].cancount=1;grid[i][j].cancount=1; break;};  ////JUST BRING TOP ELEMENT DOWN

      for(int j=1;j<=8;j++)
       for(int i=8,n=0;i>0;i--)
       {             grid[i][j].cancount=1;

         if (grid[i][j].match)
           {
            grid[i][j].kind = rand()%color_ava;
            grid[i][j].y = -ts*n++;    ///////FILL THE REMAING FROM TOP;;
            grid[i][j].match=0;
			grid[i][j].alpha = 255;
           }
       }
     }


    //////draw///////
    app.draw(background);

	for (int i=1;i<=8;i++)
     for (int j=1;j<=8;j++)
      {
        piece p = grid[i][j];
        gems.setTextureRect( IntRect(p.kind*49,0,49,49));
        gems.setColor(Color(255,255,255,p.alpha));
        gems.setPosition(p.x,p.y);
        gems.move(offset.x-ts,offset.y-ts);
        app.draw(gems);
      }

     

      Text text;

     text.setFont(font);
    text.setString("SCORE");
    text.setColor(Color :: Red);
    text.setCharacterSize(25);
    text.setPosition(490,380);
    app.draw(text);

    stringstream sscore,hscore;

        sscore << totscore;
    text.setFont(font);
    text.setString( sscore.str().c_str() );
    text.setColor(Color :: Red);
    text.setCharacterSize(40);
    text.setPosition(499,400);
    app.draw(text);

   text.setFont(font);
    text.setString("HIGH SCORE");
    text.setColor(Color :: Red);
    text.setCharacterSize(25);
    text.setPosition(580,380);
    app.draw(text);
    
    //highscore=10000;
   
     hscore << highscore;
    text.setFont(font);
    text.setString( hscore.str().c_str() );
    text.setColor(Color :: Red);
    text.setCharacterSize(40);
    text.setPosition(590,400);
    app.draw(text);

     app.display();
    }
    return 0;
}
