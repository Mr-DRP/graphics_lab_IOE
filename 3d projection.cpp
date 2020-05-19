# include <iostream>
 # include <graphics.h>
 # include    <conio.h>
 # include     <math.h>

 void show_screen( );

 void draw_cube(int [8][3]);
 void draw_pyramid(int [5][3]);

 void get_projected_point(int&,int&,int&);
 void multiply_matrices(constint[4],constint[4][4],int[4]);

 void Line(constint,constint,constint,constint);


 int main( )
    {
       int driver=VGA;
       int mode=VGAHI;

       initgraph(&driver,&mode,"..\\Bgi");

       show_screen( );

       int cube[8][3]={
             {370,200,50},      //  front left top
             {470,200,50},      //  front right top
             {470,300,50},      //  front right bottom
             {370,300,50},      //  front left bottom
             {370,200,-50},     //  back left top
             {470,200,-50},     //  back right top
             {470,300,-50},     //  back right bottom
             {370,300,-50}      //  back left bottom
              };

       setcolor(15);
     draw_cube(cube);

       settextstyle(0,0,1);
     outtextxy(400,320,"Cube");

       int pyramid[5][3]={
                {120,300,50},      //  base front left
                {220,300,50},      //  base front right
                {220,300,-50},     //  base back right
                {120,300,-50},     //  base back left
                {170,150,0}        //  top
             };

       setcolor(15);
     draw_pyramid(pyramid);

       settextstyle(0,0,1);
     outtextxy(135,320,"Pyramid");

       getch( );
       closegraph( );
       return 0;
    }


 /************************************************************************///----------------------------  draw_cube( )  --------------------------///************************************************************************/void draw_cube(int edge_points[8][3])
    {
       for(int i=0;i<8;i++)
      get_projected_point(edge_points[i][0],
                     edge_points[i][1],edge_points[i][2]);

     Line(edge_points[0][0],edge_points[0][1],
                     edge_points[1][0],edge_points[1][1]);
     Line(edge_points[1][0],edge_points[1][1],
                     edge_points[2][0],edge_points[2][1]);
     Line(edge_points[2][0],edge_points[2][1],
                     edge_points[3][0],edge_points[3][1]);
     Line(edge_points[3][0],edge_points[3][1],
                     edge_points[0][0],edge_points[0][1]);

     Line(edge_points[4][0],edge_points[4][1],
                     edge_points[5][0],edge_points[5][1]);
     Line(edge_points[5][0],edge_points[5][1],
                     edge_points[6][0],edge_points[6][1]);
     Line(edge_points[6][0],edge_points[6][1],
                     edge_points[7][0],edge_points[7][1]);
     Line(edge_points[7][0],edge_points[7][1],
                     edge_points[4][0],edge_points[4][1]);


     Line(edge_points[0][0],edge_points[0][1],
                      edge_points[4][0],edge_points[4][1]);
     Line(edge_points[1][0],edge_points[1][1],
                      edge_points[5][0],edge_points[5][1]);
     Line(edge_points[2][0],edge_points[2][1],
                      edge_points[6][0],edge_points[6][1]);
     Line(edge_points[3][0],edge_points[3][1],
                      edge_points[7][0],edge_points[7][1]);
    }

 /************************************************************************///--------------------------  draw_pyramid( )  -------------------------///************************************************************************/void draw_pyramid(int edge_points[5][3])
    {
       for(int i=0;i<5;i++)
      get_projected_point(edge_points[i][0],
                    edge_points[i][1],edge_points[i][2]);

     Line(edge_points[0][0],edge_points[0][1],
                      edge_points[1][0],edge_points[1][1]);
     Line(edge_points[1][0],edge_points[1][1],
                      edge_points[2][0],edge_points[2][1]);
     Line(edge_points[2][0],edge_points[2][1],
                      edge_points[3][0],edge_points[3][1]);
     Line(edge_points[3][0],edge_points[3][1],
                      edge_points[0][0],edge_points[0][1]);

     Line(edge_points[0][0],edge_points[0][1],
                      edge_points[4][0],edge_points[4][1]);
     Line(edge_points[1][0],edge_points[1][1],
                      edge_points[4][0],edge_points[4][1]);
     Line(edge_points[2][0],edge_points[2][1],
                      edge_points[4][0],edge_points[4][1]);
     Line(edge_points[3][0],edge_points[3][1],
                      edge_points[4][0],edge_points[4][1]);
    }

 /************************************************************************///---------------------  get_projected_point( )  -----------------------///************************************************************************/void get_projected_point(int& x,int& y,int& z)
    {
       int Par_k[4][4]={
             {1,0,0,0},
             {0,1,0,0},
             {0,0,0,0},
             {0,0,0,1}
               };

       int xy[4]={x,y,z,1};
       int new_xy[4]={0};

       multiply_matrices(xy,Par_k,new_xy);

       x=new_xy[0];
       y=new_xy[1];
       z=new_xy[2];
    }

void multiply_matrices(constint matrix_1[4],
                   constint matrix_2[4][4],int matrix_3[4])
    {
       for(int count_1=0;count_1<4;count_1++)
      {
         for(int count_2=0;count_2<4;count_2++)
        matrix_3[count_1]+=
               (matrix_1[count_2]*matrix_2[count_2][count_1]);
      }
    }

 /*************************************************************************///--------------------------  Line( )  ------------------------///*************************************************************************/void Line(constint x_1,constint y_1,constint x_2,constint y_2)
    {
       int color=getcolor( );

       int x1=x_1;
       int y1=y_1;

       int x2=x_2;
       int y2=y_2;

       if(x_1>x_2)
      {
         x1=x_2;
         y1=y_2;

         x2=x_1;
         y2=y_1;
      }

       int dx=abs(x2-x1);
       int dy=abs(y2-y1);
       int inc_dec=((y2>=y1)?1:-1);

       if(dx>dy)
      {
         int two_dy=(2*dy);
         int two_dy_dx=(2*(dy-dx));
         int p=((2*dy)-dx);

         int x=x1;
         int y=y1;

         putpixel(x,y,color);

         while(x<x2)
        {
           x++;

           if(p<0)
              p+=two_dy;

           else
              {
             y+=inc_dec;
             p+=two_dy_dx;
              }

           putpixel(x,y,color);
        }
      }

       else
      {
         int two_dx=(2*dx);
         int two_dx_dy=(2*(dx-dy));
         int p=((2*dx)-dy);

         int x=x1;
         int y=y1;

         putpixel(x,y,color);

         while(y!=y2)
        {
           y+=inc_dec;

           if(p<0)
              p+=two_dx;

           else
              {
             x++;
             p+=two_dx_dy;
              }

           putpixel(x,y,color);
        }
      }
    }

 /*************************************************************************///--------------------------  show_screen( )  ---------------------------///*************************************************************************/void show_screen( )
    {
       setfillstyle(1,1);
     bar(120,26,515,38);

       settextstyle(0,0,1);
     setcolor(15);
       outtextxy(5,5,"******************************************************************************");
       outtextxy(5,17,"*-**************************************************************************-*");
       outtextxy(5,29,"*------------                                                    ------------*");
       outtextxy(5,41,"*-**************************************************************************-*");
       outtextxy(5,53,"*-**************************************************************************-*");

     setcolor(11);
       outtextxy(128,29,"Orthographics Parallel Projection onto xy-plane");

     setcolor(15);

       for(int count=0;count<=30;count++)
          outtextxy(5,(65+(count*12)),"*-*                                                                        *-*");

       outtextxy(5,438,"*-**************************************************************************-*");
       outtextxy(5,450,"*---------------------------                         ------------------------*");
       outtextxy(5,462,"******************************************************************************");

     setcolor(12);
       outtextxy(227,450,"  Press any key to exit ");
    }
