#include <stdio.h>
#include <stdbool.h>

typedef struct point point_t;
typedef struct rectangle rectangle_t;

struct point
{
  int x;
  int y;
};

struct rectangle
{
  point_t x;
  point_t y;
};

void translate(point_t *p1, point_t *p2)
{
  p1->x += p2->x;
  p1->y += p2->y;
}

void print_point(point_t *p)
{
    printf("point(%d, %d)", p->x, p->y);
}

void print_rect(rectangle_t *p)
{
    printf("rectangle(upper_left=");
    print_point(&p->x);
    printf(" lower_right=");
    print_point(&p->y);
    printf(")\n");
}

point_t make_point(int x, int y)
{
  point_t p = {.x = x, .y = y};
  return p;
}

rectangle_t make_rectangle(int a, int b, int c, int d)
{
  rectangle_t r = {.x = make_point(a, b), .y = make_point(c, d)};
  return r;
}

int area_rect(rectangle_t *rect){
    int width = rect->x.x - rect->y.x;
    int length = rect->x.y - rect->y.y;
    int area = width * length;
    return area;
}

bool intersects_rect(rectangle_t *rect1, rectangle_t *rect2){
    int leftX1 = rect1->x.x;
    int rightX1 = rect1->y.x;
    int leftX2 = rect2->x.x;
    int rightX2 = rect2->y.x;

    int topY1 = rect1->x.y;
    int bottomY1 = rect1->y.y;
    int topY2 = rect2->x.y;
    int bottomY2 = rect2->y.y;

    // printf("%d\n", topY1);
    // printf("%d\n", bottomY2);
    // printf("%d\n", bottomY1);
    // printf("%d\n", topY2);

    if ((topY1 >= bottomY2) && (bottomY1 <= topY2) && (rightX1 >= leftX2) && (leftX1 <= rightX2)){
      return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    /* point_t test = {.x = 10, .y = 10};
    point_t test2 = make_point(5, 5);
    print_point(&test2);
    rectangle_t testrec = {.x = make_point(5,5), .y = make_point(3,3)}; */
    rectangle_t testrec2 = make_rectangle(5, 6, 8, 4);
    rectangle_t testrec3 = make_rectangle(4, 5, 9, 3);
    //print_rect(&testrec2);
    printf("%d\n", intersects_rect(&testrec2, &testrec3));
    return 0;
}
