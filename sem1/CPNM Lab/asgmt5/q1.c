#include <stdio.h>
#include <math.h>

typedef struct Point
{
	float x;
	float y;
} Pt;

double distance(Pt *p1, Pt *p2)
{
	return sqrt(pow(p1->x - p2->x, 2) + (p1->y - p2->y, 2));
}

double area(Pt *p1, Pt *p2, Pt *p3)
{
	int x1 = p1->x, x2 = p2->x, x3 = p3->x, y1 = p1->y, y2 = p2->y, y3 = p3->y;

	return fabs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}

int checkPointInside(Pt *p1, Pt *p2, Pt *p3, Pt *p)
{
	double a = area(p1, p2, p3);
	double a1 = area(p1, p2, p);
	double a2 = area(p1, p, p3);
	double a3 = area(p, p2, p3);

	// printf("%lf %lf %lf %lf\n", a, a1, a2, a3);

	if (a1 + a2 + a3 == a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	Pt p1, p2, p3, p;
	Pt *pt1 = &p1, *pt2 = &p2, *pt3 = &p3, *pt = &p;

	printf("Enter vertex 1 of triangle: ");
	scanf("%f %f", &(pt1->x), &(pt1->y));

	printf("Enter vertex 2 of triangle: ");
	scanf("%f %f", &(pt2->x), &(pt2->y));

	printf("Enter vertex 3 of triangle: ");
	scanf("%f %f", &(pt3->x), &(pt3->y));

	printf("Enter point to check: ");
	scanf("%f %f", &(pt->x), &(pt->y));

	int res = checkPointInside(pt1, pt2, pt3, pt);

	if (res == 1)
	{
		printf("res = %d. Point lies inside\n", res);
	}
	else
	{
		printf("res = %d. Point lies outside\n", res);
	}

	return 0;
}
