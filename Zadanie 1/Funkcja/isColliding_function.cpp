#include <iostream>
#include <string>
#include <array>

using namespace std;

struct vec2
{
float x, y;
};

struct triangle
{
std::array<vec2, 3>points;
};



bool cp(float xa1, float ya1, float xb1, float yb1, float xc2, float yc2, float xd2, float yd2)
{
    float m1, c1, m2, c2;
    float dx1, dy1;
    float dx2, dy2;
    float intersection_X, intersection_Y;
    
        // line 1
    dx1 = xb1 - xa1;
    dy1 = yb1 - ya1;
    
    m1 = dy1 / dx1;
    c1 = ya1 - m1 * xa1;
    
        // line 2
    dx2 = xd2 - xc2;
    dy2 = yd2 - yc2;
    
    m2 = dy2 / dx2;
    c2 = yd2 - m2 * xd2;
    


        // Showing lines equations (unnecessary)
         std::cout << "\n\n";

    std::cout << "\tLine 1 points: (" << xa1 << ", "<< ya1 << ")  ,  (" << xb1 << ", "<< yb1 << ")\n";
    std::cout << "Equation of line 1: ";

    std::cout << "y = " << m1 << "x " << ((c1 < 0) ? ' ' : '+') << c1 << "\n";

   

    std::cout << "\tLine 2 points: (" << xc2 << ", "<< yc2 << ")  ,  (" << xd2 << ", "<< yd2 << ")\n";
    std::cout << "Equation of line 2: ";

    std::cout << "y = " << m2 << "x " << ((c2 < 0) ? ' ' : '+') << c2 << "\n";

    
        // checking
    
    if( (m1 - m2) == 0 || (dx1 == 0 && dx2 == 0 && xa1 != xc2))
    {
         if(c1 != c2)
        {
            std::cout << "\tNo Intersection between the lines\n";
            return false;
        }
        else if(c1 == c2 && (xa1 == xb1 && xc2 == xd2 && xa1 == xc2))
        {
             std::cout << "\n\tFull Coverage."<<endl;
            return true;
        }
    }
    else
    {
        if(dx1 == 0 && dx2 == 0 && xa1 == xc2)
        {
            std::cout << "\n\tFull Coverage"<<endl;
            return true;
        }
        else if(dx1 == 0)
        {
            intersection_X = xa1;
            intersection_Y = m2 * intersection_X + c2;
        }
        else if(dx2 == 0)
        {
            intersection_X = xc2;
            intersection_Y = m1 * intersection_X + c1;
        }
        else
        {

        intersection_X = (c2 - c1) / (m1 - m2);
        
        intersection_Y = m1 * intersection_X + c1;
        }
        std::cout << "\tIntersecting Point: = ";

        std::cout << intersection_X;

        std::cout << ",";

        std::cout << intersection_Y;

        std::cout << "\n";
        
        
            // line 1 "a\b"
        if( (xa1 < xb1) && (ya1 > yb1) && ((intersection_X < xa1) || (intersection_X > xb1)) && ((intersection_Y > ya1) || (intersection_Y < yb1)) )
        {
            return false;
        }
        
            // line 1 "a/b"
        else if( (xa1 < xb1) && (ya1 < yb1) && ((intersection_X < xa1) || (intersection_X > xb1)) && ((intersection_Y < ya1) || (intersection_Y > yb1)) )
        {
            return false;
        }
        
            // line 1 "b\a"
        else if( (xb1 < xa1) && (yb1 > ya1) && ((intersection_X > xa1) || (intersection_X < xb1)) && ((intersection_Y < ya1) || (intersection_Y > yb1)) )
        {
            return false;
        }
        
            // line 1 "b/a"
        else if( (xb1 < xa1) && (yb1 < ya1) && ((intersection_X > xa1) || (intersection_X < xb1)) && ((intersection_Y > ya1) || (intersection_Y < yb1)) )
        {
            return false;
        }

            // line 1 "a|b" // a point is lower than b
        else if( (xa1 == xb1) && (ya1 < yb1) && ((intersection_Y < ya1) || (intersection_Y > yb1)) )
        {
            return false;
        }

            // line 1 "b|a" // b point is lower than a
        else if( (xa1 == xb1) && (ya1 > yb1) && ((intersection_Y > ya1) || (intersection_Y < yb1)) )
        {
            return false;
        }

            // line 1 "a-b"
        else if( (xa1 < xb1) && (ya1 == yb1) && ((intersection_X < xa1) || (intersection_X > xb1)) )
        {
            return false;
        }

            // line 1 "b-a"
        else if( (xa1 > xb1) && (ya1 == yb1) && ((intersection_X > xa1) || (intersection_X < xb1)) )
        {
            return false;
        }
        
        

            // line 2 "c\d"
        else if( (xc2 < xd2) && (yc2 > yd2) && ((intersection_X < xc2) || (intersection_X > xd2)) && ((intersection_Y > yc2) || (intersection_Y < yd2)) )
        {
            return false;
        }
        
            // line 2 "c/d"
        else if( (xc2 < xd2) && (yc2 < yd2) && ((intersection_X < xc2) || (intersection_X > xd2)) && ((intersection_Y < yc2) || (intersection_Y > yd2)) )
        {
            return false;
        }
        
            // line 2 "d\c"
        else if( (xd2 < xc2) && (yd2 > yc2) && ((intersection_X > xc2) || (intersection_X < xd2)) && ((intersection_Y < yc2) || (intersection_Y > yd2)) )
        {
            return false;
        }
        
            // line 2 "d/c"
        else if( (xd2 < xc2) && (yd2 < yc2) && ((intersection_X > xc2) || (intersection_X < xd2)) && ((intersection_Y > yc2) || (intersection_Y < yd2)) )
        {
            return false;
        }

            // line 2 "c|d" // c point is lower than d
        else if( (xc2 == xd2) && (yc2 < yd2) && ((intersection_Y < yc2) || (intersection_Y > yd2)) )
        {
            return false;
        }

            // line 2 "d|c" // d point is lower than c
        else if( (xc2 == xd2) && (yc2 > yd2) && ((intersection_Y > yc2) || (intersection_Y < yd2)) )
        {
            return false;
        }

            // line 2 "c-d"
        else if( (xc2 < xd2) && (yc2 == yd2) && ((intersection_X < xc2) || (intersection_X > xd2)) )
        {
            return false;
        }

            // line 2 "d-c"
        else if( (xc2 > xd2) && (yc2 == yd2) && ((intersection_X > xc2) || (intersection_X < xd2)) )
        {
            return false;
        }
        
        else
        {
           return true; 
        }
        

    }
    
    
}


float sign (vec2 p1, vec2 p2, vec2 p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (vec2 pt, vec2 v1, vec2 v2, vec2 v3)
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, v1, v2);
    d2 = sign(pt, v2, v3);
    d3 = sign(pt, v3, v1);

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}


bool isColliding(const triangle& triangle1, const triangle& triangle2 )
{
    
   triangle1.points[0].x;

   bool CollisionDetect = false;

    int z1[3] = {0, 0, 1};
    int z2[3] = {1, 2, 2};
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            CollisionDetect = cp(triangle1.points[z1[i]].x, triangle1.points[z1[i]].y, triangle1.points[z2[i]].x, triangle1.points[z2[i]].y, triangle2.points[z1[j]].x, triangle2.points[z1[j]].y, triangle2.points[z2[j]].x, triangle2.points[z2[j]].y);
            
            if(CollisionDetect == true)
            {
                break;
            }
        }

        if(CollisionDetect == true)
        {
            break;
        }

    }

    if(CollisionDetect == false)  // Checking if one triangle points are contained in the other one
    {
        bool is_inside = false;
        is_inside = PointInTriangle(triangle2.points[0], triangle1.points[0], triangle1.points[1], triangle1.points[2]);
        if(is_inside == false)
        {is_inside = PointInTriangle(triangle2.points[1], triangle1.points[0], triangle1.points[1], triangle1.points[2]);}
        if(is_inside == false)
        {is_inside = PointInTriangle(triangle2.points[2], triangle1.points[0], triangle1.points[1], triangle1.points[2]);}

        if(is_inside == false)
        {is_inside = PointInTriangle(triangle1.points[0], triangle2.points[0], triangle2.points[1], triangle2.points[2]);}
        if(is_inside == false)
        {is_inside = PointInTriangle(triangle1.points[1], triangle2.points[0], triangle2.points[1], triangle2.points[2]);}
        if(is_inside == false)
        {is_inside = PointInTriangle(triangle1.points[2], triangle2.points[0], triangle2.points[1], triangle2.points[2]);}

        if(is_inside == true)
        {
        std::cout<<"\n\tOne triangle is contained in the other one ! \n";
        }

        CollisionDetect = is_inside;

    }
    
    
    return CollisionDetect;

}




